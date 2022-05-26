/*****************************************************************************
Copyright (c) 2012 - 2032, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 05/01/2022
http://asynframe.sf.net

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the
above copyright notice, this list of conditions
and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/
#pragma once

#define PER_DATA_SIZE 4096

class CIpcsEvent : public asynsdk::asyn_message_events_impl
{
public:
    CIpcsEvent(IAsynIpcChannel *lpAsynIpcsChannel, IAsynFrameThread *lpAsynFrameThread, BOOL bIsStream = TRUE)
        : m_lSeqno(1)
    {
        m_spAsynIpcsChannel = lpAsynIpcsChannel;
        m_spAsynFrameThread = lpAsynFrameThread;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        m_hNotify = CreateEvent(NULL, TRUE, FALSE, NULL);
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **ppAsynIoOperation )
    {
        if( lMessageId != AF_IOMSG_NOTIFY )
        {
            printf("lMsg: %d, param: %I64d/%I64d\n", lMessageId, lParam1, lParam2);
        }
        if( lMessageId == AF_IOMSG_NOTIFY )
        {
            IAsynIoOperation *lpAsynIoOperation = (IAsynIoOperation *)*ppAsynIoOperation;
            uint32_t lErrorCode, lTransferedBytes;
            lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);


            if( lParam2 == Io_recv )
            {
                if( lErrorCode ) printf("recv error: %d\n", lErrorCode);
                if( lErrorCode )
                {
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer( 0, 0, &lpBuffer );
                    printf("recv[%04I64d] %s, %p/%d\n", lParam1, (char *)lpBuffer, lpBuffer, lTransferedBytes);

                    return m_spAsynIpcDevice->Read(lpAsynIoOperation);
                }
            }
            if( lParam2 == Io_send )
            {
                if( lErrorCode ) printf("send, error: %d\n", lErrorCode);
                if( lErrorCode )
                {
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    if( m_lSeqno <= 10 )   //send
                    {
                        unsigned char *lpBuffer;
                        lpAsynIoOperation->GetIoBuffer( 0, 0, &lpBuffer );
                        sprintf((char *)lpBuffer, "1%08I64d", m_lSeqno);
                        lpAsynIoOperation->SetIoParams(0, 10, 0);
                        lpAsynIoOperation->SetOpParam1( m_lSeqno ++ );
                        return m_spAsynIpcDevice->Write(lpAsynIoOperation, 0);
                    }

                    return E_NOTIMPL;
                }
            }

            if( lParam2 == Io_acceptd )
            {
                if( lErrorCode ) printf("accept, error: %d\n", lErrorCode);
                if( lErrorCode )
                {
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    CComPtr<IAsynIpcIoOperation> spAsynIoOperation;
                    lpAsynIoOperation->QueryInterface(IID_IAsynIpcIoOperation, (void **)&spAsynIoOperation);

                    uint32_t    ppid;
                    std::string name;
                    asynsdk::CStringSetterRef temp(1, &name);
                    spAsynIoOperation->GetPeerAddress(&temp, &ppid);
                    printf("succ to accept from %s:%d\n", name.c_str(), ppid);

                    m_lSeqno = 1;
                    //send
                    {
                        CComPtr<IAsynIoOperation> spAsynIoOperation;
                        m_spAsynIpcsChannel->CreateAsynIoOperation(m_spAsynFrame, 0, 0, IID_IAsynIpcIoOperation, (void **)&spAsynIoOperation);
                        unsigned char *lpBuffer;
                        spAsynIoOperation->NewIoBuffer( 0, 0, 0, 0, PER_DATA_SIZE, &lpBuffer );
                        sprintf((char *)lpBuffer, "1%08I64d", m_lSeqno);
                        spAsynIoOperation->SetIoParams( 0, 10, 0 );
                        spAsynIoOperation->SetOpParam1( m_lSeqno ++);
                        m_spAsynIpcDevice->Write( spAsynIoOperation, 0 );
                    }

                    return m_spAsynIpcDevice->Read( lpAsynIoOperation );
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Start(const std::string &name)
    {
        m_spAsynIpcsChannel->CreateAsynIpcDeviceListener(asynsdk::STRING_EX::null, &m_spAsynIpcDevice);
        HRESULT r1 = m_spAsynIpcDevice->Open(m_spAsynFrameThread, STRING_from_string(name));
        if( r1 != S_OK )
        {
            printf("open %s:%d, error: %d", name.c_str(), ::GetCurrentProcessId(), r1);
            return false;
        }

        CComPtr<IAsynIpcIoOperation> spAsynIoOperation;
        m_spAsynIpcsChannel->CreateAsynIoOperation(m_spAsynFrame, 0, 0, IID_IAsynIpcIoOperation, (void **)&spAsynIoOperation);

        printf("ipc.listen %s:%d\n", name.c_str(), ::GetCurrentProcessId());
        m_spAsynIpcDevice->Accept(spAsynIoOperation);
        return true;
    }

    void Shutdown()
    {
        m_spAsynFrame->Shutdown();
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynIpcChannel > m_spAsynIpcsChannel;
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    HANDLE m_hNotify;

    CComPtr<IAsynIpcDeviceListener> m_spAsynIpcDevice;
    uint64_t m_lSeqno;
};

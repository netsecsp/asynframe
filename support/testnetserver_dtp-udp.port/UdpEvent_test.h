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

class CUdpEvent_test : public asynsdk::asyn_message_events_impl
{
public:
    CUdpEvent_test(unsigned char ident, IAsynFrameThread *lpAsynFrameThread, IAsynNetwork *lpAsynNetwork)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        m_seqno = 1;
        m_ident = ident;
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **object )
    {
        if( lMessageId == AF_QUERY_RESULT )
        {
            STRING* data = (STRING*)lParam2;
            return data->len >= 10 && data->ptr[8] == m_ident? S_OK : S_FALSE;
        }
        if( lMessageId == AF_IOMSG_NOTIFY )
        {
            IAsynIoOperation* lpAsynIoOperation = (IAsynIoOperation*)object[0];
            uint32_t lErrorCode, lTransferedBytes;
            lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    printf("recv, error: %d\n", lErrorCode);
                    return E_NOTIMPL;
                }
                else
                {
                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    asynsdk::CStringSetter host(1);
                    PORT port;
                    spAsynIoOperation->GetPeerAddress(&host, 0, &port, 0);

                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer(0, 0, &lpBuffer);
                    printf("%p recv[%4d] %s from %s:%d\n", this, lTransferedBytes, (char *)lpBuffer, host.m_val.c_str(), port);

                    sprintf((char *)lpBuffer, "1%08d", m_seqno ++);
                    lpAsynIoOperation->SetIoParams(0, 10, 0);
                    return m_spAsynUdpSocket->Write(lpAsynIoOperation);
                }
            }
            if( lParam2 == Io_send )
            {
                if( lErrorCode )
                {
                    printf("send, error: %d\n", lErrorCode);
                    return E_NOTIMPL;
                }
                else
                {
                    lpAsynIoOperation->SetIoParams(0, 1500, 0);
                    return m_spAsynUdpSocket->Read(lpAsynIoOperation);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    void Start(IDtpService *lpDtpService, uint32_t position = 0)
    {
        lpDtpService->CreateAsynDtpSocketLayer(GetAsynMessageEvents(), position, 0, asynsdk::STRING_EX::null, (IUnknown**)&m_spAsynUdpSocket);

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, AF_INET, 0, IID_IAsynNetIoOperation, (IUnknown **)&spAsynIoOperation);

        m_spAsynUdpSocket->Open(0, AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        spAsynIoOperation->NewIoBuffer(0, 0, 0, 0, 1500, 0);
        spAsynIoOperation->SetIoParams(0, 1500, 0);
        m_spAsynUdpSocket->Read(spAsynIoOperation);
    }

    void Shutdown()
    {
        m_spAsynFrame->Shutdown();
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;
    CComPtr<IAsynUdpSocket  > m_spAsynUdpSocket;
    unsigned long m_seqno;
    unsigned char m_ident;
};

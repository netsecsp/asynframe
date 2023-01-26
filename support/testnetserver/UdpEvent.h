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

#define PER_DATA_SIZE 1500

class CUdpEvent : public asynsdk::asyn_message_events_impl
{
public:
    CUdpEvent(IAsynFrameThread *lpAsynFrameThread, IAsynNetwork *lpAsynNetwork, uint32_t af)
        : m_lSeqno(1), m_af(af)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
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
                if( lErrorCode )
                {
                    printf("recv error: %d\n", lErrorCode);
                    return E_NOTIMPL;
                }
                else
                {
                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    asynsdk::CStringSetter host(1);
                    PORT port;
                    spAsynIoOperation->GetPeerAddress(&host, 0, &port, 0);

                    if( host.m_val != m_host ||
                        port != m_port )   //first to send
                    {
                        m_host = host.m_val;
                        m_port = port;
                        m_lSeqno  = 1;
                        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                        spAsynIoOperation->SetPeerAddress(0, &STRING_from_string(m_host), 0, m_port, 0);

                        unsigned char *lpBuffer;
                        spAsynIoOperation->NewIoBuffer(0, 0, 0, 0, PER_DATA_SIZE, &lpBuffer);
                        sprintf_s((char *)lpBuffer, 10, "1%08d", m_lSeqno ++);
                        spAsynIoOperation->SetIoParams(0, 10, 0);
                        m_spAsynUdpSocket->Write(spAsynIoOperation, 0);
                    }

                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer(0, 0, &lpBuffer);
                    printf("recv[%4d] %s from %s:%d\n", lTransferedBytes, (char *)lpBuffer, host.m_val.c_str(), port);

                    lpAsynIoOperation->SetIoParams(0, PER_DATA_SIZE, 0);
                    return m_spAsynUdpSocket->Read(lpAsynIoOperation);
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
                    if( m_lSeqno > 20 ) return E_NOTIMPL;
                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    spAsynIoOperation->SetPeerAddress(0, &STRING_from_string(m_host), 0, m_port, 0);

                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer( 0, 0, &lpBuffer );
                    sprintf_s((char *)lpBuffer, 10, "1%08d", m_lSeqno ++);
                    lpAsynIoOperation->SetIoParams(0, 10, 0);
                    return m_spAsynUdpSocket->Write(lpAsynIoOperation, 0);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Start(PORT port, const char *mhost = 0)
    {
        m_spAsynNetwork->CreateAsynUdpSocket(&m_spAsynUdpSocket );
        m_spAsynUdpSocket->Open( m_spAsynFrameThread, m_af, SOCK_DGRAM, m_af==AF_IPX? NSPROTO_IPX : IPPROTO_UDP);
        
        if( mhost ) //228.88.88.88
        {// 查看加入组播命令: netsh interface ipv4/ipv6 show joins
            CComPtr<IAsynGrpSocket> spAsynGrpSocket; m_spAsynUdpSocket->QueryInterface(IID_IAsynGrpSocket, (void**)&spAsynGrpSocket);
            spAsynGrpSocket->Add(asynsdk::STRING_EX::null, STRING_from_string(mhost));
        }

        HRESULT r1 = m_spAsynUdpSocket->Bind( asynsdk::STRING_EX::null, port, TRUE, NULL );
        if( r1 != S_OK)
        {
            printf("bind *:%d, error: %d\n", port, r1);
            return false;
        }
        if( port == 0 ) m_spAsynUdpSocket->GetSockAddress(0, 0, &port, 0);
        printf("%s.listen *:%d\n", m_af==AF_IPX? "ipx" : "udp", port);

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);

        spAsynIoOperation->NewIoBuffer(0, 0, 0, 0, PER_DATA_SIZE, 0);
        spAsynIoOperation->SetIoParams(0, PER_DATA_SIZE, 0);
        m_spAsynUdpSocket->Read(spAsynIoOperation);
        return true;
    }

    void Shutdown()
    {
        Stop(m_spAsynFrame);
        m_spAsynFrame = 0;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;
    CComPtr<IAsynUdpSocket  > m_spAsynUdpSocket;

    std::string   m_host;
    PORT          m_port;

    uint32_t m_af; //ipv4/ipv6/ipx
    uint32_t m_lSeqno;
};

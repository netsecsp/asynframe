/*****************************************************************************
Copyright (c) 2012 - 2019, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 07/01/2016
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

class CTcpEvent : public asynsdk::asyn_message_events_impl
{
public:
    CTcpEvent(IAsynFrameThread *lpAsynFrameThread, IAsynNetwork *lpAsynNetwork, uint32_t af)
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
                    printf("fail to recv, error: %d\n", lErrorCode);
                    m_arOp2AsynTcpSockets.erase(lpAsynIoOperation);
                    return E_NOTIMPL;
                }
                else
                {
                    auto it = m_arOp2AsynTcpSockets.find(lpAsynIoOperation);
                    if( it == m_arOp2AsynTcpSockets.end()) return E_NOTIMPL;
                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer(0, 0, &lpBuffer);
                    printf("recv[%4d] %s\n", lTransferedBytes, (char *)lpBuffer);

                    lpAsynIoOperation->SetIoParams(0, 10, 0);
                    return it->second->Read(lpAsynIoOperation);
                }
            }
            if( lParam2 == Io_send )
            {
                if( lErrorCode )
                {
                    printf("fail to send, error: %d\n", lErrorCode);
                    m_arOp2AsynTcpSockets.erase(lpAsynIoOperation);
                    return E_NOTIMPL;
                }
                else
                {
                    if( m_lSeqno > 20 ) return E_NOTIMPL;
                    auto it = m_arOp2AsynTcpSockets.find(lpAsynIoOperation);
                    if( it == m_arOp2AsynTcpSockets.end()) return E_NOTIMPL;
                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer(0, 0, &lpBuffer);

                    sprintf((char *)lpBuffer, "1%08d", m_lSeqno ++);
                    lpAsynIoOperation->SetIoParams(0, 10, 0);
                    return it->second->Write(lpAsynIoOperation);
                }
            }

            if( lParam2 == Io_acceptd )
            {
                if( lErrorCode )
                {
                    printf("fail to accept: %d\n", lErrorCode);
                    return m_spAsynTcpSocketListener->Accept(lpAsynIoOperation);
                }

                m_lSeqno = 1;
                {
                    //??????
                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    asynsdk::CStringSetter host;
                    PORT        port;
                    spAsynIoOperation->GetPeerAddress(&host, 0, &port, 0);
                    printf("succ to accept from %s:%d\n", host.m_val.c_str(), port);
                }

                CComPtr<IAsynTcpSocket     > spNewAsynTcpSocket;
                lpAsynIoOperation->GetCompletedObject(1, IID_IAsynTcpSocket, (void **)&spNewAsynTcpSocket);

                {
                    //send
                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    m_arOp2AsynTcpSockets[spAsynIoOperation] = spNewAsynTcpSocket;

                    unsigned char *lpBuffer;
                    spAsynIoOperation->NewIoBuffer(0, 0, 0, 0, PER_DATA_SIZE, &lpBuffer);
                    sprintf((char *)lpBuffer, "1%08d", m_lSeqno ++);
                    spAsynIoOperation->SetIoParams(0, 10, 0);
                    spNewAsynTcpSocket->Write(spAsynIoOperation);
                }

                {
                    //recv
                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    m_arOp2AsynTcpSockets[spAsynIoOperation] = spNewAsynTcpSocket;

                    spAsynIoOperation->NewIoBuffer(0, 0, 0, 0, PER_DATA_SIZE, 0);
                    spAsynIoOperation->SetIoParams(0, 10, 0);
                    spNewAsynTcpSocket->Read(spAsynIoOperation);
                }

                return m_spAsynTcpSocketListener->Accept(lpAsynIoOperation);
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Start(PORT port)
    {
        m_spAsynNetwork->CreateAsynTcpSocketListener(asynsdk::STRING_EX::null, &m_spAsynTcpSocketListener);
        m_spAsynTcpSocketListener->Open(m_spAsynFrameThread, m_af, SOCK_STREAM, IPPROTO_TCP);

        HRESULT r1 = m_spAsynTcpSocketListener->Bind(asynsdk::STRING_EX::null, port, TRUE, NULL); //???bind
        if( r1 != S_OK)
        {
            printf("fail to bind *:%d, error: %d\n", port, r1);
            return false;
        }

        if( port == 0 ) m_spAsynTcpSocketListener->GetSockAddress(0, 0, &port, 0);
        printf("tcp.listen *:%d\n", port);

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
        m_spAsynTcpSocketListener->Accept(spAsynIoOperation);
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
    CComPtr<IAsynTcpSocketListener> m_spAsynTcpSocketListener;

    uint32_t m_af; //ipv4/ipv6/ipx
    uint32_t m_lSeqno;
    std::map<IAsynIoOperation *, CComPtr<IAsynTcpSocket> > m_arOp2AsynTcpSockets;
};

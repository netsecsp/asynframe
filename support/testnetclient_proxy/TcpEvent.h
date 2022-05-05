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

            if( lParam2 == Io_connect )
            {
                if( lErrorCode )
                {
                    printf("connect, error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    printf("succ to connect\n\n");
                    {// send
                        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                        unsigned char *lpBuffer;
                        spAsynIoOperation->NewIoBuffer( 0,  0, 0, 0, PER_DATA_SIZE, &lpBuffer );
                        sprintf((char *)lpBuffer, "%09d", m_lSeqno ++);
                        spAsynIoOperation->SetIoParams( 0, 10, 0 );
                        m_spAsynTcpSocket->Write( spAsynIoOperation, 0 );
                    }

                    lpAsynIoOperation->NewIoBuffer( 0, 0, 0, 0, PER_DATA_SIZE, 0 );
                    lpAsynIoOperation->SetIoParams( 0, 10, 0 );
                    return m_spAsynTcpSocket->Read( lpAsynIoOperation );
                }
            }

            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    printf("recv, error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer(0, 0, &lpBuffer);
                    printf("recv[%4d] %s\n", lTransferedBytes, (char *)lpBuffer);

                    lpAsynIoOperation->SetIoParams(0, 10, 0);
                    return m_spAsynTcpSocket->Read(lpAsynIoOperation);
                }
            }
            if( lParam2 == Io_send )
            {
                if( lErrorCode )
                {
                    printf("send, error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    if( m_lSeqno > 20 ) return E_NOTIMPL;
                    unsigned char *lpBuffer;
                    lpAsynIoOperation->GetIoBuffer(0, 0, &lpBuffer);
                    sprintf((char *)lpBuffer, "%09d", m_lSeqno ++);
                    lpAsynIoOperation->SetIoParams(0, 10, 0);
                    return m_spAsynTcpSocket->Write(lpAsynIoOperation, 0);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Connect(const std::string &host, PORT port, uint32_t connect_timeout = 2000/*2sec*/)
    {
        CComPtr<IAsynTcpSocket> spAsynInnSocket;
        m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket );

        setting sets("config.txt");
        std::string proxyname = sets.get_string("proxy", "protocol", "none");
        if( proxyname != "http" &&
            proxyname != "socks" )
        {
            printf("can't support proxy: %s\n", proxyname.c_str());
            return false;
        }

        CComPtr<IAsynRawSocket> spAsynPtlSocket;
		m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("proxy"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(proxyname + "/" + sets.get_string("proxy", "version", "5.0")), &spAsynPtlSocket);
        if( spAsynPtlSocket == NULL )
        {
            printf("can't load plugin: proxy\n");
            return false;
        }

        CComPtr<IAsynProxySocket> spProxy;
        HRESULT r1 = spAsynPtlSocket->QueryInterface( IID_IAsynProxySocket, (void **)&spProxy);

        asynsdk::CKeyvalSetter    params(1);
		params.Set(STRING_from_string(";account"), 1, STRING_from_string(sets.get_string("proxy", "user") + ":" + sets.get_string("proxy", "password")));

		HRESULT hr = spProxy->SetProxyContext(STRING_from_string(sets.get_string("proxy", "host", "127.0.0.1")), sets.get_long("proxy", "port", 1080), asynsdk::STRING_EX::null, &params);
        if( proxyname == "http" )
        {
			CComPtr<IHttpTxTunnel> spDataTxTunnel; spProxy->QueryInterface(IID_IHttpTxTunnel, (void **)&spDataTxTunnel);
            spDataTxTunnel->SetEnabled(1); //强制直接代理
        }

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);

        printf("start to tcp.connect %s:%d\n", host.c_str(), port);
        spAsynPtlSocket->QueryInterface(IID_IAsynTcpSocket, (void **)&m_spAsynTcpSocket);
		m_spAsynTcpSocket->Open(m_spAsynFrameThread, m_af, SOCK_STREAM, IPPROTO_TCP);
        m_spAsynTcpSocket->Connect(STRING_from_string(host), port, 0, spAsynIoOperation, connect_timeout);
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
    HANDLE m_hNotify;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;
    CComPtr<IAsynTcpSocket  > m_spAsynTcpSocket;

    uint32_t m_af; //ipv4/ipv6/ipx
    uint32_t m_lSeqno;
};

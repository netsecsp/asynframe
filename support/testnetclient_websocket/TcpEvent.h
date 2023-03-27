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
#include "Tranfile.h"

class CTcpEvent : public asynsdk::asyn_message_events_impl
{
public:
    CTcpEvent(IAsynNetwork *lpAsynNetwork, IAsynFrameThread *lpAsynFrameThread)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        m_hNotify = CreateEvent(NULL, TRUE, FALSE, NULL);
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **objects )
    {
        if( lMessageId == AF_EVENT_NOTIFY )
        {
            SetEvent(m_hNotify);
            return E_NOTIMPL;
        }
        if( lMessageId == AF_IOMSG_NOTIFY )
        {
            IAsynIoOperation *lpAsynIoOperation = (IAsynIoOperation *)objects[0];
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
                    printf("connect succ\n");
                    return m_spAsynPtlSocket->SendPacket(STRING_from_string("GET"), STRING_from_string(m_uri), 0, lpAsynIoOperation);
                }
            }

            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    printf("recv error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    CComPtr<INetmsg> spRspmsg;
                    lpAsynIoOperation->GetCompletedObject(1, IID_INetmsg, (void **)&spRspmsg);
                    if( spRspmsg == NULL )
                    {
                        printf("recv, not found http ack\n");
                        SetEvent(m_hNotify);
                        return E_NOTIMPL;
                    }

                    STRING Status;
                    STRING Params;
                    spRspmsg->Getline(&Status, &Params, 0, 0 );
                    std::string status = string_from_STRING(Status);
                    std::string params = string_from_STRING(Params);
                    lErrorCode = atoi(status.c_str());
                    if( lErrorCode / 100 != 1 )
                    {
                        printf("%d %s\n", lErrorCode, params.c_str());
                        SetEvent(m_hNotify);
                        return E_NOTIMPL;
                    }
                    
                    lpAsynIoOperation->SetOpParams(AF_EVENT_NOTIFY, 0, 0); //通知结果
                    m_tranfile.reset(new CTranfile(m_spAsynFrameThread, lpAsynIoOperation, m_spAsynPtlSocket));
                    if( m_sendfile.empty())
                        m_tranfile->Recvfile();
                    else
                        m_tranfile->Sendfile(m_sendfile);
                    return S_OK;
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
                    lpAsynIoOperation->SetIoParam1(0); //recv http.ack
                    return m_spAsynPtlSocket->Read(lpAsynIoOperation);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Connect(const std::string &url, const char *sendfile)
    {// url格式， protocol://[user:password@]host[:port]/path/[;parameters][?query]#fragment
        m_sendfile = sendfile;

        std::string::size_type pos1 = url.find("://");
        if( pos1 == std::string::npos )
        {
            printf("fail to parse %s\n", url.c_str());
            return false;
        }
        std::string schema = url.substr(0, pos1);
        pos1 += 3/*skip "://" */;
        _strlwr_s((char *)schema.c_str(), schema.size() + 1);
        if( schema != "ws" && schema != "wss" )
        {
            printf("invalid schema: %s\n", url.c_str());
            return false;
        }

        std::string::size_type pos2 = url.find('/', pos1);

        std::string hostport, host;
        PORT port;

        if( pos2 == std::string::npos )
        {
            hostport = url.substr(pos1);
            m_uri = "/";
        }
        else
        {
            hostport = url.substr(pos1, pos2 - pos1);
            m_uri = url.substr(pos2);
        }

        std::string::size_type pos3 = hostport.find('@');
        if( pos3 == std::string::npos )
        {
            pos3 = 0;
        }
        else
        {
            pos3+= 1;
        }
 
        std::string::size_type pos4 = hostport.find(':', pos3);
        if( pos4 == std::string::npos )
        {
            host = hostport.substr(pos3);
            port = schema == "ws"? 80 : 443;
        }
        else
        {
            host = hostport.substr(pos3, pos4 - pos3);
            port = atoi(hostport.substr(pos4 + 1).c_str());
        }

        CComPtr<IAsynTcpSocket> spAsynInnSocket;
        m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket );

        CComPtr<IAsynRawSocket> spAsynPtlSocket;
        if( m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("websocket"), (IUnknown **)&spAsynInnSocket.p, STRING_from_string(schema == "ws"? "13" : "13:tls/1.0"), &spAsynPtlSocket) != S_OK )
        {
            printf("can't load plugin: websocket\n");
            return false;
        }
        else
        {
            spAsynPtlSocket->QueryInterface(IID_INet, (void **)&m_spAsynPtlSocket);
        }

        CComPtr<IAsynIoOperation> spAsynIoOperation;
        m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);

        CComPtr<IAsynTcpSocket> spAsynTcpSocket;
        spAsynPtlSocket->QueryInterface(IID_IAsynTcpSocket, (void **)&spAsynTcpSocket);

        spAsynTcpSocket->Open(m_spAsynFrameThread, AF_INET, SOCK_STREAM, IPPROTO_TCP);
        printf("start to tcp.connect %s:%d\n", host.c_str(), port);
        spAsynTcpSocket->Connect(STRING_from_string(host), port, 0, spAsynIoOperation, 2000);
        return true;
    }

    void Shutdown()
    {
        m_spAsynFrame->Shutdown();
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynNetwork> m_spAsynNetwork;
    HANDLE m_hNotify;
    CComPtr<INet> m_spAsynPtlSocket;
    
    std::unique_ptr<CTranfile> m_tranfile;
    std::string m_uri;
    std::string m_sendfile;
};

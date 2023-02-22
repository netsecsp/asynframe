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
#include "TcpEvent_http.h"
#include "TcpEvent_test.h"

class CTcpEvent
{
public:
    CTcpEvent(IAsynFrameThread *lpAsynFrameThread, IAsynFileSystem *lpAsynFileSystem, IAsynNetwork *lpAsynNetwork)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
        m_spAsynFileSystem  = lpAsynFileSystem;
    }

public:
    bool Start(PORT port)
    {
        CComPtr<IAsynTcpSocketListener> spAsynTcpSocketListener;
        m_spAsynNetwork->CreateAsynTcpSocketListener(0, &spAsynTcpSocketListener);

        spAsynTcpSocketListener->Open(m_spAsynFrameThread, AF_INET, SOCK_STREAM, IPPROTO_TCP);

        HRESULT r1 = spAsynTcpSocketListener->Bind(asynsdk::STRING_EX::null, port, TRUE, NULL);
        if( r1 != S_OK)
        {
            printf("bind *:%d, error: %d\n", port, r1);
            return false;
        }
        if( port == 0 ) spAsynTcpSocketListener->GetSockAddress(0, 0, &port, 0);
        printf("tcp.listen *:%d\n", port);

        if( m_spAsynNetwork->CreateAppService(STRING_from_string(IN_Dtp), (IUnknown**)&spAsynTcpSocketListener.p, STRING_from_string("rcvsize=1024&minsize=10"), 0, (IAppService**)&m_spDtp) != S_OK)
        {
            printf("fail to load plugin: %s\n", IN_Dtp);
            return false;
        }
 
        //注意：以下初始化隐含了查询优先级
        m_lpTcpEvent_http = new CTcpEvent_http(m_spAsynFrameThread, m_spAsynFileSystem, m_spAsynNetwork);
        m_lpTcpEvent_http->Start(m_spDtp);

        m_lpTcpEvent_test = new CTcpEvent_test(m_spAsynFrameThread, m_spAsynNetwork);
        m_lpTcpEvent_test->Start(m_spDtp);

        HRESULT r2 = m_spDtp->Control(1); //启动服务
        return true;
    }

    void Shutdown()
    {
        HRESULT r1 = m_spDtp->Control(0);
        m_lpTcpEvent_http->Shutdown();
        m_lpTcpEvent_test->Shutdown();
        delete m_lpTcpEvent_http;
        delete m_lpTcpEvent_test;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;
    CComPtr<IAsynFileSystem > m_spAsynFileSystem;

    CComPtr<IDtpService> m_spDtp;
    CTcpEvent_test *m_lpTcpEvent_test;
    CTcpEvent_http *m_lpTcpEvent_http;
};

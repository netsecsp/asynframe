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
#include "UdpEvent_test.h"

class CUdpEvent
{
public:
    CUdpEvent(IAsynFrameThread *lpAsynFrameThread, IAsynNetwork *lpAsynNetwork)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
    }

public:
    bool Start(PORT port)
    {
        CComPtr<IAsynUdpSocket> spAsynUdpSocket;
        m_spAsynNetwork->CreateAsynUdpSocket(&spAsynUdpSocket );
        spAsynUdpSocket->Open(m_spAsynFrameThread, AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        HRESULT r1 = spAsynUdpSocket->Bind(asynsdk::STRING_EX::null, port, TRUE, NULL);
        if( r1 != S_OK)
        {
            printf("bind *:%d, error: %d\n", port, r1);
            return false;
        }
        if( port == 0 ) spAsynUdpSocket->GetSockAddress(0, 0, &port, 0);
        printf("udp.listen *:%d\n", port);

        if( m_spAsynNetwork->CreateAppService(STRING_from_string(IN_Dtp), (IUnknown**)&spAsynUdpSocket.p, asynsdk::STRING_EX::null, 0, (IAppService**)&m_spDtp) != S_OK )
        {
            printf("fail to load plugin: %s\n", IN_Dtp);
            return false;
        }

        m_lpUdpEvent_test1 = new CUdpEvent_test('1', m_spAsynFrameThread, m_spAsynNetwork);
        m_lpUdpEvent_test1->Start(m_spDtp);

        m_lpUdpEvent_test2 = new CUdpEvent_test('2', m_spAsynFrameThread, m_spAsynNetwork);
        m_lpUdpEvent_test2->Start(m_spDtp);

        m_spDtp->Control(1); //Æô¶¯·þÎñ
        return true;
    }

    void Shutdown()
    {
        m_spDtp->Control(0);
        m_lpUdpEvent_test1->Shutdown();
        m_lpUdpEvent_test2->Shutdown();
        delete m_lpUdpEvent_test1;
        delete m_lpUdpEvent_test2;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;

    CComPtr<IDtpService> m_spDtp;

    CUdpEvent_test *m_lpUdpEvent_test1;
    CUdpEvent_test *m_lpUdpEvent_test2;
};

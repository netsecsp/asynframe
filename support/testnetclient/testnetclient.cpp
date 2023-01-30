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
#include "stdafx.h"
#include <conio.h>

#include <frame/AsynNetwork_internal.h>
#define AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IAsynNetwork_i.c>
#endif
#include <wsipx.h>	  //支持IPX/SPX
#include "TcpEvent.h"
#include "UdpEvent.h"

#ifdef  AAPIDLL_USING
#ifdef _DEBUG
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#else
#pragma comment(lib, "asynsdk_mini-MD.lib")
#endif
#pragma comment(lib,"asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif
STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IUnknown *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager *) GetInstancesManager();

int _tmain(int argc, _TCHAR *argv[])
{
    printf("usage: %s tcp/udp|spx/ipx ipv4/ipv6 host port\n\texample: %s tcp ipv4 192.168.1.101 7675\n\t\t %s tcp ipv6 2000::1:2345:6789:abcd 7675\n", argv[0], argv[0], argv[0]);
	if( argc <= 1 ) return 0;

    HRESULT hr1 = Initialize(NULL, NULL);

    do{
        InstancesManager *lpInstancesManager = GetInstancesManager();

        if( lpInstancesManager->Require(STRING_from_string(IN_AsynNetwork)) != S_OK )
        {
            printf("can't load plugin: %s\n", IN_AsynNetwork);
            break;
        }

        CComPtr<IAsynNetwork     > spAsynNetwork;
        lpInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

        CComPtr<IAsynFrameThread > spAsynFrameThread;
        lpInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (void **)&spAsynFrameThread);

        if( strcmp(argv[1], "tcp") == 0 )
        {
            CTcpEvent *pEvent = new CTcpEvent( spAsynFrameThread, spAsynNetwork, argc <= 2 || strcmp(argv[2], "ipv4") == 0 ? AF_INET : 23 );
            if( pEvent->Connect(argc > 3 ? argv[3] : "127.0.0.1", atoi(argc > 4 ? argv[4] : "7675")) )
            {
                while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                       _kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
        else if( strcmp(argv[1], "udp") == 0 )
        {
            CUdpEvent *pEvent = new CUdpEvent( spAsynFrameThread, spAsynNetwork, argc <= 2 || strcmp(argv[2], "ipv4") == 0 ? AF_INET : 23 );
            if( pEvent->Write(argc > 3 ? argv[3] : "127.0.0.1", atoi(argc > 4 ? argv[4] : "7675"), argc > 5 ? argv[5] : 0) )
            {
                while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                       _kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
        else if( strcmp(argv[1], "spx") == 0 )
        {
            CTcpEvent *pEvent = new CTcpEvent( spAsynFrameThread, spAsynNetwork, AF_IPX );
            if( pEvent->Connect(argc > 2 ? argv[2] : "10510028:0080A044880F", atoi(argc > 3 ? argv[3] : "7675")) )
            {
                while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                        _kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
        else if( strcmp(argv[1], "ipx") == 0 )
        {
            CUdpEvent *pEvent = new CUdpEvent( spAsynFrameThread, spAsynNetwork, AF_IPX );
            if( pEvent->Write(argc > 2 ? argv[2] : "10510028:0080A044880F", atoi(argc > 3 ? argv[3] : "7675")) )
            {
                while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                       _kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }		
    }while(0);

    HRESULT hr2 = Destory();
    return 0;
}

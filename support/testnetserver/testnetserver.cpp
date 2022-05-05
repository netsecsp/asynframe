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
#include "stdafx.h"
#include <conio.h>

#include <frame/AsynNetwork_internal.h>
#define AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IAsynNetwork_i.c>
#endif
#include <wsipx.h>    //Ö§³ÖIPX/SPX
#include "TcpEvent.h"
#include "UdpEvent.h"

#ifdef  AAPIDLL_USING
#pragma comment(lib,"asynsdk_mini-MDd.lib")
#pragma comment(lib,"asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif
STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IKeyvalSetter *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager *) GetInstancesManager();

int _tmain(int argc, _TCHAR *argv[])
{
    printf("usage: %s port tcp/udp|spx/ipx ipv4/ipv6\n\texample: %s 7675 tcp ipv4\n", argv[0], argv[0]);

    HRESULT hr1 = Initialize(NULL, NULL);

    {
        InstancesManager *lpInstancesManager = GetInstancesManager();

        lpInstancesManager->Verify(STRING_from_string(IN_AsynNetwork));

        CComPtr<IAsynNetwork     > spAsynNetwork;
        lpInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

        CComPtr<IAsynFrameThread > spAsynFrameThread;
        lpInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (void **)&spAsynFrameThread);

        if( argc <= 2 || strcmp(argv[2], "tcp") == 0 )
        {
            CTcpEvent *pEvent = new CTcpEvent( spAsynFrameThread, spAsynNetwork, argc <= 3 || strcmp(argv[3], "ipv4") == 0 ? AF_INET : 23 );
            if( pEvent->Start(argc <= 1? 7675 : atol(argv[1])) )
            {
                while( kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
        else if( strcmp(argv[2], "udp") == 0 )
        {
            CUdpEvent *pEvent = new CUdpEvent( spAsynFrameThread, spAsynNetwork, argc <= 3 || strcmp(argv[3], "ipv4") == 0 ? AF_INET : 23 );
            if( pEvent->Start(argc <= 1? 7675 : atol(argv[1]), argc > 4? argv[4] : 0) )
            {
                while( kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
        else if( strcmp(argv[2], "spx") == 0 )
        {
            CTcpEvent *pEvent = new CTcpEvent( spAsynFrameThread, spAsynNetwork, AF_IPX );
            if( pEvent->Start(argc <= 1? 7675 : atol(argv[1])) )
            {
                while( kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
        else if( strcmp(argv[2], "ipx") == 0 )
        {
            CUdpEvent *pEvent = new CUdpEvent( spAsynFrameThread, spAsynNetwork, AF_IPX );
            if( pEvent->Start(argc <= 1? 7675 : atol(argv[1])) )
            {
                while( kbhit() == 0 )
                {
                    Sleep(100);
                }
            }
            pEvent->Shutdown();
            delete pEvent;
        }
    }

    HRESULT hr2 = Destory();
    return 0;
}

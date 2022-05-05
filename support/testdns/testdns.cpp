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

#define AAPIDLL_USING

#include "AsynDnsHandler.h"
#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IAsynNetwork_i.c>
#endif

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
    printf("usage: %s host ipv4/ipv6 [dnsip]\n\texample: %s  www.baidu.com ipv4\n\t\t %s ipv6.baidu.com ipv6\n", argv[0], argv[0], argv[0]);
    const char *host = argc > 1 ? argv[1] : "www.baidu.com";
    const char *ipvx = argc > 2 ? argv[2] : "ipv4";
    const char *puri = argc > 3 ? argv[3] : "http://119.29.29.29/d?dn=[host].&ip=[ip]&ttl=1";
    //const char *puri = argc > 3 ? argv[3] : "udp://8.8.8.8:53";

    HRESULT hr1 = Initialize(NULL, NULL);

    {
        CComPtr<InstancesManager> spInstancesManager = GetInstancesManager();

        CComPtr<IAsynFrameThread> spAsynFrameThread;
        spInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (void **)&spAsynFrameThread);

        spInstancesManager->Verify(STRING_from_string(IN_AsynNetwork));

        CComPtr<IAsynNetwork     > spAsynNetwork;
        spInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

        CComPtr<IAsynDnsResolver> spAsynDnsResolver;
        spAsynNetwork->CreateAsynDnsResolver(STRING_from_string("dns"), 0, STRING_from_string(puri), 0, &spAsynDnsResolver);

        CAsynDnsHandler *pEvent = new CAsynDnsHandler(spAsynFrameThread, spAsynNetwork);
        if( pEvent->Start(spAsynDnsResolver, host, strcmp(ipvx, "ipv4") == 0 ? AF_INET : 23) )
        {
            while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                    kbhit() == 0 )
            {
                Sleep(100);
            }
        }
        pEvent->Shutdown();
        delete pEvent;
    }

    HRESULT hr2 = Destory();
    return 0;
}

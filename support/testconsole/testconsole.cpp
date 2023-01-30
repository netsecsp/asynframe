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

#include <frame/Console.h>
#define AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IConsole_i.c>
#endif

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
    asynsdk::CStringSetter fileconf(1, "config.ini");
    HRESULT hr1 = Initialize(NULL, &fileconf);

    do{
        InstancesManager *lpInstancesManager = GetInstancesManager();

        if( lpInstancesManager->Require(STRING_from_string(IN_Console)) != S_OK )
        {
            printf("can't load plugin: %s\n", IN_Console);
            break;
        }

        CComPtr<IConsole> console;
        lpInstancesManager->GetInstance(STRING_from_string(IN_Console), IID_IConsole, (void **)&console);

        class e : public asynsdk::asyn_message_events_base
        {
        public:
            e(IConsole *p)
              : console(p)
            {
            }
            STDMETHOD(OnMessage)( /*[in]*/uint32_t message, /*[in]*/uint64_t lparam1, /*[in]*/uint64_t lparam2, /*[in,out]*/IUnknown **objects )
            {
                if( message == AF_EVENT_NOTIFY &&
                    lparam2 )
                {
                    console->AllocWindow((IAsynFrameThread *)objects[0], asynsdk::STRING_EX::null, 3, 0);
                }
                return E_NOTIMPL;
            }

            CComPtr<IConsole> console;
        };

        asynsdk::DoMessageLoop(lpInstancesManager, 0, 0, &e(console));
    }while(0);

    HRESULT hr2 = Destory();
    return 0;
}

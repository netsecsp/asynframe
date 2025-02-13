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

#include <frame/AsynConsole.h>
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

class CGlobalEvents : public asynsdk::CAsynMessageEvents_base
{
public:
    CGlobalEvents()
      :  asynsdk::CAsynMessageEvents_base(1)
    {
    }

protected: //interface of CAsynMessageEvents_base
    STDMETHOD(OnMessage)( /*[in ]*/uint32_t message, /*[in ]*/uint64_t lparam1, /*[in ]*/uint64_t lparam2, /*[in,out]*/IUnknown** objects )
    {
        if( message == AF_EVENT_NOTIFY &&
            lparam1 == 0 )
        {
            printf("recv ctrl[%lld]\n", lparam2);
            return S_OK;
        }
        return E_NOTIMPL;
    }
};

class CThreadEvents : public asynsdk::CThreadMessageEvents_base
{
public:
    CThreadEvents( InstancesManager* lpInstancesManager )
      : asynsdk::CThreadMessageEvents_base(1)
    {
        lpInstancesManager->GetInstance(STRING_from_string(IN_Console), IID_IConsole, (IUnknown**)&console);
    }

protected: //interface of CThreadMessageEvents_base
    virtual void OnThreadEnter( /*[in ]*/IThread* thread )
    {
        console->AllocWindow((IAsynFrameThread*)thread, STRING_from_string("hello console"), ENABLE_INPUT_KEYBOARD|ENABLE_INPUT_MOUSE, 0);
    }

protected:
    CComPtr<IConsole> console;
};

int _tmain(int argc, _TCHAR *argv[])
{
    printf("console[single thread], load config.ini and load/unload IOsCommand object of cmd/lua/jvm/python/sqlite\n\n");

    CObjPtr<IKeyvalSetter> param2(new asynsdk::CKeyvalSetter());
    param2->Set(STRING_from_string(";appconf"), 1, STRING_from_string("config.ini"));
    param2->Set(STRING_from_string(";ospower"), 1, STRING_from_string("1"));
    CGlobalEvents e;
    HRESULT hr1 = Initialize(&e, param2); //load config.ini

    do{
        InstancesManager *lpInstancesManager = GetInstancesManager();

        if( CHECK_NO(lpInstancesManager->Require(STRING_from_string(IN_Console), 0)))
        {
            printf("can't load plugin: %s\n", IN_Console);
            break;
        }

        CThreadEvents t(lpInstancesManager);
        asynsdk::DoMessageLoop(lpInstancesManager, asynsdk::TC_Uapc, &t);
    }while(0);

    HRESULT hr2 = Destory();
    return 0;
}

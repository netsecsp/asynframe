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

#include <frame/AsynCore_internal.h>
#include <frame/asm/ICrashExplorer.h>
#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/ICrashExplorer_i.c>
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
    HRESULT hr1 = Initialize(NULL, NULL);
    {
        InstancesManager *lpInstancesManager = GetInstancesManager();

        if( argc <= 1 || atoi(argv[1]) == 0 )
        {
            char *p = 0;
            *p = 1;
        }
        else if( atoi(argv[1]) == 1 )
        {
            char *p = new char[10];
            delete p;
            delete p;
        }
        else if( atoi(argv[1]) == 2 )
        {// can't trap
            char *p = new char[10];
            memcpy(p, "12345678901234567890", 20);
        }
        else if( atoi(argv[1]) == 3 )
        {
            char *p = new char[10];
            delete p;
            p[0] = '1';
        }
        else 
        {
            int p = 8;
            int v = p/0;
        }
    }
    HRESULT hr2 = Destory();
    return 0;
}

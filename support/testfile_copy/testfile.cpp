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

#include <frame/AsynFile_internal.h>
#define AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IAsynFileSystem_i.c>
#endif
#include "FileEvent.h"

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
    printf("usage: %s srcfile dstfile\n\texample: %s src.dat dst.dat\n", argv[0], argv[0]);

    const char *srcfile = argc > 1 ? argv[1] : argv[0];
    const char *dstfile = argc > 2 ? argv[2] : "dst.dat";

    HRESULT hr1 = Initialize(NULL, NULL);

    do{
        InstancesManager *lpInstancesManager = GetInstancesManager();

        if( lpInstancesManager->Require(STRING_from_string(IN_AsynFileSystem)) != S_OK )
        {
            printf("can't load plugin: %s\n", IN_AsynFileSystem);
            break;
        }

        CComPtr<IAsynFileSystem > spAsynFileSystem;
        lpInstancesManager->GetInstance(STRING_from_string(IN_AsynFileSystem), IID_IAsynFileSystem, (IUnknown **)&spAsynFileSystem);

        CComPtr<IAsynFrameThread> spAsynFrameThread;
        lpInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (IUnknown **)&spAsynFrameThread);

        CFileEvent *pEvent = new CFileEvent( spAsynFrameThread, spAsynFileSystem );
        
        do{
        HRESULT r1 = pEvent->m_spSrcAsynFile->Open(spAsynFrameThread,
                     STRING_from_string(srcfile),
                     GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL);
        if( r1 != S_OK )
        {
            printf("open %s, error: %d\n", srcfile, r1);
            break;
        }

        HRESULT r2 = pEvent->m_spDstAsynFile->Open(spAsynFrameThread,
                     STRING_from_string(dstfile),
                     GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL);
        if( r2 != S_OK )
        {
            printf("open %s, error: %d\n", dstfile, r2);
            break;
        }

        CComPtr<IBuffer> spBuffer;
        lpInstancesManager->NewInstance(0, 0, IID_IBuffer, (IUnknown**)&spBuffer);
        if( pEvent->Copy(spBuffer) )
        {
            while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) && _kbhit() == 0 )
            {
                Sleep(100);
            }
        }
        }while(0);

        pEvent->Shutdown();
        delete pEvent;
    }while(0);

    HRESULT hr2 = Destory();
    return 0;
}

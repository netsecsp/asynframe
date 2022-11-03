/*****************************************************************************
Copyright (c) 2012 - 2032, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 05/05/2022
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
#include "AsynFrameHandler.h"
#define AAPIDLL_USING

#include <frame/log/Logger.h>
#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#endif

#ifdef  AAPIDLL_USING
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#pragma comment(lib, "asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif

STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IKeyvalSetter *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager *) GetInstancesManager();

LOGGER_IMPLEMENT(logger, "app", "ui");

static BYTE B2H( char ch )
{
    if( ch >= '0' && ch <= '9' )
    {
        return ch - '0';
    }

    if( ch >= 'A' && ch <= 'F' )
    {
        return ch - 'A' + 0xa;
    }

    if( ch >= 'a' && ch <= 'f' )
    {
        return ch - 'a' + 0xa;
    }
    else
    {
        return 0;
    }
}

int _tmain(int argc, _TCHAR *argv[])
{
    HRESULT hr1 = Initialize(NULL, NULL);

    {
        InstancesManager *lpInstancesManager = GetInstancesManager();

        #ifdef _LOG
        asynsdk::AsynLogger_Initialize(lpInstancesManager);
        #endif

        //自动加载asynfile/asynsock
        HRESULT r1 = lpInstancesManager->Require(STRING_from_string(IN_AsynFileSystem), 0);
        LOGGER_INFO(logger, "Require: name=" << IN_AsynFileSystem << (r1 == 0 ? " ok" : " no"));

        HRESULT r2 = lpInstancesManager->Require(STRING_from_string(IN_AsynNetwork), 0);
        LOGGER_INFO(logger, "Require: name=" << IN_AsynNetwork << (r2 == 0 ? " ok" : " no"));

        CComPtr<IAsynFrameThread> spAsynFrameThread;
#if 1
        CComPtr<IAsynFrameThreadFactory> spAsynFrameThreadFactory;
        lpInstancesManager->GetInstance(STRING_from_string(IN_AsynFrameThreadFactory), IID_IAsynFrameThreadFactory, (void **)&spAsynFrameThreadFactory);
        spAsynFrameThreadFactory->CreateAsynFrameThread(0, 0, 0, 0, &spAsynFrameThread);
#else
        lpInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (void **)&spAsynFrameThread);
#endif

        CComPtr<IThreadPool  > spThreadpool;
        CComPtr<IOsCommand   > spCommand;
        CComPtr<IDataTransmit> spDataTransmit;

        CAsynFrameHandler *pEvent = new CAsynFrameHandler(lpInstancesManager, spAsynFrameThread);
        if( argc == 1 || strcmp(argv[1], "timer") == 0 )
        {
            uint32_t elapse = argc < 3 ? 1000 : atol(argv[2]);
            LOGGER_INFO(logger, "Create Timer: " << elapse);
            pEvent->m_spOsTime->GetTickcount(&pEvent->s);
            pEvent->m_spAsynFrame->CreateTimer(1, 2, elapse, TRUE);
            
            while( kbhit() == 0 )
            {
                Sleep(100);
            }
        }
        else if( strcmp(argv[1], "ops") == 0 )
        {
            if( argc <=2 || atoi(argv[2]) == 0 )
            {
                printf("Post %d\n", AF_EVENT_APPID1);
                pEvent->m_spAsynFrame->PostMessage(0, AF_EVENT_APPID1, 1, 0, NULL); //异步消息
                printf("Post ok\n");
            }
            else
            {
                printf("Send %d\n", AF_EVENT_APPID1);
                pEvent->m_spAsynFrame->SendMessage(AF_EVENT_APPID1, 1, 0, NULL); //同步消息
                printf("Send ok\n");
            }
            
            while( kbhit() == 0 )
            {
                Sleep(100);
            }
        }
        else if( strcmp(argv[1], "zipfile") == 0 )
        {
            asynsdk::CStringSetter name(1, argc > 2 ? argv[2] : "1.zip");
            spDataTransmit.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "zip", &name, 0, 0));

            BYTE tmp[1024]; 
            FILE *f1 = fopen(".\\1.txt", "rb");
            if( f1 )
            {
                asynsdk::CStringSetter v(1, ".\\scripts\\1.txt");
                spDataTransmit->Write(&v, "1.txt:comments=1:password=123456", 0);
                
                int l = fread(tmp, 1, 1024, f1);
                spDataTransmit->Write(0, tmp, l);
                fclose(f1);
            }
            FILE *f2 = fopen(".\\2.txt", "rb");
            if( f2 )
            {
                asynsdk::CStringSetter v(1, ".\\scripts\\2.txt");
                spDataTransmit->Write(&v, "2\\2.txt", 0);

                int l = fread(tmp, 1, 1024, f2);
                spDataTransmit->Write(0, tmp, l);
                fclose(f2);
            }
        }
        else if( strcmp(argv[1], "zipencoder") == 0 )
        {
            asynsdk::CStringSetter name(1, argc > 2 ? argv[2] : "e.zip");
            CComPtr<IDataTransmit> target;
            target.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "file", &name, 0, 0));

            spDataTransmit.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "zip", target, 0, 0/*encoder*/));

            spDataTransmit->Write(0, "1234567890", 10);
            spDataTransmit->Write(0, "aaaaaaaaaa", 10);
            spDataTransmit->Write(0, 0, 0); //1F8B080000000000000A33343236313533B7B03448840300E77A6FFA14000000
        }
        else if( strcmp(argv[1], "zipdecoder") == 0 )
        {
            asynsdk::CStringSetter name(1, argc > 2 ? argv[2] : "d.txt");
            CComPtr<IDataTransmit> target;
            target.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "file", &name, 0, 0));

            spDataTransmit.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "zip", target, 0, 1/*decoder*/));
            char *hex = "1F8B080000000000000A33343236313533B7B03448840300E77A6FFA14000000";
            BYTE b[1024];
            int n = 0;
            for(int i = 0; i < strlen(hex); i += 2, n ++)
            {
                b[n] = (B2H(hex[i + 0]) << 4) + B2H(hex[i + 1]);
            }
            spDataTransmit->Write(0, b, n);
            spDataTransmit->Write(0, 0, 0);
        }
        else if( strcmp(argv[1], "sqlite") == 0 )
        {
            asynsdk::CStringSetter name(1, argc > 2 ? argv[2] : "test.db");
            spCommand.Attach(asynsdk::CreateCommand(lpInstancesManager, "sqlite", 0, &name, 0));

            spCommand->Execute(0, STRING_from_string("CREATE TABLE IF NOT EXISTS coreinfo(iseq INTEGER PRIMARY KEY AUTOINCREMENT, info TEXT, vals int);"), 0, 0, 0, 0);

            spCommand->Execute(0, STRING_from_string("insert into coreinfo(info, vals) values('show', 1);"), 0, 0, 0, 0);

            spCommand->Execute(0, STRING_from_string("insert into coreinfo(info, vals) values('show', 2);"), 0, 0, 0, 0);

            spCommand->Execute(0, STRING_from_string("select * from coreinfo;"), 0, 0, 0, pEvent->GetAsynMessageEvents());
        }
        else
        {
            CComPtr<IAsynIoOperation> spAsynIoOperation;
            pEvent->m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
            spAsynIoOperation->SetOpParams(AF_EVENT_APPID1, 0, 1/*for print extcode*/);

            lpInstancesManager->NewInstance(0, 2/*eventthreadpool*/, IID_IThreadPool, (void **)&spThreadpool);
            spCommand.Attach(asynsdk::CreateCommand(lpInstancesManager, "cmd", spThreadpool, 0, 0));
            spCommand->Execute(0, STRING_from_string(argv[1]), 0, 0, 0, spAsynIoOperation);
            
            while( kbhit() == 0 )
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

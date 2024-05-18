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
#include "AsynFrameHandler.h"
#include <time.h>

BEGIN_ASYN_MESSAGE_MAP(CAsynFrameHandler)
ON_APPID_NOTIFY(OnAppidNotify, IAsynIoOperation, AF_EVENT_APPID1)
ON_EVENT_NOTIFY(OnEventNotify, IUnknown)
ON_TIMER(OnTimer)
END_ASYN_MESSAGE_MAP()

HRESULT CAsynFrameHandler::OnAppidNotify(uint32_t message, uint64_t lParam1, uint64_t lParam2, IAsynIoOperation *lpAsynIoOperation)
{
    if( lParam2 == 0 )
    {
        printf("switch1: %I64d/%I64d threadid: %d\n", lParam1, lParam2, ::GetCurrentThreadId());
    }
    if( lParam2 == 1 )
    {
        uint32_t lErrorCode; lpAsynIoOperation->GetCompletedResult(&lErrorCode, 0, 0 );
        printf("extcode: %d\n", lErrorCode);
    }
    if( lParam2 == 2 )
    {
        ShowTime("sleep2 b");
        m_spAsynFrame->Sleep(1000 * 5); //5sec
        ShowTime("sleep2 a");
    }
    return E_NOTIMPL;
}

HRESULT CAsynFrameHandler::OnEventNotify(uint64_t lParam1, uint64_t lParam2, IUnknown *object)
{
    STRING *vals = (STRING *)lParam2;
    if( lParam1 == 0 )
    {
        printf("record");
        for(int i = 0; ; ++i)
        {
            if(!vals[i].ptr ) break;
            printf("\t%s", (char *)vals[i].ptr);
        }
        printf("\n");
    }
    else
    {
        if(!vals )
        {
            printf("%6I64d records\n", lParam1);
        }
        else
        {
            printf("%6I64d", lParam1);
            for(int i = 0; ; ++i)
            {
                if(!vals[i].ptr ) break;
                printf("\t%s", (char *)vals[i].ptr);
            }
            printf("\n");
        }
    }
    return S_OK;
}

void CAsynFrameHandler::ShowTime(const char *info)
{
    SYSTEMTIME t; GetLocalTime(&t );
    printf("%02d-%02d %02d:%02d:%02d.%03d %s\n", t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds, info? info : "");
}

HRESULT CAsynFrameHandler::OnTimer( uint64_t lParam1, uint64_t lParam2 )
{
    ShowTime();
    return S_OK;
}
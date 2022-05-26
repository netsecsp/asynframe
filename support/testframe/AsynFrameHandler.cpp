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
        printf("switch1, params: %I64d/%I64d threadid: %d\n", lParam1, lParam2, ::GetCurrentThreadId());
    else
        printf("extcode=%I64d\n", lParam1);
    return E_NOTIMPL;
}

void CAsynFrameHandler::OnEventNotify(uint64_t lParam1, uint64_t lParam2, IUnknown *object)
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
}

HRESULT CAsynFrameHandler::OnTimer( uint64_t lParam1, uint64_t lParam2 )
{
    uint64_t e;
    m_spOsTime->GetTickcount(&e);

    struct tm tm, *p = &tm;
    SYSTEMTIME wtm;
    GetLocalTime(&wtm);
    tm.tm_year  = wtm.wYear - 1900;
    tm.tm_mon   = wtm.wMonth - 1;
    tm.tm_mday  = wtm.wDay;
    tm.tm_hour  = wtm.wHour;
    tm.tm_min   = wtm.wMinute;
    tm.tm_sec   = wtm.wSecond;
    tm.tm_isdst = -1;
    struct timeval v;
    v.tv_sec  = mktime(&tm);
    v.tv_usec = wtm.wMilliseconds * 1000;

    printf("%02d-%02d %02d:%02d:%02d.%03d diff=%.03fms\n", 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, (int)(v.tv_usec / 1000), (e - s) / 1000.0);
    s = e;
	return S_OK;
}
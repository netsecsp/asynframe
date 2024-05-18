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
#include "AsynDnsHandler.h"
#include <conio.h>

BEGIN_ASYN_MESSAGE_MAP(CAsynDnsHandler)
ON_IOMSG_NOTIFY(OnIomsgNotify)
END_ASYN_MESSAGE_MAP()

HRESULT CAsynDnsHandler::OnIomsgNotify( uint64_t lParam1, uint64_t lAction, IAsynIoOperation *lpAsynIoOperation )
{
    uint32_t lErrorCode = NO_ERROR;
    lpAsynIoOperation->GetCompletedResult(&lErrorCode, 0, 0 );

    switch(lAction)
    {
    case Io_hostdns:
    {
        if( lErrorCode != NO_ERROR )   // ����ʧ��
        {
            printf("dns, error: %d\n", lErrorCode);
            break;
        }

        CComPtr<IStringStack> spDnsResult;
        HRESULT r = lpAsynIoOperation->GetCompletedObject( TRUE, IID_IStringStack, (IUnknown **)&spDnsResult );
        for(int i = 0; ; i ++)
        {
            asynsdk::CStringSetter addr(1); if( spDnsResult->Pop(&addr) != S_OK ) break;
            printf("[%d]: %s\n", i, addr.m_val.c_str());
        }
        break;
    }
    }

    SetEvent(m_hNotify);
    return E_NOTIMPL;
}

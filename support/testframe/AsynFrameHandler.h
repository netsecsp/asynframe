#ifndef __AsynFrameHandler_H__
#define __AsynFrameHandler_H__
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
#include <frame/AsynCore_internal.h>
#include <frame/AsynFile_internal.h>
#include <frame/AsynNetwork_internal.h>

class CAsynFrameHandler : public asynsdk::asyn_message_events_impl
{
public:
    CAsynFrameHandler(InstancesManager *lpInstancesManager, IAsynFrameThread *lpAsynFrameThread)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        lpInstancesManager->GetInstance(STRING_from_string(IN_SysTime), IID_IOsTime, (void **)&m_spOsTime);
    }

public: // interface of asyn_message_events_impl
    DECLARE_ASYN_MESSAGE_MAP(CAsynFrameHandler)
	HRESULT OnTimer(uint64_t lParam1, uint64_t lParam2);
    HRESULT OnAppidNotify(uint32_t message, uint64_t lParam1, uint64_t lParam2, IAsynIoOperation *lpAsynIoOperation);
    void    OnEventNotify(uint64_t lParam1, uint64_t lParam2, IUnknown *object);
public:
    void Shutdown()
    {
        Stop(m_spAsynFrame);
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IOsTime         > m_spOsTime;
    uint64_t s;
};

#endif
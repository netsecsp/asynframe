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
#pragma once

#define PER_DATA_SIZE	32768

class CFileEvent : public asynsdk::asyn_message_events_impl
{
public:
    CFileEvent(IAsynFrameThread *lpAsynFrameThread, IAsynFileSystem *lpAsynFileSystems)
    {
        m_spAsynFileSystems = lpAsynFileSystems;
        m_spAsynFrameThread = lpAsynFrameThread;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        m_hNotify = CreateEvent(NULL, TRUE, FALSE, NULL);
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **ppAsynIoOperation)
    {
        if( lMessageId == AF_EVENT_NOTIFY )
        {
            if( m_spAsynIoBridge != (IAsynIoBridge *)lParam1 ) return S_OK;

            if( lParam2 != NO_ERROR )
            {
                ((IAsynIoOperation *)*ppAsynIoOperation)->GetOpParams(0, 0, &lParam1);
                if( lParam1 == Io_recv )
                {
                    if( lParam2 == AE_RESET )
                        printf("copy completed\n");
                    else
                        printf("occur error: %I64d while read from file\n", lParam2);
                }
                else
                {
                    printf("occur error: %I64d while write to file\n", lParam2);
                }
            }
            SetEvent(m_hNotify);
            return S_OK;
        }
        if( lMessageId == AF_QUERY_RESULT )
        {
            if( m_spAsynIoBridge != (IAsynIoBridge *)lParam1 ) return S_OK;

            printf("Transmit: %I64d\n", lParam2);
            return S_OK; //继续写
        }

        printf("lMsg: %d, param: %I64d/%I64d\n", lMessageId, lParam1, lParam2);
        return E_NOTIMPL;
    }

public:
    bool Copy(IAsynFile *lpSrcAsynFile, IAsynFile *lpDstAsynFile, uint32_t max_sendspeed = -1)
    {
        CComPtr<IObjectHolder> spObjectHolder; //设置全局写文件速度B/s
        m_spAsynFileSystems->QueryInterface(IID_IObjectHolder, (void **)&spObjectHolder);
        HRESULT r1 = spObjectHolder->Get(DT_GetSendSpeedController, 0, IID_ISpeedController, (void **)&m_spSpeedController);
        m_spSpeedController->SetMaxSpeed(max_sendspeed);

        m_spAsynFrameThread->CreateAsynIoBridge(lpSrcAsynFile, lpDstAsynFile, 0, &m_spAsynIoBridge);
        m_spAsynIoBridge->Invoke(0, GetAsynMessageEvents());
        return true;
    }

    void Shutdown()
    {
        Stop(m_spAsynFrame);
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynFileSystem > m_spAsynFileSystems;
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    HANDLE m_hNotify;

    CComPtr<ISpeedController> m_spSpeedController;

    CComPtr<IAsynIoBridge   > m_spAsynIoBridge;
};

#include "souistd.h"
#include "core/SMsgLoop.h"
#include "core/frame_Api.h"

namespace SOUI
{


    void SMessageLoop::OnMsg(LPMSG pMsg)
    {
        if(!PreTranslateMessage(pMsg))
        {
            ::TranslateMessage(pMsg);
            ::DispatchMessage(pMsg);
        }
    }

	void SMessageLoop::Quit()
	{
		if (!m_bRunning) return;
		m_bQuit = TRUE;
	}

    #if  0
    int SMessageLoop::Run()
    {
        BOOL bDoIdle = TRUE;
        int nIdleCount = 0;
        BOOL bRet;
        
        m_bRunning = TRUE;
		m_bQuit = FALSE;
        for(;;)
        {
            while(bDoIdle && !::PeekMessage(&m_msg, NULL, 0, 0, PM_NOREMOVE))
            {
                if(!OnIdle(nIdleCount++))
                    bDoIdle = FALSE;
				if (m_bQuit) goto exit_loop;
            }

            bRet = ::GetMessage(&m_msg, NULL, 0, 0);

            if(bRet == -1)
            {
				SLOGFMTD(_T("::GetMessage returned -1 (error)"));
                continue;   // error, don't process
            }
            else if(!bRet)
            {
				SLOGFMTD(_T("SMessageLoop::Run - exiting,code = %d"),(int)m_msg.wParam);
                break;   // WM_QUIT, exit message loop
            }
            
            OnMsg(&m_msg);

            if(IsIdleMessage(&m_msg))
            {
                bDoIdle = TRUE;
                nIdleCount = 0;
            }
			if (m_bQuit) break;
        }

	exit_loop:
        m_bRunning = FALSE;
        
        return (int)m_msg.wParam;
    }
    #else
    int SMessageLoop::Run()
    {
        class frame_CWindowMessageEvents : public asynsdk::CThreadMessageEvents_base
        {
        public:
            frame_CWindowMessageEvents(SMessageLoop *loop)
              : asynsdk::CThreadMessageEvents_base(1), m_loop(loop)
            {
            }

        protected: //interface of frame_CWindowMessageEvents
            STDMETHOD(OnMessage)( /*[in ]*/uint32_t message, /*[in ]*/uint64_t lparam1, /*[in ]*/uint64_t lparam2, /*[in, out]*/IUnknown** object)
            {
                if( message == AF_QUERY_RESULT )
                {
                    return m_loop->PreTranslateMessage((MSG*)lparam2)? S_FALSE : S_OK;
                }
                return asynsdk::CThreadMessageEvents_base::OnMessage(message, lparam1, lparam2, object);
            }
            
            SMessageLoop *m_loop;
        };
        
        frame_CWindowMessageEvents e(this);
        CComPtr<IThreadMessagePump> spThreadMessagePump;
        spThreadMessagePump.Attach(asynsdk::CreateThreadMessagePump(frame_GetInstancesManager(), 1/*window*/, asynsdk::TC_Auto, &e, NULL));

        // for tracking the idle time state
        LONG lIdleCount = 0;

        // acquire and dispatch messages until a WM_QUIT message is received.
        for(;;)
        {
            HRESULT ret = spThreadMessagePump->WaitMessage(NULL, 5000/*5ms*/);
            if( ret == E_ABORT )
            {
                break;
            }

            if( ret == S_OK    )
            {
                spThreadMessagePump->PumpMessage(NULL);
                lIdleCount = 0;
            }
            else
            {
                // call OnIdle while in bIdle state
                OnIdle(lIdleCount ++);
            }
        }

        spThreadMessagePump = 0;
        return 0;
    }
    #endif

    BOOL SMessageLoop::OnIdle( int /*nIdleCount*/ )
    {
        for(size_t i = 0; i < m_aIdleHandler.GetCount(); i++)
        {
            IIdleHandler* pIdleHandler = m_aIdleHandler[i];
            if(pIdleHandler != NULL)
                pIdleHandler->OnIdle();
        }
        return FALSE;   // don't continue
    }

    BOOL SMessageLoop::PreTranslateMessage( MSG* pMsg )
    {
        // loop backwards
        for(int i = (int)m_aMsgFilter.GetCount() - 1; i >= 0; i--)
        {
            IMessageFilter* pMessageFilter = m_aMsgFilter[i];
            if(pMessageFilter != NULL && pMessageFilter->PreTranslateMessage(pMsg))
                return TRUE;
        }
        return FALSE;   // not translated
    }

    BOOL SMessageLoop::IsIdleMessage( MSG* pMsg )
    {
        // These messages should NOT cause idle processing
        switch(pMsg->message)
        {
        case WM_MOUSEMOVE:
        case WM_NCMOUSEMOVE:
        case WM_PAINT:
        case WM_SYSTIMER:	// WM_SYSTIMER (caret blink)
            return FALSE;
        }

        return TRUE;
    }

    BOOL SMessageLoop::RemoveIdleHandler( IIdleHandler* pIdleHandler )
    {
        return RemoveElementFromArray(m_aIdleHandler,pIdleHandler);
    }

    BOOL SMessageLoop::AddIdleHandler( IIdleHandler* pIdleHandler )
    {
        m_aIdleHandler.Add(pIdleHandler);
		return TRUE;
    }

    BOOL SMessageLoop::RemoveMessageFilter( IMessageFilter* pMessageFilter )
    {
        return RemoveElementFromArray(m_aMsgFilter,pMessageFilter);
    }

    BOOL SMessageLoop::AddMessageFilter( IMessageFilter* pMessageFilter )
    {
        m_aMsgFilter.Add(pMessageFilter);
		return TRUE;
    }


}//end of namespace SOUI

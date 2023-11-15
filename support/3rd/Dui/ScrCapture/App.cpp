// App.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ScrCaptureWnd.h"
#include "..\DuiLib\Core\frame_Api.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;

    HRESULT hr1 = frame_Initialize(NULL, NULL); //frame init

    CScrCaptureWnd* pFrame = CScrCaptureWnd::Instance();
    if( pFrame == NULL ) return 0;
    pFrame->Create(NULL, _T(""), WS_VISIBLE | WS_POPUP, /*WS_EX_TOOLWINDOW|WS_EX_TOPMOST*/0);
	pFrame->ShowWindow(true);
    
    CPaintManagerUI::MessageLoop_frame(); //frame loop
    //CPaintManagerUI::MessageLoop();

    HRESULT hr2 = frame_Destory(); //frame uninit

    ::CoUninitialize();
    return 0;
}

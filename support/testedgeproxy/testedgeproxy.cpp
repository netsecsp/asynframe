// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string>
#include <tchar.h>


#define AAPIDLL_USING

#include <frame/AsynWebView.h>
#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IChromeWebView_i.c>
#endif

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

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

static CComPtr<IChromeWebView> g_webview;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
        _T("WebView sample"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1200, 900,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if(!hWnd )
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

    HRESULT hr1 = Initialize(NULL, NULL);

    do{
        InstancesManager *lpInstancesManager = GetInstancesManager();

        //require edgeproxy
        if( CHECK_NO(lpInstancesManager->Require(STRING_from_string(IN_WebView "/edgeproxy"), 0)))
        {
            printf("can't load plugin: %s\n", "edgeproxy");
            break;
        }

        //acquire g_webview
        asynsdk::CStringSetter uri(1, "https://www.baidu.com");
        if( asynsdk::CreateObject(lpInstancesManager, IN_WebView "/edgeproxy", &uri, (uint64_t)hWnd, IID_IChromeWebView, (IUnknown**)&g_webview) != S_OK )
        {
            break;
        }

        //acquire IThreadMessagePump
        CObjPtr<IThreadMessagePump> spThreadMessagePump;
        lpInstancesManager->NewInstance(0, 2/*TC_Windows*/, IID_IThreadMessagePump, (IUnknown**)&spThreadMessagePump.p);

    	// The parameters to ShowWindow explained:
    	// hWnd: the value returned from CreateWindow
    	// nCmdShow: the fourth parameter from WinMain
    	ShowWindow(hWnd, nCmdShow);
    	UpdateWindow(hWnd);

        // Main message loop
        do{
        HRESULT ret = spThreadMessagePump->WaitMessage(0, INFINITE*1000ULL, 0);
        if( ret == E_ABORT ) break;
        if( ret != S_FALSE )
        {
            spThreadMessagePump->PumpMessage(0);
        }
        }while(1);

        g_webview = 0;
    }while(0);

    Destory();
    return 0;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_SIZE:
         if( g_webview ) g_webview->SetViewSize(LOWORD(lParam), HIWORD(lParam));
         break;
    case WM_DESTROY:
         PostQuitMessage(0);
         break;
    default:
         return DefWindowProc(hWnd, message, wParam, lParam);
         break;
    }
    return 0;
}

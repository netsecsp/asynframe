// testsvc.cpp : 定义服务程序的入口点。
//
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define SVCNAME   _T("Test-SvcName")
#define EVENTID   10086

#pragma comment(lib, "advapi32.lib") //for service api

////////////////////////////////////////////////////////////////////////////////////////////////////
#include <frame/AsynCore.h>

#define AAPIDLL_USING 1
#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#endif

#ifdef  AAPIDLL_USING
#ifdef _DEBUG
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#else
#pragma comment(lib, "asynsdk_mini-MD.lib")
#endif
#pragma comment(lib, "asyncore_dll.lib")
#else
#pragma comment(lib, "asynframe-MT_lib.lib")
#endif
STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IUnknown *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager*) GetInstancesManager();

LOGGER_IMPLEMENT(logger, "app", "CService");
////////////////////////////////////////////////////////////////////////////////////////////////////
class CService : 
        public asynsdk::CThreadMessageEvents_base
{
public:
    CService(DWORD dwServiceType = SERVICE_WIN32_OWN_PROCESS)
      : asynsdk::CThreadMessageEvents_base(1)
    {
        memset(&m_status, 0, sizeof(m_status));
        m_status.dwServiceType = dwServiceType;
    }

public:
    static void WINAPI Entry(DWORD dwArgc, LPTSTR* lpszArgv)
    {// Service Entry
        CService mySvc;
        mySvc.m_handle = RegisterServiceCtrlHandlerEx(SVCNAME, CService::CtrlHandler, &mySvc);
        if( mySvc.m_handle == NULL )
        {
            printf("RegisterServiceCtrlHandler failed (%d)\n", (int)GetLastError());
            return;
        }

        mySvc.ReportSvcStatus(SERVICE_START_PENDING, NO_ERROR, 1000); // Report initial status to the SCM

        HRESULT r = Initialize(0, 0);
        asynsdk::DoMessageLoop(GetInstancesManager(), 0, asynsdk::TC_Auto, &mySvc); //will fire OnThreadEnter events
        Destory();

        mySvc.ReportSvcStatus(SERVICE_STOPPED, NO_ERROR);
    }

    static DWORD WINAPI CtrlHandler(DWORD inControl, DWORD inEventType, LPVOID inEventData, LPVOID Context)
    {// Service Handle the requested control code. 
        switch(inControl)
        {
            case SERVICE_CONTROL_STOP:
            case SERVICE_CONTROL_SHUTDOWN:
                 LOGGER_INFO(logger, "do Shutdown, Control=" << inControl);
                 ((CService*)Context)->Shutdown(); //Signal the service to stop.
                 break;

            case SERVICE_CONTROL_POWEREVENT:
                 if( inEventType == PBT_APMSUSPEND       )
                 {
                     LOGGER_INFO(logger, "do PowerEvent, EventType=" << inEventType);
                 }
                 if( inEventType == PBT_APMRESUMESUSPEND )
                 {
                     LOGGER_INFO(logger, "do PowerEvent, EventType=" << inEventType);
                 }
                 break;

            default:
                 break;
        }
        return NO_ERROR;
    }

    void ReportSvcStatus(DWORD dwCurrentState, DWORD dwWin32ExitCode, DWORD dwWaitHint = 0)
    {
        static DWORD dwCheckPoint = 1;

        // Fill in the SERVICE_STATUS structure.
        m_status.dwCurrentState = dwCurrentState;
        m_status.dwWin32ExitCode = dwWin32ExitCode;
        m_status.dwWaitHint = dwWaitHint;

        if( dwCurrentState == SERVICE_START_PENDING)
        {
            m_status.dwControlsAccepted = 0;
        }
        else 
        {
            m_status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
        }

        if( dwCurrentState == SERVICE_RUNNING || dwCurrentState == SERVICE_STOPPED )
        {
            m_status.dwCheckPoint = 0;
        }
        else
        {
            m_status.dwCheckPoint = dwCheckPoint ++;
        }

        SetServiceStatus(m_handle, &m_status); // Report the status of the service to the SCM.
    }

    void ReportSvcEvents(LPTSTR szFunction)
    {
        LPCTSTR lpszStrings[2];
        TCHAR   cBuffer[80];
     
        HANDLE hEventSource = RegisterEventSource(NULL, SVCNAME);
        if( hEventSource != NULL )
        {
            StringCchPrintf(cBuffer, 80, TEXT("%s failed with %d"), szFunction, (int)GetLastError());

            lpszStrings[0] = SVCNAME;
            lpszStrings[1] = cBuffer;

            ReportEvent(hEventSource,        // event log handle
                        EVENTLOG_ERROR_TYPE, // event type
                        0,                   // event category
                        EVENTID,             // event identifier
                        NULL,                // no security identifier
                        2,                   // size of lpszStrings array
                        0,                   // no binary data
                        lpszStrings,         // array of strings
                        NULL);               // no binary data
     
            DeregisterEventSource(hEventSource);
        }
    }

    void Shutdown()
    {
        ReportSvcStatus(SERVICE_STOP_PENDING, NO_ERROR);
        m_thread = 0; //notify thread exit and will fire OnThreadLeave events
    }

protected: //interface of CThreadMessageEvents_base
    virtual void OnThreadEnter( /*[in ]*/IThread* t )
    {
        ReportSvcStatus(SERVICE_RUNNING, NO_ERROR); // Report running status when initialization is complete. 
        m_thread = t;
    }

    virtual void OnThreadLeave( void )
    {
        ReportSvcStatus(m_status.dwCurrentState, NO_ERROR);
    }

protected:
    SERVICE_STATUS_HANDLE m_handle;
    SERVICE_STATUS        m_status;
    CComPtr<IThread> m_thread; //Used to notify thread quit
};

////////////////////////////////////////////////////////////////////////////////////////////////////
void SvcDoInstall()
{
    TCHAR szUnquotedPath[MAX_PATH];
    if(!GetModuleFileName(NULL, szUnquotedPath, MAX_PATH))
    {
        printf("Cannot install service (%d)\n", (int)GetLastError());
        return;
    }
 
    // In case the path contains a space, it must be quoted so that
    // it is correctly interpreted. For example,
    // "d:\my share\testsvc.exe" should be specified as ""d:\my share\testsvc.exe""
    TCHAR szPath[MAX_PATH];
    StringCbPrintf(szPath, MAX_PATH, TEXT("\"%s\""), szUnquotedPath);
 
    // Get a handle to the SCM database. 
    SC_HANDLE schManager = OpenSCManager(
                                NULL,                    // local computer
                                NULL,                    // ServicesActive database 
                                SC_MANAGER_ALL_ACCESS);  // full access rights 
    if( schManager == NULL )
    {
        printf("OpenSCManager failed (%d)\n", (int)GetLastError());
        return;
    }
 
    do{
    // Create the service
    SC_HANDLE schService = CreateService(
                                schManager,              // SCM database 
                                SVCNAME,                   // name of service 
                                _T("Test"),                // service name to display 
                                SERVICE_ALL_ACCESS,        // desired access 
                                SERVICE_WIN32_OWN_PROCESS, // service type 
                                SERVICE_DEMAND_START,      // start type 
                                SERVICE_ERROR_NORMAL,      // error control type 
                                szPath,                    // path to service's binary 
                                NULL,                      // no load ordering group 
                                NULL,                      // no tag identifier 
                                NULL,                      // no dependencies 
                                NULL,                      // LocalSystem account 
                                NULL);                     // no password 
    if( schService == NULL )
    {
        printf("CreateService failed (%d)\n", (int)GetLastError());
        break;
    }
    else
    {
        printf("Service installed successfully\n");
    }

    CloseServiceHandle(schService);
    }while(0);

    CloseServiceHandle(schManager);
}
 
void SvcUnInstall()
{ 
    // Get a handle to the SCM database. 
    SC_HANDLE schManager = OpenSCManager(
                                NULL,                    // local computer
                                NULL,                    // ServicesActive database 
                                SC_MANAGER_ALL_ACCESS);  // full access rights 
    if( schManager == NULL )
    {
        printf("OpenSCManager failed (%d)\n", (int)GetLastError());
        return;
    }
 
    do{
    // Get a handle to the service.
    SC_HANDLE schService = OpenService(
                                schManager,       // SCM database 
                                SVCNAME,            // name of service 
                                DELETE);            // need delete access 
    if( schService == NULL )
    {
        printf("OpenService failed (%d)\n", (int)GetLastError());
        break;
    }
 
    // Delete the service.
    if(!DeleteService(schService))
    {
        printf("DeleteService failed (%d)\n", (int)GetLastError());
    }
    else
    {
        printf("Service deleted successfully\n");
    }

    CloseServiceHandle(schService);
    }while(0);

    CloseServiceHandle(schManager);
}

int _tmain(int argc, _TCHAR* argv[])
{// https://learn.microsoft.com/en-us/windows/win32/services/svc-cpp
    if( argc > 1 )
    {
        if( lstrcmpi(argv[1], TEXT("install"  )) == 0 )
        {
            SvcDoInstall();
            return 0;
        }
        if( lstrcmpi(argv[1], TEXT("uninstall")) == 0 )
        {
            SvcUnInstall();
            return 0;
        }
    }

    // Add additional services for the process to this table.
    SERVICE_TABLE_ENTRY DispatchTable[] =
    {
        { SVCNAME, (LPSERVICE_MAIN_FUNCTION)CService::Entry },
        { NULL, NULL }
    };

    // This call returns when the service has stopped. 
    // The process should simply terminate when the call returns.
    if(!StartServiceCtrlDispatcher(DispatchTable))
    {// 首先要注册服务，然后必须用sc命令或者windows服务器管理器去启动程序。手动启动或者vs调试都将会失败, 返回1063
        printf("StartServiceCtrlDispatcher failed (%d)\n", (int)GetLastError());
    }

    printf("exit.\n");
    return 0;
}
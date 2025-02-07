
// testnetclient.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "testnetclient.h"
#include "MainFrm.h"

#include "testnetclientDoc.h"
#include "testnetclientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define AAPIDLL_USING

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
#pragma comment(lib,"asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif
STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IUnknown *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager *) GetInstancesManager();

// CtestnetclientApp

BEGIN_MESSAGE_MAP(CtestnetclientApp, CWinAppEx)
    ON_COMMAND(ID_APP_ABOUT, &CtestnetclientApp::OnAppAbout)
    // �����ļ��ı�׼�ĵ�����
    ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CtestnetclientApp ����

CtestnetclientApp::CtestnetclientApp()
{
    m_bHiColorIcons = TRUE;

    // ֧����������������
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
    // ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
    //     1) �����д˸������ã�������������������֧�ֲ�������������
    //     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
    System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

    // TODO:  ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
    //Ϊ CompanyName.ProductName.SubProduct.VersionInformation
    SetAppID(_T("testnetclient.AppID.NoVersion"));

    // TODO:  �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CtestnetclientApp ����

CtestnetclientApp theApp;

// CtestnetclientApp ��ʼ��

BOOL CtestnetclientApp::InitInstance()
{
    // ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
    // ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
    //����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
    // �����ؼ��ࡣ
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinAppEx::InitInstance();

    Initialize(NULL, NULL); //Initialize asynframe

    EnableTaskbarInteraction(FALSE);

    // ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()
    // AfxInitRichEdit2();

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO:  Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯��
    SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
    LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


    InitContextMenuManager();

    InitKeyboardManager();

    InitTooltipManager();
    CMFCToolTipInfo ttParams;
    ttParams.m_bVislManagerTheme = TRUE;
    theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
            RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

    // ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
    // �������ĵ�����ܴ��ں���ͼ֮�������
    CSingleDocTemplate *pDocTemplate;
    pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(CtestnetclientDoc),
        RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
        RUNTIME_CLASS(CtestnetclientView));
    if (!pDocTemplate)
        return FALSE;
    AddDocTemplate(pDocTemplate);


    // ������׼ shell ���DDE�����ļ�������������
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);



    // ��������������ָ�������  ���
    // �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
    if (!ProcessShellCommand(cmdInfo))
        return FALSE;

    // Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}

int  CtestnetclientApp::Run()
{
    //return CWinAppEx::Run();
    ASSERT_VALID(this);

    CComPtr<IThreadMessagePump> spThreadMessagePump;
    spThreadMessagePump.Attach(asynsdk::CreateThreadMessagePump(GetInstancesManager(), asynsdk::TC_Windows, NULL, NULL));

    // for tracking the idle time state
    LONG lIdleCount = 0;

    // acquire and dispatch messages until a WM_QUIT message is received.
    for(;;)
    {
        HRESULT ret = spThreadMessagePump->WaitMessage(NULL, 5000/*5ms*/, NULL);
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
    return ExitInstance();
}

int  CtestnetclientApp::ExitInstance()
{
    Destory(); //destory asynframe

    return CWinApp::ExitInstance();
}

// CtestnetclientApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // �Ի�������
    enum { IDD = IDD_ABOUTBOX };

protected:
    virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV ֧��

    // ʵ��
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CtestnetclientApp::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}

// CtestnetclientApp �Զ������/���淽��

void CtestnetclientApp::PreLoadState()
{
    BOOL bNameValid;
    CString strName;
    bNameValid = strName.LoadString(IDS_EDIT_MENU);
    ASSERT(bNameValid);
    GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
    bNameValid = strName.LoadString(IDS_EXPLORER);
    ASSERT(bNameValid);
    GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CtestnetclientApp::LoadCustomState()
{
}

void CtestnetclientApp::SaveCustomState()
{
}

// CtestnetclientApp ��Ϣ�������




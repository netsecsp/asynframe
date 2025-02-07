
// testnetclient.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "testnetclient.h"
#include "testnetclientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IAsynNetwork_i.c>
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

// CtestnetclientApp

BEGIN_MESSAGE_MAP(CtestnetclientApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtestnetclientApp ����

CtestnetclientApp::CtestnetclientApp()
{
    // ֧����������������
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

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

    CWinApp::InitInstance();

    Initialize(NULL, NULL); //Initialize asynframe
    GetInstancesManager()->Require(STRING_from_string(IN_AsynNetwork), 0);

    AfxEnableControlContainer();

    // ���� shell ���������Է��Ի������
    // �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
    CShellManager *pShellManager = new CShellManager;

    // ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO:  Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯��
    SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

    CtestnetclientDlg dlg;

    m_pMainWnd = &dlg;
    m_spThreadMessagePump.Attach(dlg.CreateThreadMessagePump(GetInstancesManager()));

    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO:  �ڴ˷��ô����ʱ��
        //  ��ȷ�������رնԻ���Ĵ���
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO:  �ڴ˷��ô����ʱ��
        //  ��ȡ�������رնԻ���Ĵ���
    }
    else if (nResponse == -1)
    {
        TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
        TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
    }

    // ɾ�����洴���� shell ��������
    if (pShellManager != NULL)
    {
        delete pShellManager;
    }

    // ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
    //  ����������Ӧ�ó������Ϣ�á�
    return FALSE;
}

BOOL CtestnetclientApp::PumpMessage()
{
    //return CWinApp::PumpMessage();

    if( m_spThreadMessagePump->WaitMessage(NULL, INFINITE * 1000LL, NULL) == S_OK )
    {// ������Դ�����ֵ=E_ABORT/S_FALSE
        m_spThreadMessagePump->PumpMessage(NULL);
    }
    return TRUE;
}

int  CtestnetclientApp::ExitInstance()
{
    m_spThreadMessagePump = 0;
    Destory(); //destory asynframe

    return CWinApp::ExitInstance();
}




// testnetclient.h : testnetclient Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

#include <frame/AsynCore.h>

// CtestnetclientApp:
// �йش����ʵ�֣������ testnetclient.cpp
//

class CtestnetclientApp : public CWinApp
{
public:
    CtestnetclientApp();

    // ��д
public:
    virtual BOOL InitInstance();
    virtual BOOL PumpMessage();     // low level message pump
    virtual int  ExitInstance();

    // ʵ��
    CComPtr<IThreadMessagePump> m_spThreadMessagePump;

    DECLARE_MESSAGE_MAP()
};

STDAPI_(extern InstancesManager *) GetInstancesManager();
extern CtestnetclientApp theApp;
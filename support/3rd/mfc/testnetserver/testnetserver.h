
// testnetserver.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include <frame/AsynCore.h>

// CtestnetserverApp:
// �йش����ʵ�֣������ testnetserver.cpp
//

class CtestnetserverApp : public CWinApp
{
public:
    CtestnetserverApp();

    // ��д
public:
    virtual BOOL InitInstance();
    virtual BOOL PumpMessage();     // low level message pump
    virtual int  ExitInstance();

    // ʵ��
    CComPtr<IThreadMessagePump> m_spThreadMessagePump; //frame pump

    DECLARE_MESSAGE_MAP()
};

STDAPI_(extern InstancesManager *) GetInstancesManager();
extern CtestnetserverApp theApp;

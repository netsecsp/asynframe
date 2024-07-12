
// testnetserver.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#include <frame/AsynCore.h>

// CtestnetserverApp:
// 有关此类的实现，请参阅 testnetserver.cpp
//

class CtestnetserverApp : public CWinApp
{
public:
    CtestnetserverApp();

    // 重写
public:
    virtual BOOL InitInstance();
    virtual BOOL PumpMessage();     // low level message pump
    virtual int  ExitInstance();

    // 实现
    CComPtr<IThreadMessagePump> m_spThreadMessagePump; //frame pump

    DECLARE_MESSAGE_MAP()
};

STDAPI_(extern InstancesManager *) GetInstancesManager();
extern CtestnetserverApp theApp;

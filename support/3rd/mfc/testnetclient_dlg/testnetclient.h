
// testnetclient.h : testnetclient 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号

#include <frame/AsynCore_internal.h>

// CtestnetclientApp:
// 有关此类的实现，请参阅 testnetclient.cpp
//

class CtestnetclientApp : public CWinApp
{
public:
    CtestnetclientApp();

    // 重写
public:
    virtual BOOL InitInstance();
    virtual BOOL PumpMessage();     // low level message pump
    virtual int  ExitInstance();

    // 实现
    CComPtr<IThreadMessagePump> m_spThreadMessagePump;

    DECLARE_MESSAGE_MAP()
};

STDAPI_(extern InstancesManager *) GetInstancesManager();
extern CtestnetclientApp theApp;
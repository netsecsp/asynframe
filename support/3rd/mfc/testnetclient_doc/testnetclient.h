
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

class CtestnetclientApp : public CWinAppEx
{
public:
	CtestnetclientApp();

// ��д
public:
	virtual BOOL InitInstance();
    virtual int Run();
	virtual int  ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtestnetclientApp theApp;

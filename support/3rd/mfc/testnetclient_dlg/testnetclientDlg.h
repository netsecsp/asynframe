
// testnetclientDlg.h : 头文件
//

#pragma once

#include <frame/AsynNetwork_internal.h>

// CtestnetclientDlg 对话框
class CtestnetclientDlg : public CDialogEx, public asynsdk::asyn_message_events_base
{
    // 构造
public:
    CtestnetclientDlg(CWnd *pParent = NULL);	// 标准构造函数

    // 对话框数据
    enum { IDD = IDD_TESTNETCLIENT_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV 支持

    // 重写
    virtual BOOL ContinueModal();
    virtual void EndModalLoop(int nResult);

protected: //interface of asynsdk::asyn_message_events_base
    STDMETHOD(OnMessage)( /*[in]*/uint32_t message, /*[in]*/uint64_t lparam1, /*[in]*/uint64_t lparam2, /*[in,out]*/IUnknown **objects )
    {
        if( message == AF_EVENT_NOTIFY &&
                lparam2 != 0 )
        {
            m_spAsynFrameThread = (IAsynFrameThread *)objects[0];
        }
        return E_NOTIMPL;
    }

    // 实现
protected:
    HICON m_hIcon;
    CComPtr<IAsynFrameThread> m_spAsynFrameThread; //当前线程对应的IAsynFrameThread对象

    // 生成的消息映射函数
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
};

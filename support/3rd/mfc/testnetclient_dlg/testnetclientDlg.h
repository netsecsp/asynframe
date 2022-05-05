
// testnetclientDlg.h : ͷ�ļ�
//

#pragma once

#include <frame/AsynNetwork_internal.h>

// CtestnetclientDlg �Ի���
class CtestnetclientDlg : public CDialogEx, public asynsdk::asyn_message_events_base
{
    // ����
public:
    CtestnetclientDlg(CWnd *pParent = NULL);	// ��׼���캯��

    // �Ի�������
    enum { IDD = IDD_TESTNETCLIENT_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV ֧��

    // ��д
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

    // ʵ��
protected:
    HICON m_hIcon;
    CComPtr<IAsynFrameThread> m_spAsynFrameThread; //��ǰ�̶߳�Ӧ��IAsynFrameThread����

    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
};

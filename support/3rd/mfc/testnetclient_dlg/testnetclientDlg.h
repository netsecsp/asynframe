
// testnetclientDlg.h : ͷ�ļ�
//

#pragma once

#include <frame/AsynNetwork.h>

// CtestnetclientDlg �Ի���
class CtestnetclientDlg : public CDialogEx
{
    // ����
public:
    CtestnetclientDlg(CWnd *pParent = NULL);	// ��׼���캯��

    // �Ի�������
    enum { IDD = IDD_TESTNETCLIENT_DIALOG };

    IThreadMessagePump *CreateThreadMessagePump(InstancesManager *lpInstancesManager)
    {
        return asynsdk::CreateThreadMessagePump(lpInstancesManager, asynsdk::TC_Windows, 0, (IAsynFrameThread**)&m_spAsynFrameThread);
    }

protected:
    virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV ֧��

    // ��д
    virtual BOOL ContinueModal();
    virtual void EndModalLoop(int nResult);

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

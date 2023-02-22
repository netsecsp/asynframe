
// testnetserverDlg.h : ͷ�ļ�
//

#pragma once

#include <frame/AsynNetwork_internal.h>
#include "UdpEvent.h"

// CtestnetserverDlg �Ի���
class CtestnetserverDlg : public CDialogEx, public asynsdk::asyn_message_events_base
{
    // ����
public:
    CtestnetserverDlg(CWnd *pParent = NULL);	// ��׼���캯��

    // �Ի�������
    enum { IDD = IDD_TESTNETSERVER_DIALOG };

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
            CComPtr<IAsynNetwork> spAsynNetwork;
            GetInstancesManager()->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

            m_pEvent = new CUdpEvent((IAsynFrameThread *)objects[0], spAsynNetwork, AF_INET);
            m_pEvent->Start(7675);
        }
        return E_NOTIMPL;
    }

    // ʵ��
protected:
    HICON m_hIcon;

    CUdpEvent *m_pEvent; //frame udp

    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
};

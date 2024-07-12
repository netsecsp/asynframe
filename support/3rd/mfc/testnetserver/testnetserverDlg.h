
// testnetserverDlg.h : ͷ�ļ�
//

#pragma once

#include <frame/AsynNetwork.h>
#include "UdpEvent.h"

// CtestnetserverDlg �Ի���
class CtestnetserverDlg : public CDialogEx, 
                          public asynsdk::asyn_message_events_impl
{
    // ����
public:
    CtestnetserverDlg(CWnd *pParent = NULL);	// ��׼���캯��

    // �Ի�������
    enum { IDD = IDD_TESTNETSERVER_DIALOG };

    IThreadMessagePump *CreateThreadMessagePump(InstancesManager *lpInstancesManager)
    {
        return asynsdk::CreateThreadMessagePump(lpInstancesManager, 1, asynsdk::TC_Auto, asynsdk::asyn_message_events_impl::GetAsynMessageEvents(), (IAsynFrameThread**)&m_spAsynFrameThread);
    }

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
            GetInstancesManager()->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (IUnknown **)&spAsynNetwork);

            m_pEvent = new CUdpEvent(m_spAsynFrameThread, spAsynNetwork, AF_INET);
            m_pEvent->Start(7675);
        }
        return E_NOTIMPL;
    }

    // ʵ��
protected:
    HICON m_hIcon;

    CComPtr<IAsynFrameThread> m_spAsynFrameThread; //��ǰ�̶߳�Ӧ��IAsynFrameThread����
    CUdpEvent *m_pEvent; //frame udp

    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
};

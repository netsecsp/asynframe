
// testnetclientView.h : CtestnetclientView ��Ľӿ�
//

#pragma once


class CtestnetclientView : public CView
{
protected: // �������л�����
    CtestnetclientView();
    DECLARE_DYNCREATE(CtestnetclientView)

    // ����
public:
    CtestnetclientDoc *GetDocument() const;

    // ����
public:

    // ��д
public:
    virtual void OnDraw(CDC *pDC);  // ��д�Ի��Ƹ���ͼ
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);
protected:

    // ʵ��
public:
    virtual ~CtestnetclientView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext &dc) const;
#endif

protected:

    // ���ɵ���Ϣӳ�亯��
protected:
    afx_msg void OnFilePrintPreview();
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnContextMenu(CWnd *pWnd, CPoint point);
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // testnetclientView.cpp �еĵ��԰汾
inline CtestnetclientDoc *CtestnetclientView::GetDocument() const
{
    return reinterpret_cast<CtestnetclientDoc *>(m_pDocument);
}
#endif


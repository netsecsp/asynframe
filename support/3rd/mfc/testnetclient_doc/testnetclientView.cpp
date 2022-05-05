
// testnetclientView.cpp : CtestnetclientView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "testnetclient.h"
#endif

#include "testnetclientDoc.h"
#include "testnetclientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestnetclientView

IMPLEMENT_DYNCREATE(CtestnetclientView, CView)

BEGIN_MESSAGE_MAP(CtestnetclientView, CView)
    ON_WM_CONTEXTMENU()
    ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CtestnetclientView ����/����

CtestnetclientView::CtestnetclientView()
{
    // TODO:  �ڴ˴���ӹ������

}

CtestnetclientView::~CtestnetclientView()
{
}

BOOL CtestnetclientView::PreCreateWindow(CREATESTRUCT &cs)
{
    // TODO:  �ڴ˴�ͨ���޸�
    //  CREATESTRUCT cs ���޸Ĵ��������ʽ

    return CView::PreCreateWindow(cs);
}

// CtestnetclientView ����

void CtestnetclientView::OnDraw(CDC * /*pDC*/)
{
    CtestnetclientDoc *pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CtestnetclientView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
    ClientToScreen(&point);
    OnContextMenu(this, point);
}

void CtestnetclientView::OnContextMenu(CWnd * /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
    theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CtestnetclientView ���

#ifdef _DEBUG
void CtestnetclientView::AssertValid() const
{
    CView::AssertValid();
}

void CtestnetclientView::Dump(CDumpContext &dc) const
{
    CView::Dump(dc);
}

CtestnetclientDoc *CtestnetclientView::GetDocument() const // �ǵ��԰汾��������
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestnetclientDoc)));
    return (CtestnetclientDoc *)m_pDocument;
}
#endif //_DEBUG


// CtestnetclientView ��Ϣ�������


// testnetclientView.cpp : CtestnetclientView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CtestnetclientView 构造/析构

CtestnetclientView::CtestnetclientView()
{
    // TODO:  在此处添加构造代码

}

CtestnetclientView::~CtestnetclientView()
{
}

BOOL CtestnetclientView::PreCreateWindow(CREATESTRUCT &cs)
{
    // TODO:  在此处通过修改
    //  CREATESTRUCT cs 来修改窗口类或样式

    return CView::PreCreateWindow(cs);
}

// CtestnetclientView 绘制

void CtestnetclientView::OnDraw(CDC * /*pDC*/)
{
    CtestnetclientDoc *pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO:  在此处为本机数据添加绘制代码
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


// CtestnetclientView 诊断

#ifdef _DEBUG
void CtestnetclientView::AssertValid() const
{
    CView::AssertValid();
}

void CtestnetclientView::Dump(CDumpContext &dc) const
{
    CView::Dump(dc);
}

CtestnetclientDoc *CtestnetclientView::GetDocument() const // 非调试版本是内联的
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestnetclientDoc)));
    return (CtestnetclientDoc *)m_pDocument;
}
#endif //_DEBUG


// CtestnetclientView 消息处理程序

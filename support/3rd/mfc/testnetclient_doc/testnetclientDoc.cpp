
// testnetclientDoc.cpp : CtestnetclientDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "testnetclient.h"
#endif

#include "testnetclientDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtestnetclientDoc

IMPLEMENT_DYNCREATE(CtestnetclientDoc, CDocument)

BEGIN_MESSAGE_MAP(CtestnetclientDoc, CDocument)
END_MESSAGE_MAP()


// CtestnetclientDoc ����/����

CtestnetclientDoc::CtestnetclientDoc()
{
    // TODO:  �ڴ����һ���Թ������

}

CtestnetclientDoc::~CtestnetclientDoc()
{
}

BOOL CtestnetclientDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO:  �ڴ�������³�ʼ������
    // (SDI �ĵ������ø��ĵ�)

    return TRUE;
}




// CtestnetclientDoc ���л�

void CtestnetclientDoc::Serialize(CArchive &ar)
{
    if (ar.IsStoring())
    {
        // TODO:  �ڴ���Ӵ洢����
    }
    else
    {
        // TODO:  �ڴ���Ӽ��ش���
    }
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CtestnetclientDoc::OnDrawThumbnail(CDC &dc, LPRECT lprcBounds)
{
    // �޸Ĵ˴����Ի����ĵ�����
    dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

    CString strText = _T("TODO: implement thumbnail drawing here");
    LOGFONT lf;

    CFont *pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
    pDefaultGUIFont->GetLogFont(&lf);
    lf.lfHeight = 36;

    CFont fontDraw;
    fontDraw.CreateFontIndirect(&lf);

    CFont *pOldFont = dc.SelectObject(&fontDraw);
    dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
    dc.SelectObject(pOldFont);
}

// ������������֧��
void CtestnetclientDoc::InitializeSearchContent()
{
    CString strSearchContent;
    // ���ĵ����������������ݡ�
    // ���ݲ���Ӧ�ɡ�;���ָ�

    // ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
    SetSearchContent(strSearchContent);
}

void CtestnetclientDoc::SetSearchContent(const CString &value)
{
    if (value.IsEmpty())
    {
        RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
    }
    else
    {
        CMFCFilterChunkValueImpl *pChunk = NULL;
        ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
        if (pChunk != NULL)
        {
            pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
            SetChunkValue(pChunk);
        }
    }
}

#endif // SHARED_HANDLERS

// CtestnetclientDoc ���

#ifdef _DEBUG
void CtestnetclientDoc::AssertValid() const
{
    CDocument::AssertValid();
}

void CtestnetclientDoc::Dump(CDumpContext &dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG


// CtestnetclientDoc ����

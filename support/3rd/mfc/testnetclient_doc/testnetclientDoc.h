
// testnetclientDoc.h : CtestnetclientDoc ��Ľӿ�
//


#pragma once

class CtestnetclientDoc : public CDocument
{
protected: // �������л�����
    CtestnetclientDoc();
    DECLARE_DYNCREATE(CtestnetclientDoc)

    // ����
public:

    // ����
public:

    // ��д
public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive &ar);
#ifdef SHARED_HANDLERS
    virtual void InitializeSearchContent();
    virtual void OnDrawThumbnail(CDC &dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

    // ʵ��
public:
    virtual ~CtestnetclientDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext &dc) const;
#endif

    // ���ɵ���Ϣӳ�亯��
protected:
    DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
    // ����Ϊ����������������������ݵ� Helper ����
    void SetSearchContent(const CString &value);
#endif // SHARED_HANDLERS
};

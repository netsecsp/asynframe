// StringSetter.h: Definition of the CStringSetter/CObjectSetter/CStringSetterRef class
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STRINGSETTER_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
#define AFX_STRINGSETTER_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 05/01/2022
http://asynframe.sf.net

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the
above copyright notice, this list of conditions
and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
NAMESPACE_BEGIN(asynsdk)

//////////////////////////////////////////////////////////////////////////////
class CStringSetter :
        public IStringSetter,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CStringSetter(uint32_t dwRef = 0, const char *val = "")
      : CSingleThreadModelObject(dwRef), m_val(val)
    {
    }
    CStringSetter(const std::string &val)
      : CSingleThreadModelObject(1), m_val(val)
    {
    }
    virtual ~CStringSetter() { }

//  DECLARE_NOT_AGGREGATABLE(CStringSetter)
//  BEGIN_COM_MAP(CStringSetter)
//      COM_INTERFACE_ENTRY(CStringSetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CStringSetter)
    OBJ_INTERFACE_ENTRY(IStringSetter)
    END_OBJ_MAP()

public: //interface of IStringSetter
    STDMETHOD(Get)( /*[out]*/STRING *buf )
    {
        buf->ptr = (unsigned char *)(m_val.empty()? "" : m_val.c_str());
        buf->len = m_val.size();
        return buf->len ? S_OK : S_FALSE;
    }
    STDMETHOD(Set)( /*[in ]*/STRING  buf )
    {
        Set(buf.ptr, buf.len); //若buf.len=0, 则需要m_val.clear()
        return S_OK;
    }

public:
    CStringSetter *Set(const void *val, uint32_t len);
    CStringSetter *Set(const char *val)
    {
        return Set(val, strlen(val));
    }
    CStringSetter *Clear()
    {
        m_val.clear();
        return this;
    }

public:
    std::string  m_val;
};

class CObjectSetter :
        public IStringSetter,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CObjectSetter(uint32_t dwRef = 0, IUnknown *o = 0)
      : CSingleThreadModelObject(dwRef), object(o)
    {
    }
    CObjectSetter(IUnknown *o)
      : CSingleThreadModelObject(1), object(o)
    {
    }
    virtual ~CObjectSetter()
    {
        if( object ) object->Release();
    }

//  DECLARE_NOT_AGGREGATABLE(CObjectSetter)
//  BEGIN_COM_MAP(CObjectSetter)
//      COM_INTERFACE_ENTRY(CObjectSetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CObjectSetter)
    OBJ_INTERFACE_ENTRY(IStringSetter)
    END_OBJ_MAP()

public: //interface of IStringSetter
    STDMETHOD(Get)( /*[out]*/STRING *buf );
    STDMETHOD(Set)( /*[in ]*/STRING  buf );

public:
    CObjectSetter *Set(const void *val, uint32_t len);
    CObjectSetter *Clear()
    {
        {// clear
            buffer = "";
        }
        if( object )
        {
            object->Release();
            object = 0;
        }
        return this;
    }

public:
    std::string buffer;
    IUnknown   *object;
};

class CMemorySetter :
        public IStringSetter,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CMemorySetter(uint32_t dwRef = 0, const void *val = "", uint32_t len = 0)
      : CSingleThreadModelObject(dwRef)
    {
        m_val.ptr = (unsigned char*)val;
        m_val.len = len;
    }
    CMemorySetter(const void *val, uint32_t len = sizeof(void*))
      : CSingleThreadModelObject(1)
    {
        m_val.ptr = (unsigned char*)val;
        m_val.len = len;
    }
    virtual ~CMemorySetter() { }

//  DECLARE_NOT_AGGREGATABLE(CMemorySetter) 
//  BEGIN_COM_MAP(CMemorySetter)
//      COM_INTERFACE_ENTRY(CMemorySetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CMemorySetter)
    OBJ_INTERFACE_ENTRY(IStringSetter)
    END_OBJ_MAP()

public: //interface of IStringSetter
    STDMETHOD(Get)( /*[out]*/STRING *buf )
    {
        buf->ptr = m_val.ptr;
        buf->len = m_val.len;
        return buf->len ? S_OK : S_FALSE;
    }
    STDMETHOD(Set)( /*[in ]*/STRING  buf )
    {
        m_val = buf;
        return S_OK;
    }

public:
    CMemorySetter *Set(const void *val, uint32_t len)
    {
        STRING_EX::Set(m_val, val, len);
        return this;
    }

public:
    STRING m_val;
};

class CStringSetterRef :
        public IStringSetter,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CStringSetterRef(uint32_t dwRef = 0, std::string *v = 0)
      : CSingleThreadModelObject(dwRef), m_val(v)
    {
    }
    CStringSetterRef(std::string *v)
      : CSingleThreadModelObject(1), m_val(v)
    {
    }
    virtual ~CStringSetterRef() { }

//  DECLARE_NOT_AGGREGATABLE(CStringSetterRef) 
//  BEGIN_COM_MAP(CStringSetterRef)
//      COM_INTERFACE_ENTRY(CStringSetterRef)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CStringSetterRef)
    OBJ_INTERFACE_ENTRY(IStringSetter)
    END_OBJ_MAP()

public: //interface of IStringSetter
    STDMETHOD(Get)( /*[out]*/STRING *buf )
    {
        buf->ptr = (unsigned char *)(m_val->empty() ? "" : m_val->c_str());
        buf->len = m_val->size();
        return buf->len ? S_OK : S_FALSE;
    }
    STDMETHOD(Set)( /*[in ]*/STRING  buf )
    {
        Set(buf.ptr, buf.len); //若buf.len=0, 则需要m_val->clear()
        return S_OK;
    }

public:
    CStringSetterRef *Set(const void  *val, uint32_t len);
    CStringSetterRef *Set(std::string *val)
    {
        m_val = val;
        return this;
    }
    CStringSetterRef *Clear()
    {
        m_val->clear();
        return this;
    }

public:
    std::string *m_val; //ref
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_STRINGSETTER_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
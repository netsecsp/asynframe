// StringsStack.h: interface for the CStringsStack class.
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STRINGSSTACK_H__8D72F57C_CA8F_4812_BEE1_342F9810C19F__INCLUDED_)
#define AFX_STRINGSSTACK_H__8D72F57C_CA8F_4812_BEE1_342F9810C19F__INCLUDED_
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
#include <list>
NAMESPACE_BEGIN(asynsdk)

typedef std::list<std::string> t_lstips;

//////////////////////////////////////////////////////////////////////
class CStringsStack :
        public IStringsStack,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CStringsStack(uint32_t dwRef = 0)
      : CSingleThreadModelObject(dwRef)
    {
    }
    virtual ~CStringsStack() { }

//  DECLARE_NOT_AGGREGATABLE(CStringsStack) 
//  BEGIN_COM_MAP(CStringsStack)
//      COM_INTERFACE_ENTRY(IStringsStack)
//      COM_INTERFACE_ENTRY(IStringSetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CStringsStack)
        OBJ_INTERFACE_ENTRY(IStringsStack)
        OBJ_INTERFACE_ENTRY(IStringSetter)
    END_OBJ_MAP()

public: //interface of IStringSetter
    STDMETHOD(Get)( /*[out]*/STRING *Val );
    STDMETHOD(Set)( /*[in ]*/STRING  Val );

public: //interface of IStringsStack
    STDMETHOD(Pop)( /*[out]*/IStringSetter *Val );
    STDMETHOD(Add)( /*[in ]*/STRING  Val );

public:
    CStringsStack *Set(t_lstips &vals, bool bDoCopy = true)
    {
        if( bDoCopy )
        {
            for(t_lstips::iterator it = vals.begin(); it != vals.end(); ++ it)
            {
                m_vals.emplace_back(it->c_str());
            }
        }
        else
        {
            m_vals.swap(vals);
        }
        return this;
    }
    CStringsStack *Set(const std::string &val)
    {
        m_vals.emplace_back(val);
        return this;
    }

public:
    t_lstips  m_vals;
};

class CStringsStackRef :
        public IStringsStack,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CStringsStackRef(uint32_t dwRef = 0, t_lstips *vals = 0)
      : CSingleThreadModelObject(dwRef), m_vals(vals)
    {
    }
    virtual ~CStringsStackRef() { }

//  DECLARE_NOT_AGGREGATABLE(CStringsStackRef)
//  BEGIN_COM_MAP(CStringsStackRef)
//      COM_INTERFACE_ENTRY(IStringsStack)
//      COM_INTERFACE_ENTRY(IStringSetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CStringsStackRef)
        OBJ_INTERFACE_ENTRY(IStringsStack)
        OBJ_INTERFACE_ENTRY(IStringSetter)
    END_OBJ_MAP()

public: //interface of IStringSetter
    STDMETHOD(Get)( /*[out]*/STRING *Val );
    STDMETHOD(Set)( /*[in ]*/STRING  Val );

public: //interface of IStringsStack
    STDMETHOD(Pop)( /*[out]*/IStringSetter *Val );
    STDMETHOD(Add)( /*[in ]*/STRING  Val );

public:
    t_lstips *m_vals;
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_STRINGSSTACK_H__8D72F57C_CA8F_4812_BEE1_342F9810C19F__INCLUDED_)
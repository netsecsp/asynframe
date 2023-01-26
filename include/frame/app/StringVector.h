// StringVector.h: interface for the CStringVector class.
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STRINGVECTOR_H__8D72F57C_CA8F_4812_BEE1_342F9810C19F__INCLUDED_)
#define AFX_STRINGVECTOR_H__8D72F57C_CA8F_4812_BEE1_342F9810C19F__INCLUDED_
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
#include <vector>
NAMESPACE_BEGIN(asynsdk)

typedef std::vector<std::string> t_vecips;

//////////////////////////////////////////////////////////////////////
class CStringVector :
        public IStringVector,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CStringVector(uint32_t dwRef = 0)
      : CSingleThreadModelObject(dwRef)
    {
    }
    virtual ~CStringVector() { }

//  DECLARE_NOT_AGGREGATABLE(CStringVector) 
//  BEGIN_COM_MAP(CStringVector)
//      COM_INTERFACE_ENTRY(IStringVector)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CStringVector)
        OBJ_INTERFACE_ENTRY(IStringVector)
    END_OBJ_MAP()

public: //interface of IStringVector
    STDMETHOD(Get)( /*[in ]*/uint32_t index, /*[out]*/STRING* Val );
    STDMETHOD(Add)( /*[in ]*/STRING Val );
    STDMETHOD(Set)( /*[in ][size_is(sizeof(STRING)*Size)]*/STRING* Val, /*[in ]*/uint32_t Size );

public:
    CStringVector *Set(t_vecips &vals, bool bDoCopy = true)
    {
        if( bDoCopy )
        {
            for(t_vecips::iterator it = vals.begin(); it != vals.end(); ++ it)
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
    CStringVector *Set(const std::string &val)
    {
        m_vals.emplace_back(val);
        return this;
    }

public:
    t_vecips  m_vals;
};

class CStringVectorRef :
        public IStringVector,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CStringVectorRef(uint32_t dwRef = 0, t_vecips *vals = 0)
      : CSingleThreadModelObject(dwRef), m_vals(vals)
    {
    }
    virtual ~CStringVectorRef() { }

//  DECLARE_NOT_AGGREGATABLE(CStringVectorRef)
//  BEGIN_COM_MAP(CStringVectorRef)
//      COM_INTERFACE_ENTRY(IStringVector)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CStringVectorRef)
        OBJ_INTERFACE_ENTRY(IStringVector)
    END_OBJ_MAP()

public: //interface of IStringVector
    STDMETHOD(Get)( /*[in ]*/uint32_t index, /*[out]*/STRING* Val );
    STDMETHOD(Add)( /*[in ]*/STRING Val );
    STDMETHOD(Set)( /*[in ][size_is(sizeof(STRING)*Size)]*/STRING* Val, /*[in ]*/uint32_t Size );

public:
    t_vecips *m_vals;
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_StringVector_H__8D72F57C_CA8F_4812_BEE1_342F9810C19F__INCLUDED_)
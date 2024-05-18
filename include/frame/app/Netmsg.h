/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_NETMSG_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
#define AFX_NETMSG_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 01/15/2024
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

#include "KeyvalSetter.h"
#include "../asm/INet.h"
NAMESPACE_BEGIN(asynsdk)

class CNetmsg :
        public INetmsg,
        public CKeyval,
        public CMultiThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CNetmsg(uint32_t dwRef = 0, BOOL ack = 0)
      : CMultiThreadModelObject(dwRef), m_ack(ack)
    {
    }
    virtual ~CNetmsg() { }

//  DECLARE_NOT_AGGREGATABLE(CNetmsg) 
//  BEGIN_COM_MAP(CNetmsg)
//      COM_INTERFACE_ENTRY(INetmsg )
//      COM_INTERFACE_ENTRY(IKeyvalSetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CNetmsg)
        OBJ_INTERFACE_ENTRY(INetmsg      )
        OBJ_INTERFACE_ENTRY(IKeyvalSetter)
    END_OBJ_MAP()

public: //interface of IKeyvalSetter
    STDMETHOD(Get    )( /*[in ]*/STRING Key, /*[in ]*/uint32_t Index, /*[in ]*/BOOL remove, /*[in ]*/IStringSetter *value )
    {
        return CKeyval::Get(Key, Index, remove, value);
    }
    STDMETHOD(Set    )( /*[in ]*/STRING Key, /*[in ]*/BOOL Multi, /*[in ]*/STRING value )
    {
        return CKeyval::Set(Key, Multi, value);
    }
    STDMETHOD(Del    )( /*[in ]*/STRING Key, /*[in ]*/uint32_t Index )
    {
        return CKeyval::Del(Key, Index);
    }
    STDMETHOD(Has    )( /*[in ]*/STRING Key, /*[out]*/uint32_t *pCount )
    {
        return CKeyval::Has(Key, pCount);
    }
    STDMETHOD(Format )( /*[in ]*/STRING sep, /*[in ]*/STRING end, /*[in,out]*/STRING *out )
    {
        return CKeyval::Format(sep, end, out);
    }
    STDMETHOD(Travel)( /*[in ]*/IUnknown* pParams )
    {
        return CKeyval::Travel(pParams);
    }

public: //interface of INetmsg
    STDMETHOD(Getline)( /*[out]*/STRING *pMethod, /*[out]*/STRING *pParam1, /*[out]*/STRING *pParam2, /*[out]*/BOOL *ack )
    {
        if( ack ) *ack = m_ack;
        if( pMethod )
        {
            pMethod->ptr = (BYTE *)m_method.c_str();
            pMethod->len = m_method.size();
        }
        if( pParam1 )
        {
            pParam1->ptr = (BYTE *)m_param1.c_str();
            pParam1->len = m_param1.size();
        }
        if( pParam2 )
        {
            pParam2->ptr = (BYTE *)m_param2.c_str();
            pParam2->len = m_param2.size();
        }
        return S_OK;
    }
    STDMETHOD(Setline)( /*[in ]*/STRING Method, /*[in ]*/STRING param1, /*[in ]*/STRING param2 )
    {
        m_method = string_from_STRING(Method);
        m_param1 = string_from_STRING(param1);
        m_param2 = string_from_STRING(param2);
        return S_OK;
    }

public:
    std::string m_method;
    std::string m_param1;
    std::string m_param2;
    BOOL  m_ack; //0-req 1-ack
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_NETMSG_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
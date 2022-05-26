// KeyvalSetter.h: Definition of the CKeyvalSetter class
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_KEYVALSETTER_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
#define AFX_KEYVALSETTER_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_
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
#include <memory>
#include <map>
NAMESPACE_BEGIN(asynsdk)

//;开头的key表示注释
/////////////////////////////////////////////////////////////////////////////////
struct CKeyval
{// 注意非线程安全
public:
    HRESULT Get   ( /*[in ]*/STRING Key, /*[in ]*/uint32_t  Index, /*[in ]*/BOOL remove, /*[in ]*/IStringSetter *value );
    HRESULT Set   ( /*[in ]*/STRING Key, /*[in ]*/BOOL Multi, /*[in ]*/STRING value );
    HRESULT Del   ( /*[in ]*/STRING Key, /*[in ]*/uint32_t  Index );
    HRESULT Has   ( /*[in ]*/STRING Key, /*[out]*/uint32_t *Count );

public:
    HRESULT Format( /*[in ]*/STRING sep, /*[in ]*/STRING end, /*[in,out]*/STRING *out );
    HRESULT Travel( /*[in ]*/IUnknown* pParams ); //remark: 只支持IAsynMessageEvents参数, 遍历元素时，若events->OnMessage(AF_EVENT_NOTIFY, key, val, object)!=0时表示通知从容器删除该元素

public:
    struct KEY_Sort
    {// 忽略大小写
        bool operator()(const std::string &a, const std::string &b) const;
    };
    struct VAL
    {
        void        *val;
        unsigned int len;

        VAL(void *v, unsigned int l)
        {
            Set(v, l);
        }
        VAL()
            : val(0), len(0)
        {
        }
        ~VAL()
        {
            if( val )
            {
                if( len )
                    delete[] (char *)val;
                else
                    ((IUnknown *)val)->Release();
            }
        }

        void Set(void *v, unsigned int l);
    };
    std::multimap< std::string, VAL, KEY_Sort > m_mapVals; //val.len=0:object val.len=1:string
};

class CKeyvalSetter :
        public IKeyvalSetter,
        public CMultiThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CKeyvalSetter(uint32_t dwRef = 0)
      : CMultiThreadModelObject(dwRef)
    {
    }
    virtual ~CKeyvalSetter() { }

//  DECLARE_NOT_AGGREGATABLE(CKeyvalSetter) 
//  BEGIN_COM_MAP(CKeyvalSetter)
//      COM_INTERFACE_ENTRY(IKeyvalSetter)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CKeyvalSetter)
    OBJ_INTERFACE_ENTRY(IKeyvalSetter)
    END_OBJ_MAP()

public: //interface of IKeyvalSetter
    STDMETHOD(Get   )( /*[in ]*/STRING Key, /*[in ]*/uint32_t Index, /*[in ]*/BOOL remove, /*[in ]*/IStringSetter *value )
    {
        return m_val.Get(Key, Index, remove, value);
    }
    STDMETHOD(Set   )( /*[in ]*/STRING Key, /*[in ]*/BOOL Multi, /*[in ]*/STRING value )
    {
        return m_val.Set(Key, Multi, value);
    }
    STDMETHOD(Del   )( /*[in ]*/STRING Key, /*[in ]*/uint32_t  Index )
    {
        return m_val.Del(Key, Index);
    }
    STDMETHOD(Has   )( /*[in ]*/STRING Key, /*[out]*/uint32_t *Count )
    {
        return m_val.Has(Key, Count);
    }
    STDMETHOD(Format)( /*[in ]*/STRING sep, /*[in ]*/STRING end, /*[in,out]*/STRING *out )
    {
        return m_val.Format(sep, end, out);
    }
    
    STDMETHOD(Travel)( /*[in ]*/IUnknown* pParams )
    {
        return m_val.Travel(pParams); //remark: IN_SysArgv所对应的对象增加支持传入IStringSetter参数: 用于保存参数到指定文件
    }

public:
    CKeyval m_val;
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_KEYVALSETTER_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)

// Unknown.h: interface for the CUnknownSingleThread/CUnknownMultiThread class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_UNKNOWN_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_)
#define AFX_UNKNOWN_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_
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

NAMESPACE_BEGIN(asynsdk)

#define BEGIN_OBJ_MAP_EX(c, s)      template< class Q > operator Q*() { return static_cast<Q*>(this); } \
                                    ULONG STDMETHODCALLTYPE AddRef () { return UnknownAddRef (); } \
                                    ULONG STDMETHODCALLTYPE Release() { if( m_dwRef == 1 ) s; return UnknownRelease(); } \
                                    STDMETHODIMP QueryInterface(REFIID riid, void **ppObject) { *ppObject = NULL; IUnknown* pUnknown = NULL;

#define BEGIN_OBJ_MAP(c)            template< class Q > operator Q*() { return static_cast<Q*>(this); } \
                                    ULONG STDMETHODCALLTYPE AddRef () { return UnknownAddRef (); } \
                                    ULONG STDMETHODCALLTYPE Release() { return UnknownRelease(); } \
                                    STDMETHODIMP QueryInterface(REFIID riid, void **ppObject) { *ppObject = NULL; IUnknown* pUnknown = NULL;
#define OBJ_INTERFACE_ENTRY(i)      if( IsEqualIID(riid,__uuidof(i))) { *ppObject = static_cast<i*>(this); AddRef(); return S_OK; } pUnknown = static_cast<IUnknown*>(static_cast<i*>(this));
#define OBJ_INTERFACE_ENTRY_EX(i,j) if( IsEqualIID(riid,__uuidof(i))) { *ppObject = static_cast<i*>(static_cast<j*>(this)); AddRef(); return S_OK; } pUnknown = static_cast<IUnknown*>(static_cast<i*>(static_cast<j*>(this)));
#define END_OBJ_MAP()               if( pUnknown && IsEqualIID(riid,IID_IUnknown)) { *ppObject = pUnknown; AddRef(); return S_OK; } return E_NOINTERFACE; }

//////////////////////////////////////////////////////////////////////
class CSingleThreadModelObject
{
public:
    CSingleThreadModelObject(ULONG dwRef = 0)
      : m_dwRef(dwRef)
    {
    }
    virtual ~CSingleThreadModelObject() { }

public:
    ULONG UnknownAddRef ();
    ULONG UnknownRelease();

public:
    ULONG m_dwRef;
};

class CMultiThreadModelObject
{
public:
    CMultiThreadModelObject(ULONG dwRef = 0)
      : m_dwRef(dwRef)
    {
    }
    virtual ~CMultiThreadModelObject() { }

public:
    ULONG UnknownAddRef ();
    ULONG UnknownRelease();

public:
    ULONG m_dwRef;
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_UNKNOWN_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_)

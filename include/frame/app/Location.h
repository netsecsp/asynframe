/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_LOCATION_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
#define AFX_LOCATION_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_
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

#include "String.h"
NAMESPACE_BEGIN(asynsdk)

#ifdef _LOG
#define OBJECT_FROM_HERE(o) new asynsdk::CLocation(0, o, __FILE__, __FUNCTION__, __LINE__) // Define a macro to record the current source location.
#else
#define OBJECT_FROM_HERE(o) o
#endif

/////////////////////////////////////////////////////////////////////////////
class CLocation :
        public ILocation,
        public CSingleThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CLocation(uint32_t dwRef, IUnknown *object, const char *file, const char *func, uint32_t line)
      : CSingleThreadModelObject(dwRef), m_file(file), m_func(func), m_line(line), m_object(object)
    {
    }
    virtual ~CLocation() { }

//  DECLARE_NOT_AGGREGATABLE(CLocation) 
//  BEGIN_COM_MAP(CLocation)
//      COM_INTERFACE_ENTRY(ILocation)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CLocation)
        OBJ_INTERFACE_ENTRY(ILocation)
    END_OBJ_MAP()

public: //interface of ILocation
    STDMETHOD(Get)( /*[out]*/IUnknown** outp, /*[out]*/STRING* file, /*[out]*/STRING* func, /*[out]*/uint32_t* line )
    {
        if( file ) STRING_EX::Set(file, m_file, (uint32_t)strlen(m_file));
        if( func ) STRING_EX::Set(func, m_func, (uint32_t)strlen(m_func));
        if( line ) *line = m_line;
        if( outp ) *outp = m_object.AddRef();
        return S_OK;
    }

public:
    const char *m_file;
    const char *m_func;
    uint32_t    m_line;
    CObjPtr<IUnknown> m_object;
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_LOCATION_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
// String.h: Definition of the STRING_EX class
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STRING_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)
#define AFX_STRING_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_
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

#define string_from_STRING(S)    std::string((char*)(S).ptr, (S).len)
#define string_from_BUFFER(S, l) std::string((char*)(S), l)
#define STRING_from_string(s)    asynsdk::STRING_EX(s)
#define STRING_from_buffer(S, l) asynsdk::STRING_EX((void*)(S), l)
#define STRING_from_object(S)    asynsdk::STRING_EX((void*)(S), 0)
#define STRING_from_value(S)     asynsdk::STRING_EX(&(S), sizeof(S))
template<typename T> T value_from_STRING(STRING *s) { return *((T*)s->ptr);}

/////////////////////////////////////////////////////////////////////////////////
struct STRING_EX : public STRING
{
public:
    STRING_EX(const char *s = "")
    {
        Set(s, (uint32_t)strlen(s));
    }
    STRING_EX(const std::string &s)
    {
        Set(s.empty()? "" : s.c_str(), (uint32_t)s.size());
    }
    STRING_EX(const void *s, uint32_t l)
    {
        Set(s, l);
    }

public:
    static unsigned int Set(STRING *v, const void *s, uint32_t l)
    {
        v->ptr = (unsigned char *)s;
        v->len = l;
        return l;
    }
    STRING_EX *Set(const void *s, uint32_t l)
    {
        ptr = (unsigned char *)s; 
        len = l;
        return this;
    }

public:
    static STRING_EX null; //定义空值
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_STRING_H__EAB9B945_803E_460B_8137_8C63F70CB605__INCLUDED_)

#ifndef __COMMON_COM_H__
#define __COMMON_COM_H__
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 07/01/2016
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
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
#include <atlcom.h>
#include <comdef.h>

#include <stdint.h>
#include <assert.h>

#define USING_NAMESPACE(name) using namespace name
#define NAMESPACE_BEGIN(name) namespace name {
#define NAMESPACE_END( name ) }

#define IF_POINTER_INVALID_RETURN(ptr,ret) do{ assert(ptr); if( !(ptr) ) return ret; }while(0)
#define IF_VAR_EQUAL_RETURN(var,value,ret) do{ if( (var)==(value) ) return ret; }while(0)

NAMESPACE_BEGIN(asynsdk)
template<class T, int doAddref> T *CreateObject( void )
{
    T *object = new T(); //CComObject<T>* object = 0; CComObject<T>::CreateInstance(&object );
    if( doAddref ) object->AddRef();
    return object;
}

NAMESPACE_END(asynsdk)

#endif//__COMMON_COM_H__
///////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_PROXY_PYTHON_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)
#define AFX_PROXY_PYTHON_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_
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

#include "../asynsdk_common.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifndef _Using_PYTHON_VERSION //default use python 3.8.20
#define _Using_PYTHON_VERSION 38
#endif
#pragma message("warning message: Extend Python Library project should add link library: python" xstr(_Using_PYTHON_VERSION ) "_dll.lib")

#define PY_SSIZE_T_CLEAN  /* Make "s#" use Py_ssize_t rather than int. */
#if _Using_PYTHON_VERSION == 38
#include "v308/python.h"
#else
#include "v312/python.h"
#endif
#ifdef __cplusplus
}
#endif
#include "Pyptr.h"
#include "../AsynCore.h"
#include "../asm/IScriptHost.h"
NAMESPACE_BEGIN(python)

/////////////////////////////////////////////////////////////////////
IScriptHost *GetScriptHost( void ); //get from sys.xvmhost

//生成object对应的python对象
//1.addref_for_python=true表示在python端持有c对象的引用计数器
//2.auto_bindc_python=true表示调用SObject.Set绑定python对象
PyObject    *Create( /*[in ]*/IUnknown *object, /*[in ]*/const char *name, /*[in ]*/PyObject *module, /*[in ]*/bool addref_for_python = false, /*[in ]*/bool auto_bindc_python = false );
/////////////////////////////////////////////////////////////////////

NAMESPACE_END(python)

#endif // !defined(AFX_PROXY_PYTHON_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)

// Crashepr_internal.h: interface.
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_CRASHEXPLORER_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
#define AFX_CRASHEXPLORER_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_
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

#include "AsynCore_internal.h"
#include "asm/ICrashExplorer.h"
NAMESPACE_BEGIN(asynsdk)

/////////////////////////////////////////////////////////////////////////////////
//ICrashExplorer(InstanceName)
#define IN_CrashExplorer "com.app.crashexplorer"

/////////////////////////////////////////////////////////////////////////////////
typedef enum tag_ET_EXCEPTION_TYPE
{
    ET_SEH_EXCEPTION        = 0, //!< SEH exception.
    ET_INVALID_PARAMETER,        //!< Invalid parameter exception (VS 2005 and later).
    ET_NONCONTINUABLE_EXCEPTION, //!< Non continuable sofware exception.
    ET_CPP_TERMINATE_CALL,       //!< C++ terminate() call.
    ET_CPP_UNEXPECTED_CALL,      //!< C++ unexpected() call.
    ET_CPP_PURE_CALL,            //!< C++ pure virtual function call (VS .NET and later).
    ET_CPP_NEW_OPERATOR_ERROR,   //!< C++ new operator fault (VS .NET and later).
    ET_CPP_SIGABRT,              //!< C++ SIGABRT signal (abort).
    ET_CPP_SIGFPE,               //!< C++ SIGFPE signal (flotating point exception).
    ET_CPP_SIGILL,               //!< C++ SIGILL signal (illegal instruction).
    ET_CPP_SIGINT,               //!< C++ SIGINT signal (CTRL+C).
    ET_CPP_SIGSEGV,              //!< C++ SIGSEGV signal (invalid storage access).
    ET_CPP_SIGTERM,              //!< C++ SIGTERM signal (termination request).
    ET_CPP_THROW,                //!< Throw C++ typed exception.
    ET_CPP_SECURITY_EXCEPTION,   //!< Previous security exception filter.
    ET_MANUAL_EXCEPTION          //!< Manual report .
} ET_EXCEPTION_TYPE;

typedef struct tag_SI_STACKFRAME_INFO
{
    uint32_t size;               //!< Size of this structure in bytes; should be initialized before using.
    uint32_t displacement;
    void    *base;
    void    *addr;
    uint32_t line;
} SI_STACKFRAME_INFO;

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_CRASHEXPLORER_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
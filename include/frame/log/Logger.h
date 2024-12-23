#if !defined(AFX_LOGGER_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)
#define AFX_LOGGER_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_
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

#ifndef _DEBUG
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#else //激活日志版本
///////////////////////////////////////////////////////////////////////////////
#ifndef _LOG
#define _LOG
#endif
///////////////////////////////////////////////////////////////////////////////
#endif

#ifndef _LOG
#pragma message("warning message: disable logger")
///////////////////////////////////////////////////////////////////////////////
#define LOGGER_DECLARE(logger)
#define LOGGER_IMPLEMENT(logger, mname, cname)
#define LOGGER_CLASS_DECLARE(logger)
#define LOGGER_CLASS_IMPLEMENT(classname, logger, mname, cname)
///////////////////////////////////////////////////////////////////////////////
#define LOGGER_TRACE(a,b)
#define LOGGER_DEBUG(a,b)
#define LOGGER_INFO( a,b)
#define LOGGER_WARN( a,b)
#define LOGGER_ERROR(a,b)
#define LOGGER_FATAL(a,b)
#define LOGGER_NOTE( a,b)
#define LOGGER_DUMP( a,l,b,d,s )
#define LOGGER_FUNC( a,b)
#define LOGGER_LOGS( l, a, b)
///////////////////////////////////////////////////////////////////////////////
#define LOGGER_THIS_TRACE(a,b)
#define LOGGER_THIS_DEBUG(a,b)
#define LOGGER_THIS_INFO( a,b)
#define LOGGER_THIS_WARN( a,b)
#define LOGGER_THIS_ERROR(a,b)
#define LOGGER_THIS_FATAL(a,b)
#define LOGGER_THIS_NOTE( a,b)
#define LOGGER_THIS_DUMP( a,l,b,d,s )
///////////////////////////////////////////////////////////////////////////////
#define OBJECT_LEAK_DECLARE(helper)
#define OBJECT_LEAK_INIT(helper,o,n )
///////////////////////////////////////////////////////////////////////////////
#else
///////////////////////////////////////////////////////////////////////////////
#pragma message("warning message: enabled logger")

#include <sstream> //for stringstream

#define LOGGER_DECLARE(logger)                                  extern asynsdk::CAsynLoggerHelper logger
#define LOGGER_IMPLEMENT(logger, mname, cname)                  asynsdk::CAsynLoggerHelper logger(mname, cname)
#define LOGGER_CLASS_DECLARE(logger)                            static asynsdk::CAsynLoggerHelper logger
#define LOGGER_CLASS_IMPLEMENT(classname, logger, mname, cname) asynsdk::CAsynLoggerHelper classname::logger(mname, cname)

///////////////////////////////////////////////////////////////////////////////
#define LOGGER_TRACE(a,b) { if( a.IsEnabled(asynsdk::FL_TRACE) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_TRACE, ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_DEBUG(a,b) { if( a.IsEnabled(asynsdk::FL_DEBUG) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_DEBUG, ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_INFO( a,b) { if( a.IsEnabled(asynsdk::FL_INFO ) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_INFO , ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_WARN( a,b) { if( a.IsEnabled(asynsdk::FL_WARN ) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_WARN , ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_ERROR(a,b) { if( a.IsEnabled(asynsdk::FL_ERROR) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_ERROR, ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_FATAL(a,b) { if( a.IsEnabled(asynsdk::FL_FATAL) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_FATAL, ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_NOTE( a,b) { if( a.IsEnabled(asynsdk::FL_NOTE ) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_NOTE , ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_FUNC( a,b) { if( a.IsEnabled(asynsdk::FL_INFO ) ) { std::stringstream ss; ss << b; a.Logs( asynsdk::FL_INFO , ss.str(), __FILE__, __LINE__ ); } }
#define LOGGER_DUMP( a,l,b,d,s ) { if( a.IsEnabled(l) ) { std::stringstream ss; ss << b; a.Dump(l, ss.str(), d, s); } }
#define LOGGER_LOGS(l, a, b) { if( a.IsEnabled(l) ) { std::stringstream ss; ss << b; a.Logs(l, ss.str(), __FILE__, __LINE__); } }
///////////////////////////////////////////////////////////////////////////////
#define LOGGER_THIS_TRACE(a,b) LOGGER_TRACE(a, '[' << this << ']' << b )
#define LOGGER_THIS_DEBUG(a,b) LOGGER_DEBUG(a, '[' << this << ']' << b )
#define LOGGER_THIS_INFO( a,b) LOGGER_INFO( a, '[' << this << ']' << b )
#define LOGGER_THIS_WARN( a,b) LOGGER_WARN( a, '[' << this << ']' << b )
#define LOGGER_THIS_ERROR(a,b) LOGGER_ERROR(a, '[' << this << ']' << b )
#define LOGGER_THIS_FATAL(a,b) LOGGER_FATAL(a, '[' << this << ']' << b )
#define LOGGER_THIS_NOTE( a,b) LOGGER_NOTE( a, '[' << this << ']' << b )
#define LOGGER_THIS_DUMP( a,l,b,d,s ) LOGGER_DUMP( a, l, '[' << this << ']' << b, d, s )
///////////////////////////////////////////////////////////////////////////////
#define OBJECT_LEAK_DECLARE(helper)   asynsdk::CObjectsLeakHelper helper
#define OBJECT_LEAK_INIT(helper,o,n ) helper.Logs(o, n)
///////////////////////////////////////////////////////////////////////////////
NAMESPACE_BEGIN(asynsdk)

enum FRAME_LOGLEVEL
{
    FL_TRACE = 1,
    FL_DEBUG = 2,
    FL_INFO  = 3,
    FL_WARN  = 4,
    FL_ERROR = 5,
    FL_FATAL = 6,
    FL_NOTE  = 7 //always output
};

class CAsynLoggerHelper
{
public:
    CAsynLoggerHelper(/*in*/const char *mname, /*in*/const char *cname)
      : m_value(0), m_mname(mname), m_cname(cname)
    {
    }
    ~CAsynLoggerHelper()
    {
        if( m_value )
            m_value->Release();
    }

public:
    bool IsEnabled(/*in*/unsigned int level); //日志级别是否可输出
    void Logs(/*in*/unsigned int level, /*in*/const std::string &text, /*in*/const char *file="", /*in*/unsigned int line = 0);
    void Dump(/*in*/unsigned int level, /*in*/const std::string &head, /*in*/unsigned char *data, /*in*/unsigned int size);

private:
    const char *m_mname; //模块, 注意：要求是常量字符串
    const char *m_cname; //类名
    IUnknown *m_value;
};
///////////////////////////////////////////////////////////////////////////////
class CObjectsLeakHelper
{
public:
    CObjectsLeakHelper()
      : m_value(0)
    {
    }
    ~CObjectsLeakHelper();

public:
    void Logs(/*in*/IUnknown *object, /*in*/const char *cname);
    static bool Dump(/*in*/const char *mname, /*out*/std::string &info);

private:
    IUnknown *m_value;
};
///////////////////////////////////////////////////////////////////////////////
void AsynLogger_Initialize(/*in*/IUnknown *lpInstancesManager);
void AsynLogger_Output(/*in*/IDataTransmit *target);
///////////////////////////////////////////////////////////////////////////////
NAMESPACE_END(asynsdk)

#endif

#endif // AFX_LOGGER_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_
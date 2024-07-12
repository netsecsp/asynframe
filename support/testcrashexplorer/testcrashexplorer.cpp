/*****************************************************************************
Copyright (c) 2012 - 2032, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 05/01/2022
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
#include "stdafx.h"
#include <conio.h>
#include <signal.h>
#include <eh.h>
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <float.h>

#define AAPIDLL_USING

#include <frame/AsynCore.h>
#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#endif

#ifdef  AAPIDLL_USING
#ifdef _DEBUG
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#else
#pragma comment(lib, "asynsdk_mini-MD.lib")
#endif
#pragma comment(lib,"asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif

STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IUnknown *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager *) GetInstancesManager();

// Code taken from http://msdn.microsoft.com/zh-cn/library/3c594ae3.aspx
#pragma warning(disable : 4355)
class CDerived;
class CBase
{
public:
    CBase(CDerived *derived) : m_pDerived(derived) {};
    ~CBase();
    virtual void function( ) = 0;

    CDerived *m_pDerived;
};

class CDerived : public CBase
{
public:
    CDerived() : CBase(this) {};   // C4355 "this" used in derived c'tor
    virtual void function( ) {};
};

CBase::~CBase()
{
    m_pDerived->function();
}

int EmulateCrash(char ExceptionType) throw (...)
{
    switch(ExceptionType)
    {
    case '0': {// Access violation
            int *p = 0;
            *p = 0;
         }
         break;
    case '1': {// Call terminate
            terminate();
         }
         break;
    case '2': {// Call unexpected
            unexpected();
         }
         break;
    case '3': {// pure virtual method call
            CDerived derived;
         }
         break;
    case '4': {// Call printf_s with invalid parameters.
            char* formatString = NULL; 
            printf(formatString);
         }
         break;
    case '5': {// Cause memory allocation error
            #define BIG_NUMBER 0x1fffffff
            #pragma warning(disable: 4717)
            #pragma warning(disable: 4702)
            int *pi;
            for(;;) pi = new int[BIG_NUMBER];        
         }
         break;
    case '6': {// Call abort
            abort();
         }
         break;
    case '7': {// floating point exception ( /fp:except compiler option)
            // Code taken from http://www.devx.com/cplus/Article/34993/1954

            //Set the x86 floating-point control word according to what
            //exceptions you want to trap. 
            _clearfp(); //Always call _clearfp before setting the control
            //word
            //Because the second parameter in the following call is 0, it
            //only returns the floating-point control word
            unsigned int cw; 
            #if _MSC_VER<1400
            cw = _controlfp(0, 0); //Get the default control
            #else
            _controlfp_s(&cw, 0, 0); //Get the default control
            #endif 
            //word
            //Set the exception masks off for exceptions that you want to
            //trap.  When a mask bit is set, the corresponding floating-point
            //exception is //blocked from being generating.
            cw &=~(EM_OVERFLOW|EM_UNDERFLOW|EM_ZERODIVIDE|EM_DENORMAL|EM_INVALID);
            //For any bit in the second parameter (mask) that is 1, the 
            //corresponding bit in the first parameter is used to update
            //the control word.  
            unsigned int cwOriginal = 0;
            #if _MSC_VER<1400
            cwOriginal = _controlfp( cw, MCW_EM); //Set it.
            #else
            _controlfp_s(&cwOriginal,cw, MCW_EM); //Set it.
            #endif
            //MCW_EM is defined in float.h.

            // Divide by zero
            float a = 1.0f;
            float b = 0.0f;
            float c = a/b;
            //Restore the original value when done:
            //_controlfp_s(cwOriginal, MCW_EM);
         }    
         break;
    case '8': {
            int result = raise(SIGILL);  
            assert(result==0);
         }
         break;
    case '9': {
            int result = raise(SIGINT);  
            assert(result==0);
         }   
         break;
    case 'a': {
            int result = raise(SIGSEGV);  
            assert(result==0);
         } 
         break;
    case 'b': {
            int result = raise(SIGTERM);  
            assert(result==0);
         }
         break;
    case 'c': {// Raise noncontinuable software exception
            RaiseException(0x7b, EXCEPTION_NONCONTINUABLE, 0, NULL);        
         }
         break;
    case 'd': {// Throw typed C++ exception.
            throw 13;
         }
         break;
    default:
         break;
    }

    return 1;
}

class CGlobalEvents : public asynsdk::CAsynMessageEvents_base
{
public:
    CGlobalEvents()
      : CAsynMessageEvents_base(1)
    {
    }

public: // interface of asyn_message_events_impl
    STDMETHOD(OnMessage)( /*[in]*/uint32_t message, /*[in]*/uint64_t lparam1, /*[in]*/uint64_t lparam2, /*[in,out]*/IUnknown** objects )
    {
        if( message == AF_EVENT_NOTIFY &&
            lparam1 == EN_SystemEvent )
        {
            // Set up process start up info
            STARTUPINFO si; memset(&si, 0, sizeof(STARTUPINFO));
            si.cb = sizeof(STARTUPINFO);

            // Set up process information
            PROCESS_INFORMATION pi; memset(&pi, 0, sizeof(PROCESS_INFORMATION));  

            asynsdk::CStringSetter v(1); ((IKeyvalSetter *)objects[0])->Get(STRING_from_string(";memname"), 0, 0, &v);

            // Create process using the command line prepared earlier
            if(!CreateProcess(NULL, (char*)("./snd/testcrashrpt.exe " + v.m_val).c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
            {
                printf("call CreateProcess testcrashrpt.exe return 0, lErrorcode=%d\n", GetLastError());
                if(((IKeyvalSetter *)objects[0])->Get(STRING_from_string(";context"), 0, 0, &v) == S_OK )
                {// stack
                    printf("%s\n", v.m_val.c_str());
                }
            }
            else
            {
                if( pi.hThread )
                {
                    CloseHandle(pi.hThread);
                }

                DWORD iret = WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                return S_FALSE; //because testcrashrpt.exe implement WriteDumpfile, so notify system cancel to do WriteDumpfile
            }
        }
        return E_NOTIMPL;
    }
};

int _tmain(int argc, _TCHAR *argv[])
{
    CGlobalEvents e;
    HRESULT hr1 = Initialize(&e, NULL);
    {
        char ExceptionType = 0;
        do{
        printf("Choose an exception type:\n");
        printf("\t0 - SEH exception\n");
        printf("\t1 - terminate\n");
        printf("\t2 - unexpected\n");
        printf("\t3 - pure virtual method call\n");
        printf("\t4 - invalid parameter\n");
        printf("\t5 - new operator fault\n");    
        printf("\t6 - SIGABRT\n");
        printf("\t7 - SIGFPE\n");
        printf("\t8 - SIGILL\n");
        printf("\t9 - SIGINT\n");
        printf("\ta - SIGSEGV\n");
        printf("\tb - SIGTERM\n");
        printf("\tc - RaiseException\n");
        printf("\td - throw C++ typed exception\n");
        printf("\te - exit\n"); 
        printf("Your choice-> ");
        scanf_s("%c", &ExceptionType, 1);
        }while((ExceptionType < '0' || ExceptionType > '9') && (ExceptionType < 'a' || ExceptionType > 'e'));
        EmulateCrash(ExceptionType);
    }
    HRESULT hr2 = Destory();
    return 0;
}


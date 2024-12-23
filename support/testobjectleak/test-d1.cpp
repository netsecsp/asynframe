// dll_core.cpp : Implementation of DLL Exports.
// Note: Proxy/Stub Information
//       To build a separate proxy/stub DLL,
//       run nmake -f dll_core.mk in the project directory.
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <frame/AsynCore.h>
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>

class D1 : 
        public IUnknown,
        public asynsdk::CSingleThreadModelObject
{
public:
    D1()
      : asynsdk::CSingleThreadModelObject(1)
    {
        printf("+D1.%p\n", this);
        OBJECT_LEAK_INIT(ol, this, "D1");
    }
    virtual ~D1()
    {
        printf("-D1.%p\n", this);
    }

    BEGIN_OBJ_MAP(D1)
        OBJ_INTERFACE_ENTRY(IUnknown)
    END_OBJ_MAP()

    OBJECT_LEAK_DECLARE(ol);
};

//http://blog.chinaunix.net/uid-20743151-id-326347.html
#ifdef _DEBUG
#ifdef _DLL
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#else
#pragma comment(lib, "asynsdk_mini-MTd.lib")
#endif
#else
#ifdef _DLL
#pragma comment(lib, "asynsdk_mini-MD.lib")
#else
#pragma comment(lib, "asynsdk_mini-MT.lib")
#endif
#endif
//////////////////////////////////////////////////////////////////////////////////
// DLL Entry Point
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, ULONG dwReason, LPVOID lpReserved)
{// DllMain函数说明，https://blog.csdn.net/yiling2012/article/details/51742079
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        //_Module.Init(NULL,hInstance);
        DisableThreadLibraryCalls(hInstance);
        printf(" D1: enter\n");
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        //_Module.Term();
        printf(" D1: leave\n");
    }
    return TRUE;
}

//cl test-d1.cpp /D"_LOG" /EHsc /MD /I"..\..\include" -link -dll -out:test-d1.dll /LIBPATH:"..\..\lib"

#ifdef __cplusplus 
extern "C" { 
#endif

__declspec(dllexport)
IUnknown *d1_create(IUnknown *o)
{
    asynsdk::AsynLogger_Initialize(o);
    return new D1();
}

#ifdef __cplusplus 
}
#endif
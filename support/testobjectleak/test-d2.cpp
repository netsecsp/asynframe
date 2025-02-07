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

class D2 : 
        public IUnknown,
        public asynsdk::CSingleThreadModelObject
{
public:
    D2()
      : asynsdk::CSingleThreadModelObject(1)
    {
        printf("+D2.%p\n", this);
        OBJECT_LEAK_INIT(ol, this, "D2");
    }
    virtual ~D2()
    {
        printf("-D2.%p\n", this);
    }

    BEGIN_OBJ_MAP(D2)
        OBJ_INTERFACE_ENTRY(IUnknown)
    END_OBJ_MAP()

    OBJECT_LEAK_DECLARE(ol);
};

class Gl
{
public:
    Gl()
    {
        printf("+Gl.%p\n", this);
    }
    virtual ~Gl()
    {
        printf("-Gl.%p\n", this);
    }
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


static Gl g;
//////////////////////////////////////////////////////////////////////////////////
// DLL Entry Point
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, ULONG dwReason, LPVOID lpReserved)
{// DllMain函数说明，https://blog.csdn.net/yiling2012/article/details/51742079
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        //_Module.Init(NULL,hInstance);
        DisableThreadLibraryCalls(hInstance);
        printf(" D2: enter\n");
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        //_Module.Term();
        printf(" D2: leave\n");
    }
    return TRUE;
}

//cl test-d2.cpp /D"_LOG" /EHsc /MD /I"..\..\include" -link -dll -out:test-d2.dll /LIBPATH:"..\..\lib\win32"

#ifdef __cplusplus 
extern "C" { 
#endif

__declspec(dllexport)
IUnknown *d2_create(IUnknown *o)
{
    asynsdk::AsynLogger_Initialize(o);
    return new D2();
}

#ifdef __cplusplus 
}
#endif
// dll_testapi.cpp : Implementation of DLL Exports.
// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f lua_testapi.mk in the project directory.
#include <StdAfx.h>
#include "resource.h"

//CComModule _Module;
//////////////////////////////////////////////////////////////////////////////////
// DLL Entry Point
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, ULONG dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        //_Module.Init(NULL,hInstance);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        //_Module.Term();
    }
    return TRUE;
}
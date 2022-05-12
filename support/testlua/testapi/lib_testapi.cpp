// lib_testapi.cpp : Implementation of lib Exports.
#include <StdAfx.h>
#include <initguid.h>
#ifdef __cplusplus //由于.cpp文件是按c++编译,所以当包括c.api.h时必须用extern C, 确保编译器找到c函数名
extern "C" {
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "llimits.h"
#ifdef __cplusplus
}
#endif
#include <frame/lua/Utility.h>
#ifndef _LIB
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#endif

#ifndef _LIB //只有动态链接库才生效
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#endif
#pragma comment(lib, "lua_dll.lib")

LOGGER_IMPLEMENT( logger, "testapi", "Testapi(lua)" );

static int Logd(lua_State *pState)
{
    if( lua_isstring(pState, -1))
    {
        LOGGER_DEBUG(logger, lua_tostring(pState, -1));
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
int luaopen_testapi(lua_State *pState)
{
    InstancesManager *lpInstancesManager = asynsdk::GetInstancesManager(pState);
    if(!lpInstancesManager )
    {// 通知加载失败
        return 0;
    }

    asynsdk::AsynLogger_Initialize(lpInstancesManager);

    static const luaL_Reg testapi_methods[] = {
        { "d", Logd},
        {NULL, NULL}
    };

    luaL_newlib(pState, testapi_methods); //注册接口
    return 1;
}

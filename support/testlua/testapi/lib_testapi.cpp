// lib_testapi.cpp : Implementation of lib Exports.
#include <StdAfx.h>
#include <initguid.h>
#include <frame/lua/Utility.h>
#include "ITestapi.h"
#include "ITestapi_i.c"
#pragma comment(lib, "lua_dll.lib")

class CAsynMessageEvents : public asynsdk::CAsynMessageEvents_base
{
public:
    CAsynMessageEvents()
    {
        printf("+CAsynMessageEvents: %p\n", this);
    }
    virtual ~CAsynMessageEvents()
    {
        printf("-CAsynMessageEvents: %p\n", this);
    }

public: //interface of IAsynMessageEvents
    STDMETHOD(OnMessage)( /*[in ]*/uint32_t message, /*[in ]*/uint64_t lparam1, /*[in ]*/uint64_t lparam2, /*[in, out]*/IUnknown** objects )
    {
        printf("execute: message=%d, lparam1=%lld, lparam2=%lld, object=%p\n", message, lparam1, lparam2, objects? objects[0] : 0);
        return S_OK;
    }
};

class CTestX :
        public ITestA ,
        public ITestB ,
        public SObject,
        public asynsdk::CMultiThreadModelObject //CComObjectRootEx<CComSingleThreadModel>
{
public:
    CTestX( /*[in ]*/uint32_t dwRef = 0 )
      : asynsdk::CMultiThreadModelObject(dwRef)
    {
        printf("+CTestX: %p\n", this);
    }
    virtual ~CTestX()
    {
        printf("-CTestX: %p\n", this);
    }

//  DECLARE_NOT_AGGREGATABLE(CTestX)
//  BEGIN_COM_MAP(CTestX)
//      COM_INTERFACE_ENTRY(ITestA )
//      COM_INTERFACE_ENTRY(ITestB )
//      COM_INTERFACE_ENTRY(SObject)
//  END_COM_MAP()
    BEGIN_OBJ_MAP(CTestX)
        OBJ_INTERFACE_ENTRY(ITestA )
        OBJ_INTERFACE_ENTRY(ITestB )
        OBJ_INTERFACE_ENTRY(SObject)
    END_OBJ_MAP()

public: //interface of SObject
    STDMETHOD(Get)( /*[out]*/STRING* name )
    {
        name->ptr = (unsigned char*)"CTestX";
        name->len = 6;
        return S_OK;
    }
    STDMETHOD(CastOf)( /*[in ]*/STRING name, /*[out]*/IUnknown** object )
    {
        if( name.len == 6 )
        {
            if( memcmp(name.ptr, "ITestA", 6) == 0 || memcmp(name.ptr, "CTestX", 6) == 0 ) {
               *object = DoCast<ITestA>(true);
                return S_OK;
            }
            if( memcmp(name.ptr, "ITestB", 6) == 0 ) {
               *object = DoCast<ITestB>(true);
                return S_OK;
            }
        }
        return E_NOTIMPL;
    }

public: //interface of ITestA/ITestB
    STDMETHOD(WorkA)( /*[in ]*/uint32_t index )
    {
        printf("%p.workA(%d)\n", this, index);
        return S_OK;
    }

    STDMETHOD(WorkB)( /*[in ]*/uint32_t index )
    {
        printf("%p.workB(%d)\n", this, index);
        return S_OK;
    }

    STDMETHOD(WorkX)( /*[in ]*/uint32_t index )
    {
        printf("%p.workX(%d)\n", this, index);
        return S_OK;
    }
};

LOGGER_IMPLEMENT( logger, "lua", "Testapi(lua)");
/////////////////////////////////////////////////////////////////////////////
static int apiWrite(lua_State *pState)
{
    if( lua_isstring(pState, -1))
    {
        LOGGER_INFO(logger, lua_tostring(pState, -1));
    }
    return 0;
}

static int apiCreateObject(lua_State *pState)
{
    lua::Push(pState, lua_tointeger(pState, -1)==0? (IUnknown*)new CAsynMessageEvents() : (IUnknown*)static_cast<ITestA*>(new CTestX()));
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
int luaopen_testapi(lua_State *pState)
{
    InstancesManager *lpInstancesManager = lua::GetInstancesManager(pState);
    if(!lpInstancesManager )
    {// 通知失败
        return 0;
    }

    #ifdef  _LOG
    #ifndef _LIB
    asynsdk::AsynLogger_Initialize(lpInstancesManager);
    #endif
    LOGGER_DEBUG(logger, "1.0 builded in " << __DATE__ << " " << __TIME__);
    #endif

    static const luaL_Reg testapi_methods[] = {
        { "write", apiWrite},
        { "createObject", apiCreateObject},
        {NULL, NULL}
    };

    luaL_newlib(pState, testapi_methods); //注册接口: write

	lua::class_add<CTestX>(pState, "CTestX"); //register CTestX
	lua::class_inh<CTestX, IUnknown>(pState);
    lua::class_def<CTestX>(pState, "workA", &CTestX::WorkA);
    lua::class_def<CTestX>(pState, "workB", &CTestX::WorkB);
    lua::class_def<CTestX>(pState, "workX", &CTestX::WorkX);

	lua::class_add<ITestA>(pState, "ITestA"); //register ITestA
	lua::class_inh<ITestA, IUnknown>(pState);
    lua::class_def<ITestA>(pState, "workA", &ITestA::WorkA);
    lua::class_def<ITestA>(pState, "workX", &ITestA::WorkX);
    
	lua::class_add<ITestB>(pState, "ITestB"); //register ITestB
	lua::class_inh<ITestB, IUnknown>(pState);
    lua::class_def<ITestB>(pState, "workB", &ITestB::WorkB);
    lua::class_def<ITestB>(pState, "workX", &ITestB::WorkX);
    return 1;
}

#include "StdAfx.h"
#include "frame_Api.h"

#define  AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynframe_i.c>

#pragma comment(lib, "asynsdk_mini-MTd.lib")
#pragma comment(lib, "asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif

STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *events, /*[in ]*/IKeyvalSetter *param2 );
STDAPI_(extern InstancesManager*) GetInstancesManager( void );
STDAPI_(extern HRESULT) Destory( void );

HRESULT frame_Initialize( /*[in ]*/IAsynMessageEvents *events, /*[in ]*/IKeyvalSetter *param2 )
{
    return Initialize(events, param2);
}

InstancesManager *frame_GetInstancesManager( void )
{
    return GetInstancesManager();
}

HRESULT frame_Destory( void )
{
    return Destory();
}
#ifndef __FRAME_API_H__
#define __FRAME_API_H__

#pragma once

#include <frame/AsynCore_internal.h>

#ifdef __cplusplus 
extern "C" { 
#endif

DUILIB_API HRESULT frame_Initialize( /*[in ]*/IAsynMessageEvents *events, /*[in ]*/IKeyvalSetter *param2 );
DUILIB_API InstancesManager *frame_GetInstancesManager( void );
DUILIB_API HRESULT frame_Destory( void );

#ifdef __cplusplus 
}
#endif

#endif // __FRAME_API_H__
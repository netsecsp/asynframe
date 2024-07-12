#ifndef __FRAME_API_H__
#define __FRAME_API_H__

#pragma once

#include "souistd.h"
#include <frame/AsynCore.h>

#ifdef __cplusplus 
extern "C" { 
#endif

SOUI_EXP HRESULT frame_Initialize( /*[in ]*/IAsynMessageEvents *events, /*[in ]*/IUnknown *param2 );
SOUI_EXP InstancesManager *frame_GetInstancesManager( void );
SOUI_EXP HRESULT frame_Destory( void );

#ifdef __cplusplus 
}
#endif

#endif // __FRAME_API_H__
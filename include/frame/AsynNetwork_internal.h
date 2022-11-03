// AsynNetwork_internal.h: interface.
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_ASYNNETWORK_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
#define AFX_ASYNNETWORK_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 05/01/2022
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

#include "AsynCore_internal.h"
#include "asm/IAsynNetwork.h"
NAMESPACE_BEGIN(asynsdk)

/////////////////////////////////////////////////////////////////////////////////
//IAsynNetwork(InstanceName)
#define IN_AsynNetwork "com.asynframe.asynsock"

/////////////////////////////////////////////////////////////////////////////////
BEGIN_ASYN_IOERROR(IAsynNetwork)
    USER_ERROR(UNREACHABLE) //网络不可达/主机不可达
    USER_ERROR(EXPIRED)     //TTL 超时
    USER_ERROR(NOPARSE)     //无法解析
END_ASYN_IOERROR()

/////////////////////////////////////////////////////////////////////////////////
//IAsynDnsResolver.IObjectHolder(lType)
#define DT_GetDnsHostZone        ( 1 ) //获取IAsynDnsResolver内部IDnsHostZone

//IAsynNetwork.IObjectHolder(lType)
#define DT_GetAsynTcplinkManager (100) //获取内部的IAsynTcplinkManager

/////////////////////////////////////////////////////////////////////////////////
//SetSockopt/GetSockopt的定义level
#define EXT_SOCKET               (0xffffffff)

/////////////////////////////////////////////////////////////////////////////////
//SetSockopt/GetSockopt的定义optname
#define NET_SNDIO                ( 0 ) //是否同步发送UDP数据
#define NET_MTU                  ( 1 )
#define NET_WAN                  ( 2 ) //格式: port[2B]addr[4|16B]

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_ASYNNETWORK_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
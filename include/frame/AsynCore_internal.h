// AsynCore_internal.h: interface.
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_ASYNCORE_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
#define AFX_ASYNCORE_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_
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

#include "asynsdk_common.h"
#include "asm/ITypedef.h"
#include "asm/IAsynFrame.h"
#include "app/Unknown.h"
#include "app/Utility.h"
#include "log/Logger.h"
#include "app/STRING.h"
#include "app/StringSetter.h"
#include "app/StringsStack.h"
#include "app/KeyvalSetter.h"
#include "app/AsynMessageEvents.h"
NAMESPACE_BEGIN(asynsdk)

/////////////////////////////////////////////////////////////////////////////////
#define BEGIN_ASYN_IOERROR(label) \
   enum label##ErrType { \
        label##ErrType_Start = (label##_Start << 16) - 1,

#define USER_ERROR(label) \
        UE_##label,

#define END_ASYN_IOERROR() \
    };

/////////////////////////////////////////////////////////////////////////////////
typedef enum tag_ObjectIdStart
{
    IAsynFrame_Start  = 1,
    IAsynFileSystem_Start,
    IAsynNetwork_Start,
    IAsynIpcChannel_Start,
} ObjectIdStart;

/////////////////////////////////////////////////////////////////////////////////
//InstanceName
#ifdef _LOG
#define IN_AsynLoggerFactory            "com.app.loggerfactory"
#define IN_ObjectsLeaker                "com.app.objectsleaker"
#endif
#define IN_AsynFrameThreadFactory       "com.app.threadfactory"
#define IN_UniqueFrameThread            "uniqueasynframethread"
#define IN_MultiLanguage                "com.app.multilanguage"
#define IN_UniqueMempool                "uniquemempool"
#define IN_UniqueEvtpool                "uniqueevtpool"
#define IN_UniqueOpspool                "uniqueopspool"
#define IN_UniqueNetpool                "uniquenetpool"
#define IN_SysArgv                      "sysargv" //获取系统参数
#define IN_SysRoot                      "sysroot" //获取系统路径
#define IN_AppData                      "appdata" //获取数据路径
#define IN_SysInfo                      "sysinfo"
#define IN_SysTime                      "systime"

#define IN_Instancesmanager             "instancesmanager" //for lua

/////////////////////////////////////////////////////////////////////////////////
#define Io_recv                         ( 0)
#define Io_send                         ( 1)
#define Io_acceptd                      (16)
#define Io_connect                      (17)
#define Io_bind                         (18)
#define Io_hostdns                      (19)

/////////////////////////////////////////////////////////////////////////////////
#define CHECK_NO(r)                     (((r) >> 1) != 0) //r != S_OK && r != S_FALSE
#define CHECK_OK(r)                     (((r) >> 1) == 0) //r == S_OK || r == S_FALSE

BEGIN_ASYN_IOERROR(IAsynFrame)
    USER_ERROR(SYNTAX) //格式/语法错误
    USER_ERROR(ENCODE) //编码出错
    USER_ERROR(DECODE) //解码出错
    USER_ERROR(VERIFY) //校验失败
END_ASYN_IOERROR()

/////////////////////////////////////////////////////////////////////////////////
//ISpeedController.IObjectHolder(lType)
#define CT_SetAppSpeedController        ( 0) //获取/设置内部的ISpeedController
#define CT_GetAppSpeedController        ( 0)

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoOperation.IObjectHolder(lType)
#define OT_SetAsynIoOperation           ( 0) //设置顶级IAsynIoOperation
#define OT_TakeBindIoOperation          ( 0) //获取绑定IAsynIoOperation

#define OT_GetAddrOsBuffer              ( 1) //获取/提取内部地址:Buffer

#define OT_SetAsynIoDevice              ( 2) //设置/提取内部设备:Device
#define OT_GetAsynIoDevice              ( 2)

#define OT_GetMessageEvent              ( 3) //获取内部IAsynMessageEvents

#define OT_GetAppAsynFrame              ( 4)

/////////////////////////////////////////////////////////////////////////////////
////IAsynFrame.IObjectHolder(lType)
#define FT_GetOsMempool                 ( 0) //获取内部IOsMempool
#define FT_SetOsMempool                 ( 0) //设置内部IOsMempool

////IAsynFrame.Add/Pop
#define FF_Checkio                      ( 1)
#define FF_Checkaf                      ( 2)

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoDevice.IObjectHolder(lType)
#define DT_SetRecvSpeedController       ( 0) //设置内部的接收IWinsSpeedController
#define DT_GetRecvSpeedController       ( 0) //获取内部的接收IWinsSpeedController
#define DT_SetSendSpeedController       ( 1) //设置内部的发送IWinsSpeedController
#define DT_GetSendSpeedController       ( 1) //获取内部的发送IWinsSpeedController

#define DT_SetAppRecvSpeedController    ( 2) //设置内部的接收ISpeedController
#define DT_SetAppSendSpeedController    ( 3) //设置内部的发送ISpeedController

#define DT_GetAppAsynFrame              ( 4)

#define DT_GetAsynIoDevice              ( 5) //获取内部IAsynIoDevice

#define DT_GetAsynIoOperationFactory    ( 6) //获取内部IAsynIoOperationFactory

#define DT_GetAsynFrameThread           ( 7) //获取内部IAsynFrameThread[第一个]
#define DT_SetAsynFrameThread           ( 7) //设置内部IAsynFrameThread, 注意: 只有IAsynTcpSocketListener有效

#define DT_SetAsynDnsResolver           ( 8) //获取内部的IAsynDnsResolver
#define DT_GetAsynDnsResolver           ( 8)

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoBridge.IObjectHolder(lType)
#define BT_GetSource                    ( 0) //获取源IAsynIoDevice
#define BT_GetTarget                    ( 1)
#define BT_GetSourceIoOperation         ( 2) //获取读IAsynIoOperation
#define BT_GetTargetIoOperation         ( 3) //获取写IAsynIoOperation

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoOperationFactory.CreateAsynIoOperation(lType)
#define BT_SharedMemoryBuffer           ( 1) //共享内存

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoDevice.Attach(lType)
#define DA_PortHandle                   ( 0) //主动激活句柄
#define DA_PasvHandle                   ( 1) //被动激活句柄

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoDevice.IsOpened(pDeviceName)
#define DN_File                         ("file"    ) //文件
#define DN_Pipe                         ("pipe"    ) //管道
#define DN_Device                       ("device"  ) //设备
#define DN_Socket                       ("socket"  ) //网络套接字
#define DN_Icmp                         ("icmp"    )
#define DN_Tunnel                       ("tunnel"  ) //隧道

/////////////////////////////////////////////////////////////////////////////////
//IAsynFrameThread.BindAsynIoOperation(lMode):以下值可以自由组合
#define BM_Oneway                       (0x00000001) //单向关联:1-只能允许front.cancel事件传递/0-允许front.cancel/self事件传递, 不能跟BM_Result|BM_Calcio|BM_Onlyec联合使用
#define BM_ExBuff                       (0x00000002) //间接引用数据Buffer, SetExtraBuffer(-1, Buffer)
#define BM_Result                       (0x00000004) //拷贝:Result/errors
#define BM_Calcio                       (0x00000008) //计算:IoArea
#define BM_Onlyec                       (0x00000010) //当BM_Onlyec=1时表示不传递Result
#define BM_OsAddr                       (0x00010000) //直接引用地址Buffer
#define BM_IoBuff                       (0x00020000) //直接引用数据Buffer
#define BM_Device                       (0x00040000) //传递:Device
#define BM_Copyio                       (0x00080000) //拷贝:IoArea
#define BM_Nolink                       (0x40000000) //不做关联
#define BM_ResetOptimer                 (0x80000000) //移除Op定时器

/////////////////////////////////////////////////////////////////////////////////
//IAsynIoOperation.GetOsBuffer(index)
#define OB_OsOverlapped                 ( 0) //Overlapped
#define OB_OsAddr                       ( 1) //OsAddr
#define OB_IoArea                       ( 2) //IoArea

#pragma pack(push, 1)
/////////////////////////////////////////////////////////////////////////////////
typedef struct tag_OSBUFFER_IOAREA
{
    uint32_t lTransferedBytes; //完成传输长度(r/w)
    uint32_t lReserved; //可由用户控制，比如传输密文时，设置明文长度(r/w)
    uint32_t lSumBytes; //期望传输长度(r/w)
    uint32_t lMinBytes; //至少传输长度(r/w), 要求lMinBytes<=lSumBytes
    uint32_t lUseIoNum; //(r/w)
    uint32_t lMaxIoNum; //(r)
    STRING  *iovectors; //(r)
} OSBUFFER_IOAREA;
/////////////////////////////////////////////////////////////////////////////////
#pragma pack(pop)

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_ASYNCORE_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)

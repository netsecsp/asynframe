#if !defined(AFX_MEDIA_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
#define AFX_MEDIA_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 01/15/2024
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

#ifdef __cplusplus
extern "C" {
#endif
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libavutil/imgutils.h"
#include "libavutil/frame.h"
#ifdef __cplusplus
}
#endif
#include "../AsynCore.h"
#include "../asm/IMediaFrame.h"
NAMESPACE_BEGIN(asynsdk)

/////////////////////////////////////////////////////////////////////////////////
//IMediaFrame(InstanceName)
#define IN_MediaFrame "com.frame.avmedia"

enum FrameBuffer_FrameID
{
    MFT_Texture = 0, //Texture
    MFT_Bufferp,     //pPacket
    MFT_Bufferf,     //AvFrame
    MFT_Buffers,
};

enum ImageRender_ShowMode
{
    IRM_DoubleScreens = 0, //双屏
    IRM_Fill,              //填充
    IRM_Tile,              //平铺
    IRM_Stretch,           //拉伸
    IRM_Suit,              //适应, 默认值
    IRM_Center,            //居中
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_MEDIA_INTERNAL_H__88966194_6F5D_4303_8670_7EAE695A32B3__INCLUDED_)
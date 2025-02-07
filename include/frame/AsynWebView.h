///////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_WEBVIEW_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)
#define AFX_WEBVIEW_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_
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

#include "AsynCore.h"
#include "asm/IChromeWebView.h"
NAMESPACE_BEGIN(asynsdk)

/////////////////////////////////////////////////////////////////////////////////
//InstanceName
#define IN_WebView "com.frame.webview"

/////////////////////////////////////////////////////////////////////////////////
//edgeproxy[IAsynFramePlugin].events:
//1.AF_EVENT_NOTIFY 0 (4<<32)+result keyval //for webview.initialize: result=0-ok result=1-no

/////////////////////////////////////////////////////////////////////////////////
//edgeproxy[IChromeWebView  ].events:
#define EVENT_ID_WebViewCreateResult         0x1 //AF_EVENT_NOTIFY 1 result ICoreWebView2Controller

#define EVENT_ID_WebViewNavigationStarting   0x2 //AF_EVENT_NOTIFY 2      0                     url
#define EVENT_ID_WebViewSourceChanged        0x3 //AF_EVENT_NOTIFY 3 newdoc                       0
#define EVENT_ID_WebViewDocumentTitleChanged 0x4 //AF_EVENT_NOTIFY 4      0                   title
#define EVENT_ID_WebViewNavigationResult     0x5 //AF_EVENT_NOTIFY 5 result           ICoreWebView2
#define EVENT_ID_WebViewNewWindows           0x6
#define EVENT_ID_WebViewClosed               0x7
#define EVENT_ID_WebViewDialog               0x8
#define EVENT_ID_WebViewPermission           0x9 //AF_QUERY_RESULT 9 pmtype                       0
#define EVENT_ID_WebViewFullScreen           0xa

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_WEBVIEW_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)

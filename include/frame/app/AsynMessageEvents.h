// AsynMessageEvents.h: interface for the CAsynMessageEvents class.
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_ASYNMESSAGEEVENTS_H__B2A00F47_9C06_4B38_8CC1_312322D02E91__INCLUDED_)
#define AFX_ASYNMESSAGEEVENTS_H__B2A00F47_9C06_4B38_8CC1_312322D02E91__INCLUDED_
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

NAMESPACE_BEGIN(asynsdk)

/////////////////////////////////////////////////////////////////////////////////
class asyn_message_events_base
{
public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t message, /*[in]*/uint64_t lparam1, /*[in]*/uint64_t lparam2, /*[in,out]*/IUnknown** objects )
    {
        return E_NOTIMPL;
    }
};

class asyn_message_events_impl : public asyn_message_events_base
{// 注意子类析构前必须主动调用Stop释放资源-强烈建议不要在子类的析构函数里执行Stop
public:
    asyn_message_events_impl(bool safe = true);
    virtual ~asyn_message_events_impl();

public:
    IAsynMessageEvents *GetAsynMessageEvents() { return m_lpAsynMessageEvents;}
    void Reset( /*[in ]*/asyn_message_events_base* c ); //切换回调对象

    void Stop ( /*[in ]*/IAsynFrame* lpAsynFrame = 0 ); //注意释放对象前必须主动调用Stop释放资源

    void CreateAsynFrame( /*[in ]*/IAsynFrameThread* lpAsynFrameThread, /*[in ]*/uint32_t lMaxIdlepools, /*[out]*/IAsynFrame** ppAsynFrame )
    {
        lpAsynFrameThread->CreateAsynFrame(m_lpAsynMessageEvents, lMaxIdlepools, ppAsynFrame);
    }

private:
    IAsynMessageEvents *m_lpAsynMessageEvents; //只读属性
};

/////////////////////////////////////////////////////////////////////////////////
#define DECLARE_ASYN_MESSAGE_MAP(class_name) \
    STDMETHOD(OnMessage)( /*[in]*/uint32_t message, /*[in]*/uint64_t lparam1, /*[in]*/uint64_t lparam2, /*[in,out]*/IUnknown** objects );

#define BEGIN_ASYN_MESSAGE_MAP(class_name) \
    STDMETHODIMP class_name::OnMessage( /*[in]*/uint32_t message, /*[in]*/uint64_t lparam1, /*[in]*/uint64_t lparam2, /*[in,out]*/IUnknown** objects ) \
    { \
        switch(message) {

#define ON_APPID_NOTIFY(memberFxn, T, msgid) \
            case msgid: \
                 return memberFxn( msgid, lparam1, lparam2, objects? (T*)*objects : (T*)0 );

#define ON_QUERY_RESULT(memberFxn, T) \
            case AF_QUERY_RESULT:  \
                 return memberFxn( lparam1, lparam2, (T**)objects );

#define ON_EVENT_NOTIFY(memberFxn, T) \
            case AF_EVENT_NOTIFY:  \
                 memberFxn( lparam1, lparam2, objects? (T*)*objects : (T*)0 ); \
                 return S_OK;

#define ON_IOMSG_NOTIFY(memberFxn) \
            case AF_IOMSG_NOTIFY:  \
                 return memberFxn( lparam1, lparam2, (IAsynIoOperation*)*objects );

#define ON_TIMER(memberFxn) \
            case AF_TIMER:  \
                 return memberFxn( lparam1, lparam2 );

#define END_ASYN_MESSAGE_MAP() \
            default: \
                 return E_NOTIMPL; \
        } \
    }

#define END_ASYN_FORWORD_MAP(pParent) \
            default: \
                 return pParent->OnMessage(message, lparam1, lparam2, objects); \
        } \
    }

/////////////////////////////////////////////////////////////////////////////////
//注意: 使用以下宏定义模块的编译配置页C/C++/常规/调试信息格式设置/Zi，不能使用/ZI，否则报错: error C2051: case expression not constant
//1. 编译配置页C/C++/命令行/附加选项增加/EP。注：/P用于生成.i文件: 检查预展开源码
//2. 尽量是C模式编码, 减少编译错误, 即: 变量声明必须放在crStartP/crStartV之前
#define DECLARE_ASYN_CRSTATE(v)    \
        int _lStatus;

#define crStateV(v)    _lStatus = (v)

#define crStartV(v)    switch(_lStatus) { case v:
#define crFinish(v)    } return (v)

#define crLabelP(v, p) do{ _lStatus = p; return (v); case p:;} while(0)
#define crReturn(v)    crLabelP(v, __LINE__)

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_ASYNMESSAGEEVENTS_H__B2A00F47_9C06_4B38_8CC1_312322D02E91__INCLUDED_)

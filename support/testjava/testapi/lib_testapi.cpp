// lib_testapi.cpp : Implementation of lib Exports.
#include <StdAfx.h>
#include <initguid.h>
#include <frame/jvm/JniProxy.h>

void Call_Testapi_print(const char *text);

LOGGER_IMPLEMENT( logger, "testapi", "Testapi(jvm)");
/////////////////////////////////////////////////////////////////////////////

class CAsynMessageEvents : public asynsdk::CAsynMessageEvents_base
{
public:
    CAsynMessageEvents( /*[in ]*/uint32_t dwRef = 0 )
      : asynsdk::CAsynMessageEvents_base(dwRef)
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
        printf("message=%d, lparam1=%lld, lparam2=%lld, object=%p in testapi, ref=%d\n", message, lparam1, lparam2, objects? objects[0] : 0, m_dwRef);
        Call_Testapi_print("Hello World!!!"); //c->java
        return S_OK;
    }
};

IScriptHost* _g_scripthost = 0;
/////////////////////////////////////////////////////////////////////////////
jobject JNICALL Java_com_demo_Testapi_getEvent(JNIEnv *env, jclass obj)
{
    static CObjPtr<IUnknown> events(new CAsynMessageEvents(0)); //must hold object
    return jvm::Create(env, events, 0, false/*ref*/); //created from java
}

void JNICALL Java_com_demo_Testapi_write(JNIEnv *env, jclass obj, jstring j_text)
{
    const char *text = (char *)env->GetStringUTFChars(j_text, 0);
    LOGGER_INFO(logger, text);
    env->ReleaseStringUTFChars(j_text, text);
}

/////////////////////////////////////////////////////////////////////////////
void Call_Testapi_print(const char *text)
{
    JNIEnv *env;_g_scripthost->AttachCurrentThread(0, (handle*)&env);

    jclass jc_Testapi = env->FindClass("com/demo/Testapi");
    if( jc_Testapi )
    {
        jmethodID jm_Testapi_print = env->GetStaticMethodID(jc_Testapi, "print", "(Ljava/lang/String;)V");
        if( jm_Testapi_print )
        {
            env->CallVoidMethod(jc_Testapi, jm_Testapi_print, env->NewStringUTF(text));
        }
    }

    _g_scripthost->DetachCurrentThread();
}

/////////////////////////////////////////////////////////////////////////////
jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
{
    JNIEnv* env; //注册时在JNIEnv中实现的，所以必须首先获取它
    if( jvm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK )
    {// 从JavaVM获取JNIEnv
        return -1;
    }

    _g_scripthost = jvm::GetScriptHost(env); //get IScriptHost.ref
    #ifdef  _LOG
    #ifndef _LIB
    asynsdk::AsynLogger_Initialize(_g_scripthost );
    #endif
    LOGGER_DEBUG(logger, "1.0 builded in " << __DATE__ << " " << __TIME__);
    #endif

    static const JNINativeMethod methods[] = {
        {"write"   , "(Ljava/lang/String;)V"     , (void*)Java_com_demo_Testapi_write   },
        {"getEvent", "()Lcom/frame/api/CUnknown;", (void*)Java_com_demo_Testapi_getEvent}
    };

    jclass jc_Testapi = env->FindClass("com/demo/Testapi");
    if(!jc_Testapi )
    {
        return -1;
    }

    env->RegisterNatives(jc_Testapi, methods, sizeof(methods) / sizeof(methods[0]));
    return JNI_VERSION_1_4; //必须返回版本，否则jvm认为加载失败。
}

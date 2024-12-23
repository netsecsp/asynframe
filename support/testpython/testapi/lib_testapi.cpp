// lib_testapi.cpp : Implementation of lib Exports.
#ifndef _Using_PYTHON_VERSION
#pragma message("project must define _Using_PYTHON_VERSION=38")
#define _Using_PYTHON_VERSION 38
#endif
#include <frame/python/JniProxy.h>
#pragma comment(lib, "python" xstr(_Using_PYTHON_VERSION) "_dll.lib")

IScriptHost* _g_scripthost = 0;
LOGGER_IMPLEMENT( logger, "testapi", "Testapi(python)");
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
        printf("onMessage: message= %d , lparam1= %lld , lparam2= %lld , object= %p in testapi, ref=%d\n", message, lparam1, lparam2, objects? objects[0] : 0, m_dwRef);
        return S_OK;
    }
};

static PyObject *Testapi_GetEvent(PyObject *self, PyObject *args) {
    static CObjPtr<IUnknown> events(new CAsynMessageEvents(0));
    return python::Create(events, 0, 0, false);
}

static PyObject *Testapi_sum(PyObject *self, PyObject *args) {
    int arg1, arg2, sum;
    if(!PyArg_ParseTuple(args, "ii", &arg1, &arg2))
    {
        return NULL;
    }
    sum = arg1 + arg2;
    printf("call sums: %d + %d = %d\n", arg1, arg2, sum);
    return PyLong_FromLong(sum);
}
 
static PyMethodDef Testapi_Methods[] = {
    {"sum"     , Testapi_sum     , METH_VARARGS, "Calculates the sum of two numbers."},
    {"getEvent", Testapi_GetEvent, METH_VARARGS, "Testapi.getEvent"},
    {NULL, NULL, 0, NULL}
};
 
static struct PyModuleDef Testapi_module = {
    PyModuleDef_HEAD_INIT,
    "testapi",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    Testapi_Methods
};
/////////////////////////////////////////////////////////////////////////////
PyMODINIT_FUNC PyInit_testapi(void) {
    _g_scripthost = python::GetScriptHost(); //get IScriptHost.ref from sys.xvmhost
    #ifdef  _LOG
    #ifndef _LIB
    asynsdk::AsynLogger_Initialize(_g_scripthost );
    #endif
    LOGGER_DEBUG(logger, "1.0 builded in " << __DATE__ << " " << __TIME__);
    #endif

    return PyModule_Create(&Testapi_module);
}
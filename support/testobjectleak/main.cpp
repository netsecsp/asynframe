#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <frame/AsynCore.h>
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>

#ifdef __cplusplus 
extern "C" { 
#endif 
typedef IUnknown* (*FUN_dx_create)(IUnknown*);
#ifdef __cplusplus 
}
#endif

#ifdef _DEBUG
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#else
#pragma comment(lib, "asynsdk_mini-MD.lib")
#endif

#pragma comment(lib, "test-d1.lib")
#pragma comment(lib, "asyncore_dll.lib")

#ifdef __cplusplus 
extern "C" { 
#endif

IUnknown *d1_create(IUnknown *o); //from test-d1.dll

#ifdef __cplusplus 
}
#endif

STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IUnknown *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager*) GetInstancesManager();

//cl main.cpp /D"_LOG" /EHsc /MD /I"..\..\include" -link /LIBPATH:"..\..\lib"

int main(int argc, const char *argv[])
{
	printf("ouput address, object name and file name of the objects be detected when it leaks\n");
	printf("usage:\n");
	printf("\t%s [0|1|2|3]\n\n", argv[0]);

    HRESULT hr1 = Initialize(NULL, NULL);

    {
        InstancesManager *lpInstancesManager = GetInstancesManager();
        #ifdef _LOG
        asynsdk::AsynLogger_Initialize(lpInstancesManager);
        #endif
        printf(" Mm: enter\n");
        /////////////////////////////////////////////////////////////////////////////
        CObjPtr<IUnknown> d1(d1_create(lpInstancesManager), false);
        CObjPtr<IUnknown> d2;
        /////////////////////////////////////////////////////////////////////////////
        printf(" Mm: load test-d2.dll\n");
        HMODULE dx = LoadLibrary("test-d2.dll");
        if( dx )
        {
            FUN_dx_create d2_create = (FUN_dx_create)GetProcAddress(dx, "d2_create");
            if( d2_create ) d2.Attach(d2_create(lpInstancesManager));

            if( argc > 1 && (atoi(argv[1]) & 0x01))
            {
                printf(" Mm: leak d2=%p\n", d2.p);
                d2.Detach();
            }
            else
            {
                d2 = 0;
                printf(" Mm: free test-d2.dll\n");
                FreeLibrary(dx);
            }
        }
        
        {// d1
            if( argc > 1 && (atoi(argv[1]) & 0x02))
            {
                printf(" Mm: leak d1=%p\n", d1.p);
                d1.Detach();
            }
            else
            {
                d1 = 0;
            }
        }
        /////////////////////////////////////////////////////////////////////////////
        printf(" Mm: leave\n");
        #ifdef _LOG
        std::string info;
        if( asynsdk::CObjectsLeakHelper::Dump(0, info))
        {
            printf("\nDetected object leaks!\n%s\n", info.c_str());
        }
        #endif
    }

    Destory();
    return 0;
}
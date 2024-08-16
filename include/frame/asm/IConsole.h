

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Aug 09 20:55:24 2024
 */
/* Compiler settings for IConsole.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IConsole_h__
#define __IConsole_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IConsole_FWD_DEFINED__
#define __IConsole_FWD_DEFINED__
typedef interface IConsole IConsole;

#endif 	/* __IConsole_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IConsole_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IConsole_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IConsole_0000_0000_v0_0_s_ifspec;

#ifndef __IConsole_INTERFACE_DEFINED__
#define __IConsole_INTERFACE_DEFINED__

/* interface IConsole */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConsole;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6D9C9AB-6481-42f4-9AE5-4981A5F2905A")
    IConsole : public IAsynMessageObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AllocWindow( 
            /* [in] */ IAsynFrameThread *thread,
            /* [in] */ STRING title,
            /* [in] */ uint32_t param2,
            /* [in] */ IUnknown *object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ IUnknown *line,
            /* [in] */ handle param1,
            /* [in] */ uint64_t param2) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConsoleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConsole * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConsole * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConsole * This);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IConsole * This,
            /* [in] */ IUnknown *observer,
            /* [in] */ uint64_t subject);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IConsole * This,
            /* [in] */ IUnknown *observer);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            IConsole * This,
            /* [in] */ STRING *subject,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *AllocWindow )( 
            IConsole * This,
            /* [in] */ IAsynFrameThread *thread,
            /* [in] */ STRING title,
            /* [in] */ uint32_t param2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IConsole * This,
            /* [in] */ IUnknown *line,
            /* [in] */ handle param1,
            /* [in] */ uint64_t param2);
        
        END_INTERFACE
    } IConsoleVtbl;

    interface IConsole
    {
        CONST_VTBL struct IConsoleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConsole_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConsole_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConsole_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConsole_Attach(This,observer,subject)	\
    ( (This)->lpVtbl -> Attach(This,observer,subject) ) 

#define IConsole_Detach(This,observer)	\
    ( (This)->lpVtbl -> Detach(This,observer) ) 

#define IConsole_Notify(This,subject,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Notify(This,subject,message,lparam1,lparam2,object) ) 


#define IConsole_AllocWindow(This,thread,title,param2,object)	\
    ( (This)->lpVtbl -> AllocWindow(This,thread,title,param2,object) ) 

#define IConsole_Write(This,line,param1,param2)	\
    ( (This)->lpVtbl -> Write(This,line,param1,param2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConsole_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IConsole_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IConsole_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IConsole_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



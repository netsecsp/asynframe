

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jul 12 17:04:58 2024
 */
/* Compiler settings for IScriptHost.idl:
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

#ifndef __IScriptHost_h__
#define __IScriptHost_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __SObject_FWD_DEFINED__
#define __SObject_FWD_DEFINED__
typedef interface SObject SObject;

#endif 	/* __SObject_FWD_DEFINED__ */


#ifndef __IScriptHost_FWD_DEFINED__
#define __IScriptHost_FWD_DEFINED__
typedef interface IScriptHost IScriptHost;

#endif 	/* __IScriptHost_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IScriptHost_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IScriptHost_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IScriptHost_0000_0000_v0_0_s_ifspec;

#ifndef __SObject_INTERFACE_DEFINED__
#define __SObject_INTERFACE_DEFINED__

/* interface SObject */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_SObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39536006-6C36-4C2D-A222-E6835D3F781B")
    SObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ handle object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [out] */ STRING *pName,
            /* [out] */ handle *object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CastOf( 
            /* [in] */ STRING cName,
            /* [out] */ IUnknown **object) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct SObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            SObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            SObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            SObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            SObject * This,
            /* [in] */ handle object);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            SObject * This,
            /* [out] */ STRING *pName,
            /* [out] */ handle *object);
        
        HRESULT ( STDMETHODCALLTYPE *CastOf )( 
            SObject * This,
            /* [in] */ STRING cName,
            /* [out] */ IUnknown **object);
        
        END_INTERFACE
    } SObjectVtbl;

    interface SObject
    {
        CONST_VTBL struct SObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define SObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define SObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define SObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define SObject_Set(This,object)	\
    ( (This)->lpVtbl -> Set(This,object) ) 

#define SObject_Get(This,pName,object)	\
    ( (This)->lpVtbl -> Get(This,pName,object) ) 

#define SObject_CastOf(This,cName,object)	\
    ( (This)->lpVtbl -> CastOf(This,cName,object) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __SObject_INTERFACE_DEFINED__ */


#ifndef __IScriptHost_INTERFACE_DEFINED__
#define __IScriptHost_INTERFACE_DEFINED__

/* interface IScriptHost */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IScriptHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3427C7EA-00B9-4868-819A-02F01E756A69")
    IScriptHost : public IAsynMessageHolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AttachCurrentThread( 
            /* [in] */ uint32_t unused,
            /* [out] */ handle *env) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DetachCurrentThread( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScriptHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScriptHost * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScriptHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScriptHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScriptHost * This,
            /* [in] */ IThread *thread,
            /* [in] */ IUnknown *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *AttachCurrentThread )( 
            IScriptHost * This,
            /* [in] */ uint32_t unused,
            /* [out] */ handle *env);
        
        HRESULT ( STDMETHODCALLTYPE *DetachCurrentThread )( 
            IScriptHost * This);
        
        END_INTERFACE
    } IScriptHostVtbl;

    interface IScriptHost
    {
        CONST_VTBL struct IScriptHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScriptHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScriptHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScriptHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScriptHost_Invoke(This,thread,events,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Invoke(This,thread,events,message,lparam1,lparam2,object) ) 


#define IScriptHost_AttachCurrentThread(This,unused,env)	\
    ( (This)->lpVtbl -> AttachCurrentThread(This,unused,env) ) 

#define IScriptHost_DetachCurrentThread(This)	\
    ( (This)->lpVtbl -> DetachCurrentThread(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScriptHost_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IScriptHost_0000_0002 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IScriptHost_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IScriptHost_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



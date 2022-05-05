

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 26 17:25:00 2022
 */
/* Compiler settings for IVmHost.idl:
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

#ifndef __IVmHost_h__
#define __IVmHost_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVmHost_FWD_DEFINED__
#define __IVmHost_FWD_DEFINED__
typedef interface IVmHost IVmHost;

#endif 	/* __IVmHost_FWD_DEFINED__ */


/* header files for imported files */
#include "ITypedef.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IVmHost_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IVmHost_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVmHost_0000_0000_v0_0_s_ifspec;

#ifndef __IVmHost_INTERFACE_DEFINED__
#define __IVmHost_INTERFACE_DEFINED__

/* interface IVmHost */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVmHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3427C7EA-00B9-4868-819A-02F01E756A69")
    IVmHost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AttachCurrentThread( 
            /* [in] */ uint32_t params,
            /* [out] */ handle *env) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DetachCurrentThread( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVmHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVmHost * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVmHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVmHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *AttachCurrentThread )( 
            IVmHost * This,
            /* [in] */ uint32_t params,
            /* [out] */ handle *env);
        
        HRESULT ( STDMETHODCALLTYPE *DetachCurrentThread )( 
            IVmHost * This);
        
        END_INTERFACE
    } IVmHostVtbl;

    interface IVmHost
    {
        CONST_VTBL struct IVmHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVmHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVmHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVmHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVmHost_AttachCurrentThread(This,params,env)	\
    ( (This)->lpVtbl -> AttachCurrentThread(This,params,env) ) 

#define IVmHost_DetachCurrentThread(This)	\
    ( (This)->lpVtbl -> DetachCurrentThread(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVmHost_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IVmHost_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IVmHost_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVmHost_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



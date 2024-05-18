

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ITestapi.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0626 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ITestapi_h__
#define __ITestapi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ITestA_FWD_DEFINED__
#define __ITestA_FWD_DEFINED__
typedef interface ITestA ITestA;

#endif 	/* __ITestA_FWD_DEFINED__ */


#ifndef __ITestB_FWD_DEFINED__
#define __ITestB_FWD_DEFINED__
typedef interface ITestB ITestB;

#endif 	/* __ITestB_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ITestapi_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_ITestapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ITestapi_0000_0000_v0_0_s_ifspec;

#ifndef __ITestA_INTERFACE_DEFINED__
#define __ITestA_INTERFACE_DEFINED__

/* interface ITestA */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITestA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4CBCC7DA-A174-418C-874B-173B13EC094C")
    ITestA : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WorkA( 
            /* [in] */ uint32_t index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WorkX( 
            /* [in] */ uint32_t index) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITestAVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestA * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestA * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestA * This);
        
        DECLSPEC_XFGVIRT(ITestA, WorkA)
        HRESULT ( STDMETHODCALLTYPE *WorkA )( 
            ITestA * This,
            /* [in] */ uint32_t index);
        
        DECLSPEC_XFGVIRT(ITestA, WorkX)
        HRESULT ( STDMETHODCALLTYPE *WorkX )( 
            ITestA * This,
            /* [in] */ uint32_t index);
        
        END_INTERFACE
    } ITestAVtbl;

    interface ITestA
    {
        CONST_VTBL struct ITestAVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestA_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITestA_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITestA_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITestA_WorkA(This,index)	\
    ( (This)->lpVtbl -> WorkA(This,index) ) 

#define ITestA_WorkX(This,index)	\
    ( (This)->lpVtbl -> WorkX(This,index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITestA_INTERFACE_DEFINED__ */


#ifndef __ITestB_INTERFACE_DEFINED__
#define __ITestB_INTERFACE_DEFINED__

/* interface ITestB */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITestB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("336A18C3-2393-459B-B071-C039C9D83018")
    ITestB : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WorkB( 
            /* [in] */ uint32_t index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WorkX( 
            /* [in] */ uint32_t index) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITestBVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestB * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestB * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestB * This);
        
        DECLSPEC_XFGVIRT(ITestB, WorkB)
        HRESULT ( STDMETHODCALLTYPE *WorkB )( 
            ITestB * This,
            /* [in] */ uint32_t index);
        
        DECLSPEC_XFGVIRT(ITestB, WorkX)
        HRESULT ( STDMETHODCALLTYPE *WorkX )( 
            ITestB * This,
            /* [in] */ uint32_t index);
        
        END_INTERFACE
    } ITestBVtbl;

    interface ITestB
    {
        CONST_VTBL struct ITestBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITestB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITestB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITestB_WorkB(This,index)	\
    ( (This)->lpVtbl -> WorkB(This,index) ) 

#define ITestB_WorkX(This,index)	\
    ( (This)->lpVtbl -> WorkX(This,index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITestB_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ITestapi_0000_0002 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_ITestapi_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ITestapi_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



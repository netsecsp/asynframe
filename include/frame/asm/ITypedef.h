

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 26 17:24:42 2022
 */
/* Compiler settings for ITypedef.idl:
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

#ifndef __ITypedef_h__
#define __ITypedef_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRangesSetter_FWD_DEFINED__
#define __IRangesSetter_FWD_DEFINED__
typedef interface IRangesSetter IRangesSetter;

#endif 	/* __IRangesSetter_FWD_DEFINED__ */


#ifndef __IStringSetter_FWD_DEFINED__
#define __IStringSetter_FWD_DEFINED__
typedef interface IStringSetter IStringSetter;

#endif 	/* __IStringSetter_FWD_DEFINED__ */


#ifndef __IStringsStack_FWD_DEFINED__
#define __IStringsStack_FWD_DEFINED__
typedef interface IStringsStack IStringsStack;

#endif 	/* __IStringsStack_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ITypedef_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)

typedef void *handle;

typedef struct tagRANGE
    {
    uint64_t len;
    uint64_t pos;
    } 	RANGE;



extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0000_v0_0_s_ifspec;

#ifndef __IRangesSetter_INTERFACE_DEFINED__
#define __IRangesSetter_INTERFACE_DEFINED__

/* interface IRangesSetter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRangesSetter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("864BC6A2-5BDA-4eda-ADD4-B6EBC2BB171D")
    IRangesSetter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [size_is][in] */ RANGE *Val,
            /* [in] */ uint32_t Size) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRangesSetterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRangesSetter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRangesSetter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRangesSetter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IRangesSetter * This,
            /* [size_is][in] */ RANGE *Val,
            /* [in] */ uint32_t Size);
        
        END_INTERFACE
    } IRangesSetterVtbl;

    interface IRangesSetter
    {
        CONST_VTBL struct IRangesSetterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRangesSetter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRangesSetter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRangesSetter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRangesSetter_Set(This,Val,Size)	\
    ( (This)->lpVtbl -> Set(This,Val,Size) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRangesSetter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ITypedef_0000_0001 */
/* [local] */ 

typedef struct tagSTRING
    {
    uint32_t len;
    /* [size_is] */ BYTE *ptr;
    } 	STRING;



extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0001_v0_0_s_ifspec;

#ifndef __IStringSetter_INTERFACE_DEFINED__
#define __IStringSetter_INTERFACE_DEFINED__

/* interface IStringSetter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStringSetter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30044812-451F-4d2a-888C-A3D8222A6FBA")
    IStringSetter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [out] */ STRING *Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ STRING Val) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStringSetterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStringSetter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStringSetter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStringSetter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IStringSetter * This,
            /* [out] */ STRING *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IStringSetter * This,
            /* [in] */ STRING Val);
        
        END_INTERFACE
    } IStringSetterVtbl;

    interface IStringSetter
    {
        CONST_VTBL struct IStringSetterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStringSetter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStringSetter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStringSetter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStringSetter_Get(This,Val)	\
    ( (This)->lpVtbl -> Get(This,Val) ) 

#define IStringSetter_Set(This,Val)	\
    ( (This)->lpVtbl -> Set(This,Val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStringSetter_INTERFACE_DEFINED__ */


#ifndef __IStringsStack_INTERFACE_DEFINED__
#define __IStringsStack_INTERFACE_DEFINED__

/* interface IStringsStack */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStringsStack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24CEF41C-4C1B-499b-B3A4-85119CB98B3A")
    IStringsStack : public IStringSetter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pop( 
            /* [in] */ IStringSetter *Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ STRING Val) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStringsStackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStringsStack * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStringsStack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStringsStack * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IStringsStack * This,
            /* [out] */ STRING *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IStringsStack * This,
            /* [in] */ STRING Val);
        
        HRESULT ( STDMETHODCALLTYPE *Pop )( 
            IStringsStack * This,
            /* [in] */ IStringSetter *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IStringsStack * This,
            /* [in] */ STRING Val);
        
        END_INTERFACE
    } IStringsStackVtbl;

    interface IStringsStack
    {
        CONST_VTBL struct IStringsStackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStringsStack_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStringsStack_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStringsStack_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStringsStack_Get(This,Val)	\
    ( (This)->lpVtbl -> Get(This,Val) ) 

#define IStringsStack_Set(This,Val)	\
    ( (This)->lpVtbl -> Set(This,Val) ) 


#define IStringsStack_Pop(This,Val)	\
    ( (This)->lpVtbl -> Pop(This,Val) ) 

#define IStringsStack_Add(This,Val)	\
    ( (This)->lpVtbl -> Add(This,Val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStringsStack_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ITypedef_0000_0003 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



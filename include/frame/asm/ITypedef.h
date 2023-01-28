

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Jan 28 08:50:42 2023
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

#ifndef __IRangesVector_FWD_DEFINED__
#define __IRangesVector_FWD_DEFINED__
typedef interface IRangesVector IRangesVector;

#endif 	/* __IRangesVector_FWD_DEFINED__ */


#ifndef __IStringSetter_FWD_DEFINED__
#define __IStringSetter_FWD_DEFINED__
typedef interface IStringSetter IStringSetter;

#endif 	/* __IStringSetter_FWD_DEFINED__ */


#ifndef __IStringVector_FWD_DEFINED__
#define __IStringVector_FWD_DEFINED__
typedef interface IStringVector IStringVector;

#endif 	/* __IStringVector_FWD_DEFINED__ */


#ifndef __IStringStack_FWD_DEFINED__
#define __IStringStack_FWD_DEFINED__
typedef interface IStringStack IStringStack;

#endif 	/* __IStringStack_FWD_DEFINED__ */


#ifndef __IKeyvalSetter_FWD_DEFINED__
#define __IKeyvalSetter_FWD_DEFINED__
typedef interface IKeyvalSetter IKeyvalSetter;

#endif 	/* __IKeyvalSetter_FWD_DEFINED__ */


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

#ifndef __IRangesVector_INTERFACE_DEFINED__
#define __IRangesVector_INTERFACE_DEFINED__

/* interface IRangesVector */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRangesVector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("864BC6A2-5BDA-4eda-ADD4-B6EBC2BB171D")
    IRangesVector : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ uint32_t index,
            /* [out] */ RANGE *Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ RANGE Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [size_is][in] */ RANGE *Val,
            /* [in] */ uint32_t Size) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRangesVectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRangesVector * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRangesVector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRangesVector * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IRangesVector * This,
            /* [in] */ uint32_t index,
            /* [out] */ RANGE *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IRangesVector * This,
            /* [in] */ RANGE Val);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IRangesVector * This,
            /* [size_is][in] */ RANGE *Val,
            /* [in] */ uint32_t Size);
        
        END_INTERFACE
    } IRangesVectorVtbl;

    interface IRangesVector
    {
        CONST_VTBL struct IRangesVectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRangesVector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRangesVector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRangesVector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRangesVector_Get(This,index,Val)	\
    ( (This)->lpVtbl -> Get(This,index,Val) ) 

#define IRangesVector_Add(This,Val)	\
    ( (This)->lpVtbl -> Add(This,Val) ) 

#define IRangesVector_Set(This,Val,Size)	\
    ( (This)->lpVtbl -> Set(This,Val,Size) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRangesVector_INTERFACE_DEFINED__ */


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


#ifndef __IStringVector_INTERFACE_DEFINED__
#define __IStringVector_INTERFACE_DEFINED__

/* interface IStringVector */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStringVector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8A6AAB4-0DA2-49C1-8B83-7EF4A916BF16")
    IStringVector : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ uint32_t index,
            /* [out] */ STRING *Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ STRING Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [size_is][in] */ STRING *Val,
            /* [in] */ uint32_t Size) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStringVectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStringVector * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStringVector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStringVector * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IStringVector * This,
            /* [in] */ uint32_t index,
            /* [out] */ STRING *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IStringVector * This,
            /* [in] */ STRING Val);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IStringVector * This,
            /* [size_is][in] */ STRING *Val,
            /* [in] */ uint32_t Size);
        
        END_INTERFACE
    } IStringVectorVtbl;

    interface IStringVector
    {
        CONST_VTBL struct IStringVectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStringVector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStringVector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStringVector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStringVector_Get(This,index,Val)	\
    ( (This)->lpVtbl -> Get(This,index,Val) ) 

#define IStringVector_Add(This,Val)	\
    ( (This)->lpVtbl -> Add(This,Val) ) 

#define IStringVector_Set(This,Val,Size)	\
    ( (This)->lpVtbl -> Set(This,Val,Size) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStringVector_INTERFACE_DEFINED__ */


#ifndef __IStringStack_INTERFACE_DEFINED__
#define __IStringStack_INTERFACE_DEFINED__

/* interface IStringStack */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStringStack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24CEF41C-4C1B-499b-B3A4-85119CB98B3A")
    IStringStack : public IStringSetter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pop( 
            /* [in] */ IStringSetter *Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ STRING Val) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStringStackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStringStack * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStringStack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStringStack * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IStringStack * This,
            /* [out] */ STRING *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IStringStack * This,
            /* [in] */ STRING Val);
        
        HRESULT ( STDMETHODCALLTYPE *Pop )( 
            IStringStack * This,
            /* [in] */ IStringSetter *Val);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IStringStack * This,
            /* [in] */ STRING Val);
        
        END_INTERFACE
    } IStringStackVtbl;

    interface IStringStack
    {
        CONST_VTBL struct IStringStackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStringStack_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStringStack_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStringStack_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStringStack_Get(This,Val)	\
    ( (This)->lpVtbl -> Get(This,Val) ) 

#define IStringStack_Set(This,Val)	\
    ( (This)->lpVtbl -> Set(This,Val) ) 


#define IStringStack_Pop(This,Val)	\
    ( (This)->lpVtbl -> Pop(This,Val) ) 

#define IStringStack_Add(This,Val)	\
    ( (This)->lpVtbl -> Add(This,Val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStringStack_INTERFACE_DEFINED__ */


#ifndef __IKeyvalSetter_INTERFACE_DEFINED__
#define __IKeyvalSetter_INTERFACE_DEFINED__

/* interface IKeyvalSetter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IKeyvalSetter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92552692-3635-4e41-AF63-D921E0CEE6D4")
    IKeyvalSetter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ STRING Key,
            /* [in] */ uint32_t Index,
            /* [in] */ BOOL Remove,
            /* [in] */ IStringSetter *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ STRING Key,
            /* [in] */ BOOL Multi,
            /* [in] */ STRING value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Del( 
            /* [in] */ STRING Key,
            /* [in] */ uint32_t Index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Has( 
            /* [in] */ STRING Key,
            /* [out] */ uint32_t *Count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Format( 
            /* [in] */ STRING Sep,
            /* [in] */ STRING End,
            /* [out][in] */ STRING *out) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Travel( 
            /* [in] */ IUnknown *pParams) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IKeyvalSetterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKeyvalSetter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKeyvalSetter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKeyvalSetter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IKeyvalSetter * This,
            /* [in] */ STRING Key,
            /* [in] */ uint32_t Index,
            /* [in] */ BOOL Remove,
            /* [in] */ IStringSetter *value);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IKeyvalSetter * This,
            /* [in] */ STRING Key,
            /* [in] */ BOOL Multi,
            /* [in] */ STRING value);
        
        HRESULT ( STDMETHODCALLTYPE *Del )( 
            IKeyvalSetter * This,
            /* [in] */ STRING Key,
            /* [in] */ uint32_t Index);
        
        HRESULT ( STDMETHODCALLTYPE *Has )( 
            IKeyvalSetter * This,
            /* [in] */ STRING Key,
            /* [out] */ uint32_t *Count);
        
        HRESULT ( STDMETHODCALLTYPE *Format )( 
            IKeyvalSetter * This,
            /* [in] */ STRING Sep,
            /* [in] */ STRING End,
            /* [out][in] */ STRING *out);
        
        HRESULT ( STDMETHODCALLTYPE *Travel )( 
            IKeyvalSetter * This,
            /* [in] */ IUnknown *pParams);
        
        END_INTERFACE
    } IKeyvalSetterVtbl;

    interface IKeyvalSetter
    {
        CONST_VTBL struct IKeyvalSetterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKeyvalSetter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKeyvalSetter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKeyvalSetter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKeyvalSetter_Get(This,Key,Index,Remove,value)	\
    ( (This)->lpVtbl -> Get(This,Key,Index,Remove,value) ) 

#define IKeyvalSetter_Set(This,Key,Multi,value)	\
    ( (This)->lpVtbl -> Set(This,Key,Multi,value) ) 

#define IKeyvalSetter_Del(This,Key,Index)	\
    ( (This)->lpVtbl -> Del(This,Key,Index) ) 

#define IKeyvalSetter_Has(This,Key,Count)	\
    ( (This)->lpVtbl -> Has(This,Key,Count) ) 

#define IKeyvalSetter_Format(This,Sep,End,out)	\
    ( (This)->lpVtbl -> Format(This,Sep,End,out) ) 

#define IKeyvalSetter_Travel(This,pParams)	\
    ( (This)->lpVtbl -> Travel(This,pParams) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKeyvalSetter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ITypedef_0000_0005 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ITypedef_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



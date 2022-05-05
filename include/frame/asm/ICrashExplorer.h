

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 26 17:24:56 2022
 */
/* Compiler settings for ICrashExplorer.idl:
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

#ifndef __ICrashExplorer_h__
#define __ICrashExplorer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICrashExplorer_FWD_DEFINED__
#define __ICrashExplorer_FWD_DEFINED__
typedef interface ICrashExplorer ICrashExplorer;

#endif 	/* __ICrashExplorer_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ICrashExplorer_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_ICrashExplorer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ICrashExplorer_0000_0000_v0_0_s_ifspec;

#ifndef __ICrashExplorer_INTERFACE_DEFINED__
#define __ICrashExplorer_INTERFACE_DEFINED__

/* interface ICrashExplorer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICrashExplorer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1F4C098C-5615-4623-8EB0-64A012DC7DB4")
    ICrashExplorer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetupThreadExceptTrapper( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DumpStack( 
            /* [in] */ handle hExcptinfo,
            /* [in] */ IAsynMessageEvents *events) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ handle file,
            /* [in] */ handle hExcptinfo,
            /* [in] */ uint32_t type) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICrashExplorerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICrashExplorer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICrashExplorer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICrashExplorer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetupThreadExceptTrapper )( 
            ICrashExplorer * This);
        
        HRESULT ( STDMETHODCALLTYPE *DumpStack )( 
            ICrashExplorer * This,
            /* [in] */ handle hExcptinfo,
            /* [in] */ IAsynMessageEvents *events);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            ICrashExplorer * This,
            /* [in] */ handle file,
            /* [in] */ handle hExcptinfo,
            /* [in] */ uint32_t type);
        
        END_INTERFACE
    } ICrashExplorerVtbl;

    interface ICrashExplorer
    {
        CONST_VTBL struct ICrashExplorerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICrashExplorer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICrashExplorer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICrashExplorer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICrashExplorer_SetupThreadExceptTrapper(This)	\
    ( (This)->lpVtbl -> SetupThreadExceptTrapper(This) ) 

#define ICrashExplorer_DumpStack(This,hExcptinfo,events)	\
    ( (This)->lpVtbl -> DumpStack(This,hExcptinfo,events) ) 

#define ICrashExplorer_Write(This,file,hExcptinfo,type)	\
    ( (This)->lpVtbl -> Write(This,file,hExcptinfo,type) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICrashExplorer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ICrashExplorer_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_ICrashExplorer_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ICrashExplorer_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



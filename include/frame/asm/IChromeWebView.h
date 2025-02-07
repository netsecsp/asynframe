

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Jan 26 14:13:04 2025
 */
/* Compiler settings for IChromeWebView.idl:
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

#ifndef __IChromeWebView_h__
#define __IChromeWebView_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IChromeWebView_FWD_DEFINED__
#define __IChromeWebView_FWD_DEFINED__
typedef interface IChromeWebView IChromeWebView;

#endif 	/* __IChromeWebView_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IChromeWebView_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IChromeWebView_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IChromeWebView_0000_0000_v0_0_s_ifspec;

#ifndef __IChromeWebView_INTERFACE_DEFINED__
#define __IChromeWebView_INTERFACE_DEFINED__

/* interface IChromeWebView */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IChromeWebView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5963DCD6-9DE7-4579-ADE7-C8635069F113")
    IChromeWebView : public IAsynMessageEvents
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetViewSize( 
            /* [out] */ uint32_t *w,
            /* [out] */ uint32_t *h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetViewSize( 
            /* [in] */ uint32_t w,
            /* [in] */ uint32_t h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshPage( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFocus( 
            /* [in] */ BOOL focused) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IChromeWebViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChromeWebView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChromeWebView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChromeWebView * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnMessage )( 
            IChromeWebView * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [out][in] */ IUnknown **object);
        
        HRESULT ( STDMETHODCALLTYPE *GetViewSize )( 
            IChromeWebView * This,
            /* [out] */ uint32_t *w,
            /* [out] */ uint32_t *h);
        
        HRESULT ( STDMETHODCALLTYPE *SetViewSize )( 
            IChromeWebView * This,
            /* [in] */ uint32_t w,
            /* [in] */ uint32_t h);
        
        HRESULT ( STDMETHODCALLTYPE *RefreshPage )( 
            IChromeWebView * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFocus )( 
            IChromeWebView * This,
            /* [in] */ BOOL focused);
        
        END_INTERFACE
    } IChromeWebViewVtbl;

    interface IChromeWebView
    {
        CONST_VTBL struct IChromeWebViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChromeWebView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChromeWebView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChromeWebView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChromeWebView_OnMessage(This,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> OnMessage(This,message,lparam1,lparam2,object) ) 


#define IChromeWebView_GetViewSize(This,w,h)	\
    ( (This)->lpVtbl -> GetViewSize(This,w,h) ) 

#define IChromeWebView_SetViewSize(This,w,h)	\
    ( (This)->lpVtbl -> SetViewSize(This,w,h) ) 

#define IChromeWebView_RefreshPage(This)	\
    ( (This)->lpVtbl -> RefreshPage(This) ) 

#define IChromeWebView_SetFocus(This,focused)	\
    ( (This)->lpVtbl -> SetFocus(This,focused) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChromeWebView_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IChromeWebView_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IChromeWebView_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IChromeWebView_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



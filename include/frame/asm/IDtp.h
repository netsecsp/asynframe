

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 11 09:02:56 2024
 */
/* Compiler settings for IDtp.idl:
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

#ifndef __IDtp_h__
#define __IDtp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDtpService_FWD_DEFINED__
#define __IDtpService_FWD_DEFINED__
typedef interface IDtpService IDtpService;

#endif 	/* __IDtpService_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynNetwork.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IDtp_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IDtp_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IDtp_0000_0000_v0_0_s_ifspec;

#ifndef __IDtpService_INTERFACE_DEFINED__
#define __IDtpService_INTERFACE_DEFINED__

/* interface IDtpService */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDtpService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECA80487-D902-441a-B7DF-52CEE47D13AD")
    IDtpService : public IAppService
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynDtpSocketLayer( 
            /* [in] */ IUnknown *pOwner,
            /* [in] */ uint32_t position,
            /* [in] */ IUnknown *param1,
            /* [in] */ STRING param2,
            /* [out] */ IUnknown **ppObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDtpServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDtpService * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDtpService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDtpService * This);
        
        HRESULT ( STDMETHODCALLTYPE *Control )( 
            IDtpService * This,
            /* [in] */ uint32_t action);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynDtpSocketLayer )( 
            IDtpService * This,
            /* [in] */ IUnknown *pOwner,
            /* [in] */ uint32_t position,
            /* [in] */ IUnknown *param1,
            /* [in] */ STRING param2,
            /* [out] */ IUnknown **ppObject);
        
        END_INTERFACE
    } IDtpServiceVtbl;

    interface IDtpService
    {
        CONST_VTBL struct IDtpServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDtpService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDtpService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDtpService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDtpService_Control(This,action)	\
    ( (This)->lpVtbl -> Control(This,action) ) 


#define IDtpService_CreateAsynDtpSocketLayer(This,pOwner,position,param1,param2,ppObject)	\
    ( (This)->lpVtbl -> CreateAsynDtpSocketLayer(This,pOwner,position,param1,param2,ppObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDtpService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IDtp_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IDtp_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IDtp_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



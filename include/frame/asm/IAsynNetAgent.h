

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 26 17:24:40 2022
 */
/* Compiler settings for IAsynNetAgent.idl:
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

#ifndef __IAsynNetAgent_h__
#define __IAsynNetAgent_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsynNetAgent_FWD_DEFINED__
#define __IAsynNetAgent_FWD_DEFINED__
typedef interface IAsynNetAgent IAsynNetAgent;

#endif 	/* __IAsynNetAgent_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynNetwork.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IAsynNetAgent_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IAsynNetAgent_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynNetAgent_0000_0000_v0_0_s_ifspec;

#ifndef __IAsynNetAgent_INTERFACE_DEFINED__
#define __IAsynNetAgent_INTERFACE_DEFINED__

/* interface IAsynNetAgent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynNetAgent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("68E29861-A676-4b82-803C-785CD0D75D6D")
    IAsynNetAgent : public IAsynMessageEvents
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IAsynRawSocket *pAsynSrcSocket,
            /* [in] */ STRING Protocol,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynNetAgentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynNetAgent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynNetAgent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynNetAgent * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnMessage )( 
            IAsynNetAgent * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [out][in] */ IUnknown **object);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IAsynNetAgent * This,
            /* [in] */ IAsynRawSocket *pAsynSrcSocket,
            /* [in] */ STRING Protocol,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms);
        
        END_INTERFACE
    } IAsynNetAgentVtbl;

    interface IAsynNetAgent
    {
        CONST_VTBL struct IAsynNetAgentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynNetAgent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynNetAgent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynNetAgent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynNetAgent_OnMessage(This,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> OnMessage(This,message,lparam1,lparam2,object) ) 


#define IAsynNetAgent_Connect(This,pAsynSrcSocket,Protocol,pAsynIoOperation,lTimeoutms)	\
    ( (This)->lpVtbl -> Connect(This,pAsynSrcSocket,Protocol,pAsynIoOperation,lTimeoutms) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynNetAgent_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAsynNetAgent_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IAsynNetAgent_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynNetAgent_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



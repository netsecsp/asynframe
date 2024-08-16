

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Aug 09 20:55:29 2024
 */
/* Compiler settings for ISsl.idl:
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

#ifndef __ISsl_h__
#define __ISsl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISsl_FWD_DEFINED__
#define __ISsl_FWD_DEFINED__
typedef interface ISsl ISsl;

#endif 	/* __ISsl_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynNetwork.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ISsl_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_ISsl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISsl_0000_0000_v0_0_s_ifspec;

#ifndef __ISsl_INTERFACE_DEFINED__
#define __ISsl_INTERFACE_DEFINED__

/* interface ISsl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISsl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF55F287-A527-430b-B13A-1CAA21CBB6C1")
    ISsl : public IAsynRawSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCryptContext( 
            /* [in] */ STRING *target,
            /* [in] */ handle pctx,
            /* [in] */ STRING *certandpasswd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VerifyPeerCertificate( 
            /* [in] */ handle pctx,
            /* [in] */ uint32_t flags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISslVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISsl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISsl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISsl * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            ISsl * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            ISsl * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            ISsl * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            ISsl * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            ISsl * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISsl * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISsl * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            ISsl * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            ISsl * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            ISsl * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISsl * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            ISsl * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            ISsl * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            ISsl * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            ISsl * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetCryptContext )( 
            ISsl * This,
            /* [in] */ STRING *target,
            /* [in] */ handle pctx,
            /* [in] */ STRING *certandpasswd);
        
        HRESULT ( STDMETHODCALLTYPE *VerifyPeerCertificate )( 
            ISsl * This,
            /* [in] */ handle pctx,
            /* [in] */ uint32_t flags);
        
        END_INTERFACE
    } ISslVtbl;

    interface ISsl
    {
        CONST_VTBL struct ISslVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISsl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISsl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISsl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISsl_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define ISsl_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define ISsl_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define ISsl_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define ISsl_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define ISsl_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define ISsl_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#define ISsl_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define ISsl_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define ISsl_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define ISsl_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define ISsl_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define ISsl_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define ISsl_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define ISsl_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define ISsl_SetCryptContext(This,target,pctx,certandpasswd)	\
    ( (This)->lpVtbl -> SetCryptContext(This,target,pctx,certandpasswd) ) 

#define ISsl_VerifyPeerCertificate(This,pctx,flags)	\
    ( (This)->lpVtbl -> VerifyPeerCertificate(This,pctx,flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISsl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ISsl_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_ISsl_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISsl_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



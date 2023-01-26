

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Jan 18 10:40:02 2023
 */
/* Compiler settings for IProxy.idl:
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

#ifndef __IProxy_h__
#define __IProxy_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsynProxySocket_FWD_DEFINED__
#define __IAsynProxySocket_FWD_DEFINED__
typedef interface IAsynProxySocket IAsynProxySocket;

#endif 	/* __IAsynProxySocket_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynNetwork.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IProxy_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IProxy_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IProxy_0000_0000_v0_0_s_ifspec;

#ifndef __IAsynProxySocket_INTERFACE_DEFINED__
#define __IAsynProxySocket_INTERFACE_DEFINED__

/* interface IAsynProxySocket */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynProxySocket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3FC5835E-8924-41ac-8631-131A4958B346")
    IAsynProxySocket : public IAsynRawSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProxyContext( 
            /* [in] */ STRING Host,
            /* [in] */ PORT port,
            /* [in] */ STRING Method,
            /* [in] */ IKeyvalSetter *Param2) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynProxySocketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynProxySocket * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynProxySocket * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynProxySocket * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynProxySocket * This,
            /* [in] */ IStringSetter *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynProxySocket * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynProxySocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynProxySocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynProxySocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynProxySocket * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynProxySocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            IAsynProxySocket * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            IAsynProxySocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetProxyContext )( 
            IAsynProxySocket * This,
            /* [in] */ STRING Host,
            /* [in] */ PORT port,
            /* [in] */ STRING Method,
            /* [in] */ IKeyvalSetter *Param2);
        
        END_INTERFACE
    } IAsynProxySocketVtbl;

    interface IAsynProxySocket
    {
        CONST_VTBL struct IAsynProxySocketVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynProxySocket_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynProxySocket_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynProxySocket_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynProxySocket_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynProxySocket_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynProxySocket_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynProxySocket_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynProxySocket_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynProxySocket_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynProxySocket_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynProxySocket_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynProxySocket_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynProxySocket_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynProxySocket_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynProxySocket_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define IAsynProxySocket_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define IAsynProxySocket_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define IAsynProxySocket_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define IAsynProxySocket_SetProxyContext(This,Host,port,Method,Param2)	\
    ( (This)->lpVtbl -> SetProxyContext(This,Host,port,Method,Param2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynProxySocket_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IProxy_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IProxy_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IProxy_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



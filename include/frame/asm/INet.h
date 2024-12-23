

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Nov 15 14:12:35 2024
 */
/* Compiler settings for INet.idl:
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

#ifndef __INet_h__
#define __INet_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INetmsg_FWD_DEFINED__
#define __INetmsg_FWD_DEFINED__
typedef interface INetmsg INetmsg;

#endif 	/* __INetmsg_FWD_DEFINED__ */


#ifndef __INet_FWD_DEFINED__
#define __INet_FWD_DEFINED__
typedef interface INet INet;

#endif 	/* __INet_FWD_DEFINED__ */


#ifndef __IHttpTxTunnel_FWD_DEFINED__
#define __IHttpTxTunnel_FWD_DEFINED__
typedef interface IHttpTxTunnel IHttpTxTunnel;

#endif 	/* __IHttpTxTunnel_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynNetwork.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_INet_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_INet_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_INet_0000_0000_v0_0_s_ifspec;

#ifndef __INetmsg_INTERFACE_DEFINED__
#define __INetmsg_INTERFACE_DEFINED__

/* interface INetmsg */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INetmsg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7A81B83C-2FF2-4bda-A5A6-336AC940F12E")
    INetmsg : public IKeyvalSetter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Getline( 
            /* [out] */ STRING *Method,
            /* [out] */ STRING *Param1,
            /* [out] */ STRING *Param2,
            /* [out] */ BOOL *ack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Setline( 
            /* [in] */ STRING Method,
            /* [in] */ STRING Param1,
            /* [in] */ STRING Param2) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetmsgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetmsg * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetmsg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetmsg * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            INetmsg * This,
            /* [in] */ STRING Key,
            /* [in] */ uint32_t Index,
            /* [in] */ BOOL Remove,
            /* [in] */ IStringSetter *value);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            INetmsg * This,
            /* [in] */ STRING Key,
            /* [in] */ BOOL Multi,
            /* [in] */ STRING value);
        
        HRESULT ( STDMETHODCALLTYPE *Del )( 
            INetmsg * This,
            /* [in] */ STRING Key,
            /* [in] */ uint32_t Index);
        
        HRESULT ( STDMETHODCALLTYPE *Has )( 
            INetmsg * This,
            /* [in] */ STRING Key,
            /* [out] */ uint32_t *Count);
        
        HRESULT ( STDMETHODCALLTYPE *Format )( 
            INetmsg * This,
            /* [in] */ STRING Sep,
            /* [in] */ STRING End,
            /* [out][in] */ STRING *out);
        
        HRESULT ( STDMETHODCALLTYPE *Travel )( 
            INetmsg * This,
            /* [in] */ IUnknown *pParams);
        
        HRESULT ( STDMETHODCALLTYPE *Getline )( 
            INetmsg * This,
            /* [out] */ STRING *Method,
            /* [out] */ STRING *Param1,
            /* [out] */ STRING *Param2,
            /* [out] */ BOOL *ack);
        
        HRESULT ( STDMETHODCALLTYPE *Setline )( 
            INetmsg * This,
            /* [in] */ STRING Method,
            /* [in] */ STRING Param1,
            /* [in] */ STRING Param2);
        
        END_INTERFACE
    } INetmsgVtbl;

    interface INetmsg
    {
        CONST_VTBL struct INetmsgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetmsg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetmsg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetmsg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetmsg_Get(This,Key,Index,Remove,value)	\
    ( (This)->lpVtbl -> Get(This,Key,Index,Remove,value) ) 

#define INetmsg_Set(This,Key,Multi,value)	\
    ( (This)->lpVtbl -> Set(This,Key,Multi,value) ) 

#define INetmsg_Del(This,Key,Index)	\
    ( (This)->lpVtbl -> Del(This,Key,Index) ) 

#define INetmsg_Has(This,Key,Count)	\
    ( (This)->lpVtbl -> Has(This,Key,Count) ) 

#define INetmsg_Format(This,Sep,End,out)	\
    ( (This)->lpVtbl -> Format(This,Sep,End,out) ) 

#define INetmsg_Travel(This,pParams)	\
    ( (This)->lpVtbl -> Travel(This,pParams) ) 


#define INetmsg_Getline(This,Method,Param1,Param2,ack)	\
    ( (This)->lpVtbl -> Getline(This,Method,Param1,Param2,ack) ) 

#define INetmsg_Setline(This,Method,Param1,Param2)	\
    ( (This)->lpVtbl -> Setline(This,Method,Param1,Param2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetmsg_INTERFACE_DEFINED__ */


#ifndef __INet_INTERFACE_DEFINED__
#define __INet_INTERFACE_DEFINED__

/* interface INet */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCA84EA9-CC7F-4d6a-B7E5-7FD443F83BC1")
    INet : public IAsynRawSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendPacket( 
            /* [in] */ STRING Method,
            /* [in] */ STRING Param1,
            /* [in] */ IUnknown *Param2,
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INet * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            INet * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            INet * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            INet * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            INet * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            INet * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            INet * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            INet * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            INet * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            INet * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            INet * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            INet * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            INet * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            INet * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            INet * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            INet * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SendPacket )( 
            INet * This,
            /* [in] */ STRING Method,
            /* [in] */ STRING Param1,
            /* [in] */ IUnknown *Param2,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } INetVtbl;

    interface INet
    {
        CONST_VTBL struct INetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INet_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define INet_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define INet_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define INet_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define INet_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define INet_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define INet_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#define INet_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define INet_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define INet_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define INet_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define INet_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define INet_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define INet_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define INet_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define INet_SendPacket(This,Method,Param1,Param2,pAsynIoOperation)	\
    ( (This)->lpVtbl -> SendPacket(This,Method,Param1,Param2,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INet_INTERFACE_DEFINED__ */


#ifndef __IHttpTxTunnel_INTERFACE_DEFINED__
#define __IHttpTxTunnel_INTERFACE_DEFINED__

/* interface IHttpTxTunnel */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHttpTxTunnel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DFFEA42D-B431-4C7B-876C-D545A4A58EC9")
    IHttpTxTunnel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetEnabled( 
            /* [in] */ uint32_t method) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHttpTxTunnelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpTxTunnel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpTxTunnel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpTxTunnel * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetEnabled )( 
            IHttpTxTunnel * This,
            /* [in] */ uint32_t method);
        
        END_INTERFACE
    } IHttpTxTunnelVtbl;

    interface IHttpTxTunnel
    {
        CONST_VTBL struct IHttpTxTunnelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpTxTunnel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpTxTunnel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpTxTunnel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpTxTunnel_SetEnabled(This,method)	\
    ( (This)->lpVtbl -> SetEnabled(This,method) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpTxTunnel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_INet_0000_0003 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_INet_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_INet_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



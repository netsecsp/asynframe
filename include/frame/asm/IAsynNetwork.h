

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Feb 18 14:07:13 2023
 */
/* Compiler settings for IAsynNetwork.idl:
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

#ifndef __IAsynNetwork_h__
#define __IAsynNetwork_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsynNetIoOperation_FWD_DEFINED__
#define __IAsynNetIoOperation_FWD_DEFINED__
typedef interface IAsynNetIoOperation IAsynNetIoOperation;

#endif 	/* __IAsynNetIoOperation_FWD_DEFINED__ */


#ifndef __IAsynDnsResolver_FWD_DEFINED__
#define __IAsynDnsResolver_FWD_DEFINED__
typedef interface IAsynDnsResolver IAsynDnsResolver;

#endif 	/* __IAsynDnsResolver_FWD_DEFINED__ */


#ifndef __IAsynTcplinkManager_FWD_DEFINED__
#define __IAsynTcplinkManager_FWD_DEFINED__
typedef interface IAsynTcplinkManager IAsynTcplinkManager;

#endif 	/* __IAsynTcplinkManager_FWD_DEFINED__ */


#ifndef __IAsynRawSocket_FWD_DEFINED__
#define __IAsynRawSocket_FWD_DEFINED__
typedef interface IAsynRawSocket IAsynRawSocket;

#endif 	/* __IAsynRawSocket_FWD_DEFINED__ */


#ifndef __IAsynUdpSocket_FWD_DEFINED__
#define __IAsynUdpSocket_FWD_DEFINED__
typedef interface IAsynUdpSocket IAsynUdpSocket;

#endif 	/* __IAsynUdpSocket_FWD_DEFINED__ */


#ifndef __IAsynGrpSocket_FWD_DEFINED__
#define __IAsynGrpSocket_FWD_DEFINED__
typedef interface IAsynGrpSocket IAsynGrpSocket;

#endif 	/* __IAsynGrpSocket_FWD_DEFINED__ */


#ifndef __IAsynTcpSocket_FWD_DEFINED__
#define __IAsynTcpSocket_FWD_DEFINED__
typedef interface IAsynTcpSocket IAsynTcpSocket;

#endif 	/* __IAsynTcpSocket_FWD_DEFINED__ */


#ifndef __IAsynMuxSocket_FWD_DEFINED__
#define __IAsynMuxSocket_FWD_DEFINED__
typedef interface IAsynMuxSocket IAsynMuxSocket;

#endif 	/* __IAsynMuxSocket_FWD_DEFINED__ */


#ifndef __IAsynDtpSocketListener_FWD_DEFINED__
#define __IAsynDtpSocketListener_FWD_DEFINED__
typedef interface IAsynDtpSocketListener IAsynDtpSocketListener;

#endif 	/* __IAsynDtpSocketListener_FWD_DEFINED__ */


#ifndef __IAsynTcpSocketListener_FWD_DEFINED__
#define __IAsynTcpSocketListener_FWD_DEFINED__
typedef interface IAsynTcpSocketListener IAsynTcpSocketListener;

#endif 	/* __IAsynTcpSocketListener_FWD_DEFINED__ */


#ifndef __IAppService_FWD_DEFINED__
#define __IAppService_FWD_DEFINED__
typedef interface IAppService IAppService;

#endif 	/* __IAppService_FWD_DEFINED__ */


#ifndef __IAsynNetwork_FWD_DEFINED__
#define __IAsynNetwork_FWD_DEFINED__
typedef interface IAsynNetwork IAsynNetwork;

#endif 	/* __IAsynNetwork_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IAsynNetwork_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)










typedef USHORT PORT;



extern RPC_IF_HANDLE __MIDL_itf_IAsynNetwork_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynNetwork_0000_0000_v0_0_s_ifspec;

#ifndef __IAsynNetIoOperation_INTERFACE_DEFINED__
#define __IAsynNetIoOperation_INTERFACE_DEFINED__

/* interface IAsynNetIoOperation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynNetIoOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5544D1A8-7C18-4e08-98C2-48522983B3A0")
    IAsynNetIoOperation : public IAsynIoOperation
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPeerAddress( 
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPeerAddress( 
            /* [in] */ BOOL Multi,
            /* [in] */ STRING *Host,
            /* [in] */ BYTE *Addr,
            /* [in] */ PORT Port,
            /* [in] */ uint32_t af) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHost( 
            /* [out] */ STRING *Host) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHost( 
            /* [in] */ STRING Host,
            /* [in] */ BOOL checkipx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPort( 
            /* [out] */ PORT *Port) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPort( 
            /* [in] */ PORT Port) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynNetIoOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynNetIoOperation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynNetIoOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynNetIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetAsynFrameThread )( 
            IAsynNetIoOperation * This,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IAsynNetIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *NewIoBuffer )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lNewBufferSize,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoBuffer )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ IBuffer **ppObject,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoBuffer )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ IBuffer *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetOsBuffer )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpParams )( 
            IAsynNetIoOperation * This,
            /* [out] */ uint32_t *message,
            /* [out] */ uint64_t *pParam1,
            /* [out] */ uint64_t *pParam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParams )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t *pParam1,
            /* [in] */ uint64_t lparam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParam1 )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint64_t lparam1);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoParams )( 
            IAsynNetIoOperation * This,
            /* [out] */ uint32_t *pSumBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParam1 )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t lSumBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParams )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes,
            /* [in] */ uint32_t lSumBytes,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *NewBufferIovectors )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t lCount,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferIovectors )( 
            IAsynNetIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddBufferIovectors )( 
            IAsynNetIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lAddBytes);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBuffers )( 
            IAsynNetIoOperation * This,
            /* [out][in] */ STRING *pSrcIovector,
            /* [out][in] */ uint32_t *count,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IAsynNetIoOperation * This,
            /* [in] */ BOOL bIsDGRAM,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes,
            /* [out] */ uint32_t *pStayBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedResult )( 
            IAsynNetIoOperation * This,
            /* [out] */ uint32_t *pErrorCode,
            /* [out] */ uint32_t *pTransferedBytes,
            /* [out] */ uint32_t *pReservedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedResult )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t lErrorCode);
        
        HRESULT ( STDMETHODCALLTYPE *SetTransferedBytes )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddTransferedBytes )( 
            IAsynNetIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedObject )( 
            IAsynNetIoOperation * This,
            /* [in] */ BOOL bTaked,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedObject )( 
            IAsynNetIoOperation * This,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetPeerAddress )( 
            IAsynNetIoOperation * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *SetPeerAddress )( 
            IAsynNetIoOperation * This,
            /* [in] */ BOOL Multi,
            /* [in] */ STRING *Host,
            /* [in] */ BYTE *Addr,
            /* [in] */ PORT Port,
            /* [in] */ uint32_t af);
        
        HRESULT ( STDMETHODCALLTYPE *GetHost )( 
            IAsynNetIoOperation * This,
            /* [out] */ STRING *Host);
        
        HRESULT ( STDMETHODCALLTYPE *SetHost )( 
            IAsynNetIoOperation * This,
            /* [in] */ STRING Host,
            /* [in] */ BOOL checkipx);
        
        HRESULT ( STDMETHODCALLTYPE *GetPort )( 
            IAsynNetIoOperation * This,
            /* [out] */ PORT *Port);
        
        HRESULT ( STDMETHODCALLTYPE *SetPort )( 
            IAsynNetIoOperation * This,
            /* [in] */ PORT Port);
        
        END_INTERFACE
    } IAsynNetIoOperationVtbl;

    interface IAsynNetIoOperation
    {
        CONST_VTBL struct IAsynNetIoOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynNetIoOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynNetIoOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynNetIoOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynNetIoOperation_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynNetIoOperation_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynNetIoOperation_GetAsynFrameThread(This,ppAsynFrameThread)	\
    ( (This)->lpVtbl -> GetAsynFrameThread(This,ppAsynFrameThread) ) 

#define IAsynNetIoOperation_QueryStatus(This)	\
    ( (This)->lpVtbl -> QueryStatus(This) ) 

#define IAsynNetIoOperation_NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer)	\
    ( (This)->lpVtbl -> NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer) ) 

#define IAsynNetIoOperation_GetIoBuffer(This,index,ppObject,ppBuffer)	\
    ( (This)->lpVtbl -> GetIoBuffer(This,index,ppObject,ppBuffer) ) 

#define IAsynNetIoOperation_SetIoBuffer(This,index,pObject)	\
    ( (This)->lpVtbl -> SetIoBuffer(This,index,pObject) ) 

#define IAsynNetIoOperation_GetOsBuffer(This,index,ppBuffer)	\
    ( (This)->lpVtbl -> GetOsBuffer(This,index,ppBuffer) ) 

#define IAsynNetIoOperation_GetOpParams(This,message,pParam1,pParam2)	\
    ( (This)->lpVtbl -> GetOpParams(This,message,pParam1,pParam2) ) 

#define IAsynNetIoOperation_SetOpParams(This,message,pParam1,lparam2)	\
    ( (This)->lpVtbl -> SetOpParams(This,message,pParam1,lparam2) ) 

#define IAsynNetIoOperation_SetOpParam1(This,lparam1)	\
    ( (This)->lpVtbl -> SetOpParam1(This,lparam1) ) 

#define IAsynNetIoOperation_GetIoParams(This,pSumBytes,pMinBytes)	\
    ( (This)->lpVtbl -> GetIoParams(This,pSumBytes,pMinBytes) ) 

#define IAsynNetIoOperation_SetIoParam1(This,lSumBytes)	\
    ( (This)->lpVtbl -> SetIoParam1(This,lSumBytes) ) 

#define IAsynNetIoOperation_SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes)	\
    ( (This)->lpVtbl -> SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes) ) 

#define IAsynNetIoOperation_NewBufferIovectors(This,lCount,ppBuffer)	\
    ( (This)->lpVtbl -> NewBufferIovectors(This,lCount,ppBuffer) ) 

#define IAsynNetIoOperation_SetBufferIovectors(This,pIovector,lCount,lMinBytes)	\
    ( (This)->lpVtbl -> SetBufferIovectors(This,pIovector,lCount,lMinBytes) ) 

#define IAsynNetIoOperation_AddBufferIovectors(This,pIovector,lCount,lAddBytes)	\
    ( (This)->lpVtbl -> AddBufferIovectors(This,pIovector,lCount,lAddBytes) ) 

#define IAsynNetIoOperation_ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes)	\
    ( (This)->lpVtbl -> ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes) ) 

#define IAsynNetIoOperation_Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes)	\
    ( (This)->lpVtbl -> Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes) ) 

#define IAsynNetIoOperation_GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes)	\
    ( (This)->lpVtbl -> GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes) ) 

#define IAsynNetIoOperation_SetCompletedResult(This,lErrorCode)	\
    ( (This)->lpVtbl -> SetCompletedResult(This,lErrorCode) ) 

#define IAsynNetIoOperation_SetTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> SetTransferedBytes(This,lTransferedBytes) ) 

#define IAsynNetIoOperation_AddTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> AddTransferedBytes(This,lTransferedBytes) ) 

#define IAsynNetIoOperation_GetCompletedObject(This,bTaked,riid,ppObject)	\
    ( (This)->lpVtbl -> GetCompletedObject(This,bTaked,riid,ppObject) ) 

#define IAsynNetIoOperation_SetCompletedObject(This,pObject)	\
    ( (This)->lpVtbl -> SetCompletedObject(This,pObject) ) 


#define IAsynNetIoOperation_GetPeerAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetPeerAddress(This,Host,Addr,Port,af) ) 

#define IAsynNetIoOperation_SetPeerAddress(This,Multi,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> SetPeerAddress(This,Multi,Host,Addr,Port,af) ) 

#define IAsynNetIoOperation_GetHost(This,Host)	\
    ( (This)->lpVtbl -> GetHost(This,Host) ) 

#define IAsynNetIoOperation_SetHost(This,Host,checkipx)	\
    ( (This)->lpVtbl -> SetHost(This,Host,checkipx) ) 

#define IAsynNetIoOperation_GetPort(This,Port)	\
    ( (This)->lpVtbl -> GetPort(This,Port) ) 

#define IAsynNetIoOperation_SetPort(This,Port)	\
    ( (This)->lpVtbl -> SetPort(This,Port) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynNetIoOperation_INTERFACE_DEFINED__ */


#ifndef __IAsynDnsResolver_INTERFACE_DEFINED__
#define __IAsynDnsResolver_INTERFACE_DEFINED__

/* interface IAsynDnsResolver */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynDnsResolver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13C32332-EED4-4701-8644-C2F6E3CCBFE6")
    IAsynDnsResolver : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDnsServer( 
            /* [in] */ STRING svc,
            /* [size_is][in] */ STRING *pHostport,
            /* [in] */ uint32_t Count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ IUnknown *data,
            /* [in] */ uint32_t af) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynDnsResolverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynDnsResolver * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynDnsResolver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynDnsResolver * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDnsServer )( 
            IAsynDnsResolver * This,
            /* [in] */ STRING svc,
            /* [size_is][in] */ STRING *pHostport,
            /* [in] */ uint32_t Count);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IAsynDnsResolver * This,
            /* [in] */ IUnknown *data,
            /* [in] */ uint32_t af);
        
        END_INTERFACE
    } IAsynDnsResolverVtbl;

    interface IAsynDnsResolver
    {
        CONST_VTBL struct IAsynDnsResolverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynDnsResolver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynDnsResolver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynDnsResolver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynDnsResolver_SetDnsServer(This,svc,pHostport,Count)	\
    ( (This)->lpVtbl -> SetDnsServer(This,svc,pHostport,Count) ) 

#define IAsynDnsResolver_Commit(This,data,af)	\
    ( (This)->lpVtbl -> Commit(This,data,af) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynDnsResolver_INTERFACE_DEFINED__ */


#ifndef __IAsynTcplinkManager_INTERFACE_DEFINED__
#define __IAsynTcplinkManager_INTERFACE_DEFINED__

/* interface IAsynTcplinkManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynTcplinkManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11B383C7-EAFE-4766-85C0-69793799B4A3")
    IAsynTcplinkManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [out] */ uint32_t *pCurSynConnects) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ uint32_t lMaxSynConnects) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynTcplinkManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynTcplinkManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynTcplinkManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynTcplinkManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynTcplinkManager * This,
            /* [out] */ uint32_t *pCurSynConnects);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynTcplinkManager * This,
            /* [in] */ uint32_t lMaxSynConnects);
        
        END_INTERFACE
    } IAsynTcplinkManagerVtbl;

    interface IAsynTcplinkManager
    {
        CONST_VTBL struct IAsynTcplinkManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynTcplinkManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynTcplinkManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynTcplinkManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynTcplinkManager_Get(This,pCurSynConnects)	\
    ( (This)->lpVtbl -> Get(This,pCurSynConnects) ) 

#define IAsynTcplinkManager_Set(This,lMaxSynConnects)	\
    ( (This)->lpVtbl -> Set(This,lMaxSynConnects) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynTcplinkManager_INTERFACE_DEFINED__ */


#ifndef __IAsynRawSocket_INTERFACE_DEFINED__
#define __IAsynRawSocket_INTERFACE_DEFINED__

/* interface IAsynRawSocket */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynRawSocket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D7B9AE9-C33A-4d98-B738-596F82044993")
    IAsynRawSocket : public IAsynIoDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSockAddress( 
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSockopt( 
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSockopt( 
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynRawSocketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynRawSocket * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynRawSocket * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynRawSocket * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynRawSocket * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynRawSocket * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynRawSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynRawSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynRawSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynRawSocket * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynRawSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            IAsynRawSocket * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            IAsynRawSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        END_INTERFACE
    } IAsynRawSocketVtbl;

    interface IAsynRawSocket
    {
        CONST_VTBL struct IAsynRawSocketVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynRawSocket_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynRawSocket_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynRawSocket_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynRawSocket_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynRawSocket_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynRawSocket_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynRawSocket_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynRawSocket_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynRawSocket_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynRawSocket_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynRawSocket_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynRawSocket_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynRawSocket_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynRawSocket_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynRawSocket_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define IAsynRawSocket_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define IAsynRawSocket_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define IAsynRawSocket_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynRawSocket_INTERFACE_DEFINED__ */


#ifndef __IAsynUdpSocket_INTERFACE_DEFINED__
#define __IAsynUdpSocket_INTERFACE_DEFINED__

/* interface IAsynUdpSocket */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynUdpSocket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C94171F-82C0-4ccb-A883-76E29C6AEAE2")
    IAsynUdpSocket : public IAsynRawSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Bind( 
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ BOOL bReUseAddr,
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynUdpSocketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynUdpSocket * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynUdpSocket * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynUdpSocket * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynUdpSocket * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynUdpSocket * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynUdpSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynUdpSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynUdpSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynUdpSocket * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynUdpSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            IAsynUdpSocket * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            IAsynUdpSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *Bind )( 
            IAsynUdpSocket * This,
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ BOOL bReUseAddr,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynUdpSocketVtbl;

    interface IAsynUdpSocket
    {
        CONST_VTBL struct IAsynUdpSocketVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynUdpSocket_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynUdpSocket_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynUdpSocket_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynUdpSocket_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynUdpSocket_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynUdpSocket_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynUdpSocket_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynUdpSocket_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynUdpSocket_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynUdpSocket_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynUdpSocket_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynUdpSocket_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynUdpSocket_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynUdpSocket_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynUdpSocket_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define IAsynUdpSocket_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define IAsynUdpSocket_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define IAsynUdpSocket_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define IAsynUdpSocket_Bind(This,Host,Port,bReUseAddr,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Bind(This,Host,Port,bReUseAddr,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynUdpSocket_INTERFACE_DEFINED__ */


#ifndef __IAsynGrpSocket_INTERFACE_DEFINED__
#define __IAsynGrpSocket_INTERFACE_DEFINED__

/* interface IAsynGrpSocket */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynGrpSocket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B9ECE67-CEFA-4283-A07E-DCFF0E8A5986")
    IAsynGrpSocket : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol,
            /* [in] */ uint32_t nttl,
            /* [in] */ BOOL loop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ STRING IHost,
            /* [in] */ STRING MHost) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pop( 
            /* [in] */ STRING IHost,
            /* [in] */ STRING MHost) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynGrpSocketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynGrpSocket * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynGrpSocket * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynGrpSocket * This);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynGrpSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol,
            /* [in] */ uint32_t nttl,
            /* [in] */ BOOL loop);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAsynGrpSocket * This,
            /* [in] */ STRING IHost,
            /* [in] */ STRING MHost);
        
        HRESULT ( STDMETHODCALLTYPE *Pop )( 
            IAsynGrpSocket * This,
            /* [in] */ STRING IHost,
            /* [in] */ STRING MHost);
        
        END_INTERFACE
    } IAsynGrpSocketVtbl;

    interface IAsynGrpSocket
    {
        CONST_VTBL struct IAsynGrpSocketVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynGrpSocket_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynGrpSocket_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynGrpSocket_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynGrpSocket_Open(This,pAsynFrameThread,af,type,protocol,nttl,loop)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol,nttl,loop) ) 

#define IAsynGrpSocket_Add(This,IHost,MHost)	\
    ( (This)->lpVtbl -> Add(This,IHost,MHost) ) 

#define IAsynGrpSocket_Pop(This,IHost,MHost)	\
    ( (This)->lpVtbl -> Pop(This,IHost,MHost) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynGrpSocket_INTERFACE_DEFINED__ */


#ifndef __IAsynTcpSocket_INTERFACE_DEFINED__
#define __IAsynTcpSocket_INTERFACE_DEFINED__

/* interface IAsynTcpSocket */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynTcpSocket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35671780-4E44-4563-A330-2876AEE3A5BB")
    IAsynTcpSocket : public IAsynRawSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ uint32_t Priority,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynTcpSocketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynTcpSocket * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynTcpSocket * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynTcpSocket * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynTcpSocket * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynTcpSocket * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynTcpSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynTcpSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynTcpSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynTcpSocket * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynTcpSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            IAsynTcpSocket * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            IAsynTcpSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IAsynTcpSocket * This,
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ uint32_t Priority,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms);
        
        END_INTERFACE
    } IAsynTcpSocketVtbl;

    interface IAsynTcpSocket
    {
        CONST_VTBL struct IAsynTcpSocketVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynTcpSocket_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynTcpSocket_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynTcpSocket_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynTcpSocket_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynTcpSocket_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynTcpSocket_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynTcpSocket_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynTcpSocket_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynTcpSocket_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynTcpSocket_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynTcpSocket_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynTcpSocket_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynTcpSocket_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynTcpSocket_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynTcpSocket_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define IAsynTcpSocket_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define IAsynTcpSocket_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define IAsynTcpSocket_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define IAsynTcpSocket_Connect(This,Host,Port,Priority,pAsynIoOperation,lTimeoutms)	\
    ( (This)->lpVtbl -> Connect(This,Host,Port,Priority,pAsynIoOperation,lTimeoutms) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynTcpSocket_INTERFACE_DEFINED__ */


#ifndef __IAsynMuxSocket_INTERFACE_DEFINED__
#define __IAsynMuxSocket_INTERFACE_DEFINED__

/* interface IAsynMuxSocket */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynMuxSocket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("85AE4F4C-A618-49fc-9C01-E41E8FE8965E")
    IAsynMuxSocket : public IAsynTcpSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynTcpSocket( 
            /* [in] */ STRING argv,
            /* [out] */ IAsynTcpSocket **ppAsynTcpSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynMuxSocketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynMuxSocket * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynMuxSocket * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynMuxSocket * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynMuxSocket * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynMuxSocket * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynMuxSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynMuxSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynMuxSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynMuxSocket * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynMuxSocket * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            IAsynMuxSocket * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            IAsynMuxSocket * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IAsynMuxSocket * This,
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ uint32_t Priority,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynTcpSocket )( 
            IAsynMuxSocket * This,
            /* [in] */ STRING argv,
            /* [out] */ IAsynTcpSocket **ppAsynTcpSocket);
        
        HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IAsynMuxSocket * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynMuxSocketVtbl;

    interface IAsynMuxSocket
    {
        CONST_VTBL struct IAsynMuxSocketVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynMuxSocket_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynMuxSocket_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynMuxSocket_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynMuxSocket_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynMuxSocket_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynMuxSocket_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynMuxSocket_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynMuxSocket_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynMuxSocket_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynMuxSocket_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynMuxSocket_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynMuxSocket_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynMuxSocket_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynMuxSocket_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynMuxSocket_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define IAsynMuxSocket_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define IAsynMuxSocket_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define IAsynMuxSocket_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define IAsynMuxSocket_Connect(This,Host,Port,Priority,pAsynIoOperation,lTimeoutms)	\
    ( (This)->lpVtbl -> Connect(This,Host,Port,Priority,pAsynIoOperation,lTimeoutms) ) 


#define IAsynMuxSocket_CreateAsynTcpSocket(This,argv,ppAsynTcpSocket)	\
    ( (This)->lpVtbl -> CreateAsynTcpSocket(This,argv,ppAsynTcpSocket) ) 

#define IAsynMuxSocket_Accept(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Accept(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynMuxSocket_INTERFACE_DEFINED__ */


#ifndef __IAsynDtpSocketListener_INTERFACE_DEFINED__
#define __IAsynDtpSocketListener_INTERFACE_DEFINED__

/* interface IAsynDtpSocketListener */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynDtpSocketListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A243506A-6E9C-453c-B556-F0C9619550DE")
    IAsynDtpSocketListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynTcpSocket( 
            /* [in] */ STRING argv,
            /* [out] */ IAsynTcpSocket **ppAsynTcpSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynDtpSocketListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynDtpSocketListener * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynDtpSocketListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynDtpSocketListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynTcpSocket )( 
            IAsynDtpSocketListener * This,
            /* [in] */ STRING argv,
            /* [out] */ IAsynTcpSocket **ppAsynTcpSocket);
        
        HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IAsynDtpSocketListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynDtpSocketListenerVtbl;

    interface IAsynDtpSocketListener
    {
        CONST_VTBL struct IAsynDtpSocketListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynDtpSocketListener_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynDtpSocketListener_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynDtpSocketListener_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynDtpSocketListener_CreateAsynTcpSocket(This,argv,ppAsynTcpSocket)	\
    ( (This)->lpVtbl -> CreateAsynTcpSocket(This,argv,ppAsynTcpSocket) ) 

#define IAsynDtpSocketListener_Accept(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Accept(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynDtpSocketListener_INTERFACE_DEFINED__ */


#ifndef __IAsynTcpSocketListener_INTERFACE_DEFINED__
#define __IAsynTcpSocketListener_INTERFACE_DEFINED__

/* interface IAsynTcpSocketListener */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynTcpSocketListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91AAF082-BA4B-4c28-B042-D3CAB0244E8F")
    IAsynTcpSocketListener : public IAsynRawSocket
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Bind( 
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ BOOL bReUseAddr,
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynTcpSocketListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynTcpSocketListener * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynTcpSocketListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynTcpSocketListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynTcpSocketListener * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynTcpSocketListener * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t af,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t protocol);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockAddress )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IStringSetter *Host,
            /* [out] */ BYTE *Addr,
            /* [out] */ PORT *Port,
            /* [out] */ uint32_t *af);
        
        HRESULT ( STDMETHODCALLTYPE *GetSockopt )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *SetSockopt )( 
            IAsynTcpSocketListener * This,
            /* [in] */ uint32_t type,
            /* [in] */ uint32_t level,
            /* [in] */ uint32_t optname,
            /* [in] */ STRING optval);
        
        HRESULT ( STDMETHODCALLTYPE *Bind )( 
            IAsynTcpSocketListener * This,
            /* [in] */ STRING Host,
            /* [in] */ PORT Port,
            /* [in] */ BOOL bReUseAddr,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IAsynTcpSocketListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynTcpSocketListenerVtbl;

    interface IAsynTcpSocketListener
    {
        CONST_VTBL struct IAsynTcpSocketListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynTcpSocketListener_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynTcpSocketListener_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynTcpSocketListener_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynTcpSocketListener_Get(This,method,lparam,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam,riid,ppObject) ) 

#define IAsynTcpSocketListener_Set(This,method,lparam,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam,pObject) ) 


#define IAsynTcpSocketListener_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynTcpSocketListener_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynTcpSocketListener_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynTcpSocketListener_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynTcpSocketListener_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynTcpSocketListener_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynTcpSocketListener_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynTcpSocketListener_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynTcpSocketListener_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynTcpSocketListener_Open(This,pAsynFrameThread,af,type,protocol)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,af,type,protocol) ) 

#define IAsynTcpSocketListener_GetSockAddress(This,Host,Addr,Port,af)	\
    ( (This)->lpVtbl -> GetSockAddress(This,Host,Addr,Port,af) ) 

#define IAsynTcpSocketListener_GetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> GetSockopt(This,type,level,optname,optval) ) 

#define IAsynTcpSocketListener_SetSockopt(This,type,level,optname,optval)	\
    ( (This)->lpVtbl -> SetSockopt(This,type,level,optname,optval) ) 


#define IAsynTcpSocketListener_Bind(This,Host,Port,bReUseAddr,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Bind(This,Host,Port,bReUseAddr,pAsynIoOperation) ) 

#define IAsynTcpSocketListener_Accept(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Accept(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynTcpSocketListener_INTERFACE_DEFINED__ */


#ifndef __IAppService_INTERFACE_DEFINED__
#define __IAppService_INTERFACE_DEFINED__

/* interface IAppService */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAppService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DFDD78F9-309A-4bb9-97D0-161969B9D192")
    IAppService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Control( 
            /* [in] */ uint32_t action) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAppServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppService * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppService * This);
        
        HRESULT ( STDMETHODCALLTYPE *Control )( 
            IAppService * This,
            /* [in] */ uint32_t action);
        
        END_INTERFACE
    } IAppServiceVtbl;

    interface IAppService
    {
        CONST_VTBL struct IAppServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppService_Control(This,action)	\
    ( (This)->lpVtbl -> Control(This,action) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppService_INTERFACE_DEFINED__ */


#ifndef __IAsynNetwork_INTERFACE_DEFINED__
#define __IAsynNetwork_INTERFACE_DEFINED__

/* interface IAsynNetwork */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynNetwork;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8AA7483F-9A26-4153-A403-C90A49200E73")
    IAsynNetwork : public IAsynIoOperationFactory
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynDnsResolver( 
            /* [in] */ STRING Owner,
            /* [in] */ IUnknown **param1,
            /* [in] */ STRING param2,
            /* [in] */ STRING *etchost,
            /* [out] */ IAsynDnsResolver **ppAsynDnsResolver) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynRawSocket( 
            /* [in] */ uint32_t lType,
            /* [out] */ IAsynRawSocket **ppAsynRawSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynUdpSocket( 
            /* [out] */ IAsynUdpSocket **ppAsynUdpSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynTcpSocket( 
            /* [out] */ IAsynTcpSocket **ppAsynTcpSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynTcpSocketListener( 
            /* [in] */ IUnknown *unused,
            /* [out] */ IAsynTcpSocketListener **ppAsynTcpSocketListener) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynPtlSocket( 
            /* [in] */ STRING Owner,
            /* [in] */ IUnknown **param1,
            /* [in] */ STRING param2,
            /* [out] */ IAsynRawSocket **ppAsynRawSocket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAppService( 
            /* [in] */ STRING Owner,
            /* [in] */ IUnknown **param1,
            /* [in] */ STRING param2,
            /* [in] */ IAsynMessageEvents *events,
            /* [out] */ IAppService **ppAppService) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumLocalAddress( 
            /* [in] */ uint32_t iaf,
            /* [in] */ IStringVector *output) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynNetworkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynNetwork * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynNetwork * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynNetwork * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIoOperation )( 
            IAsynNetwork * This,
            /* [in] */ IAsynFrame *pAsynFrame,
            /* [in] */ uint32_t param1,
            /* [in] */ uint32_t param2,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynDnsResolver )( 
            IAsynNetwork * This,
            /* [in] */ STRING Owner,
            /* [in] */ IUnknown **param1,
            /* [in] */ STRING param2,
            /* [in] */ STRING *etchost,
            /* [out] */ IAsynDnsResolver **ppAsynDnsResolver);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynRawSocket )( 
            IAsynNetwork * This,
            /* [in] */ uint32_t lType,
            /* [out] */ IAsynRawSocket **ppAsynRawSocket);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynUdpSocket )( 
            IAsynNetwork * This,
            /* [out] */ IAsynUdpSocket **ppAsynUdpSocket);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynTcpSocket )( 
            IAsynNetwork * This,
            /* [out] */ IAsynTcpSocket **ppAsynTcpSocket);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynTcpSocketListener )( 
            IAsynNetwork * This,
            /* [in] */ IUnknown *unused,
            /* [out] */ IAsynTcpSocketListener **ppAsynTcpSocketListener);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynPtlSocket )( 
            IAsynNetwork * This,
            /* [in] */ STRING Owner,
            /* [in] */ IUnknown **param1,
            /* [in] */ STRING param2,
            /* [out] */ IAsynRawSocket **ppAsynRawSocket);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAppService )( 
            IAsynNetwork * This,
            /* [in] */ STRING Owner,
            /* [in] */ IUnknown **param1,
            /* [in] */ STRING param2,
            /* [in] */ IAsynMessageEvents *events,
            /* [out] */ IAppService **ppAppService);
        
        HRESULT ( STDMETHODCALLTYPE *EnumLocalAddress )( 
            IAsynNetwork * This,
            /* [in] */ uint32_t iaf,
            /* [in] */ IStringVector *output);
        
        END_INTERFACE
    } IAsynNetworkVtbl;

    interface IAsynNetwork
    {
        CONST_VTBL struct IAsynNetworkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynNetwork_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynNetwork_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynNetwork_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynNetwork_CreateAsynIoOperation(This,pAsynFrame,param1,param2,riid,ppObject)	\
    ( (This)->lpVtbl -> CreateAsynIoOperation(This,pAsynFrame,param1,param2,riid,ppObject) ) 


#define IAsynNetwork_CreateAsynDnsResolver(This,Owner,param1,param2,etchost,ppAsynDnsResolver)	\
    ( (This)->lpVtbl -> CreateAsynDnsResolver(This,Owner,param1,param2,etchost,ppAsynDnsResolver) ) 

#define IAsynNetwork_CreateAsynRawSocket(This,lType,ppAsynRawSocket)	\
    ( (This)->lpVtbl -> CreateAsynRawSocket(This,lType,ppAsynRawSocket) ) 

#define IAsynNetwork_CreateAsynUdpSocket(This,ppAsynUdpSocket)	\
    ( (This)->lpVtbl -> CreateAsynUdpSocket(This,ppAsynUdpSocket) ) 

#define IAsynNetwork_CreateAsynTcpSocket(This,ppAsynTcpSocket)	\
    ( (This)->lpVtbl -> CreateAsynTcpSocket(This,ppAsynTcpSocket) ) 

#define IAsynNetwork_CreateAsynTcpSocketListener(This,unused,ppAsynTcpSocketListener)	\
    ( (This)->lpVtbl -> CreateAsynTcpSocketListener(This,unused,ppAsynTcpSocketListener) ) 

#define IAsynNetwork_CreateAsynPtlSocket(This,Owner,param1,param2,ppAsynRawSocket)	\
    ( (This)->lpVtbl -> CreateAsynPtlSocket(This,Owner,param1,param2,ppAsynRawSocket) ) 

#define IAsynNetwork_CreateAppService(This,Owner,param1,param2,events,ppAppService)	\
    ( (This)->lpVtbl -> CreateAppService(This,Owner,param1,param2,events,ppAppService) ) 

#define IAsynNetwork_EnumLocalAddress(This,iaf,output)	\
    ( (This)->lpVtbl -> EnumLocalAddress(This,iaf,output) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynNetwork_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAsynNetwork_0000_0012 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IAsynNetwork_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynNetwork_0000_0012_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



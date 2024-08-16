

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Aug 09 20:55:18 2024
 */
/* Compiler settings for IAsynIpcChannel.idl:
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

#ifndef __IAsynIpcChannel_h__
#define __IAsynIpcChannel_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsynIpcIoOperation_FWD_DEFINED__
#define __IAsynIpcIoOperation_FWD_DEFINED__
typedef interface IAsynIpcIoOperation IAsynIpcIoOperation;

#endif 	/* __IAsynIpcIoOperation_FWD_DEFINED__ */


#ifndef __IAsynNamedPipe_FWD_DEFINED__
#define __IAsynNamedPipe_FWD_DEFINED__
typedef interface IAsynNamedPipe IAsynNamedPipe;

#endif 	/* __IAsynNamedPipe_FWD_DEFINED__ */


#ifndef __IAsynIpcDevice_FWD_DEFINED__
#define __IAsynIpcDevice_FWD_DEFINED__
typedef interface IAsynIpcDevice IAsynIpcDevice;

#endif 	/* __IAsynIpcDevice_FWD_DEFINED__ */


#ifndef __IAsynIpcDeviceListener_FWD_DEFINED__
#define __IAsynIpcDeviceListener_FWD_DEFINED__
typedef interface IAsynIpcDeviceListener IAsynIpcDeviceListener;

#endif 	/* __IAsynIpcDeviceListener_FWD_DEFINED__ */


#ifndef __IAsynIpcChannel_FWD_DEFINED__
#define __IAsynIpcChannel_FWD_DEFINED__
typedef interface IAsynIpcChannel IAsynIpcChannel;

#endif 	/* __IAsynIpcChannel_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFileSystem.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IAsynIpcChannel_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)





extern RPC_IF_HANDLE __MIDL_itf_IAsynIpcChannel_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynIpcChannel_0000_0000_v0_0_s_ifspec;

#ifndef __IAsynIpcIoOperation_INTERFACE_DEFINED__
#define __IAsynIpcIoOperation_INTERFACE_DEFINED__

/* interface IAsynIpcIoOperation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIpcIoOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("63A88D82-1EB4-45a1-847D-0F2AE3D54D06")
    IAsynIpcIoOperation : public IAsynIoOperation
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPeerAddress( 
            /* [in] */ IStringSetter *Name,
            /* [out] */ uint32_t *pid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPeerAddress( 
            /* [in] */ STRING Name,
            /* [in] */ uint32_t pid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIpcIoOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIpcIoOperation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIpcIoOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIpcIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynIpcIoOperation * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynIpcIoOperation * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetAsynFrameThread )( 
            IAsynIpcIoOperation * This,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IAsynIpcIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *NewIoBuffer )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lNewBufferSize,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoBuffer )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ IBuffer **ppObject,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoBuffer )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ IBuffer *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetOsBuffer )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpParams )( 
            IAsynIpcIoOperation * This,
            /* [out] */ uint32_t *message,
            /* [out] */ uint64_t *pParam1,
            /* [out] */ uint64_t *pParam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParams )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t *pParam1,
            /* [in] */ uint64_t lparam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParam1 )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint64_t lparam1);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoParams )( 
            IAsynIpcIoOperation * This,
            /* [out] */ uint32_t *pSumBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParam1 )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t lSumBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParams )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes,
            /* [in] */ uint32_t lSumBytes,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *NewBufferIovectors )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t lCount,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferIovectors )( 
            IAsynIpcIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddBufferIovectors )( 
            IAsynIpcIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lAddBytes);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBuffers )( 
            IAsynIpcIoOperation * This,
            /* [out][in] */ STRING *pSrcIovector,
            /* [out][in] */ uint32_t *count,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IAsynIpcIoOperation * This,
            /* [in] */ BOOL bIsDGRAM,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes,
            /* [out] */ uint32_t *pStayBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedResult )( 
            IAsynIpcIoOperation * This,
            /* [out] */ uint32_t *pErrorCode,
            /* [out] */ uint32_t *pTransferedBytes,
            /* [out] */ uint32_t *pReservedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedResult )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t lErrorCode);
        
        HRESULT ( STDMETHODCALLTYPE *SetTransferedBytes )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddTransferedBytes )( 
            IAsynIpcIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedObject )( 
            IAsynIpcIoOperation * This,
            /* [in] */ BOOL bTaked,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedObject )( 
            IAsynIpcIoOperation * This,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetPeerAddress )( 
            IAsynIpcIoOperation * This,
            /* [in] */ IStringSetter *Name,
            /* [out] */ uint32_t *pid);
        
        HRESULT ( STDMETHODCALLTYPE *SetPeerAddress )( 
            IAsynIpcIoOperation * This,
            /* [in] */ STRING Name,
            /* [in] */ uint32_t pid);
        
        END_INTERFACE
    } IAsynIpcIoOperationVtbl;

    interface IAsynIpcIoOperation
    {
        CONST_VTBL struct IAsynIpcIoOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIpcIoOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIpcIoOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIpcIoOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIpcIoOperation_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynIpcIoOperation_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynIpcIoOperation_GetAsynFrameThread(This,ppAsynFrameThread)	\
    ( (This)->lpVtbl -> GetAsynFrameThread(This,ppAsynFrameThread) ) 

#define IAsynIpcIoOperation_QueryStatus(This)	\
    ( (This)->lpVtbl -> QueryStatus(This) ) 

#define IAsynIpcIoOperation_NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer)	\
    ( (This)->lpVtbl -> NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer) ) 

#define IAsynIpcIoOperation_GetIoBuffer(This,index,ppObject,ppBuffer)	\
    ( (This)->lpVtbl -> GetIoBuffer(This,index,ppObject,ppBuffer) ) 

#define IAsynIpcIoOperation_SetIoBuffer(This,index,pObject)	\
    ( (This)->lpVtbl -> SetIoBuffer(This,index,pObject) ) 

#define IAsynIpcIoOperation_GetOsBuffer(This,index,ppBuffer)	\
    ( (This)->lpVtbl -> GetOsBuffer(This,index,ppBuffer) ) 

#define IAsynIpcIoOperation_GetOpParams(This,message,pParam1,pParam2)	\
    ( (This)->lpVtbl -> GetOpParams(This,message,pParam1,pParam2) ) 

#define IAsynIpcIoOperation_SetOpParams(This,message,pParam1,lparam2)	\
    ( (This)->lpVtbl -> SetOpParams(This,message,pParam1,lparam2) ) 

#define IAsynIpcIoOperation_SetOpParam1(This,lparam1)	\
    ( (This)->lpVtbl -> SetOpParam1(This,lparam1) ) 

#define IAsynIpcIoOperation_GetIoParams(This,pSumBytes,pMinBytes)	\
    ( (This)->lpVtbl -> GetIoParams(This,pSumBytes,pMinBytes) ) 

#define IAsynIpcIoOperation_SetIoParam1(This,lSumBytes)	\
    ( (This)->lpVtbl -> SetIoParam1(This,lSumBytes) ) 

#define IAsynIpcIoOperation_SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes)	\
    ( (This)->lpVtbl -> SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes) ) 

#define IAsynIpcIoOperation_NewBufferIovectors(This,lCount,ppBuffer)	\
    ( (This)->lpVtbl -> NewBufferIovectors(This,lCount,ppBuffer) ) 

#define IAsynIpcIoOperation_SetBufferIovectors(This,pIovector,lCount,lMinBytes)	\
    ( (This)->lpVtbl -> SetBufferIovectors(This,pIovector,lCount,lMinBytes) ) 

#define IAsynIpcIoOperation_AddBufferIovectors(This,pIovector,lCount,lAddBytes)	\
    ( (This)->lpVtbl -> AddBufferIovectors(This,pIovector,lCount,lAddBytes) ) 

#define IAsynIpcIoOperation_ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes)	\
    ( (This)->lpVtbl -> ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes) ) 

#define IAsynIpcIoOperation_Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes)	\
    ( (This)->lpVtbl -> Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes) ) 

#define IAsynIpcIoOperation_GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes)	\
    ( (This)->lpVtbl -> GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes) ) 

#define IAsynIpcIoOperation_SetCompletedResult(This,lErrorCode)	\
    ( (This)->lpVtbl -> SetCompletedResult(This,lErrorCode) ) 

#define IAsynIpcIoOperation_SetTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> SetTransferedBytes(This,lTransferedBytes) ) 

#define IAsynIpcIoOperation_AddTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> AddTransferedBytes(This,lTransferedBytes) ) 

#define IAsynIpcIoOperation_GetCompletedObject(This,bTaked,riid,ppObject)	\
    ( (This)->lpVtbl -> GetCompletedObject(This,bTaked,riid,ppObject) ) 

#define IAsynIpcIoOperation_SetCompletedObject(This,pObject)	\
    ( (This)->lpVtbl -> SetCompletedObject(This,pObject) ) 


#define IAsynIpcIoOperation_GetPeerAddress(This,Name,pid)	\
    ( (This)->lpVtbl -> GetPeerAddress(This,Name,pid) ) 

#define IAsynIpcIoOperation_SetPeerAddress(This,Name,pid)	\
    ( (This)->lpVtbl -> SetPeerAddress(This,Name,pid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIpcIoOperation_INTERFACE_DEFINED__ */


#ifndef __IAsynNamedPipe_INTERFACE_DEFINED__
#define __IAsynNamedPipe_INTERFACE_DEFINED__

/* interface IAsynNamedPipe */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynNamedPipe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("852F8BD3-2CC0-40c4-8156-6AF0735FFCBD")
    IAsynNamedPipe : public IAsynIoDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING PipeName,
            /* [in] */ uint32_t lOpenMode,
            /* [in] */ BOOL bIsStream,
            /* [in] */ uint32_t lMaxInstances,
            /* [in] */ uint32_t lOutBufferSize,
            /* [in] */ uint32_t lInBufferSize,
            /* [in] */ uint32_t lDefaultTimeOut,
            /* [in] */ handle pSecurityAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynNamedPipeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynNamedPipe * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynNamedPipe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynNamedPipe * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynNamedPipe * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynNamedPipe * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynNamedPipe * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynNamedPipe * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynNamedPipe * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynNamedPipe * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynNamedPipe * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynNamedPipe * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynNamedPipe * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynNamedPipe * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynNamedPipe * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynNamedPipe * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING PipeName,
            /* [in] */ uint32_t lOpenMode,
            /* [in] */ BOOL bIsStream,
            /* [in] */ uint32_t lMaxInstances,
            /* [in] */ uint32_t lOutBufferSize,
            /* [in] */ uint32_t lInBufferSize,
            /* [in] */ uint32_t lDefaultTimeOut,
            /* [in] */ handle pSecurityAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IAsynNamedPipe * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynNamedPipeVtbl;

    interface IAsynNamedPipe
    {
        CONST_VTBL struct IAsynNamedPipeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynNamedPipe_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynNamedPipe_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynNamedPipe_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynNamedPipe_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynNamedPipe_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynNamedPipe_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynNamedPipe_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynNamedPipe_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynNamedPipe_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynNamedPipe_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#define IAsynNamedPipe_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynNamedPipe_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynNamedPipe_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynNamedPipe_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynNamedPipe_Open(This,pAsynFrameThread,PipeName,lOpenMode,bIsStream,lMaxInstances,lOutBufferSize,lInBufferSize,lDefaultTimeOut,pSecurityAttributes)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,PipeName,lOpenMode,bIsStream,lMaxInstances,lOutBufferSize,lInBufferSize,lDefaultTimeOut,pSecurityAttributes) ) 

#define IAsynNamedPipe_Accept(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Accept(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynNamedPipe_INTERFACE_DEFINED__ */


#ifndef __IAsynIpcDevice_INTERFACE_DEFINED__
#define __IAsynIpcDevice_INTERFACE_DEFINED__

/* interface IAsynIpcDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIpcDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EB387F4A-854B-41f2-B92A-0C80E2E44515")
    IAsynIpcDevice : public IAsynIoDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING IpcName,
            /* [in] */ uint32_t lDstProcessId,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIpcDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIpcDevice * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIpcDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIpcDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynIpcDevice * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynIpcDevice * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynIpcDevice * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynIpcDevice * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynIpcDevice * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynIpcDevice * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynIpcDevice * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynIpcDevice * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynIpcDevice * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynIpcDevice * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynIpcDevice * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IAsynIpcDevice * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING IpcName,
            /* [in] */ uint32_t lDstProcessId,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint32_t lTimeoutms);
        
        END_INTERFACE
    } IAsynIpcDeviceVtbl;

    interface IAsynIpcDevice
    {
        CONST_VTBL struct IAsynIpcDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIpcDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIpcDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIpcDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIpcDevice_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynIpcDevice_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynIpcDevice_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynIpcDevice_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynIpcDevice_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynIpcDevice_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynIpcDevice_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#define IAsynIpcDevice_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynIpcDevice_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynIpcDevice_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynIpcDevice_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynIpcDevice_Connect(This,pAsynFrameThread,IpcName,lDstProcessId,pAsynIoOperation,lTimeoutms)	\
    ( (This)->lpVtbl -> Connect(This,pAsynFrameThread,IpcName,lDstProcessId,pAsynIoOperation,lTimeoutms) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIpcDevice_INTERFACE_DEFINED__ */


#ifndef __IAsynIpcDeviceListener_INTERFACE_DEFINED__
#define __IAsynIpcDeviceListener_INTERFACE_DEFINED__

/* interface IAsynIpcDeviceListener */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIpcDeviceListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9ED3FDED-C662-4d3c-A951-29E7FDEDADAF")
    IAsynIpcDeviceListener : public IAsynIoDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING IpcName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIpcDeviceListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIpcDeviceListener * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIpcDeviceListener * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynIpcDeviceListener * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynIpcDeviceListener * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING IpcName);
        
        HRESULT ( STDMETHODCALLTYPE *Accept )( 
            IAsynIpcDeviceListener * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynIpcDeviceListenerVtbl;

    interface IAsynIpcDeviceListener
    {
        CONST_VTBL struct IAsynIpcDeviceListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIpcDeviceListener_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIpcDeviceListener_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIpcDeviceListener_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIpcDeviceListener_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynIpcDeviceListener_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynIpcDeviceListener_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynIpcDeviceListener_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynIpcDeviceListener_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynIpcDeviceListener_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynIpcDeviceListener_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#define IAsynIpcDeviceListener_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynIpcDeviceListener_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynIpcDeviceListener_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynIpcDeviceListener_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynIpcDeviceListener_Open(This,pAsynFrameThread,IpcName)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,IpcName) ) 

#define IAsynIpcDeviceListener_Accept(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Accept(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIpcDeviceListener_INTERFACE_DEFINED__ */


#ifndef __IAsynIpcChannel_INTERFACE_DEFINED__
#define __IAsynIpcChannel_INTERFACE_DEFINED__

/* interface IAsynIpcChannel */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIpcChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D453C04E-A8E6-4d8d-B024-442365E86B85")
    IAsynIpcChannel : public IAsynIoOperationFactory
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynNamedPipe( 
            /* [out] */ IAsynNamedPipe **ppAsynNamedPipe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynIpcDevice( 
            /* [out] */ IAsynIpcDevice **ppAsynIpcDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynIpcDeviceListener( 
            /* [in] */ STRING argv,
            /* [out] */ IAsynIpcDeviceListener **ppAsynIpcDeviceListener) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIpcChannelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIpcChannel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIpcChannel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIpcChannel * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIoOperation )( 
            IAsynIpcChannel * This,
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint32_t param1,
            /* [in] */ uint32_t param2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynNamedPipe )( 
            IAsynIpcChannel * This,
            /* [out] */ IAsynNamedPipe **ppAsynNamedPipe);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIpcDevice )( 
            IAsynIpcChannel * This,
            /* [out] */ IAsynIpcDevice **ppAsynIpcDevice);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIpcDeviceListener )( 
            IAsynIpcChannel * This,
            /* [in] */ STRING argv,
            /* [out] */ IAsynIpcDeviceListener **ppAsynIpcDeviceListener);
        
        END_INTERFACE
    } IAsynIpcChannelVtbl;

    interface IAsynIpcChannel
    {
        CONST_VTBL struct IAsynIpcChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIpcChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIpcChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIpcChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIpcChannel_CreateAsynIoOperation(This,pdatas,param1,param2,riid,ppObject)	\
    ( (This)->lpVtbl -> CreateAsynIoOperation(This,pdatas,param1,param2,riid,ppObject) ) 


#define IAsynIpcChannel_CreateAsynNamedPipe(This,ppAsynNamedPipe)	\
    ( (This)->lpVtbl -> CreateAsynNamedPipe(This,ppAsynNamedPipe) ) 

#define IAsynIpcChannel_CreateAsynIpcDevice(This,ppAsynIpcDevice)	\
    ( (This)->lpVtbl -> CreateAsynIpcDevice(This,ppAsynIpcDevice) ) 

#define IAsynIpcChannel_CreateAsynIpcDeviceListener(This,argv,ppAsynIpcDeviceListener)	\
    ( (This)->lpVtbl -> CreateAsynIpcDeviceListener(This,argv,ppAsynIpcDeviceListener) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIpcChannel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAsynIpcChannel_0000_0005 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IAsynIpcChannel_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynIpcChannel_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



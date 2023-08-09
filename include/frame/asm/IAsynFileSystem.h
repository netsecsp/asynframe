

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Aug 07 11:29:47 2023
 */
/* Compiler settings for IAsynFileSystem.idl:
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

#ifndef __IAsynFileSystem_h__
#define __IAsynFileSystem_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsynFileIoOperation_FWD_DEFINED__
#define __IAsynFileIoOperation_FWD_DEFINED__
typedef interface IAsynFileIoOperation IAsynFileIoOperation;

#endif 	/* __IAsynFileIoOperation_FWD_DEFINED__ */


#ifndef __IAsynRawDevice_FWD_DEFINED__
#define __IAsynRawDevice_FWD_DEFINED__
typedef interface IAsynRawDevice IAsynRawDevice;

#endif 	/* __IAsynRawDevice_FWD_DEFINED__ */


#ifndef __IAsynFile_FWD_DEFINED__
#define __IAsynFile_FWD_DEFINED__
typedef interface IAsynFile IAsynFile;

#endif 	/* __IAsynFile_FWD_DEFINED__ */


#ifndef __IAsynFileWatcher_FWD_DEFINED__
#define __IAsynFileWatcher_FWD_DEFINED__
typedef interface IAsynFileWatcher IAsynFileWatcher;

#endif 	/* __IAsynFileWatcher_FWD_DEFINED__ */


#ifndef __IAsynFileSystem_FWD_DEFINED__
#define __IAsynFileSystem_FWD_DEFINED__
typedef interface IAsynFileSystem IAsynFileSystem;

#endif 	/* __IAsynFileSystem_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IAsynFileSystem_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)





extern RPC_IF_HANDLE __MIDL_itf_IAsynFileSystem_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynFileSystem_0000_0000_v0_0_s_ifspec;

#ifndef __IAsynFileIoOperation_INTERFACE_DEFINED__
#define __IAsynFileIoOperation_INTERFACE_DEFINED__

/* interface IAsynFileIoOperation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFileIoOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19210367-E7A5-453a-927B-B07CA450741E")
    IAsynFileIoOperation : public IAsynIoOperation
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out] */ uint64_t *pPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPosition( 
            /* [in] */ uint64_t lPosition) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFileIoOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFileIoOperation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFileIoOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFileIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetAsynFrameThread )( 
            IAsynFileIoOperation * This,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IAsynFileIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *NewIoBuffer )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lNewBufferSize,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoBuffer )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ IBuffer **ppObject,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoBuffer )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ IBuffer *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetOsBuffer )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpParams )( 
            IAsynFileIoOperation * This,
            /* [out] */ uint32_t *message,
            /* [out] */ uint64_t *pParam1,
            /* [out] */ uint64_t *pParam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParams )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t *pParam1,
            /* [in] */ uint64_t lparam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParam1 )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint64_t lparam1);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoParams )( 
            IAsynFileIoOperation * This,
            /* [out] */ uint32_t *pSumBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParam1 )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t lSumBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParams )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes,
            /* [in] */ uint32_t lSumBytes,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *NewBufferIovectors )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t lCount,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferIovectors )( 
            IAsynFileIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddBufferIovectors )( 
            IAsynFileIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lAddBytes);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBuffers )( 
            IAsynFileIoOperation * This,
            /* [out][in] */ STRING *pSrcIovector,
            /* [out][in] */ uint32_t *count,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IAsynFileIoOperation * This,
            /* [in] */ BOOL bIsDGRAM,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes,
            /* [out] */ uint32_t *pStayBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedResult )( 
            IAsynFileIoOperation * This,
            /* [out] */ uint32_t *pErrorCode,
            /* [out] */ uint32_t *pTransferedBytes,
            /* [out] */ uint32_t *pReservedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedResult )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t lErrorCode);
        
        HRESULT ( STDMETHODCALLTYPE *SetTransferedBytes )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddTransferedBytes )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedObject )( 
            IAsynFileIoOperation * This,
            /* [in] */ BOOL bTaked,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedObject )( 
            IAsynFileIoOperation * This,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetPosition )( 
            IAsynFileIoOperation * This,
            /* [out] */ uint64_t *pPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetPosition )( 
            IAsynFileIoOperation * This,
            /* [in] */ uint64_t lPosition);
        
        END_INTERFACE
    } IAsynFileIoOperationVtbl;

    interface IAsynFileIoOperation
    {
        CONST_VTBL struct IAsynFileIoOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFileIoOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFileIoOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFileIoOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFileIoOperation_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynFileIoOperation_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynFileIoOperation_GetAsynFrameThread(This,ppAsynFrameThread)	\
    ( (This)->lpVtbl -> GetAsynFrameThread(This,ppAsynFrameThread) ) 

#define IAsynFileIoOperation_QueryStatus(This)	\
    ( (This)->lpVtbl -> QueryStatus(This) ) 

#define IAsynFileIoOperation_NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer)	\
    ( (This)->lpVtbl -> NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer) ) 

#define IAsynFileIoOperation_GetIoBuffer(This,index,ppObject,ppBuffer)	\
    ( (This)->lpVtbl -> GetIoBuffer(This,index,ppObject,ppBuffer) ) 

#define IAsynFileIoOperation_SetIoBuffer(This,index,pObject)	\
    ( (This)->lpVtbl -> SetIoBuffer(This,index,pObject) ) 

#define IAsynFileIoOperation_GetOsBuffer(This,index,ppBuffer)	\
    ( (This)->lpVtbl -> GetOsBuffer(This,index,ppBuffer) ) 

#define IAsynFileIoOperation_GetOpParams(This,message,pParam1,pParam2)	\
    ( (This)->lpVtbl -> GetOpParams(This,message,pParam1,pParam2) ) 

#define IAsynFileIoOperation_SetOpParams(This,message,pParam1,lparam2)	\
    ( (This)->lpVtbl -> SetOpParams(This,message,pParam1,lparam2) ) 

#define IAsynFileIoOperation_SetOpParam1(This,lparam1)	\
    ( (This)->lpVtbl -> SetOpParam1(This,lparam1) ) 

#define IAsynFileIoOperation_GetIoParams(This,pSumBytes,pMinBytes)	\
    ( (This)->lpVtbl -> GetIoParams(This,pSumBytes,pMinBytes) ) 

#define IAsynFileIoOperation_SetIoParam1(This,lSumBytes)	\
    ( (This)->lpVtbl -> SetIoParam1(This,lSumBytes) ) 

#define IAsynFileIoOperation_SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes)	\
    ( (This)->lpVtbl -> SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes) ) 

#define IAsynFileIoOperation_NewBufferIovectors(This,lCount,ppBuffer)	\
    ( (This)->lpVtbl -> NewBufferIovectors(This,lCount,ppBuffer) ) 

#define IAsynFileIoOperation_SetBufferIovectors(This,pIovector,lCount,lMinBytes)	\
    ( (This)->lpVtbl -> SetBufferIovectors(This,pIovector,lCount,lMinBytes) ) 

#define IAsynFileIoOperation_AddBufferIovectors(This,pIovector,lCount,lAddBytes)	\
    ( (This)->lpVtbl -> AddBufferIovectors(This,pIovector,lCount,lAddBytes) ) 

#define IAsynFileIoOperation_ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes)	\
    ( (This)->lpVtbl -> ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes) ) 

#define IAsynFileIoOperation_Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes)	\
    ( (This)->lpVtbl -> Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes) ) 

#define IAsynFileIoOperation_GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes)	\
    ( (This)->lpVtbl -> GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes) ) 

#define IAsynFileIoOperation_SetCompletedResult(This,lErrorCode)	\
    ( (This)->lpVtbl -> SetCompletedResult(This,lErrorCode) ) 

#define IAsynFileIoOperation_SetTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> SetTransferedBytes(This,lTransferedBytes) ) 

#define IAsynFileIoOperation_AddTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> AddTransferedBytes(This,lTransferedBytes) ) 

#define IAsynFileIoOperation_GetCompletedObject(This,bTaked,riid,ppObject)	\
    ( (This)->lpVtbl -> GetCompletedObject(This,bTaked,riid,ppObject) ) 

#define IAsynFileIoOperation_SetCompletedObject(This,pObject)	\
    ( (This)->lpVtbl -> SetCompletedObject(This,pObject) ) 


#define IAsynFileIoOperation_GetPosition(This,pPosition)	\
    ( (This)->lpVtbl -> GetPosition(This,pPosition) ) 

#define IAsynFileIoOperation_SetPosition(This,lPosition)	\
    ( (This)->lpVtbl -> SetPosition(This,lPosition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFileIoOperation_INTERFACE_DEFINED__ */


#ifndef __IAsynRawDevice_INTERFACE_DEFINED__
#define __IAsynRawDevice_INTERFACE_DEFINED__

/* interface IAsynRawDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynRawDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E84C89BE-2582-4afa-BBF6-3C47D655246E")
    IAsynRawDevice : public IAsynIoDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING Path,
            /* [in] */ uint32_t lDesiredAccess,
            /* [in] */ uint32_t lShareMode,
            /* [in] */ handle pSecurityAttributes,
            /* [in] */ uint32_t lCreationDisposition,
            /* [in] */ uint32_t lFlagsAndAttributes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynRawDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynRawDevice * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynRawDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynRawDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynRawDevice * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynRawDevice * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynRawDevice * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynRawDevice * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynRawDevice * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynRawDevice * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynRawDevice * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynRawDevice * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynRawDevice * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynRawDevice * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynRawDevice * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynRawDevice * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING Path,
            /* [in] */ uint32_t lDesiredAccess,
            /* [in] */ uint32_t lShareMode,
            /* [in] */ handle pSecurityAttributes,
            /* [in] */ uint32_t lCreationDisposition,
            /* [in] */ uint32_t lFlagsAndAttributes);
        
        END_INTERFACE
    } IAsynRawDeviceVtbl;

    interface IAsynRawDevice
    {
        CONST_VTBL struct IAsynRawDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynRawDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynRawDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynRawDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynRawDevice_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynRawDevice_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynRawDevice_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynRawDevice_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynRawDevice_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynRawDevice_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynRawDevice_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynRawDevice_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynRawDevice_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynRawDevice_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynRawDevice_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynRawDevice_Open(This,pAsynFrameThread,Path,lDesiredAccess,lShareMode,pSecurityAttributes,lCreationDisposition,lFlagsAndAttributes)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,Path,lDesiredAccess,lShareMode,pSecurityAttributes,lCreationDisposition,lFlagsAndAttributes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynRawDevice_INTERFACE_DEFINED__ */


#ifndef __IAsynFile_INTERFACE_DEFINED__
#define __IAsynFile_INTERFACE_DEFINED__

/* interface IAsynFile */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B4BA849-DD57-4590-93BD-EF84AE97C193")
    IAsynFile : public IAsynRawDevice
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [out] */ uint64_t *pFileSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileSize( 
            /* [in] */ uint64_t lFileSize,
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushBuffer( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynFile * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynFile * This,
            /* [in] */ uint32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynFile * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynFile * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynFile * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynFile * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynFile * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation,
            /* [in] */ uint64_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynFile * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynFile * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynFile * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynFile * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IAsynFile * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING Path,
            /* [in] */ uint32_t lDesiredAccess,
            /* [in] */ uint32_t lShareMode,
            /* [in] */ handle pSecurityAttributes,
            /* [in] */ uint32_t lCreationDisposition,
            /* [in] */ uint32_t lFlagsAndAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IAsynFile * This,
            /* [out] */ uint64_t *pFileSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileSize )( 
            IAsynFile * This,
            /* [in] */ uint64_t lFileSize,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *FlushBuffer )( 
            IAsynFile * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IAsynFileVtbl;

    interface IAsynFile
    {
        CONST_VTBL struct IAsynFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFile_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynFile_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynFile_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynFile_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynFile_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynFile_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynFile_Write(This,pAsynIoOperation,reserved)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation,reserved) ) 

#define IAsynFile_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynFile_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynFile_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynFile_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 


#define IAsynFile_Open(This,pAsynFrameThread,Path,lDesiredAccess,lShareMode,pSecurityAttributes,lCreationDisposition,lFlagsAndAttributes)	\
    ( (This)->lpVtbl -> Open(This,pAsynFrameThread,Path,lDesiredAccess,lShareMode,pSecurityAttributes,lCreationDisposition,lFlagsAndAttributes) ) 


#define IAsynFile_GetFileSize(This,pFileSize)	\
    ( (This)->lpVtbl -> GetFileSize(This,pFileSize) ) 

#define IAsynFile_SetFileSize(This,lFileSize,pAsynIoOperation)	\
    ( (This)->lpVtbl -> SetFileSize(This,lFileSize,pAsynIoOperation) ) 

#define IAsynFile_FlushBuffer(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> FlushBuffer(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFile_INTERFACE_DEFINED__ */


#ifndef __IAsynFileWatcher_INTERFACE_DEFINED__
#define __IAsynFileWatcher_INTERFACE_DEFINED__

/* interface IAsynFileWatcher */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFileWatcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F01E7E2-D839-4af2-AC4D-DCEA84425B68")
    IAsynFileWatcher : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ IUnknown *data,
            /* [in] */ uint32_t Codepage) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFileWatcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFileWatcher * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFileWatcher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFileWatcher * This);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IAsynFileWatcher * This,
            /* [in] */ IUnknown *data,
            /* [in] */ uint32_t Codepage);
        
        END_INTERFACE
    } IAsynFileWatcherVtbl;

    interface IAsynFileWatcher
    {
        CONST_VTBL struct IAsynFileWatcherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFileWatcher_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFileWatcher_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFileWatcher_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFileWatcher_Commit(This,data,Codepage)	\
    ( (This)->lpVtbl -> Commit(This,data,Codepage) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFileWatcher_INTERFACE_DEFINED__ */


#ifndef __IAsynFileSystem_INTERFACE_DEFINED__
#define __IAsynFileSystem_INTERFACE_DEFINED__

/* interface IAsynFileSystem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFileSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8195BCC2-EFFB-4106-ACAE-20DFBFE84908")
    IAsynFileSystem : public IAsynIoOperationFactory
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynRawDevice( 
            /* [out] */ IAsynRawDevice **ppAsynRawDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynFile( 
            /* [out] */ IAsynFile **ppAsynFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynFileWatcher( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING FilePath,
            /* [in] */ BOOL bWatchSubtree,
            /* [in] */ uint32_t lNotifyFilter,
            /* [out] */ IAsynFileWatcher **ppAsynFileWatcher) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFileSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFileSystem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFileSystem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFileSystem * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIoOperation )( 
            IAsynFileSystem * This,
            /* [in] */ IAsynFrame *frame,
            /* [in] */ uint32_t param1,
            /* [in] */ uint32_t param2,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynRawDevice )( 
            IAsynFileSystem * This,
            /* [out] */ IAsynRawDevice **ppAsynRawDevice);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynFile )( 
            IAsynFileSystem * This,
            /* [out] */ IAsynFile **ppAsynFile);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynFileWatcher )( 
            IAsynFileSystem * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ STRING FilePath,
            /* [in] */ BOOL bWatchSubtree,
            /* [in] */ uint32_t lNotifyFilter,
            /* [out] */ IAsynFileWatcher **ppAsynFileWatcher);
        
        END_INTERFACE
    } IAsynFileSystemVtbl;

    interface IAsynFileSystem
    {
        CONST_VTBL struct IAsynFileSystemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFileSystem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFileSystem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFileSystem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFileSystem_CreateAsynIoOperation(This,frame,param1,param2,riid,ppObject)	\
    ( (This)->lpVtbl -> CreateAsynIoOperation(This,frame,param1,param2,riid,ppObject) ) 


#define IAsynFileSystem_CreateAsynRawDevice(This,ppAsynRawDevice)	\
    ( (This)->lpVtbl -> CreateAsynRawDevice(This,ppAsynRawDevice) ) 

#define IAsynFileSystem_CreateAsynFile(This,ppAsynFile)	\
    ( (This)->lpVtbl -> CreateAsynFile(This,ppAsynFile) ) 

#define IAsynFileSystem_CreateAsynFileWatcher(This,pAsynFrameThread,FilePath,bWatchSubtree,lNotifyFilter,ppAsynFileWatcher)	\
    ( (This)->lpVtbl -> CreateAsynFileWatcher(This,pAsynFrameThread,FilePath,bWatchSubtree,lNotifyFilter,ppAsynFileWatcher) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFileSystem_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAsynFileSystem_0000_0005 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IAsynFileSystem_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynFileSystem_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



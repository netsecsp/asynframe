

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jul 12 17:04:39 2024
 */
/* Compiler settings for IAsynFrame.idl:
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

#ifndef __IAsynFrame_h__
#define __IAsynFrame_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IObjectHolder_FWD_DEFINED__
#define __IObjectHolder_FWD_DEFINED__
typedef interface IObjectHolder IObjectHolder;

#endif 	/* __IObjectHolder_FWD_DEFINED__ */


#ifndef __ISpeedController_FWD_DEFINED__
#define __ISpeedController_FWD_DEFINED__
typedef interface ISpeedController ISpeedController;

#endif 	/* __ISpeedController_FWD_DEFINED__ */


#ifndef __IOsTime_FWD_DEFINED__
#define __IOsTime_FWD_DEFINED__
typedef interface IOsTime IOsTime;

#endif 	/* __IOsTime_FWD_DEFINED__ */


#ifndef __IAsynMessageEvents_FWD_DEFINED__
#define __IAsynMessageEvents_FWD_DEFINED__
typedef interface IAsynMessageEvents IAsynMessageEvents;

#endif 	/* __IAsynMessageEvents_FWD_DEFINED__ */


#ifndef __IAsynMessageObject_FWD_DEFINED__
#define __IAsynMessageObject_FWD_DEFINED__
typedef interface IAsynMessageObject IAsynMessageObject;

#endif 	/* __IAsynMessageObject_FWD_DEFINED__ */


#ifndef __IAsynMessageHolder_FWD_DEFINED__
#define __IAsynMessageHolder_FWD_DEFINED__
typedef interface IAsynMessageHolder IAsynMessageHolder;

#endif 	/* __IAsynMessageHolder_FWD_DEFINED__ */


#ifndef __IThreadMessagePump_FWD_DEFINED__
#define __IThreadMessagePump_FWD_DEFINED__
typedef interface IThreadMessagePump IThreadMessagePump;

#endif 	/* __IThreadMessagePump_FWD_DEFINED__ */


#ifndef __IThread_FWD_DEFINED__
#define __IThread_FWD_DEFINED__
typedef interface IThread IThread;

#endif 	/* __IThread_FWD_DEFINED__ */


#ifndef __IThreadPool_FWD_DEFINED__
#define __IThreadPool_FWD_DEFINED__
typedef interface IThreadPool IThreadPool;

#endif 	/* __IThreadPool_FWD_DEFINED__ */


#ifndef __IMemoryPool_FWD_DEFINED__
#define __IMemoryPool_FWD_DEFINED__
typedef interface IMemoryPool IMemoryPool;

#endif 	/* __IMemoryPool_FWD_DEFINED__ */


#ifndef __IBuffer_FWD_DEFINED__
#define __IBuffer_FWD_DEFINED__
typedef interface IBuffer IBuffer;

#endif 	/* __IBuffer_FWD_DEFINED__ */


#ifndef __IOsCommand_FWD_DEFINED__
#define __IOsCommand_FWD_DEFINED__
typedef interface IOsCommand IOsCommand;

#endif 	/* __IOsCommand_FWD_DEFINED__ */


#ifndef __IAsynIoOperation_FWD_DEFINED__
#define __IAsynIoOperation_FWD_DEFINED__
typedef interface IAsynIoOperation IAsynIoOperation;

#endif 	/* __IAsynIoOperation_FWD_DEFINED__ */


#ifndef __IAsynIoOperationFactory_FWD_DEFINED__
#define __IAsynIoOperationFactory_FWD_DEFINED__
typedef interface IAsynIoOperationFactory IAsynIoOperationFactory;

#endif 	/* __IAsynIoOperationFactory_FWD_DEFINED__ */


#ifndef __IDataTransmit_FWD_DEFINED__
#define __IDataTransmit_FWD_DEFINED__
typedef interface IDataTransmit IDataTransmit;

#endif 	/* __IDataTransmit_FWD_DEFINED__ */


#ifndef __IDataRwInvoke_FWD_DEFINED__
#define __IDataRwInvoke_FWD_DEFINED__
typedef interface IDataRwInvoke IDataRwInvoke;

#endif 	/* __IDataRwInvoke_FWD_DEFINED__ */


#ifndef __IDataProvider_FWD_DEFINED__
#define __IDataProvider_FWD_DEFINED__
typedef interface IDataProvider IDataProvider;

#endif 	/* __IDataProvider_FWD_DEFINED__ */


#ifndef __IAsynIoDevice_FWD_DEFINED__
#define __IAsynIoDevice_FWD_DEFINED__
typedef interface IAsynIoDevice IAsynIoDevice;

#endif 	/* __IAsynIoDevice_FWD_DEFINED__ */


#ifndef __IAsynIoBridge_FWD_DEFINED__
#define __IAsynIoBridge_FWD_DEFINED__
typedef interface IAsynIoBridge IAsynIoBridge;

#endif 	/* __IAsynIoBridge_FWD_DEFINED__ */


#ifndef __IAsynFrame_FWD_DEFINED__
#define __IAsynFrame_FWD_DEFINED__
typedef interface IAsynFrame IAsynFrame;

#endif 	/* __IAsynFrame_FWD_DEFINED__ */


#ifndef __IAsynFrameThread_FWD_DEFINED__
#define __IAsynFrameThread_FWD_DEFINED__
typedef interface IAsynFrameThread IAsynFrameThread;

#endif 	/* __IAsynFrameThread_FWD_DEFINED__ */


#ifndef __IAsynFrameThreadFactory_FWD_DEFINED__
#define __IAsynFrameThreadFactory_FWD_DEFINED__
typedef interface IAsynFrameThreadFactory IAsynFrameThreadFactory;

#endif 	/* __IAsynFrameThreadFactory_FWD_DEFINED__ */


#ifndef __InstancesManager_FWD_DEFINED__
#define __InstancesManager_FWD_DEFINED__
typedef interface InstancesManager InstancesManager;

#endif 	/* __InstancesManager_FWD_DEFINED__ */


#ifndef __IAsynFramePlugin_FWD_DEFINED__
#define __IAsynFramePlugin_FWD_DEFINED__
typedef interface IAsynFramePlugin IAsynFramePlugin;

#endif 	/* __IAsynFramePlugin_FWD_DEFINED__ */


/* header files for imported files */
#include "ITypedef.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IAsynFrame_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)
















#define AF_EVENT_SYSTEM (  0  )
#define AF_EVENT_APPID0 (  1  )
#define AF_TIMER        (  2  )
#define AF_IOMSG_NOTIFY (  5  )
#define AF_EVENT_NOTIFY (  6  )
#define AF_QUERY_RESULT (  7  )
#define AF_EVENT_APPID1 (10000)
#define AF_EVENT_APPID2 (10001)
#define AF_EVENT_APPID3 (10002)
#define AF_EVENT_APPID4 (10003)
#define AE_RESET        (  1  )


extern RPC_IF_HANDLE __MIDL_itf_IAsynFrame_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynFrame_0000_0000_v0_0_s_ifspec;

#ifndef __IObjectHolder_INTERFACE_DEFINED__
#define __IObjectHolder_INTERFACE_DEFINED__

/* interface IObjectHolder */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IObjectHolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8CE1A45-9316-430a-BAE5-D905201CC180")
    IObjectHolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IObjectHolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IObjectHolder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IObjectHolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IObjectHolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IObjectHolder * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IObjectHolder * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        END_INTERFACE
    } IObjectHolderVtbl;

    interface IObjectHolder
    {
        CONST_VTBL struct IObjectHolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectHolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IObjectHolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IObjectHolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IObjectHolder_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IObjectHolder_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IObjectHolder_INTERFACE_DEFINED__ */


#ifndef __ISpeedController_INTERFACE_DEFINED__
#define __ISpeedController_INTERFACE_DEFINED__

/* interface ISpeedController */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpeedController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A420A5D-1198-44fc-ACFF-7BEC934FE7D5")
    ISpeedController : public IObjectHolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanPostIoBytes( 
            /* [in] */ uint32_t lDatIoBytes,
            /* [out] */ uint32_t *pCanIoBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPostIoBytes( 
            /* [in] */ uint32_t lDatIoBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPostIoBytes( 
            /* [out] */ uint64_t *pDatIoBytes,
            /* [out] */ uint32_t *pCurIoSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxSpeed( 
            /* [in] */ BOOL loop,
            /* [out] */ uint32_t *pMaxIoSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxSpeed( 
            /* [in] */ uint32_t lMaxIoSpeed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeedControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpeedController * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpeedController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpeedController * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            ISpeedController * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            ISpeedController * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *CanPostIoBytes )( 
            ISpeedController * This,
            /* [in] */ uint32_t lDatIoBytes,
            /* [out] */ uint32_t *pCanIoBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddPostIoBytes )( 
            ISpeedController * This,
            /* [in] */ uint32_t lDatIoBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetPostIoBytes )( 
            ISpeedController * This,
            /* [out] */ uint64_t *pDatIoBytes,
            /* [out] */ uint32_t *pCurIoSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            ISpeedController * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxSpeed )( 
            ISpeedController * This,
            /* [in] */ BOOL loop,
            /* [out] */ uint32_t *pMaxIoSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxSpeed )( 
            ISpeedController * This,
            /* [in] */ uint32_t lMaxIoSpeed);
        
        END_INTERFACE
    } ISpeedControllerVtbl;

    interface ISpeedController
    {
        CONST_VTBL struct ISpeedControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeedController_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeedController_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeedController_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeedController_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define ISpeedController_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define ISpeedController_CanPostIoBytes(This,lDatIoBytes,pCanIoBytes)	\
    ( (This)->lpVtbl -> CanPostIoBytes(This,lDatIoBytes,pCanIoBytes) ) 

#define ISpeedController_AddPostIoBytes(This,lDatIoBytes)	\
    ( (This)->lpVtbl -> AddPostIoBytes(This,lDatIoBytes) ) 

#define ISpeedController_GetPostIoBytes(This,pDatIoBytes,pCurIoSpeed)	\
    ( (This)->lpVtbl -> GetPostIoBytes(This,pDatIoBytes,pCurIoSpeed) ) 

#define ISpeedController_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define ISpeedController_GetMaxSpeed(This,loop,pMaxIoSpeed)	\
    ( (This)->lpVtbl -> GetMaxSpeed(This,loop,pMaxIoSpeed) ) 

#define ISpeedController_SetMaxSpeed(This,lMaxIoSpeed)	\
    ( (This)->lpVtbl -> SetMaxSpeed(This,lMaxIoSpeed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeedController_INTERFACE_DEFINED__ */


#ifndef __IOsTime_INTERFACE_DEFINED__
#define __IOsTime_INTERFACE_DEFINED__

/* interface IOsTime */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOsTime;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9508E64D-1F80-43fd-9E27-D39D20394ECF")
    IOsTime : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTimeofday( 
            /* [out] */ uint64_t *time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTickcount( 
            /* [out] */ uint64_t *time) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOsTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOsTime * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOsTime * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOsTime * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTimeofday )( 
            IOsTime * This,
            /* [out] */ uint64_t *time);
        
        HRESULT ( STDMETHODCALLTYPE *GetTickcount )( 
            IOsTime * This,
            /* [out] */ uint64_t *time);
        
        END_INTERFACE
    } IOsTimeVtbl;

    interface IOsTime
    {
        CONST_VTBL struct IOsTimeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOsTime_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOsTime_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOsTime_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOsTime_GetTimeofday(This,time)	\
    ( (This)->lpVtbl -> GetTimeofday(This,time) ) 

#define IOsTime_GetTickcount(This,time)	\
    ( (This)->lpVtbl -> GetTickcount(This,time) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOsTime_INTERFACE_DEFINED__ */


#ifndef __IAsynMessageEvents_INTERFACE_DEFINED__
#define __IAsynMessageEvents_INTERFACE_DEFINED__

/* interface IAsynMessageEvents */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynMessageEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("636E17D7-3713-4a36-98A7-6B0971476067")
    IAsynMessageEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnMessage( 
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [out][in] */ IUnknown **object) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynMessageEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynMessageEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynMessageEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynMessageEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnMessage )( 
            IAsynMessageEvents * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [out][in] */ IUnknown **object);
        
        END_INTERFACE
    } IAsynMessageEventsVtbl;

    interface IAsynMessageEvents
    {
        CONST_VTBL struct IAsynMessageEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynMessageEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynMessageEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynMessageEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynMessageEvents_OnMessage(This,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> OnMessage(This,message,lparam1,lparam2,object) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynMessageEvents_INTERFACE_DEFINED__ */


#ifndef __IAsynMessageObject_INTERFACE_DEFINED__
#define __IAsynMessageObject_INTERFACE_DEFINED__

/* interface IAsynMessageObject */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynMessageObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58EDD852-2FCC-4ea8-8069-3DF6E1D96866")
    IAsynMessageObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ IUnknown *observer,
            /* [in] */ uint64_t subject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Detach( 
            /* [in] */ IUnknown *observer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [in] */ STRING *subject,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynMessageObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynMessageObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynMessageObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynMessageObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynMessageObject * This,
            /* [in] */ IUnknown *observer,
            /* [in] */ uint64_t subject);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynMessageObject * This,
            /* [in] */ IUnknown *observer);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            IAsynMessageObject * This,
            /* [in] */ STRING *subject,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        END_INTERFACE
    } IAsynMessageObjectVtbl;

    interface IAsynMessageObject
    {
        CONST_VTBL struct IAsynMessageObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynMessageObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynMessageObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynMessageObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynMessageObject_Attach(This,observer,subject)	\
    ( (This)->lpVtbl -> Attach(This,observer,subject) ) 

#define IAsynMessageObject_Detach(This,observer)	\
    ( (This)->lpVtbl -> Detach(This,observer) ) 

#define IAsynMessageObject_Notify(This,subject,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Notify(This,subject,message,lparam1,lparam2,object) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynMessageObject_INTERFACE_DEFINED__ */


#ifndef __IAsynMessageHolder_INTERFACE_DEFINED__
#define __IAsynMessageHolder_INTERFACE_DEFINED__

/* interface IAsynMessageHolder */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynMessageHolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E765F457-4262-4F7B-BF6D-49F72CD81698")
    IAsynMessageHolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ IThread *thread,
            /* [in] */ IUnknown *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynMessageHolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynMessageHolder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynMessageHolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynMessageHolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAsynMessageHolder * This,
            /* [in] */ IThread *thread,
            /* [in] */ IUnknown *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        END_INTERFACE
    } IAsynMessageHolderVtbl;

    interface IAsynMessageHolder
    {
        CONST_VTBL struct IAsynMessageHolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynMessageHolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynMessageHolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynMessageHolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynMessageHolder_Invoke(This,thread,events,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Invoke(This,thread,events,message,lparam1,lparam2,object) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynMessageHolder_INTERFACE_DEFINED__ */


#ifndef __IThreadMessagePump_INTERFACE_DEFINED__
#define __IThreadMessagePump_INTERFACE_DEFINED__

/* interface IThreadMessagePump */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IThreadMessagePump;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D5B45AA-E96D-4856-B029-DC83EE2C21BB")
    IThreadMessagePump : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WaitMessage( 
            /* [in] */ handle events,
            /* [in] */ uint64_t nTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PumpMessage( 
            /* [in] */ handle pdatas) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IThreadMessagePumpVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IThreadMessagePump * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IThreadMessagePump * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IThreadMessagePump * This);
        
        HRESULT ( STDMETHODCALLTYPE *WaitMessage )( 
            IThreadMessagePump * This,
            /* [in] */ handle events,
            /* [in] */ uint64_t nTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *PumpMessage )( 
            IThreadMessagePump * This,
            /* [in] */ handle pdatas);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IThreadMessagePump * This);
        
        END_INTERFACE
    } IThreadMessagePumpVtbl;

    interface IThreadMessagePump
    {
        CONST_VTBL struct IThreadMessagePumpVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IThreadMessagePump_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IThreadMessagePump_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IThreadMessagePump_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IThreadMessagePump_WaitMessage(This,events,nTimeout)	\
    ( (This)->lpVtbl -> WaitMessage(This,events,nTimeout) ) 

#define IThreadMessagePump_PumpMessage(This,pdatas)	\
    ( (This)->lpVtbl -> PumpMessage(This,pdatas) ) 

#define IThreadMessagePump_QueryStatus(This)	\
    ( (This)->lpVtbl -> QueryStatus(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IThreadMessagePump_INTERFACE_DEFINED__ */


#ifndef __IThread_INTERFACE_DEFINED__
#define __IThread_INTERFACE_DEFINED__

/* interface IThread */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IThread;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9811E66-30E4-4D9C-BF5F-15EC25293840")
    IThread : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ModifyThreadPriority( 
            /* [in] */ int32_t priority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Post( 
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IThreadVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IThread * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IThread * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IThread * This);
        
        HRESULT ( STDMETHODCALLTYPE *ModifyThreadPriority )( 
            IThread * This,
            /* [in] */ int32_t priority);
        
        HRESULT ( STDMETHODCALLTYPE *Post )( 
            IThread * This,
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        END_INTERFACE
    } IThreadVtbl;

    interface IThread
    {
        CONST_VTBL struct IThreadVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IThread_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IThread_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IThread_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IThread_ModifyThreadPriority(This,priority)	\
    ( (This)->lpVtbl -> ModifyThreadPriority(This,priority) ) 

#define IThread_Post(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Post(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IThread_INTERFACE_DEFINED__ */


#ifndef __IThreadPool_INTERFACE_DEFINED__
#define __IThreadPool_INTERFACE_DEFINED__

/* interface IThreadPool */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IThreadPool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91209092-33B1-4ED1-A40E-0D162FA0938D")
    IThreadPool : public IThread
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IThreadPoolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IThreadPool * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IThreadPool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IThreadPool * This);
        
        HRESULT ( STDMETHODCALLTYPE *ModifyThreadPriority )( 
            IThreadPool * This,
            /* [in] */ int32_t priority);
        
        HRESULT ( STDMETHODCALLTYPE *Post )( 
            IThreadPool * This,
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        END_INTERFACE
    } IThreadPoolVtbl;

    interface IThreadPool
    {
        CONST_VTBL struct IThreadPoolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IThreadPool_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IThreadPool_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IThreadPool_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IThreadPool_ModifyThreadPriority(This,priority)	\
    ( (This)->lpVtbl -> ModifyThreadPriority(This,priority) ) 

#define IThreadPool_Post(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Post(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IThreadPool_INTERFACE_DEFINED__ */


#ifndef __IMemoryPool_INTERFACE_DEFINED__
#define __IMemoryPool_INTERFACE_DEFINED__

/* interface IMemoryPool */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMemoryPool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33A4526F-4260-4a9d-B9BE-BACBFEAF0D62")
    IMemoryPool : public IAsynMessageEvents
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ BOOL Thread,
            /* [in] */ uint32_t nBlkSize,
            /* [in] */ uint64_t nMaxSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pop( 
            /* [out] */ IBuffer **ppBuffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMemoryPoolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMemoryPool * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMemoryPool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMemoryPool * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnMessage )( 
            IMemoryPool * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [out][in] */ IUnknown **object);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IMemoryPool * This,
            /* [in] */ BOOL Thread,
            /* [in] */ uint32_t nBlkSize,
            /* [in] */ uint64_t nMaxSize);
        
        HRESULT ( STDMETHODCALLTYPE *Pop )( 
            IMemoryPool * This,
            /* [out] */ IBuffer **ppBuffer);
        
        END_INTERFACE
    } IMemoryPoolVtbl;

    interface IMemoryPool
    {
        CONST_VTBL struct IMemoryPoolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMemoryPool_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMemoryPool_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMemoryPool_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMemoryPool_OnMessage(This,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> OnMessage(This,message,lparam1,lparam2,object) ) 


#define IMemoryPool_Set(This,Thread,nBlkSize,nMaxSize)	\
    ( (This)->lpVtbl -> Set(This,Thread,nBlkSize,nMaxSize) ) 

#define IMemoryPool_Pop(This,ppBuffer)	\
    ( (This)->lpVtbl -> Pop(This,ppBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMemoryPool_INTERFACE_DEFINED__ */


#ifndef __IBuffer_INTERFACE_DEFINED__
#define __IBuffer_INTERFACE_DEFINED__

/* interface IBuffer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4CB3BD65-B69F-4d25-82AA-10D72257C61D")
    IBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [out] */ handle *ppObject,
            /* [out] */ uint64_t *pParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObject( 
            /* [in] */ handle pObject,
            /* [in] */ uint64_t lParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NewBuffer( 
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lBufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [out] */ BYTE **ppDataBuffer,
            /* [out] */ uint32_t *pDataSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reference( 
            /* [in] */ uint32_t Offset,
            /* [in] */ uint32_t size,
            /* [out] */ IBuffer **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [out] */ uint32_t *Offset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOffset( 
            /* [in] */ uint32_t Offset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ int32_t val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdjustDataSize( 
            /* [in] */ uint32_t DataSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtraBuffer( 
            /* [in] */ uint32_t Index,
            /* [out] */ IBuffer **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtraBuffer( 
            /* [in] */ uint32_t Index,
            /* [in] */ IBuffer *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveExtraBuffers( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBuffer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            IBuffer * This,
            /* [out] */ handle *ppObject,
            /* [out] */ uint64_t *pParams);
        
        HRESULT ( STDMETHODCALLTYPE *SetObject )( 
            IBuffer * This,
            /* [in] */ handle pObject,
            /* [in] */ uint64_t lParams);
        
        HRESULT ( STDMETHODCALLTYPE *NewBuffer )( 
            IBuffer * This,
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lBufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IBuffer * This,
            /* [out] */ BYTE **ppDataBuffer,
            /* [out] */ uint32_t *pDataSize);
        
        HRESULT ( STDMETHODCALLTYPE *Reference )( 
            IBuffer * This,
            /* [in] */ uint32_t Offset,
            /* [in] */ uint32_t size,
            /* [out] */ IBuffer **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffset )( 
            IBuffer * This,
            /* [out] */ uint32_t *Offset);
        
        HRESULT ( STDMETHODCALLTYPE *SetOffset )( 
            IBuffer * This,
            /* [in] */ uint32_t Offset);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            IBuffer * This,
            /* [in] */ int32_t val);
        
        HRESULT ( STDMETHODCALLTYPE *AdjustDataSize )( 
            IBuffer * This,
            /* [in] */ uint32_t DataSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtraBuffer )( 
            IBuffer * This,
            /* [in] */ uint32_t Index,
            /* [out] */ IBuffer **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetExtraBuffer )( 
            IBuffer * This,
            /* [in] */ uint32_t Index,
            /* [in] */ IBuffer *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveExtraBuffers )( 
            IBuffer * This);
        
        END_INTERFACE
    } IBufferVtbl;

    interface IBuffer
    {
        CONST_VTBL struct IBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBuffer_GetObject(This,ppObject,pParams)	\
    ( (This)->lpVtbl -> GetObject(This,ppObject,pParams) ) 

#define IBuffer_SetObject(This,pObject,lParams)	\
    ( (This)->lpVtbl -> SetObject(This,pObject,lParams) ) 

#define IBuffer_NewBuffer(This,pFillBuffer,lFillOffset,lFillSize,lBufferSize)	\
    ( (This)->lpVtbl -> NewBuffer(This,pFillBuffer,lFillOffset,lFillSize,lBufferSize) ) 

#define IBuffer_GetBuffer(This,ppDataBuffer,pDataSize)	\
    ( (This)->lpVtbl -> GetBuffer(This,ppDataBuffer,pDataSize) ) 

#define IBuffer_Reference(This,Offset,size,ppBuffer)	\
    ( (This)->lpVtbl -> Reference(This,Offset,size,ppBuffer) ) 

#define IBuffer_GetOffset(This,Offset)	\
    ( (This)->lpVtbl -> GetOffset(This,Offset) ) 

#define IBuffer_SetOffset(This,Offset)	\
    ( (This)->lpVtbl -> SetOffset(This,Offset) ) 

#define IBuffer_Move(This,val)	\
    ( (This)->lpVtbl -> Move(This,val) ) 

#define IBuffer_AdjustDataSize(This,DataSize)	\
    ( (This)->lpVtbl -> AdjustDataSize(This,DataSize) ) 

#define IBuffer_GetExtraBuffer(This,Index,ppBuffer)	\
    ( (This)->lpVtbl -> GetExtraBuffer(This,Index,ppBuffer) ) 

#define IBuffer_SetExtraBuffer(This,Index,pBuffer)	\
    ( (This)->lpVtbl -> SetExtraBuffer(This,Index,pBuffer) ) 

#define IBuffer_RemoveExtraBuffers(This)	\
    ( (This)->lpVtbl -> RemoveExtraBuffers(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBuffer_INTERFACE_DEFINED__ */


#ifndef __IOsCommand_INTERFACE_DEFINED__
#define __IOsCommand_INTERFACE_DEFINED__

/* interface IOsCommand */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOsCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B090FA6F-9712-4fd7-A9C2-4E5D114D7479")
    IOsCommand : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ IUnknown *output,
            /* [in] */ STRING name,
            /* [size_is][in] */ STRING *argv,
            /* [in] */ uint32_t argc,
            /* [in] */ IKeyvalSetter *env,
            /* [in] */ IUnknown *object) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOsCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOsCommand * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOsCommand * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOsCommand * This);
        
        HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IOsCommand * This,
            /* [in] */ IUnknown *output,
            /* [in] */ STRING name,
            /* [size_is][in] */ STRING *argv,
            /* [in] */ uint32_t argc,
            /* [in] */ IKeyvalSetter *env,
            /* [in] */ IUnknown *object);
        
        END_INTERFACE
    } IOsCommandVtbl;

    interface IOsCommand
    {
        CONST_VTBL struct IOsCommandVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOsCommand_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOsCommand_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOsCommand_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOsCommand_Execute(This,output,name,argv,argc,env,object)	\
    ( (This)->lpVtbl -> Execute(This,output,name,argv,argc,env,object) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOsCommand_INTERFACE_DEFINED__ */


#ifndef __IAsynIoOperation_INTERFACE_DEFINED__
#define __IAsynIoOperation_INTERFACE_DEFINED__

/* interface IAsynIoOperation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIoOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C34146C-C1CE-4c8c-A67F-32039009FAD7")
    IAsynIoOperation : public IObjectHolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAsynFrameThread( 
            /* [out] */ IAsynFrameThread **ppAsynFrameThread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NewIoBuffer( 
            /* [in] */ uint32_t index,
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lNewBufferSize,
            /* [out] */ BYTE **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIoBuffer( 
            /* [in] */ uint32_t index,
            /* [out] */ IBuffer **ppObject,
            /* [out] */ BYTE **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIoBuffer( 
            /* [in] */ uint32_t index,
            /* [in] */ IBuffer *pObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOsBuffer( 
            /* [in] */ uint32_t index,
            /* [out] */ handle *ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOpParams( 
            /* [out] */ uint32_t *message,
            /* [out] */ uint64_t *pParam1,
            /* [out] */ uint64_t *pParam2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOpParams( 
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t *pParam1,
            /* [in] */ uint64_t lparam2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOpParam1( 
            /* [in] */ uint64_t lparam1) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIoParams( 
            /* [out] */ uint32_t *pSumBytes,
            /* [out] */ uint32_t *pMinBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIoParam1( 
            /* [in] */ uint32_t lSumBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIoParams( 
            /* [in] */ uint32_t lTransferedBytes,
            /* [in] */ uint32_t lSumBytes,
            /* [in] */ uint32_t lMinBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NewBufferIovectors( 
            /* [in] */ uint32_t lCount,
            /* [out] */ handle *ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferIovectors( 
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lMinBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddBufferIovectors( 
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lAddBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadBuffers( 
            /* [out][in] */ STRING *pSrcIovector,
            /* [out][in] */ uint32_t *count,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ BOOL bIsDGRAM,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes,
            /* [out] */ uint32_t *pStayBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompletedResult( 
            /* [out] */ uint32_t *pErrorCode,
            /* [out] */ uint32_t *pTransferedBytes,
            /* [out] */ uint32_t *pReservedBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompletedResult( 
            /* [in] */ uint32_t lErrorCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTransferedBytes( 
            /* [in] */ uint32_t lTransferedBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTransferedBytes( 
            /* [in] */ uint32_t lTransferedBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompletedObject( 
            /* [in] */ BOOL bTaked,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompletedObject( 
            /* [in] */ IUnknown *pObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIoOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIoOperation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIoOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynIoOperation * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynIoOperation * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetAsynFrameThread )( 
            IAsynIoOperation * This,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IAsynIoOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *NewIoBuffer )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ BYTE *pFillBuffer,
            /* [in] */ uint32_t lFillOffset,
            /* [in] */ uint32_t lFillSize,
            /* [in] */ uint32_t lNewBufferSize,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoBuffer )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ IBuffer **ppObject,
            /* [out] */ BYTE **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoBuffer )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t index,
            /* [in] */ IBuffer *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetOsBuffer )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t index,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpParams )( 
            IAsynIoOperation * This,
            /* [out] */ uint32_t *message,
            /* [out] */ uint64_t *pParam1,
            /* [out] */ uint64_t *pParam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParams )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t *pParam1,
            /* [in] */ uint64_t lparam2);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpParam1 )( 
            IAsynIoOperation * This,
            /* [in] */ uint64_t lparam1);
        
        HRESULT ( STDMETHODCALLTYPE *GetIoParams )( 
            IAsynIoOperation * This,
            /* [out] */ uint32_t *pSumBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParam1 )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t lSumBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetIoParams )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes,
            /* [in] */ uint32_t lSumBytes,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *NewBufferIovectors )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t lCount,
            /* [out] */ handle *ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferIovectors )( 
            IAsynIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddBufferIovectors )( 
            IAsynIoOperation * This,
            /* [in] */ STRING *pIovector,
            /* [in] */ uint32_t lCount,
            /* [in] */ uint32_t lAddBytes);
        
        HRESULT ( STDMETHODCALLTYPE *ReadBuffers )( 
            IAsynIoOperation * This,
            /* [out][in] */ STRING *pSrcIovector,
            /* [out][in] */ uint32_t *count,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IAsynIoOperation * This,
            /* [in] */ BOOL bIsDGRAM,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [out] */ uint32_t *pCopyBytes,
            /* [out] */ uint32_t *pMinBytes,
            /* [out] */ uint32_t *pStayBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedResult )( 
            IAsynIoOperation * This,
            /* [out] */ uint32_t *pErrorCode,
            /* [out] */ uint32_t *pTransferedBytes,
            /* [out] */ uint32_t *pReservedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedResult )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t lErrorCode);
        
        HRESULT ( STDMETHODCALLTYPE *SetTransferedBytes )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *AddTransferedBytes )( 
            IAsynIoOperation * This,
            /* [in] */ uint32_t lTransferedBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletedObject )( 
            IAsynIoOperation * This,
            /* [in] */ BOOL bTaked,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletedObject )( 
            IAsynIoOperation * This,
            /* [in] */ IUnknown *pObject);
        
        END_INTERFACE
    } IAsynIoOperationVtbl;

    interface IAsynIoOperation
    {
        CONST_VTBL struct IAsynIoOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIoOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIoOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIoOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIoOperation_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynIoOperation_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynIoOperation_GetAsynFrameThread(This,ppAsynFrameThread)	\
    ( (This)->lpVtbl -> GetAsynFrameThread(This,ppAsynFrameThread) ) 

#define IAsynIoOperation_QueryStatus(This)	\
    ( (This)->lpVtbl -> QueryStatus(This) ) 

#define IAsynIoOperation_NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer)	\
    ( (This)->lpVtbl -> NewIoBuffer(This,index,pFillBuffer,lFillOffset,lFillSize,lNewBufferSize,ppBuffer) ) 

#define IAsynIoOperation_GetIoBuffer(This,index,ppObject,ppBuffer)	\
    ( (This)->lpVtbl -> GetIoBuffer(This,index,ppObject,ppBuffer) ) 

#define IAsynIoOperation_SetIoBuffer(This,index,pObject)	\
    ( (This)->lpVtbl -> SetIoBuffer(This,index,pObject) ) 

#define IAsynIoOperation_GetOsBuffer(This,index,ppBuffer)	\
    ( (This)->lpVtbl -> GetOsBuffer(This,index,ppBuffer) ) 

#define IAsynIoOperation_GetOpParams(This,message,pParam1,pParam2)	\
    ( (This)->lpVtbl -> GetOpParams(This,message,pParam1,pParam2) ) 

#define IAsynIoOperation_SetOpParams(This,message,pParam1,lparam2)	\
    ( (This)->lpVtbl -> SetOpParams(This,message,pParam1,lparam2) ) 

#define IAsynIoOperation_SetOpParam1(This,lparam1)	\
    ( (This)->lpVtbl -> SetOpParam1(This,lparam1) ) 

#define IAsynIoOperation_GetIoParams(This,pSumBytes,pMinBytes)	\
    ( (This)->lpVtbl -> GetIoParams(This,pSumBytes,pMinBytes) ) 

#define IAsynIoOperation_SetIoParam1(This,lSumBytes)	\
    ( (This)->lpVtbl -> SetIoParam1(This,lSumBytes) ) 

#define IAsynIoOperation_SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes)	\
    ( (This)->lpVtbl -> SetIoParams(This,lTransferedBytes,lSumBytes,lMinBytes) ) 

#define IAsynIoOperation_NewBufferIovectors(This,lCount,ppBuffer)	\
    ( (This)->lpVtbl -> NewBufferIovectors(This,lCount,ppBuffer) ) 

#define IAsynIoOperation_SetBufferIovectors(This,pIovector,lCount,lMinBytes)	\
    ( (This)->lpVtbl -> SetBufferIovectors(This,pIovector,lCount,lMinBytes) ) 

#define IAsynIoOperation_AddBufferIovectors(This,pIovector,lCount,lAddBytes)	\
    ( (This)->lpVtbl -> AddBufferIovectors(This,pIovector,lCount,lAddBytes) ) 

#define IAsynIoOperation_ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes)	\
    ( (This)->lpVtbl -> ReadBuffers(This,pSrcIovector,count,pCopyBytes,pMinBytes) ) 

#define IAsynIoOperation_Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes)	\
    ( (This)->lpVtbl -> Copy(This,bIsDGRAM,pDstAsynIoOperation,pCopyBytes,pMinBytes,pStayBytes) ) 

#define IAsynIoOperation_GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes)	\
    ( (This)->lpVtbl -> GetCompletedResult(This,pErrorCode,pTransferedBytes,pReservedBytes) ) 

#define IAsynIoOperation_SetCompletedResult(This,lErrorCode)	\
    ( (This)->lpVtbl -> SetCompletedResult(This,lErrorCode) ) 

#define IAsynIoOperation_SetTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> SetTransferedBytes(This,lTransferedBytes) ) 

#define IAsynIoOperation_AddTransferedBytes(This,lTransferedBytes)	\
    ( (This)->lpVtbl -> AddTransferedBytes(This,lTransferedBytes) ) 

#define IAsynIoOperation_GetCompletedObject(This,bTaked,riid,ppObject)	\
    ( (This)->lpVtbl -> GetCompletedObject(This,bTaked,riid,ppObject) ) 

#define IAsynIoOperation_SetCompletedObject(This,pObject)	\
    ( (This)->lpVtbl -> SetCompletedObject(This,pObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIoOperation_INTERFACE_DEFINED__ */


#ifndef __IAsynIoOperationFactory_INTERFACE_DEFINED__
#define __IAsynIoOperationFactory_INTERFACE_DEFINED__

/* interface IAsynIoOperationFactory */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIoOperationFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6655485B-7257-4e33-8714-120911D620EF")
    IAsynIoOperationFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAsynIoOperation( 
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint32_t param1,
            /* [in] */ uint32_t param2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIoOperationFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIoOperationFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIoOperationFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIoOperationFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIoOperation )( 
            IAsynIoOperationFactory * This,
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint32_t param1,
            /* [in] */ uint32_t param2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        END_INTERFACE
    } IAsynIoOperationFactoryVtbl;

    interface IAsynIoOperationFactory
    {
        CONST_VTBL struct IAsynIoOperationFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIoOperationFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIoOperationFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIoOperationFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIoOperationFactory_CreateAsynIoOperation(This,pdatas,param1,param2,riid,ppObject)	\
    ( (This)->lpVtbl -> CreateAsynIoOperation(This,pdatas,param1,param2,riid,ppObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIoOperationFactory_INTERFACE_DEFINED__ */


#ifndef __IDataTransmit_INTERFACE_DEFINED__
#define __IDataTransmit_INTERFACE_DEFINED__

/* interface IDataTransmit */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDataTransmit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51DAEFEC-4B50-43C5-BEB1-266FD61362A3")
    IDataTransmit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ IUnknown *pdatas,
            /* [in] */ handle param1,
            /* [in] */ uint64_t param2) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDataTransmitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataTransmit * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataTransmit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataTransmit * This);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IDataTransmit * This,
            /* [in] */ IUnknown *pdatas,
            /* [in] */ handle param1,
            /* [in] */ uint64_t param2);
        
        END_INTERFACE
    } IDataTransmitVtbl;

    interface IDataTransmit
    {
        CONST_VTBL struct IDataTransmitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataTransmit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataTransmit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataTransmit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataTransmit_Write(This,pdatas,param1,param2)	\
    ( (This)->lpVtbl -> Write(This,pdatas,param1,param2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataTransmit_INTERFACE_DEFINED__ */


#ifndef __IDataRwInvoke_INTERFACE_DEFINED__
#define __IDataRwInvoke_INTERFACE_DEFINED__

/* interface IDataRwInvoke */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDataRwInvoke;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE91B4EF-B499-4778-AF25-2D3358DC5BA1")
    IDataRwInvoke : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDataRwInvokeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataRwInvoke * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataRwInvoke * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataRwInvoke * This);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IDataRwInvoke * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IDataRwInvoke * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        END_INTERFACE
    } IDataRwInvokeVtbl;

    interface IDataRwInvoke
    {
        CONST_VTBL struct IDataRwInvokeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataRwInvoke_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataRwInvoke_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataRwInvoke_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataRwInvoke_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IDataRwInvoke_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataRwInvoke_INTERFACE_DEFINED__ */


#ifndef __IDataProvider_INTERFACE_DEFINED__
#define __IDataProvider_INTERFACE_DEFINED__

/* interface IDataProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDataProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC3598EB-758F-4363-BA80-E7263934CD9D")
    IDataProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Queryres( 
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint64_t param2,
            /* [in] */ IUnknown *object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Announce( 
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint32_t action) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDataProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Queryres )( 
            IDataProvider * This,
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint64_t param2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *Announce )( 
            IDataProvider * This,
            /* [in] */ IUnknown *pdatas,
            /* [in] */ uint32_t action);
        
        END_INTERFACE
    } IDataProviderVtbl;

    interface IDataProvider
    {
        CONST_VTBL struct IDataProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataProvider_Queryres(This,pdatas,param2,object)	\
    ( (This)->lpVtbl -> Queryres(This,pdatas,param2,object) ) 

#define IDataProvider_Announce(This,pdatas,action)	\
    ( (This)->lpVtbl -> Announce(This,pdatas,action) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataProvider_INTERFACE_DEFINED__ */


#ifndef __IAsynIoDevice_INTERFACE_DEFINED__
#define __IAsynIoDevice_INTERFACE_DEFINED__

/* interface IAsynIoDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIoDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CBFDC32B-6AC7-4dd6-BB9D-E8248366249A")
    IAsynIoDevice : public IObjectHolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsOpened( 
            /* [out] */ STRING *pDeviceName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsStream( 
            /* [out] */ uint32_t *pBlockSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceHandle( 
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Detach( 
            /* [in] */ uint32_t level) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [in] */ uint32_t reserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIoDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIoDevice * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIoDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIoDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynIoDevice * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynIoDevice * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IAsynIoDevice * This,
            /* [out] */ STRING *pDeviceName);
        
        HRESULT ( STDMETHODCALLTYPE *IsStream )( 
            IAsynIoDevice * This,
            /* [out] */ uint32_t *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceHandle )( 
            IAsynIoDevice * This,
            /* [in] */ uint32_t lType,
            /* [out] */ handle *ppDeviceHandle);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IAsynIoDevice * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IAsynIoDevice * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IAsynIoDevice * This,
            /* [in] */ IAsynFrameThread *pAsynFrameThread,
            /* [in] */ uint32_t lAttachType,
            /* [in] */ BOOL bCopyHandle,
            /* [in] */ handle pRecvDeviceHandle,
            /* [in] */ handle pSendDeviceHandle,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            IAsynIoDevice * This,
            /* [in] */ uint32_t level);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAsynIoDevice * This,
            /* [in] */ uint32_t reserved);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IAsynIoDevice * This,
            /* [in] */ IUnknown *lpReserved,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        END_INTERFACE
    } IAsynIoDeviceVtbl;

    interface IAsynIoDevice
    {
        CONST_VTBL struct IAsynIoDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIoDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIoDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIoDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIoDevice_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynIoDevice_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynIoDevice_IsOpened(This,pDeviceName)	\
    ( (This)->lpVtbl -> IsOpened(This,pDeviceName) ) 

#define IAsynIoDevice_IsStream(This,pBlockSize)	\
    ( (This)->lpVtbl -> IsStream(This,pBlockSize) ) 

#define IAsynIoDevice_GetDeviceHandle(This,lType,ppDeviceHandle)	\
    ( (This)->lpVtbl -> GetDeviceHandle(This,lType,ppDeviceHandle) ) 

#define IAsynIoDevice_Read(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Read(This,pAsynIoOperation) ) 

#define IAsynIoDevice_Write(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Write(This,pAsynIoOperation) ) 

#define IAsynIoDevice_Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation)	\
    ( (This)->lpVtbl -> Attach(This,pAsynFrameThread,lAttachType,bCopyHandle,pRecvDeviceHandle,pSendDeviceHandle,pAsynIoOperation) ) 

#define IAsynIoDevice_Detach(This,level)	\
    ( (This)->lpVtbl -> Detach(This,level) ) 

#define IAsynIoDevice_Close(This,reserved)	\
    ( (This)->lpVtbl -> Close(This,reserved) ) 

#define IAsynIoDevice_Clone(This,lpReserved,riid,ppObject)	\
    ( (This)->lpVtbl -> Clone(This,lpReserved,riid,ppObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIoDevice_INTERFACE_DEFINED__ */


#ifndef __IAsynIoBridge_INTERFACE_DEFINED__
#define __IAsynIoBridge_INTERFACE_DEFINED__

/* interface IAsynIoBridge */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynIoBridge;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BA6B23B-FF8B-4b2f-9D6F-E0B5B1B5B630")
    IAsynIoBridge : public IObjectHolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ uint64_t unused,
            /* [in] */ IAsynMessageEvents *events) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynIoBridgeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynIoBridge * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynIoBridge * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynIoBridge * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynIoBridge * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynIoBridge * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAsynIoBridge * This,
            /* [in] */ uint64_t unused,
            /* [in] */ IAsynMessageEvents *events);
        
        END_INTERFACE
    } IAsynIoBridgeVtbl;

    interface IAsynIoBridge
    {
        CONST_VTBL struct IAsynIoBridgeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynIoBridge_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynIoBridge_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynIoBridge_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynIoBridge_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynIoBridge_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynIoBridge_Invoke(This,unused,events)	\
    ( (This)->lpVtbl -> Invoke(This,unused,events) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynIoBridge_INTERFACE_DEFINED__ */


#ifndef __IAsynFrame_INTERFACE_DEFINED__
#define __IAsynFrame_INTERFACE_DEFINED__

/* interface IAsynFrame */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F16D983-8774-4daa-9239-E3B2F9E9E199")
    IAsynFrame : public IObjectHolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAsynFrameThread( 
            /* [out] */ IAsynFrameThread **ppAsynFrameThread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendMessage( 
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostMessage( 
            /* [in] */ BOOL check,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NewIoBuffer( 
            /* [out] */ IBuffer **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTimer( 
            /* [in] */ uint32_t timerid,
            /* [in] */ uint64_t lparam2,
            /* [in] */ int32_t iTimeout,
            /* [in] */ BOOL bCycled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteTimer( 
            /* [in] */ uint32_t timerid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Sleep( 
            /* [in] */ int32_t iTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynIoOperation( 
            /* [in] */ uint32_t lparam1,
            /* [in] */ uint32_t lparam2,
            /* [out] */ IAsynIoOperation **ppAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAsynIoOperation( 
            /* [in] */ IAsynIoOperation *pAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [in] */ uint32_t how) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IAsynIoOperation *lpAsynIoOperation,
            /* [in] */ uint32_t lparam2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pop( 
            /* [in] */ uint32_t lparam2,
            /* [out] */ IAsynIoOperation **ppAsynIoOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFrame * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFrame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IAsynFrame * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IAsynFrame * This,
            /* [in] */ int32_t method,
            /* [in] */ uint32_t lparam2,
            /* [in] */ IUnknown *pObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetAsynFrameThread )( 
            IAsynFrame * This,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread);
        
        HRESULT ( STDMETHODCALLTYPE *SendMessage )( 
            IAsynFrame * This,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *PostMessage )( 
            IAsynFrame * This,
            /* [in] */ BOOL check,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *NewIoBuffer )( 
            IAsynFrame * This,
            /* [out] */ IBuffer **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTimer )( 
            IAsynFrame * This,
            /* [in] */ uint32_t timerid,
            /* [in] */ uint64_t lparam2,
            /* [in] */ int32_t iTimeout,
            /* [in] */ BOOL bCycled);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteTimer )( 
            IAsynFrame * This,
            /* [in] */ uint32_t timerid);
        
        HRESULT ( STDMETHODCALLTYPE *Sleep )( 
            IAsynFrame * This,
            /* [in] */ int32_t iTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIoOperation )( 
            IAsynFrame * This,
            /* [in] */ uint32_t lparam1,
            /* [in] */ uint32_t lparam2,
            /* [out] */ IAsynIoOperation **ppAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAsynIoOperation )( 
            IAsynFrame * This,
            /* [in] */ IAsynIoOperation *pAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IAsynFrame * This,
            /* [in] */ uint32_t how);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAsynFrame * This,
            /* [in] */ IAsynIoOperation *lpAsynIoOperation,
            /* [in] */ uint32_t lparam2);
        
        HRESULT ( STDMETHODCALLTYPE *Pop )( 
            IAsynFrame * This,
            /* [in] */ uint32_t lparam2,
            /* [out] */ IAsynIoOperation **ppAsynIoOperation);
        
        HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IAsynFrame * This);
        
        END_INTERFACE
    } IAsynFrameVtbl;

    interface IAsynFrame
    {
        CONST_VTBL struct IAsynFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFrame_Get(This,method,lparam2,riid,ppObject)	\
    ( (This)->lpVtbl -> Get(This,method,lparam2,riid,ppObject) ) 

#define IAsynFrame_Set(This,method,lparam2,pObject)	\
    ( (This)->lpVtbl -> Set(This,method,lparam2,pObject) ) 


#define IAsynFrame_GetAsynFrameThread(This,ppAsynFrameThread)	\
    ( (This)->lpVtbl -> GetAsynFrameThread(This,ppAsynFrameThread) ) 

#define IAsynFrame_SendMessage(This,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> SendMessage(This,message,lparam1,lparam2,object) ) 

#define IAsynFrame_PostMessage(This,check,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> PostMessage(This,check,message,lparam1,lparam2,object) ) 

#define IAsynFrame_NewIoBuffer(This,ppBuffer)	\
    ( (This)->lpVtbl -> NewIoBuffer(This,ppBuffer) ) 

#define IAsynFrame_CreateTimer(This,timerid,lparam2,iTimeout,bCycled)	\
    ( (This)->lpVtbl -> CreateTimer(This,timerid,lparam2,iTimeout,bCycled) ) 

#define IAsynFrame_DeleteTimer(This,timerid)	\
    ( (This)->lpVtbl -> DeleteTimer(This,timerid) ) 

#define IAsynFrame_Sleep(This,iTimeout)	\
    ( (This)->lpVtbl -> Sleep(This,iTimeout) ) 

#define IAsynFrame_CreateAsynIoOperation(This,lparam1,lparam2,ppAsynIoOperation)	\
    ( (This)->lpVtbl -> CreateAsynIoOperation(This,lparam1,lparam2,ppAsynIoOperation) ) 

#define IAsynFrame_CancelAsynIoOperation(This,pAsynIoOperation)	\
    ( (This)->lpVtbl -> CancelAsynIoOperation(This,pAsynIoOperation) ) 

#define IAsynFrame_Cancel(This,how)	\
    ( (This)->lpVtbl -> Cancel(This,how) ) 

#define IAsynFrame_Add(This,lpAsynIoOperation,lparam2)	\
    ( (This)->lpVtbl -> Add(This,lpAsynIoOperation,lparam2) ) 

#define IAsynFrame_Pop(This,lparam2,ppAsynIoOperation)	\
    ( (This)->lpVtbl -> Pop(This,lparam2,ppAsynIoOperation) ) 

#define IAsynFrame_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFrame_INTERFACE_DEFINED__ */


#ifndef __IAsynFrameThread_INTERFACE_DEFINED__
#define __IAsynFrameThread_INTERFACE_DEFINED__

/* interface IAsynFrameThread */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFrameThread;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B5E89FF-D258-4443-8096-C3BCCB2DDCBA")
    IAsynFrameThread : public IThread
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InThread( 
            /* [in] */ uint32_t threadid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Dispatch( 
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindAsynIoOperation( 
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [in] */ uint32_t mode,
            /* [in] */ int32_t iTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostAsynIoOperation( 
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [in] */ int32_t iTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynFrame( 
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t lMaxIdleSize,
            /* [out] */ IAsynFrame **ppAsynFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynIoBridge( 
            /* [in] */ IAsynIoDevice *pSrcAsynIoDevice,
            /* [in] */ IUnknown *target,
            /* [in] */ BOOL duplex,
            /* [out] */ IAsynIoBridge **ppAsynIoBridge) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFrameThreadVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFrameThread * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFrameThread * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFrameThread * This);
        
        HRESULT ( STDMETHODCALLTYPE *ModifyThreadPriority )( 
            IAsynFrameThread * This,
            /* [in] */ int32_t priority);
        
        HRESULT ( STDMETHODCALLTYPE *Post )( 
            IAsynFrameThread * This,
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *InThread )( 
            IAsynFrameThread * This,
            /* [in] */ uint32_t threadid);
        
        HRESULT ( STDMETHODCALLTYPE *Dispatch )( 
            IAsynFrameThread * This,
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *BindAsynIoOperation )( 
            IAsynFrameThread * This,
            /* [in] */ IAsynIoOperation *pSrcAsynIoOperation,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [in] */ uint32_t mode,
            /* [in] */ int32_t iTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *PostAsynIoOperation )( 
            IAsynFrameThread * This,
            /* [in] */ IAsynIoOperation *pDstAsynIoOperation,
            /* [in] */ int32_t iTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynFrame )( 
            IAsynFrameThread * This,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ uint32_t lMaxIdleSize,
            /* [out] */ IAsynFrame **ppAsynFrame);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynIoBridge )( 
            IAsynFrameThread * This,
            /* [in] */ IAsynIoDevice *pSrcAsynIoDevice,
            /* [in] */ IUnknown *target,
            /* [in] */ BOOL duplex,
            /* [out] */ IAsynIoBridge **ppAsynIoBridge);
        
        END_INTERFACE
    } IAsynFrameThreadVtbl;

    interface IAsynFrameThread
    {
        CONST_VTBL struct IAsynFrameThreadVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFrameThread_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFrameThread_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFrameThread_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFrameThread_ModifyThreadPriority(This,priority)	\
    ( (This)->lpVtbl -> ModifyThreadPriority(This,priority) ) 

#define IAsynFrameThread_Post(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Post(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object) ) 


#define IAsynFrameThread_InThread(This,threadid)	\
    ( (This)->lpVtbl -> InThread(This,threadid) ) 

#define IAsynFrameThread_Dispatch(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Dispatch(This,pSrcAsynIoOperation,events,message,lparam1,lparam2,object) ) 

#define IAsynFrameThread_BindAsynIoOperation(This,pSrcAsynIoOperation,pDstAsynIoOperation,mode,iTimeout)	\
    ( (This)->lpVtbl -> BindAsynIoOperation(This,pSrcAsynIoOperation,pDstAsynIoOperation,mode,iTimeout) ) 

#define IAsynFrameThread_PostAsynIoOperation(This,pDstAsynIoOperation,iTimeout)	\
    ( (This)->lpVtbl -> PostAsynIoOperation(This,pDstAsynIoOperation,iTimeout) ) 

#define IAsynFrameThread_CreateAsynFrame(This,events,lMaxIdleSize,ppAsynFrame)	\
    ( (This)->lpVtbl -> CreateAsynFrame(This,events,lMaxIdleSize,ppAsynFrame) ) 

#define IAsynFrameThread_CreateAsynIoBridge(This,pSrcAsynIoDevice,target,duplex,ppAsynIoBridge)	\
    ( (This)->lpVtbl -> CreateAsynIoBridge(This,pSrcAsynIoDevice,target,duplex,ppAsynIoBridge) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFrameThread_INTERFACE_DEFINED__ */


#ifndef __IAsynFrameThreadFactory_INTERFACE_DEFINED__
#define __IAsynFrameThreadFactory_INTERFACE_DEFINED__

/* interface IAsynFrameThreadFactory */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFrameThreadFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1A00D0BF-C0A0-455b-8A86-83AB6ED7630D")
    IAsynFrameThreadFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryThread( 
            /* [in] */ uint32_t threadid,
            /* [in] */ REFIID Riid,
            /* [out] */ IUnknown **ppThread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAsynFrameThread( 
            /* [in] */ handle hThread,
            /* [in] */ BOOL window,
            /* [in] */ uint32_t coretype,
            /* [in] */ IAsynMessageEvents *events,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFrameThreadFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFrameThreadFactory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFrameThreadFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFrameThreadFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryThread )( 
            IAsynFrameThreadFactory * This,
            /* [in] */ uint32_t threadid,
            /* [in] */ REFIID Riid,
            /* [out] */ IUnknown **ppThread);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAsynFrameThread )( 
            IAsynFrameThreadFactory * This,
            /* [in] */ handle hThread,
            /* [in] */ BOOL window,
            /* [in] */ uint32_t coretype,
            /* [in] */ IAsynMessageEvents *events,
            /* [out] */ IAsynFrameThread **ppAsynFrameThread);
        
        END_INTERFACE
    } IAsynFrameThreadFactoryVtbl;

    interface IAsynFrameThreadFactory
    {
        CONST_VTBL struct IAsynFrameThreadFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFrameThreadFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFrameThreadFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFrameThreadFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFrameThreadFactory_QueryThread(This,threadid,Riid,ppThread)	\
    ( (This)->lpVtbl -> QueryThread(This,threadid,Riid,ppThread) ) 

#define IAsynFrameThreadFactory_CreateAsynFrameThread(This,hThread,window,coretype,events,ppAsynFrameThread)	\
    ( (This)->lpVtbl -> CreateAsynFrameThread(This,hThread,window,coretype,events,ppAsynFrameThread) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFrameThreadFactory_INTERFACE_DEFINED__ */


#ifndef __InstancesManager_INTERFACE_DEFINED__
#define __InstancesManager_INTERFACE_DEFINED__

/* interface InstancesManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_InstancesManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB2CD54D-2BCB-41c8-9757-99B43F202024")
    InstancesManager : public IAsynMessageObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NewInstance( 
            /* [in] */ IUnknown **param1,
            /* [in] */ uint64_t param2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInstance( 
            /* [in] */ STRING Name,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInstance( 
            /* [in] */ STRING Name,
            /* [in] */ IUnknown *lpObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Require( 
            /* [in] */ STRING Owner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Observe( 
            /* [in] */ STRING Ident,
            /* [in] */ handle Soctx) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct InstancesManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            InstancesManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            InstancesManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            InstancesManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *Attach )( 
            InstancesManager * This,
            /* [in] */ IUnknown *observer,
            /* [in] */ uint64_t subject);
        
        HRESULT ( STDMETHODCALLTYPE *Detach )( 
            InstancesManager * This,
            /* [in] */ IUnknown *observer);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            InstancesManager * This,
            /* [in] */ STRING *subject,
            /* [in] */ uint32_t message,
            /* [in] */ uint64_t lparam1,
            /* [in] */ uint64_t lparam2,
            /* [in] */ IUnknown *object);
        
        HRESULT ( STDMETHODCALLTYPE *NewInstance )( 
            InstancesManager * This,
            /* [in] */ IUnknown **param1,
            /* [in] */ uint64_t param2,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetInstance )( 
            InstancesManager * This,
            /* [in] */ STRING Name,
            /* [in] */ REFIID riid,
            /* [out] */ IUnknown **ppObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetInstance )( 
            InstancesManager * This,
            /* [in] */ STRING Name,
            /* [in] */ IUnknown *lpObject);
        
        HRESULT ( STDMETHODCALLTYPE *Require )( 
            InstancesManager * This,
            /* [in] */ STRING Owner);
        
        HRESULT ( STDMETHODCALLTYPE *Observe )( 
            InstancesManager * This,
            /* [in] */ STRING Ident,
            /* [in] */ handle Soctx);
        
        END_INTERFACE
    } InstancesManagerVtbl;

    interface InstancesManager
    {
        CONST_VTBL struct InstancesManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define InstancesManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define InstancesManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define InstancesManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define InstancesManager_Attach(This,observer,subject)	\
    ( (This)->lpVtbl -> Attach(This,observer,subject) ) 

#define InstancesManager_Detach(This,observer)	\
    ( (This)->lpVtbl -> Detach(This,observer) ) 

#define InstancesManager_Notify(This,subject,message,lparam1,lparam2,object)	\
    ( (This)->lpVtbl -> Notify(This,subject,message,lparam1,lparam2,object) ) 


#define InstancesManager_NewInstance(This,param1,param2,riid,ppObject)	\
    ( (This)->lpVtbl -> NewInstance(This,param1,param2,riid,ppObject) ) 

#define InstancesManager_GetInstance(This,Name,riid,ppObject)	\
    ( (This)->lpVtbl -> GetInstance(This,Name,riid,ppObject) ) 

#define InstancesManager_SetInstance(This,Name,lpObject)	\
    ( (This)->lpVtbl -> SetInstance(This,Name,lpObject) ) 

#define InstancesManager_Require(This,Owner)	\
    ( (This)->lpVtbl -> Require(This,Owner) ) 

#define InstancesManager_Observe(This,Ident,Soctx)	\
    ( (This)->lpVtbl -> Observe(This,Ident,Soctx) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __InstancesManager_INTERFACE_DEFINED__ */


#ifndef __IAsynFramePlugin_INTERFACE_DEFINED__
#define __IAsynFramePlugin_INTERFACE_DEFINED__

/* interface IAsynFramePlugin */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsynFramePlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E28ADF6E-BC0E-4561-88DF-E3E610C59B8F")
    IAsynFramePlugin : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ InstancesManager *pInstancesManager,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ IKeyvalSetter *param2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanUnloadNow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsynFramePluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsynFramePlugin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsynFramePlugin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsynFramePlugin * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAsynFramePlugin * This,
            /* [in] */ InstancesManager *pInstancesManager,
            /* [in] */ IAsynMessageEvents *events,
            /* [in] */ IKeyvalSetter *param2);
        
        HRESULT ( STDMETHODCALLTYPE *CanUnloadNow )( 
            IAsynFramePlugin * This);
        
        HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IAsynFramePlugin * This);
        
        END_INTERFACE
    } IAsynFramePluginVtbl;

    interface IAsynFramePlugin
    {
        CONST_VTBL struct IAsynFramePluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsynFramePlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsynFramePlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsynFramePlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsynFramePlugin_Initialize(This,pInstancesManager,events,param2)	\
    ( (This)->lpVtbl -> Initialize(This,pInstancesManager,events,param2) ) 

#define IAsynFramePlugin_CanUnloadNow(This)	\
    ( (This)->lpVtbl -> CanUnloadNow(This) ) 

#define IAsynFramePlugin_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsynFramePlugin_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAsynFrame_0000_0024 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IAsynFrame_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAsynFrame_0000_0024_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



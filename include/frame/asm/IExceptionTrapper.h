

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Jan 28 08:50:52 2023
 */
/* Compiler settings for IExceptionTrapper.idl:
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

#ifndef __IExceptionTrapper_h__
#define __IExceptionTrapper_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IExceptionTrapper_FWD_DEFINED__
#define __IExceptionTrapper_FWD_DEFINED__
typedef interface IExceptionTrapper IExceptionTrapper;

#endif 	/* __IExceptionTrapper_FWD_DEFINED__ */


/* header files for imported files */
#include "IAsynFrame.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IExceptionTrapper_0000_0000 */
/* [local] */ 

#pragma pack(push, 1)


extern RPC_IF_HANDLE __MIDL_itf_IExceptionTrapper_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IExceptionTrapper_0000_0000_v0_0_s_ifspec;

#ifndef __IExceptionTrapper_INTERFACE_DEFINED__
#define __IExceptionTrapper_INTERFACE_DEFINED__

/* interface IExceptionTrapper */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IExceptionTrapper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1F4C098C-5615-4623-8EB0-64A012DC7DB4")
    IExceptionTrapper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetupThreadExceptionTrapper( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteDumpfile( 
            /* [in] */ STRING memname,
            /* [in] */ uint32_t dumptype,
            /* [in] */ STRING filepath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DumpStackinfo( 
            /* [in] */ STRING memname,
            /* [in] */ IStringSetter *stack) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IExceptionTrapperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExceptionTrapper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExceptionTrapper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExceptionTrapper * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetupThreadExceptionTrapper )( 
            IExceptionTrapper * This);
        
        HRESULT ( STDMETHODCALLTYPE *WriteDumpfile )( 
            IExceptionTrapper * This,
            /* [in] */ STRING memname,
            /* [in] */ uint32_t dumptype,
            /* [in] */ STRING filepath);
        
        HRESULT ( STDMETHODCALLTYPE *DumpStackinfo )( 
            IExceptionTrapper * This,
            /* [in] */ STRING memname,
            /* [in] */ IStringSetter *stack);
        
        END_INTERFACE
    } IExceptionTrapperVtbl;

    interface IExceptionTrapper
    {
        CONST_VTBL struct IExceptionTrapperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExceptionTrapper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExceptionTrapper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExceptionTrapper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExceptionTrapper_SetupThreadExceptionTrapper(This)	\
    ( (This)->lpVtbl -> SetupThreadExceptionTrapper(This) ) 

#define IExceptionTrapper_WriteDumpfile(This,memname,dumptype,filepath)	\
    ( (This)->lpVtbl -> WriteDumpfile(This,memname,dumptype,filepath) ) 

#define IExceptionTrapper_DumpStackinfo(This,memname,stack)	\
    ( (This)->lpVtbl -> DumpStackinfo(This,memname,stack) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExceptionTrapper_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IExceptionTrapper_0000_0001 */
/* [local] */ 

#pragma pack(pop)


extern RPC_IF_HANDLE __MIDL_itf_IExceptionTrapper_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IExceptionTrapper_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif





/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 26 17:24:41 2022
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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IAsynNetIoOperation,0x5544D1A8,0x7C18,0x4e08,0x98,0xC2,0x48,0x52,0x29,0x83,0xB3,0xA0);


MIDL_DEFINE_GUID(IID, IID_IAsynDnsResolver,0x13C32332,0xEED4,0x4701,0x86,0x44,0xC2,0xF6,0xE3,0xCC,0xBF,0xE6);


MIDL_DEFINE_GUID(IID, IID_IAsynTcplinkManager,0x11B383C7,0xEAFE,0x4766,0x85,0xC0,0x69,0x79,0x37,0x99,0xB4,0xA3);


MIDL_DEFINE_GUID(IID, IID_IAsynRawSocket,0x2D7B9AE9,0xC33A,0x4d98,0xB7,0x38,0x59,0x6F,0x82,0x04,0x49,0x93);


MIDL_DEFINE_GUID(IID, IID_IAsynUdpSocket,0x2C94171F,0x82C0,0x4ccb,0xA8,0x83,0x76,0xE2,0x9C,0x6A,0xEA,0xE2);


MIDL_DEFINE_GUID(IID, IID_IAsynGrpSocket,0x2B9ECE67,0xCEFA,0x4283,0xA0,0x7E,0xDC,0xFF,0x0E,0x8A,0x59,0x86);


MIDL_DEFINE_GUID(IID, IID_IAsynTcpSocket,0x35671780,0x4E44,0x4563,0xA3,0x30,0x28,0x76,0xAE,0xE3,0xA5,0xBB);


MIDL_DEFINE_GUID(IID, IID_IAsynTcpSocketListener,0x91AAF082,0xBA4B,0x4c28,0xB0,0x42,0xD3,0xCA,0xB0,0x24,0x4E,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAsynDtpSocketListener,0xA243506A,0x6E9C,0x453c,0xB5,0x56,0xF0,0xC9,0x61,0x95,0x50,0xDE);


MIDL_DEFINE_GUID(IID, IID_IAsynMuxSocket,0x85AE4F4C,0xA618,0x49fc,0x9C,0x01,0xE4,0x1E,0x8F,0xE8,0x96,0x5E);


MIDL_DEFINE_GUID(IID, IID_IAppService,0xDFDD78F9,0x309A,0x4bb9,0x97,0xD0,0x16,0x19,0x69,0xB9,0xD1,0x92);


MIDL_DEFINE_GUID(IID, IID_IAsynNetwork,0x8AA7483F,0x9A26,0x4153,0xA4,0x03,0xC9,0x0A,0x49,0x20,0x0E,0x73);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




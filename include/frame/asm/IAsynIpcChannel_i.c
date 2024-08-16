

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IAsynIpcIoOperation,0x63A88D82,0x1EB4,0x45a1,0x84,0x7D,0x0F,0x2A,0xE3,0xD5,0x4D,0x06);


MIDL_DEFINE_GUID(IID, IID_IAsynNamedPipe,0x852F8BD3,0x2CC0,0x40c4,0x81,0x56,0x6A,0xF0,0x73,0x5F,0xFC,0xBD);


MIDL_DEFINE_GUID(IID, IID_IAsynIpcDevice,0xEB387F4A,0x854B,0x41f2,0xB9,0x2A,0x0C,0x80,0xE2,0xE4,0x45,0x15);


MIDL_DEFINE_GUID(IID, IID_IAsynIpcDeviceListener,0x9ED3FDED,0xC662,0x4d3c,0xA9,0x51,0x29,0xE7,0xFD,0xED,0xAD,0xAF);


MIDL_DEFINE_GUID(IID, IID_IAsynIpcChannel,0xD453C04E,0xA8E6,0x4d8d,0xB0,0x24,0x44,0x23,0x65,0xE8,0x6B,0x85);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




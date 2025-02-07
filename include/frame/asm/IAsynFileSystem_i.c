

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Nov 15 14:12:26 2024
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

MIDL_DEFINE_GUID(IID, IID_IAsynFileIoOperation,0x19210367,0xE7A5,0x453a,0x92,0x7B,0xB0,0x7C,0xA4,0x50,0x74,0x1E);


MIDL_DEFINE_GUID(IID, IID_IAsynRawDevice,0xE84C89BE,0x2582,0x4afa,0xBB,0xF6,0x3C,0x47,0xD6,0x55,0x24,0x6E);


MIDL_DEFINE_GUID(IID, IID_IAsynFile,0x6B4BA849,0xDD57,0x4590,0x93,0xBD,0xEF,0x84,0xAE,0x97,0xC1,0x93);


MIDL_DEFINE_GUID(IID, IID_IAsynFileWatcher,0x4F01E7E2,0xD839,0x4af2,0xAC,0x4D,0xDC,0xEA,0x84,0x42,0x5B,0x68);


MIDL_DEFINE_GUID(IID, IID_IAsynFileSystem,0x8195BCC2,0xEFFB,0x4106,0xAC,0xAE,0x20,0xDF,0xBF,0xE8,0x49,0x08);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




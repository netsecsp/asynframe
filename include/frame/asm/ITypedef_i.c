

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Jan 18 10:39:45 2023
 */
/* Compiler settings for ITypedef.idl:
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

MIDL_DEFINE_GUID(IID, IID_IRangesVector,0x864BC6A2,0x5BDA,0x4eda,0xAD,0xD4,0xB6,0xEB,0xC2,0xBB,0x17,0x1D);


MIDL_DEFINE_GUID(IID, IID_IStringSetter,0x30044812,0x451F,0x4d2a,0x88,0x8C,0xA3,0xD8,0x22,0x2A,0x6F,0xBA);


MIDL_DEFINE_GUID(IID, IID_IStringVector,0xB8A6AAB4,0x0DA2,0x49C1,0x8B,0x83,0x7E,0xF4,0xA9,0x16,0xBF,0x16);


MIDL_DEFINE_GUID(IID, IID_IStringStack,0x24CEF41C,0x4C1B,0x499b,0xB3,0xA4,0x85,0x11,0x9C,0xB9,0x8B,0x3A);


MIDL_DEFINE_GUID(IID, IID_IKeyvalSetter,0x92552692,0x3635,0x4e41,0xAF,0x63,0xD9,0x21,0xE0,0xCE,0xE6,0xD4);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




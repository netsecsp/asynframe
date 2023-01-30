/*****************************************************************************
Copyright (c) 2012 - 2032, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 05/01/2022
http://asynframe.sf.net

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the
above copyright notice, this list of conditions
and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/
#include "stdafx.h"
#include <conio.h>

#include <frame/AsynNetwork_internal.h>
#include <frame/asm/ISsl.h>
#define AAPIDLL_USING

#ifdef  AAPIDLL_USING
#include <frame/asm/ITypedef_i.c>
#include <frame/asm/IAsynFrame_i.c>
#include <frame/asm/IAsynFileSystem_i.c>
#include <frame/asm/IAsynNetwork_i.c>
#include <frame/asm/ISsl_i.c>
#endif
#include "TcpEvent.h"
#include "windows.h"

#pragma comment(lib,"crypt32.lib")
#ifdef  AAPIDLL_USING
#ifdef _DEBUG
#pragma comment(lib, "asynsdk_mini-MDd.lib")
#else
#pragma comment(lib, "asynsdk_mini-MD.lib")
#endif
#pragma comment(lib,"asyncore_dll.lib")
#else
#pragma comment(lib,"asynframe_lib.lib")
#endif
STDAPI_(extern HRESULT) Initialize( /*[in ]*/IAsynMessageEvents *param1, /*[in ]*/IUnknown *param2 );
STDAPI_(extern HRESULT) Destory();
STDAPI_(extern InstancesManager *) GetInstancesManager();

static byte B2H( char ch )
{
    if( ch >= '0' && ch <= '9' )
    {
        return ch - '0';
    }

    if( ch >= 'A' && ch <= 'F' )
    {
        return ch - 'A' + 0xa;
    }

    if( ch >= 'a' && ch <= 'f' )
    {
        return ch - 'a' + 0xa;
    }
    else
    {
        return 0;
    }
}

int _tmain(int argc, _TCHAR *argv[])
{
    printf("usage: %s host port thumb[40]\n\texample: %s 127.0.0.1 7675 205d4828037668166b3dff4fa7dc810559426602\n\t         %s 127.0.0.1 7675 p12 password\n", argv[0], argv[0], argv[0]);

    PCCERT_CONTEXT pctx = 0;
	BYTE temp[4096];
    STRING certandpasswd[2];
	HCERTSTORE hMyCertStore = 0;

    certandpasswd[0].ptr = temp;
    certandpasswd[0].len = 0;
    certandpasswd[1].ptr = 0;
    certandpasswd[1].len = 0;
    #if  0
    char *hex = argc > 3 ? argv[3] : "205d4828037668166b3dff4fa7dc810559426602";
    BYTE thumb[21]; for(int i = 0, n = 0; i < 40; i += 2, n ++) thumb[n] = (B2H(hex[i + 0]) << 4) + B2H(hex[i + 1]);
    hMyCertStore = CertOpenSystemStore(0, _T("ROOT"));
    CRYPT_HASH_BLOB hash = {20, thumb};
    pctx = CertFindCertificateInStore(hMyCertStore, PKCS_7_ASN_ENCODING, 0, CERT_FIND_HASH, &hash, NULL);
    #else
    FILE* f = 0; fopen_s(&f, argc > 4 ? argv[4] : "client.p12", "rb");
	if(!f ) {
        printf("not found %s\n", argc > 4 ? argv[4] : "client.p12");
        return 1;
    }
    certandpasswd[0].len = fread(certandpasswd[0].ptr, 1, sizeof(temp), f);
	fclose(f);
    certandpasswd[1].ptr = (unsigned char*)(argc > 5 ? argv[5] : "123456");
    certandpasswd[1].len = strlen((char*)certandpasswd[1].ptr);
    #endif

    HRESULT hr1 = Initialize(NULL, NULL);

    do{
        InstancesManager *lpInstancesManager = GetInstancesManager();

        if( lpInstancesManager->Require(STRING_from_string(IN_AsynNetwork)) != S_OK )
        {
            printf("can't load plugin: %s\n", IN_AsynNetwork);
            break;
        }

        CComPtr<IAsynNetwork     > spAsynNetwork;
        lpInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

        CComPtr<IAsynFrameThread> spAsynFrameThread;
        lpInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (void **)&spAsynFrameThread);

        CTcpEvent *pEvent = new CTcpEvent(spAsynNetwork, spAsynFrameThread, 23);
        if( pEvent->Connect((handle)pctx, pctx? 0 : certandpasswd, argc > 1 ? argv[1] : "127.0.0.1", atoi(argc > 2 ? argv[2] : "7675")) )
        {
			if (pctx) CertFreeCertificateContext(pctx);
			if (hMyCertStore) CertCloseStore(hMyCertStore, 0);
            while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                    _kbhit() == 0 )
            {
                Sleep(100);
            }
        }

        pEvent->Shutdown();
        delete pEvent;
    }while(0);

    HRESULT hr2 = Destory();
    return 0;
}


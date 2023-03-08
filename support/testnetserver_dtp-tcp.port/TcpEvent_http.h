/*****************************************************************************
Copyright (c) 2012 - 2019, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 03/16/2015
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
#pragma once
#include <frame/asm/Inet.h>
#include "setting.h"
#include <map>

class CTcpEvent_http : public asynsdk::asyn_message_events_impl
{
public:
    CTcpEvent_http(IAsynFrameThread *lpAsynFrameThread, IAsynFileSystem *lpAsynFileSystem, IAsynNetwork *lpAsynNetwork)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynFileSystem  = lpAsynFileSystem;
        m_spAsynNetwork     = lpAsynNetwork;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown** objects)
    {
        if( lMessageId == AF_EVENT_NOTIFY )
        {
            IAsynIoBridge *pAsynIoBridge = (IAsynIoBridge *)lParam1;
            std::map<IAsynIoBridge *, userinfo *>::iterator it = m_arBr2Userinfos.find(pAsynIoBridge);
            if( it == m_arBr2Userinfos.end()) return S_OK;

            userinfo *info = it->second;
            m_arBr2Userinfos.erase(pAsynIoBridge);

            if( lParam2 == NO_ERROR )
                printf("transmit completed\n");
            else
                printf("occur error: %lld from %p\n", lParam2, pAsynIoBridge);

            printf("remove client: %s\n", info->ident.c_str());
            m_arId2Userinfos.erase(info->ident);
            return S_OK;
        }
        if( lMessageId == AF_QUERY_RESULT )
        {
            if( m_spDtpService == (IDtpService*)lParam1 )
            {
                std::string packet((char *)((STRING *)lParam2)->ptr, ((STRING *)lParam2)->len);
                return packet.find("HTTP/1.1") != std::string::npos ? S_OK : E_NOTIMPL;
            }
            else
            {
                std::map<IAsynIoBridge *, userinfo *>::iterator it = m_arBr2Userinfos.find((IAsynIoBridge *)lParam1);
                if( it == m_arBr2Userinfos.end()) return S_OK;

                userinfo *info = it->second;
                printf("transmit: %lld to %s\n", lParam2, info->ident.c_str());
                info->datasize -= lParam2;
                return info->datasize > 0 ? S_OK : S_FALSE;
            }
        }
        if( lMessageId == AF_IOMSG_NOTIFY )
        {
            IAsynIoOperation* lpAsynIoOperation = (IAsynIoOperation*)objects[0];
            uint32_t lErrorCode, lTransferedBytes;
            lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    printf("recv, error: %d\n", lErrorCode);
                    userinfo *info = m_arOp2Userinfos[lpAsynIoOperation];
                    printf("remove client: %s\n", info->ident.c_str());
                    m_arOp2Userinfos.erase(lpAsynIoOperation);
                    m_arId2Userinfos.erase(info->ident);
                    return E_NOTIMPL;
                }
                else
                {
                    //接收来自客户端的HTTP请求(不带包体，目前没有处理包体)
                    userinfo *info = m_arOp2Userinfos[lpAsynIoOperation];
                    m_arOp2Userinfos.erase(lpAsynIoOperation);

                    CComPtr<INetmsg> spReqmsg;
                    lpAsynIoOperation->GetCompletedObject(TRUE, IID_INetmsg, (void **)&spReqmsg);
                    STRING Method;
                    STRING Params;
                    spReqmsg->Getline(&Method, &Params, 0, 0);
                    std::string method = string_from_STRING(Method);
                    std::string params = string_from_STRING(Params);
                    printf("recv req: %s %s\n", method.c_str(), params.c_str());

                    std::string dir;
                    std::string::size_type pos1 = params.rfind('/');
                    if( pos1 != std::string::npos ) dir = params.substr(0, pos1);

                    setting sets("config.txt");
                    std::string filename;
                    std::string::size_type pos2 = params.find_last_of('/');
                    if( pos2 == std::string::npos )
                        filename = sets.get_string("website", "home", ".\\") + dir + "\\" + params;
                    else
                        filename = sets.get_string("website", "home", ".\\") + dir + "\\" + params.substr(pos2 + 1);

                    CComPtr<IAsynFile> spAsynFile;
                    m_spAsynFileSystem->CreateAsynFile(&spAsynFile );
                    HRESULT hr = spAsynFile->Open(m_spAsynFrameThread,
                                                  STRING_from_string(filename),
                                                  GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL);

                    CComPtr<INet> spNet;
                    info->spAsynDataTcpSocket->QueryInterface(IID_INet, (void **)&spNet);

                    if( hr != NO_ERROR )
                    {
                        printf("open %s, error: %d\n", filename.c_str(), hr);
                        spNet->SendPacket(STRING_from_string("404"), STRING_from_string("file is not found"), 0, 0);
                        printf("remove client: %s\n", info->ident.c_str());
                        m_arId2Userinfos.erase(info->ident);
                        return E_NOTIMPL;
                    }
                    else
                    {
                        asynsdk::CKeyvalSetter keyval(1);

                        spAsynFile->GetFileSize(&info->datasize ); //没有考虑文件大小等于0的情况
                        std::string out = std::to_string(info->datasize);
                        keyval.Set(STRING_from_string("Content-Length"), TRUE, STRING_from_string(out));
                        keyval.Set(STRING_from_string("Server"), TRUE, STRING_from_string("ahttp/1.0"));

                        printf("open %s, filesize: %s\n", filename.c_str(), out.c_str());
                        spNet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &keyval, 0);

                        m_spAsynFrameThread->CreateAsynIoBridge(spAsynFile, info->spAsynDataTcpSocket, 0, &info->spAsynIoBridge);
                        m_arBr2Userinfos[info->spAsynIoBridge] = info;
                        info->spAsynIoBridge->Invoke(0, GetAsynMessageEvents());
                        return E_NOTIMPL;
                    }
                }
            }

            if( lParam2 == Io_acceptd )
            {
                if( lErrorCode )
                {
                    printf("accept, error: %d\n", lErrorCode);
                    return m_spAsynTcpSocketListener->Accept(lpAsynIoOperation);
                }
                else
                {
                    asynsdk::CStringSetter host(1);
                    PORT port;
                    {// 新客户端
                        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                        lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                        spAsynIoOperation->GetPeerAddress(&host, 0, &port, 0);
                        printf("accepted from %s:%d\n", host.m_val.c_str(), port);
                    }

                    CComPtr<IAsynTcpSocket> spAsynTcpSocket;
                    lpAsynIoOperation->GetCompletedObject(1, IID_IAsynTcpSocket, (void **)&spAsynTcpSocket);

                    char ident[40];
                    sprintf_s(ident, 40, "%s:%d", host.m_val.c_str(), port);
                    userinfo &info = m_arId2Userinfos[ident];
                    info.ident = ident;
                    info.spAsynDataTcpSocket = spAsynTcpSocket;

                    CComPtr<IAsynIoOperation   > spAsynIoOperation;
                    m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
                    m_arOp2Userinfos[spAsynIoOperation] = &info;

                    info.spAsynDataTcpSocket->Read(spAsynIoOperation);

                    return m_spAsynTcpSocketListener->Accept(lpAsynIoOperation);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    void Start(IDtpService *lpDtp)
    {
        m_spDtpService = lpDtp;

        CComPtr<IAsynDtpSocketListener> spAsynDtpSocketListener;
        m_spDtpService->CreateAsynDtpSocketLayer(GetAsynMessageEvents(), 0, asynsdk::STRING_EX::null, 0, (IUnknown**)&spAsynDtpSocketListener);

        CComPtr<IAsynTcpSocketListener> spAsynTcpSocketListener;
        m_spAsynNetwork->CreateAsynTcpSocketListener(spAsynDtpSocketListener, &spAsynTcpSocketListener);

        CComPtr<IAsynRawSocket> spAsynPtlSocket;
        if( m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("http"), (IUnknown**)&spAsynTcpSocketListener.p, STRING_from_string("tcp/1.1"), &spAsynPtlSocket) != S_OK )
        {
            printf("fail to load plugin: %s\n", "http");
            return;
        }
        else
        {
            spAsynPtlSocket->QueryInterface(IID_IAsynTcpSocketListener, (void**)&m_spAsynTcpSocketListener);
        }

        m_spAsynTcpSocketListener->Open(m_spAsynFrameThread, AF_INET, SOCK_STREAM, IPPROTO_TCP);

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, 0, 0, IID_IAsynNetIoOperation, (void**)&spAsynIoOperation);
        m_spAsynTcpSocketListener->Accept(spAsynIoOperation);
    }

    void Shutdown()
    {
        Stop(m_spAsynFrame);
        m_spAsynFrame = 0;
    }

public:
    CComPtr<IAsynFrameThread   > m_spAsynFrameThread;
    CComPtr<IAsynFrame         > m_spAsynFrame;
    CComPtr<IAsynFileSystem    > m_spAsynFileSystem;
    CComPtr<IAsynNetwork       > m_spAsynNetwork;
    CComPtr<IDtpService        > m_spDtpService;

    CComPtr<IAsynTcpSocketListener> m_spAsynTcpSocketListener;

    struct userinfo
    {
        CComPtr<IAsynTcpSocket> spAsynDataTcpSocket;
        CComPtr<IAsynIoBridge > spAsynIoBridge;
        uint64_t    datasize; //尚未传输长度
        std::string ident;
    };

    std::map<std::string, userinfo > m_arId2Userinfos;
    std::map<IAsynIoOperation *, userinfo *> m_arOp2Userinfos;
    std::map<IAsynIoBridge *, userinfo *> m_arBr2Userinfos;
};

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
#pragma once

#define PER_DATA_SIZE 1500

class CTcpEvent : public asynsdk::asyn_message_events_impl
{
public:
    CTcpEvent(IAsynNetwork *lpAsynNetwork, IAsynFrameThread *lpAsynFrameThread, uint32_t af = 2)
      : m_af(af)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **objects )
    {
        if( lMessageId != AF_IOMSG_NOTIFY )
        {
            printf("lMsg: %d, param: %I64d/%I64d\n", lMessageId, lParam1, lParam2);
        }

        if( lMessageId == AF_IOMSG_NOTIFY )
        {
            IAsynIoOperation *lpAsynIoOperation = (IAsynIoOperation *)objects[0];
            uint32_t lErrorCode, lTransferedBytes;
            lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

            if( lParam2 == Io_recv )
            {
                userinfo &info = m_arOp2Userinfos[lpAsynIoOperation];
                if( lErrorCode )
                {
                    if( lErrorCode != AE_RESET ) printf("recv, error: %d\n", lErrorCode);
                    if(!info.ident.empty())
                    {
                        printf("remove client: %s\n", info.ident.c_str());
                        m_arId2Userinfos.erase(info.ident);
                    }
                    {// remove
                        m_arOp2Userinfos.erase(lpAsynIoOperation);
                    }
                    return E_NOTIMPL;
                }
                else
                {// 接收来自客户端的rtsp/http请求/响应
                    userinfo &info = m_arOp2Userinfos[lpAsynIoOperation];

                    CComPtr<INetmsg> spKeyval;
                    lpAsynIoOperation->GetCompletedObject(1, IID_INetmsg, (void **)&spKeyval);

                    char *body = 0; if( lTransferedBytes ) lpAsynIoOperation->GetIoBuffer(0, 0, (BYTE **)&body);

                    STRING Method;
                    STRING params;
                    BOOL ack;
                    spKeyval->Getline(&Method, &params, 0, &ack );
                    std::string method = string_from_STRING(Method);

                    asynsdk::CStringSetter sessionxcookie;
                    asynsdk::CStringSetter rtsp_tunnelled;

                    if( method == "GET"  )
                    {// http
                        spKeyval->Get(STRING_from_string("x-sessioncookie"), 0, 0, &sessionxcookie);
                        spKeyval->Get(STRING_from_string("Accept"         ), 0, 0, &rtsp_tunnelled);
                        if( sessionxcookie.m_val.empty() || rtsp_tunnelled.m_val != "application/x-rtsp-tunnelled" )
                        {
                            m_arOp2Userinfos.erase(lpAsynIoOperation);
                            return E_NOTIMPL;
                        }

                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("application/x-rtsp-tunnelled"));
                        info.spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, 0);

                        info.ident = sessionxcookie.m_val;
                        m_arId2Userinfos[sessionxcookie.m_val] = &info;
                        return E_NOTIMPL;
                    }
                    if( method == "POST" )
                    {// http
                        spKeyval->Get(STRING_from_string("x-sessioncookie"), 0, 0, &sessionxcookie);
                        spKeyval->Get(STRING_from_string("Content-Type"   ), 0, 0, &rtsp_tunnelled);
                        if( sessionxcookie.m_val.empty() || rtsp_tunnelled.m_val != "application/x-rtsp-tunnelled" )
                        {
                            m_arOp2Userinfos.erase(lpAsynIoOperation);
                            return E_NOTIMPL;
                        }

                        auto it = m_arId2Userinfos.find(sessionxcookie.m_val);
                        if( it == m_arId2Userinfos.end())
                        {
                            m_arOp2Userinfos.erase(lpAsynIoOperation);
                            return E_NOTIMPL;
                        }

                        CComPtr<IAsynRawSocket> spAsynPtlSocket;
                        IUnknown* ppParam2[2];
                        ppParam2[0] = info.spINet;
                        ppParam2[1] = it->second->spINet;
                        m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("rtsp"), ppParam2, STRING_from_string("http/1.0"), &spAsynPtlSocket);
                        if( spAsynPtlSocket == NULL )
                        {
                            m_arId2Userinfos.erase(it);
                            m_arOp2Userinfos.erase(lpAsynIoOperation);
                            return E_NOTIMPL;
                        }
                        else
                        {
                            spAsynPtlSocket->Attach(m_spAsynFrameThread, DA_PasvHandle, 0, 0, 0, 0);
                            m_arId2Userinfos.erase(it);
                            info.spINet = 0;
                            spAsynPtlSocket->QueryInterface(IID_INet, (void**)&info.spINet);
                            return info.spINet->Read(lpAsynIoOperation);
                        }
                    }

                    asynsdk::CStringSetter CSeq;
                    spKeyval->Get(STRING_from_string("CSeq"), 0, 0, &CSeq);

                    if( ack )
                    {// 接收响应
                        printf("recv ack[%s]: %*s %*s\n", CSeq.m_val.c_str(), Method.len, Method.ptr, params.len, params.ptr);
                        if( body ) printf("%s\n", std::string(body, lTransferedBytes).c_str());

                        return info.spINet->Read(lpAsynIoOperation);
                    }
                    else
                    {// 接收请求
                        printf("recv req[%s]: %*s %*s\n", CSeq.m_val.c_str(), Method.len, Method.ptr, params.len, params.ptr);
                        if( body ) printf("%s\n", std::string(body, lTransferedBytes).c_str());
                    }

                    if( method == "SETUP")
                    {
                        /*						RTSP/1.0 200 OK
                        						Session: 2096569862826202657;Timeout=60
                        						CSeq: 1
                        						OnDemandSessionId: 1152339971764523f1000
                        						Transport: MP2T/DVBC/UDP;unicast;destination=10.4.73.240;client_port=31260;bandwidth=3750000;sop_group=SOP1;source=10.4.72.21;server_port=5554
                        						Transport: MP2T/RTP/TCP;unicast;bandwidth=3750000;sop_group=SOP1;source=10.4.72.21;server_port=5555;keystring=2096569862826202657
                        						Content-Type: application/sdp
                        						Content-Length: 165
                        						Server: asyn/1.0
                        						Date: 2014-01-22 02:31:58

                        						v=0
                        						o=- 2096569862826202657 1390329118 IN IP4 10.4.72.21
                        						s=
                        						t=0 0
                        						a=control:rtsp://10.4.72.21:5554/2096569862826202657
                        						c=IN IP4 0.0.0.0
                        						m=video 0 udp MP2T */
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657;Timeout=60"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string(CSeq.m_val));
                        spKeyval.Set(STRING_from_string("OnDemandSessionId"), FALSE, STRING_from_string("1152339971764523f1000"));
                        spKeyval.Set(STRING_from_string("Transport"), FALSE, STRING_from_string("MP2T/DVBC/UDP;unicast;destination=10.4.73.240;client_port=31260;bandwidth=3750000;sop_group=SOP1;source=10.4.72.21;server_port=5554"));
                        spKeyval.Set(STRING_from_string("Transport"), FALSE, STRING_from_string("MP2T/RTP/TCP;unicast;bandwidth=3750000;sop_group=SOP1;source=10.4.72.21;server_port=5555;keystring=2096569862826202657"));
                        spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("application/sdp"));
                        spKeyval.Set(STRING_from_string("Server"), FALSE, STRING_from_string("asyn/1.0"));

                        CComPtr<IAsynIoOperation> spAsynIoOperation;
                        m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
                        char *body = "v=0\n"
                                     "o=- 2096569862826202657 1390329118 IN IP4 10.4.72.21\n"
                                     "s=\n"
                                     "t=0 0\n"
                                     "a=control:rtsp://10.4.72.21:5554/2096569862826202657\n"
                                     "c=IN IP4 0.0.0.0\n"
                                     "m=video 0 udp MP2T";
                        unsigned long bodysize = strlen(body);
                        spAsynIoOperation->NewIoBuffer(0, (BYTE *)body, 0, bodysize, bodysize, 0);
                        spAsynIoOperation->SetIoParams(0, bodysize, bodysize);
                        info.spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, spAsynIoOperation);
                        return info.spINet->Read(lpAsynIoOperation);
                    }
                    if( method == "GET_PARAMETER")
                    {
                        /*						RTSP/1.0 200 OK
                        						Session: 2096569862826202657
                        						CSeq: 14
                        						Content-Type: text/parameters
                        						Content-Length: 34
                        						Server: Coship Stream Server
                        						Date: 2014-01-22 02:32:45

                        						position: 346.000000
                        						scale: 1.0*/
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string(CSeq.m_val));
                        spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("text/parameters"));
                        spKeyval.Set(STRING_from_string("Server"), FALSE, STRING_from_string("asyn/1.0"));

                        CComPtr<IAsynIoOperation> spAsynIoOperation;
                        m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
                        char *body = "position: 346.000000\n"
                                     "scale: 1.0";
                        unsigned long bodysize = strlen(body);
                        spAsynIoOperation->NewIoBuffer(0, (BYTE *)body, 0, bodysize, bodysize, 0);
                        spAsynIoOperation->SetIoParams(0, bodysize, bodysize);
                        info.spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, spAsynIoOperation);
                        return info.spINet->Read(lpAsynIoOperation);
                    }
                    if( method == "PLAY")
                    {
                        /*						RTSP/1.0 200 OK
                        						Session: 2096569862826202657
                        						CSeq: 1
                        						Range: npt=0.0-
                        						Scale: 1
                        						Server: Coship Stream Server
                        						Date: 2014-01-22 02:31:58 */
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string(CSeq.m_val));
                        spKeyval.Set(STRING_from_string("Range"), FALSE, STRING_from_string("npt=0.0-"));
                        spKeyval.Set(STRING_from_string("Scale"), FALSE, STRING_from_string("1"));
                        spKeyval.Set(STRING_from_string("Server"), FALSE, STRING_from_string("asyn/1.0"));

                        info.spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, 0);
                        return info.spINet->Read(lpAsynIoOperation);
                    }

                    if( method == "PAUSE")
                    {
                        /*						RTSP/1.0 200 OK
                        						Session: 2096569862826202657
                        						CSeq: 2
                        						Range: npt=7.0-
                        						Server: Coship Stream Server
                        						Date: 2014-01-22 02:32:04 */
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string(CSeq.m_val));
                        spKeyval.Set(STRING_from_string("Range"), FALSE, STRING_from_string("npt=7.0-"));
                        spKeyval.Set(STRING_from_string("Server"), FALSE, STRING_from_string("asyn/1.0"));

                        info.spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, 0);
                        return info.spINet->Read(lpAsynIoOperation);
                    }

                    if( method == "TEARDOWN")
                    {
                        /*						RTSP/1.0 200 OK
                        						Session: 2096569862826202657
                        						CSeq: 45
                        						OnDemandSessionId: 1152339971764523f1000
                        						StopPoint: 1 3600.000
                        						FinalNPT: 3599
                        						Content-Type: text/xml
                        						Content-Length: 688
                        						Server: Coship Stream Server
                        						Date: 2014-01-22 03:14:47

                        						<ResponseData><ODRMSessionHistory><ODRMSession componentName="COSHIP_SS" ODSessionID="1152339971764523f1000" setupDate="2014-01-21T18:31:58.000Z"teardownDate="2014-01-21T19:14:47.000Z" sessionGroup="SM4" ODRMIpAddr="0.0.0.0" SMIpAddr="0.0.0.0" resultCode="200"><PlayoutHistory time="2014-01-21T19:14:47.000Z"><StreamResources SOP="0" id="1" filename="/mpeg/mpeg2/rc/XGFC/ZSBTV_REAL1390212285785084.ts" provideID="ZSBTV" assetID="REAL1390212285785084" segmentNumber="1"/><EventHistory><EndEvent time="2014-01-21T19:14:47.000Z" streamResourcesID="1" NPT="0" reason="USER" description="User stop" code="200"/></EventHistory></PlayoutHistory></ODRMSession></ODRMSessionHistory></ResponseData> */

                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string(CSeq.m_val));
                        spKeyval.Set(STRING_from_string("OnDemandSessionId"), FALSE, STRING_from_string("1152339971764523f1000"));
                        spKeyval.Set(STRING_from_string("StopPoint"), FALSE, STRING_from_string("1 3600.000"));
                        spKeyval.Set(STRING_from_string("FinalNPT"), FALSE, STRING_from_string("3599"));
                        spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("text/xml"));
                        spKeyval.Set(STRING_from_string("Server"), FALSE, STRING_from_string("asyn/1.0"));

                        CComPtr<IAsynIoOperation> spAsynIoOperation;
                        m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
                        char *body = "<ResponseData><ODRMSessionHistory><ODRMSession componentName=\"SS\" ODSessionID=\"1152339971764523f1000\" setupDate=\"2014-01-21T18:31:58.000Z\" teardownDate=\"2014-01-21T19:14:47.000Z\" sessionGroup=\"SM4\" ODRMIpAddr=\"0.0.0.0\" SMIpAddr=\"0.0.0.0\" resultCode=\"200\"><PlayoutHistory time=\"2014-01-21T19:14:47.000Z\"><StreamResources SOP=\"0\" id=\"1\" filename=\"/mpeg/mpeg2/rc/XGFC/ZSBTV_REAL1390212285785084.ts\" provideID=\"ZSBTV\" assetID=\"REAL1390212285785084\" segmentNumber=\"1\"/><EventHistory><EndEvent time=\"2014-01-21T19:14:47.000Z\" streamResourcesID=\"1\" NPT=\"0\" reason=\"USER\" description=\"User stop\" code=\"200\"/></EventHistory></PlayoutHistory></ODRMSession></ODRMSessionHistory></ResponseData>";
                        unsigned long bodysize = strlen(body);
                        spAsynIoOperation->NewIoBuffer(0, (BYTE *)body, 0, bodysize, bodysize, 0);
                        spAsynIoOperation->SetIoParams(0, bodysize, bodysize);
                        info.spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, spAsynIoOperation);
                        return info.spINet->Read(lpAsynIoOperation);
                    }

                    return info.spINet->Read(lpAsynIoOperation);
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
                    asynsdk::CStringSetter host;
                    PORT                   port;
                    {// new connection
                        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                        lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                        spAsynIoOperation->GetPeerAddress(&host, 0, &port, 0);
                        printf("succ to accept from %s:%d\n", host.m_val.c_str(), port);
                    }

                    CComPtr<IAsynIoOperation> spAsynIoOperation;
                    m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
                    userinfo& info = m_arOp2Userinfos[spAsynIoOperation];

                    {// socket
                        lpAsynIoOperation->GetCompletedObject(1, IID_INet, (void **)&info.spINet);
                    }
                    if(!m_http )
                    {
                        info.ident = host.m_val + ":" + std::to_string(port);
                        m_arId2Userinfos[info.ident] = &info;
                    }

                    //接收请求
                    info.spINet->Read(spAsynIoOperation);

                    return m_spAsynTcpSocketListener->Accept(lpAsynIoOperation);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Start(PORT port, bool http)
    {
        m_http = http;

        CComPtr<IAsynTcpSocketListener> spAsynInnSocket;
        m_spAsynNetwork->CreateAsynTcpSocketListener(0, &spAsynInnSocket);

        CComPtr<IAsynRawSocket> spAsynPtlSocket;
        if( m_http )
        {
            m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("http"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tcp/1.0"), &spAsynPtlSocket);
            if( spAsynPtlSocket == NULL )
            {
                printf("fail to load plugin: http\n");
                return false;
            }

        }
        else
        {
            m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("rtsp"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tcp/1.0"), &spAsynPtlSocket);
            if( spAsynPtlSocket == NULL )
            {
                printf("fail to load plugin: rtsp\n");
                return false;
            }
        }

        spAsynPtlSocket->QueryInterface(IID_IAsynTcpSocketListener, (void**)&m_spAsynTcpSocketListener);
        m_spAsynTcpSocketListener->Open(m_spAsynFrameThread, m_af, SOCK_STREAM, IPPROTO_TCP);
        HRESULT r1 = m_spAsynTcpSocketListener->Bind(asynsdk::STRING_EX::null, port, TRUE, NULL); //同步bind
        if( r1 != S_OK)
        {
            printf("bind *:%d, error: %d\n", port, r1);
            return false;
        }
        if( port == 0 ) m_spAsynTcpSocketListener->GetSockAddress(0, 0, &port, 0);

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);

        printf("tcp.listen *:%d\n", port);
        m_spAsynTcpSocketListener->Accept(spAsynIoOperation);
        return true;
    }

    void Shutdown()
    {
        m_spAsynFrame->Shutdown();
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;
    bool m_http;

    CComPtr<IAsynTcpSocketListener> m_spAsynTcpSocketListener;
    unsigned long m_af; //ipv4/ipv6/ipx
    
    struct userinfo
    {
        CComPtr<INet> spINet;
        std::string   ident;
    };

    std::map<std::string      , userinfo*> m_arId2Userinfos;
    std::map<IAsynIoOperation*, userinfo > m_arOp2Userinfos;
};

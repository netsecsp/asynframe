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
      : m_iaf(af)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        m_spAsynNetwork     = lpAsynNetwork;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        m_hNotify = CreateEvent(NULL, TRUE, FALSE, NULL);
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

            if( lParam2 == Io_connect )
            {
                if( lErrorCode )
                {
                    printf("connect, error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    printf("succ to connect\n\n");
                    /*					SETUP rtsp://10.4.72.21:554 RTSP/1.0
                    					Content-Type: application/sdp
                    					Require: com.comcast.ngod.r2
                    					StreamControlProto: rtsp
                    					Policy: priority=1
                    					Volume: library2103
                    					OnDemandSessionId: 1152339971764523f1000
                    					Transport: MP2T/DVBC/UDP;unicast;client=0000A4D7D0F0;destination=10.4.73.240;client_port=31260;bandwidth=3750000;sop_group=SOP21
                    					Transport: MP2T/RTP/TCP;unicast;bit_rate=3750000;sop_group=SOP1;
                    					SessionGroup: SM4
                    					StartPoint: 1 0
                    					CSeq: 1
                    					User-Agent: Coship MAP-C
                    					Content-Length: 166

                    					v=0
                    					o=- 1152339971764523f1000 1390329118 IN IP4 10.4.72.54
                    					s=
                    					t=0 0
                    					a=X-playlist-item: ZSBTV REAL1390212285785084 0-3599
                    					c=IN IP4 0.0.0.0
                    					m=video 0 udp MP2T */
                    asynsdk::CKeyvalSetter spKeyval(1);
                    spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("application/sdp"));
                    spKeyval.Set(STRING_from_string("Require"), FALSE, STRING_from_string("com.comcast.ngod.r2"));
                    spKeyval.Set(STRING_from_string("StreamControlProto"), FALSE, STRING_from_string("rtsp"));
                    spKeyval.Set(STRING_from_string("Policy"), FALSE, STRING_from_string("priority=1"));
                    spKeyval.Set(STRING_from_string("Volume"), FALSE, STRING_from_string("library2103"));
                    spKeyval.Set(STRING_from_string("OnDemandSessionId"), FALSE, STRING_from_string("1152339971764523f1000"));
                    spKeyval.Set(STRING_from_string("Transport"), FALSE, STRING_from_string("MP2T/DVBC/UDP;unicast;client=0000A4D7D0F0;destination=10.4.73.240;client_port=31260;bandwidth=3750000;sop_group=SOP21"));
                    spKeyval.Set(STRING_from_string("Transport"), FALSE, STRING_from_string("MP2T/RTP/TCP;unicast;bit_rate=3750000;sop_group=SOP1;"));
                    spKeyval.Set(STRING_from_string("SessionGroup"), FALSE, STRING_from_string("SM4"));
                    spKeyval.Set(STRING_from_string("StartPoint"), FALSE, STRING_from_string("1 0"));
                    spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string("1"));
                    spKeyval.Set(STRING_from_string("User-Agent"), FALSE, STRING_from_string("MAP-C"));

                    CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                    m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, AF_INET, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                    char *body = "v=0\n"
                                 "o=- 1152339971764523f1000 1390329118 IN IP4 10.4.72.54\n"
                                 "s=\n"
                                 "t=0 0\n"
                                 "a=X-playlist-item: ZSBTV REAL1390212285785084 0-3599\n"
                                 "c=IN IP4 0.0.0.0\n"
                                 "m=video 0 udp MP2T";
                    unsigned long bodysize = strlen(body);
                    spAsynIoOperation->NewIoBuffer(0, (BYTE *)body, 0, bodysize, bodysize, 0);
                    spAsynIoOperation->SetIoParams(0, bodysize, bodysize);
                    m_spINet->SendPacket(STRING_from_string("SETUP"), STRING_from_string(m_url), &spKeyval, spAsynIoOperation);

                    m_lStatus = 1; //setup
                    return m_spINet->Read(lpAsynIoOperation);
                }
            }

            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    printf("recv error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    if( lParam1 )
                    {
                        printf("recv avs[%lld]: %ld\n", lParam1, lTransferedBytes);
                        return m_spINet->Read(lpAsynIoOperation);
                    }

                    //接收来自服务器的rtsp请求/响应
                    CComPtr<INetmsg> spKeyval;
                    lpAsynIoOperation->GetCompletedObject(TRUE, IID_INetmsg, (void **)&spKeyval);

                    char *body = 0; if( lTransferedBytes ) lpAsynIoOperation->GetIoBuffer(0, 0, (BYTE **)&body);

                    asynsdk::CStringSetter CSeq(1);
                    spKeyval->Get(STRING_from_string("CSeq"), 0, 0, &CSeq);

                    STRING method;
                    STRING params;
                    BOOL ack;
                    spKeyval->Getline(&method, &params, 0, &ack );

                    if(!ack )
                    {// 接收请求
                        printf("recv req[%s]: %*s %*s\n", CSeq.m_val.c_str(), method.len, method.ptr, params.len, params.ptr);
                        if( body ) printf("%s\n", std::string(body, lTransferedBytes).c_str());

                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string(CSeq.m_val));
                        m_spINet->SendPacket(STRING_from_string("200"), STRING_from_string("OK"), &spKeyval, 0);

                        return m_spINet->Read(lpAsynIoOperation);
                    }
                    else
                    {// 接收响应
                        printf("recv ack[%s]: %*s %*s\n", CSeq.m_val.c_str(), method.len, method.ptr, params.len, params.ptr);
                        if( body ) printf("%s\n", std::string(body, lTransferedBytes).c_str());
                    }

                    switch(m_lStatus)
                    {
                    case 1:
                    {
                        /*							 GET_PARAMETER rtsp://10.4.72.21:554 RTSP/1.0
                        							 Content-Type: text/parameters
                        							 Require: com.comcast.ngod.r2
                        							 Session: 2096569862826202657
                        							 OnDemandSessionId: 1152339971764523f1000
                        							 CSeq: 2
                        							 User-Agent: Coship MAP-C
                        							 Content-Length: 20

                        							 presentation_state */
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("text/parameters"));
                        spKeyval.Set(STRING_from_string("Require"), FALSE, STRING_from_string("com.comcast.ngod.r2"));
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("OnDemandSessionId"), FALSE, STRING_from_string("1152339971764523f1000"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string("2"));
                        spKeyval.Set(STRING_from_string("User-Agent"), FALSE, STRING_from_string("MAP-C"));

                        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
                        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, AF_INET, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
                        char *body = "presentation_state";
                        unsigned long bodysize = strlen(body);
                        spAsynIoOperation->NewIoBuffer(0, (BYTE *)body, 0, bodysize, bodysize, 0);
                        spAsynIoOperation->SetIoParams(0, bodysize, bodysize);
                        m_spINet->SendPacket(STRING_from_string("GET_PARAMETER"), STRING_from_string(m_url), &spKeyval, spAsynIoOperation);
                        m_lStatus = 2;
                        break;
                    }
                    case 2:
                    {
                        /*							 PLAY rtsp://10.4.72.21:5554/2096569862826202657 RTSP/1.0
                        							 Require: com.comcast.ngod.c1
                        							 Range: npt=0-
                        							 Scale: 1
                        							 Session: 2096569862826202657
                        							 CSeq: 1
                        							 User-Agent: Coship MAP-C*/
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Require"), FALSE, STRING_from_string("com.comcast.ngod.c1"));
                        spKeyval.Set(STRING_from_string("Range"), FALSE, STRING_from_string("npt=0-"));
                        spKeyval.Set(STRING_from_string("Scale"), FALSE, STRING_from_string("1"));
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string("3"));
                        spKeyval.Set(STRING_from_string("User-Agent"), FALSE, STRING_from_string("MAP-C"));

                        m_spINet->SendPacket(STRING_from_string("PLAY"), STRING_from_string("rtsp://10.4.72.21:5554/2096569862826202657"), &spKeyval, 0);
                        m_lStatus = 3;
                        break;
                    }
                    case 3:
                    {
                        /*							 PAUSE rtsp://10.4.72.21:5554/2096569862826202657 RTSP/1.0
                        							 x-reason: "User Requested Pause"
                        							 Require: com.comcast.ngod.c1
                        							 Session: 2096569862826202657
                        							 CSeq: 2
                        							 User-Agent: Coship MAP-C */
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("x-reason"), FALSE, STRING_from_string("\"User Requested Pause\""));
                        spKeyval.Set(STRING_from_string("Require"), FALSE, STRING_from_string("com.comcast.ngod.c1"));
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string("4"));
                        spKeyval.Set(STRING_from_string("User-Agent"), FALSE, STRING_from_string("MAP-C"));

                        m_spINet->SendPacket(STRING_from_string("PAUSE"), STRING_from_string(m_url), &spKeyval, 0);
                        m_lStatus = 4;
                        break;
                    }
                    case 4:
                    {
                        /*							 TEARDOWN rtsp://10.4.72.21:554 RTSP/1.0
                        							 Require: com.comcast.ngod.r2
                        							 Reason: 200 "user pressed stop"
                        							 Session: 2096569862826202657
                        							 OnDemandSessionId: 1152339971764523f1000
                        							 CSeq: 45
                        							 User-Agent: Coship MAP-C */
                        asynsdk::CKeyvalSetter spKeyval(1);
                        spKeyval.Set(STRING_from_string("Require"), FALSE, STRING_from_string("com.comcast.ngod.r2"));
                        spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
                        spKeyval.Set(STRING_from_string("OnDemandSessionId"), FALSE, STRING_from_string("1152339971764523f1000"));
                        spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string("5"));
                        spKeyval.Set(STRING_from_string("User-Agent"), FALSE, STRING_from_string("MAP-C"));

                        m_spINet->SendPacket(STRING_from_string("TEARDOWN"), STRING_from_string(m_url), &spKeyval, 0);
                        m_lStatus = 5;
                        break;
                    }
                    }
                    return m_spINet->Read(lpAsynIoOperation);
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    bool Connect(const std::string &url, bool http, unsigned long connect_timeout = 2000/*2sec*/)
    {
        std::string::size_type pos1 = url.find("://");
        if( pos1 == std::string::npos )
        {
            printf("fail to parse %s\n", url.c_str());
            return false;
        }
        std::string schema = url.substr(0, pos1);
        pos1 += 3/*skip "://" */;
        _strlwr_s((char *)schema.c_str(), schema.size());
        if( schema != "rtsp" )
        {
            printf("invalid schema: %s\n", url.c_str());
            return false;
        }

        std::string::size_type pos2 = url.find('/', pos1);
        std::string hostport = pos2 == std::string::npos? url.substr(pos1) : url.substr(pos1, pos2 - pos1);

        std::string host;
        PORT        port = 554;
        std::string::size_type pos3 = hostport.find(':');
        if( pos3 == std::string::npos )
        {
            host = hostport;
        }
        else
        {
            host = hostport.substr(0, pos3);
            port = atoi(hostport.substr(pos3 + 1).c_str());
        }

        CComPtr<IAsynRawSocket> spAsynPtlSocket;
        if( http )
        {
            CComPtr<IAsynTcpSocket> spAsynInnSocket[2];
            m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket[0]);
            m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket[1]);
            IUnknown* ppParam2[2];
            ppParam2[0] = spAsynInnSocket[0];
            ppParam2[1] = spAsynInnSocket[1];
            m_spAsynNetwork->CreateAsynPtlSocket( STRING_from_string("rtsp"), ppParam2, STRING_from_string("http/1.0"), &spAsynPtlSocket);
        }
        else
        {
            CComPtr<IAsynTcpSocket> spAsynInnSocket;
            m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket );
            m_spAsynNetwork->CreateAsynPtlSocket( STRING_from_string("rtsp"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tcp/1.0"), &spAsynPtlSocket);
        }
        if( spAsynPtlSocket == NULL )
        {
            printf("fail to load plugin: rtsp\n");
            return false;
        }

        CComPtr<IAsynTcpSocket> spAsynTcpSocket;
        spAsynPtlSocket->QueryInterface(IID_IAsynTcpSocket, (void **)&spAsynTcpSocket);
        spAsynPtlSocket->QueryInterface(IID_INet, (void **)&m_spINet);
        HRESULT r1 = spAsynTcpSocket->Open( m_spAsynFrameThread, AF_INET, SOCK_STREAM, IPPROTO_TCP );

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, m_iaf, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);

        m_url = url;
        printf("start to tcp.connect %s:%d\n", host.c_str(), port);
        spAsynTcpSocket->Connect(STRING_from_string(host), port, 0, spAsynIoOperation, connect_timeout);
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
    HANDLE m_hNotify;
    CComPtr<IAsynNetwork    > m_spAsynNetwork;
    CComPtr<INet> m_spINet;

    std::string m_url;
    uint32_t    m_iaf; //ipv4/ipv6/ipx
    uint32_t    m_lStatus;
};

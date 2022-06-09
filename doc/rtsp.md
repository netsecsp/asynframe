# rtsp 插件  

实现rtsph/rtsp[t/u]的协议处理模块，支持INet/IAsynTcpSocket/IAsynRawSocket等接口

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynPtlSocket(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynRawSocket** object )  
```  

## 开发
创建rtsp[t/u]对象[client]：
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("rtsp"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tcp/1.0"), &spAsynPtlSocket);
```  

创建rtsp[t/u]对象[server]：
```c++  
CComPtr<IAsynTcpSocketListener> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocketListener(asynsdk::STRING_EX::null, &spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("rtsp"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tcp/1.0"), &spAsynPtlSocket);
```  

创建rtsph对象[client]：
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket[2];
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket[0]);
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket[1]);
IUnknown* ppParam2[2];
ppParam2[0] = spAsynInnSocket[0];
ppParam2[1] = spAsynInnSocket[1];
m_spAsynNetwork->CreateAsynPtlSocket( STRING_from_string("rtsp"), ppParam2, STRING_from_string("http/1.0"), &spAsynPtlSocket);
```  

发送rtsp.req
```c++  
asynsdk::CKeyvalSetter spKeyval(1);
spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("text/parameters"));
spKeyval.Set(STRING_from_string("CSeq"), FALSE, STRING_from_string("1"));

CComPtr<IAsynIoOperation> spAsynIoOperation; m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
char *body = "position: 346.000000\n"
             "scale: 1.0";
unsigned int bodysize = strlen(body);
spAsynIoOperation->NewIoBuffer(0, (BYTE *)body, 0, bodysize, bodysize, 0);
spAsynIoOperation->SetIoParams(0, bodysize, bodysize);
spNet->SendPacket(STRING_from_string("GET_PARAMETER"), STRING_from_string("rtsp://127.0.0.1/1.mp4"), &spKeyval, spAsynIoOperation);
```  

接收
```c++  
HRESULT CService::OnIomsgNotify( uint64_t lParam1, uint64_t lAction, IAsynIoOperation *lpAsynIoOperation )
{
    uint32_t lErrorCode = NO_ERROR, lTransferedBytes;
    lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

    switch(lAction)
    {
        case Io_recv:
             if( lErrorCode == NO_ERROR )
             {// rtsp.req/ack packet
                 CComPtr<INetmsg> spRtspmsg;
                 lpAsynIoOperation->GetCompletedObject(1, IID_INetmsg, (void **)&spRtspmsg);

                 STRING Method;
                 STRING Params;
                 STRING V;
                 BOOL ack;
                 spRtspmsg->Getline(&Method, &Params, &V, &ack );
                 std::string method = string_from_STRING(Method);
                 std::string params = string_from_STRING(Params);
                 std::string v = string_from_STRING(V);
                 printf("rcv rtsp %s packet: %*s %*s\n", ack? "ack" : "req", Method.len, Method.ptr, Params.len, Params.ptr);
                 .....
             }
             break;
    }
    return E_NOTIMPL;
}
```  

## 例子  
\support\testnetclient_rtsp  
\support\testnetserver_rtsp  
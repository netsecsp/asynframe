# http 插件  

实现http[s/t/u]的协议处理模块，支持INet/IAsynTcpSocket/IAsynRawSocket/IAsynTcpSocketListener等接口

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynPtlSocket(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynRawSocket** object )  
```  

## 开发
创建http[s/t]对象[client]：
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("http"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl? "tls/1.0" : "tcp/1.0"), &spAsynPtlSocket);
```  

创建http[s/t]对象[server]：
```c++  
CComPtr<IAsynTcpSocketListener> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocketListener(asynsdk::STRING_EX::null, &spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("http"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl? "tls/1.0" : "tcp/1.0"), &spAsynPtlSocket);
```  

发送http.req
```c++  
asynsdk::CKeyvalSetter spKeyval(1);
spKeyval.Set(STRING_from_string("Session"), FALSE, STRING_from_string("2096569862826202657"));
spKeyval.Set(STRING_from_string("Content-Type"), FALSE, STRING_from_string("text/parameters"));

CComPtr<IAsynIoOperation> spAsynIoOperation; m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
spNet->SendPacket(STRING_from_string("GET"), STRING_from_string("/index.html"), &spKeyval, spAsynIoOperation);
```  

接收http.req/ack
```c++  
HRESULT CService::OnIomsgNotify( uint64_t lParam1, uint64_t lAction, IAsynIoOperation *lpAsynIoOperation )
{
    uint32_t lErrorCode = NO_ERROR, lTransferedBytes;
    lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

    switch(lAction)
    {
        case Io_recv:
             if( lErrorCode == NO_ERROR )
             {// http.req/ack packet
                 CComPtr<INetmsg> spHttpmsg;
                 lpAsynIoOperation->GetCompletedObject(1, IID_INetmsg, (void **)&spHttpmsg);

                 STRING Method;
                 STRING Params;
                 STRING V;
                 BOOL ack;
                 spHttpmsg->Getline(&Method, &Params, &V, &ack );
                 std::string method = string_from_STRING(Method);
                 std::string params = string_from_STRING(Params);
                 std::string v = string_from_STRING(V);
                 printf("rcv http %s packet: %*s %*s\n", ack? "ack" : "req", Method.len, Method.ptr, Params.len, Params.ptr);
                 .....
             }
             break;
    }
    return E_NOTIMPL;
}
```  

## 例子  
[http client/server](https://github.com/netsecsp/ahttp)
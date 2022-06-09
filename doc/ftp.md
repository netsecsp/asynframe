# ftp 插件  

实现ftp[s/t]的协议处理模块，支持INet/IAsynTcpSocket/IAsynRawSocket/IAsynTcpSocketListener等接口

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynPtlSocket(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynRawSocket** object )  
```  

## 开发  
创建显式ftp over tls/普通ftp对象[client]：  
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ftp"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl_explicit? "tls/1.0" : "tcp/1.0"), &spAsynPtlSocket);
```  

创建隐式ftp over tls对象[client]：  
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
CComPtr<IAsynRawSocket> spAsynSslSocket;
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ssl"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tls/1.0"), &spAsynSslSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ftp"), (IUnknown**)&spAsynSslSocket.p, STRING_from_string("tcp/1.0"), &spAsynPtlSocket);
```  

创建ftp[s/t]对象[server]：  
```c++  
CComPtr<IAsynTcpSocketListener> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocketListener(asynsdk::STRING_EX::null, &spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ftp"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl? "tls/1.0" : "tcp/1.0"), &spAsynPtlSocket);
```  

发送ftp.req  
```c++  
CComPtr<IAsynIoOperation> spAsynIoOperation; m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
spNet->SendPacket(STRING_from_string("USER"), STRING_from_string("netsecsp"), 0, spAsynIoOperation);
```  

接收ftp.req/ack  
```c++  
HRESULT CService::OnIomsgNotify( uint64_t lParam1, uint64_t lAction, IAsynIoOperation *lpAsynIoOperation )
{
    uint32_t lErrorCode = NO_ERROR, lTransferedBytes;
    lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

    switch(lAction)
    {
        case Io_recv:
             if( lErrorCode == NO_ERROR )
             {// ftp.req/ack packet
                 CComPtr<INetmsg> spFtpmsg;
                 lpAsynIoOperation->GetCompletedObject(1, IID_INetmsg, (void **)&spFtpmsg);

                 STRING Method;
                 STRING Params;
                 BOOL ack;
                 spFtpmsg->Getline(&Method, &Params, 0, &ack );
                 std::string method = string_from_STRING(Method);
                 std::string params = string_from_STRING(Params);
                 printf("rcv ftp %s packet: %*s %*s\n", ack? "ack" : "req", Method.len, Method.ptr, Params.len, Params.ptr);
                 .....
             }
             break;
    }
    return E_NOTIMPL;
}
```  

## 例子  
[ftp client/server](https://github.com/netsecsp/aftpx)
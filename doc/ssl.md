# ssl 插件  

实现ssl握手/加密/解密处理模块，支持ISsl/IAsynTcpSocket/IAsynRawSocket/IAsynTcpSocketListener等接口

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynPtlSocket(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynRawSocket** object )  
```  

## 开发  
创建ssl对象[client]：  
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ssl"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(tls? "tls/1.0" : "ssl/3.0"), &spAsynPtlSocket);
```  

创建ssl对象[server]：  
```c++  
CComPtr<IAsynTcpSocketListener> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocketListener(asynsdk::STRING_EX::null, &spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ssl"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(tls? "tls/1.0" : "ssl/3.0"), &spAsynPtlSocket);
```  

设置p12证书  
```c++  
CComPtr<ISsl> spSsl;
spAsynPtlSocket->QueryInterface(IID_ISsl, (void**)&spSsl);
spSsl->SetCryptContext(0, 0, &p12_cert, &password);
```  

## 例子  
\support\testnetclient_ssl  
\support\testnetserver_ssl  
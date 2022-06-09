# proxy 插件  

实现ftp/http/socks的客户端代理协议处理模块，支持INet/IAsynTcpSocket/IAsynRawSocket/IAsynProxySocket等接口

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynPtlSocket(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynRawSocket** object )  
```  

## 开发
创建显式ftp over tls/普通ftp代理对象[client]：  
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("proxy"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl_explicit? "ftps/1.0" : "ftp/1.0"), &spAsynPtlSocket);
```  

创建隐式ftp over tls代理对象[client]：  
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
CComPtr<IAsynRawSocket> spAsynSslSocket;
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("ssl"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("tls/1.0"), &spAsynSslSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("proxy"), (IUnknown**)&spAsynSslSocket.p, STRING_from_string("ftp/1.0"), &spAsynPtlSocket);
```  

创建http[s/t]代理对象[client]  
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("proxy"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl? "https/1.0" : "http/1.0"), &spAsynPtlSocket);
```  

创建socks代理对象[client]  
```c++  
#define SOCKS_VERNO "5.0" //4.0 4.a 5.0
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("proxy"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string("socks/" SOCKS_VERNO), &spAsynPtlSocket);
```  

#设置代理信息  
```c++  
CComPtr<IAsynProxySocket> spProxy; spAsynPtlSocket->QueryInterface(IID_IAsynProxySocket, (void **)&spProxy);
asynsdk::CKeyvalSetter params(1);
params.Set(STRING_from_string(";account"), 1, STRING_from_string(m_setsfile.get_string("proxy", "user") + ":" + m_setsfile.get_string("proxy", "password")));
spProxy->SetProxyContext(STRING_from_string(m_setsfile.get_string("proxy", "host", "127.0.0.1")), m_setsfile.get_long("proxy", "port", 8080), STRING_EX::null, &params);
```  

## 例子  
[ftpx client](https://github.com/netsecsp/aftpx)
[http client](https://github.com/netsecsp/ahttp)
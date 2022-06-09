# dns 插件  

实现基于udp/tcp/http的域名解析模块，通过网络模块[asynsock]加载

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynDnsResolver(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynMessageEvents* events,  
      /*[out]*/IAsynDnsResolver** object )  
```  

## 开发  
uri格式：schema://[host1|..|hostn]:port/...  
配置udp解析域名，udp://\*:53/  
配置tcp解析域名，tcp://\*:53/  
配置腾讯云解析域名，http://119.29.29.29/d?dn=[host].&ip=[ip]&ttl=1  
配置阿里云解析域名，http://203.107.1.33/{account_id}/d?host=[host]&ip=[ip]&query=[af]  

创建dns对象：  
```c++  
CComPtr<IAsynDnsResolver> spAsynDnsResolver;
const char *uri = "udp://8.8.8.8|8.8.4.4:53";
spAsynNetwork->CreateAsynDnsResolver(STRING_from_string("dns"), 0, STRING_from_string(uri), 0, &spAsynDnsResolver);
```  

提交解析域名：  
```c++  
CComPtr<IAsynNetIoOperation> spAsynIoOperation;
m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, af, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
if( spAsynIoOperation->SetHost(STRING_from_string(host), 1) != S_OK )
{// 需要解析域名
    return lpAsynDnsResolver->Commit(spAsynIoOperation, af) == S_OK;
}
else
{// 已是ipvx
    printf("ip: %s\n", host.c_str());
    return true;
}
```  

异步解析结果：  
```c++  
HRESULT CAsynDnsHandler::OnIomsgNotify( uint64_t lParam1, uint64_t lAction, IAsynIoOperation *lpAsynIoOperation )
{
    uint32_t lErrorCode = NO_ERROR;
    lpAsynIoOperation->GetCompletedResult(&lErrorCode, 0, 0 );

    switch(lAction)
    {
        case Io_hostdns:
        {
             if( lErrorCode != NO_ERROR )
             {// 解析失败
                 printf("dns, error: %d\n", lErrorCode);
             }
             else
             {// 解析成功
                 CComPtr<IStringsStack> spDnsResult;
                 HRESULT r = lpAsynIoOperation->GetCompletedObject(1, IID_IStringsStack, (void **)&spDnsResult);
                 asynsdk::CStringSetter addr;
                 for(int i = 0; spDnsResult->Pop(&addr) == S_OK ; ++ i)
                 {
                     printf("ip: %s\n", addr.m_val.c_str());
                }
                ....
             }
             break;
        }
    }
}
```  

## 例子  
\support\testdns  
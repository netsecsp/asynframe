## Asynframe framework v1.1 [english](/README_EN.md) | 中文
> https://github.com/netsecsp/asynframe  

# 项目背景  
软件产品开发过程中经常碰到如下场景的问题:   
1. 各个模块所需要的配置参数集中管理?--涉及配置参数加载以及持久化等问题；  
2. 界面组能否利用现有的网络模块自己开发功能, 比如需要把日志文件通过http协议提交到后台?--涉及网络、httpdns以及使用网络代理等知识难点；  
3. 界面跟其他各个SDK模块（包括集成第三方开源项目）之间信息交互而产生问题?--涉及线程同步，事件序列以及操作耗时过长等问题；  
4. 各个模块（包括界面）通过创建工作线程去解决耗时/同步操作等问题,--涉及资源优化；  
5. 使用同步锁,--存在死锁问题；  
6. 模块业务逻辑复杂导致频繁发布补丁包。   

# 项目介绍  
> 这是一款windows平台下基于消息驱动的SDK开发框架，提供线程、管道、文件和网络等基础接口。  

asynframe framework解决上面所提的软件产品开发过程中的六大问题:  
1. 通过有名参数管理对象来管理各个模块的参数  
2. 通过插件化以及统一操作接口来降低学习成本  
3. 提供在调用方的线程里通知结果以及设定串行操作链来解决线程同步，事件序列以及操作耗时过长等问题  
4. 通过有名线程池优化各个模块的工作线程执行  
5. 提供无锁化机制  
6. 集成lua插件实现热更新  

**功能特性:**  
1. 可轻松集成到MFC，[DUI](https://github.com/duilib/duilib)，[Qt6.x](https://download.qt.io/archive/qt) 等其他第三方开源项目  
2. 通过设备链提供统一设备操作接口（包括File、Pipe、Socket等）  
3. 通过操作链解决集成第三方开源项目时的线程之间的同步/通讯、执行超时以及资源/性能等问题  
4. 提供基本网络协议模块：dns/udp/tcp/ssl/ftp/http/proxy/websocket  
6. 引用计数管理对象内存  
7. 支持微秒级定时器  
8. 集成[Log4cplus](https://github.com/log4cplus/log4cplus)，统一模块输出日志  

**开发优势:**  
1. 协助产品模块化。  
2. 统一的开发模板，无锁化机制以及高性能IO框架降低开发者学习成本。能够迅速开发出稳定地，高性能的应用模块。可大幅度降低开发代码量。  

|模块|类型|功能|例子/程序|
|:--|:--|:--|:--|
|asyncore|框架|asynframe框架|\support\testframe|
|||集成到mfc|\support\3rd\mfc\testnetserver<br>\support\3rd\mfc\testnetclient_dlg<br>\support\3rd\mfc\testnetclient_doc|
|||集成到DUI|\support\3rd\\[dui](https://github.com/duilib/duilib)|
|crashexplorer|插件[asyncore]|捕获当前进程的崩溃信息，同时生成dmp文件|\support\testcrashexplorer|
|console|插件[asyncore]|命令控制台<br>1.支持加载/卸载ICommand插件：cmd/lua<br>2.支持键盘/鼠标输入|\support\testconsole|
|asynfile|插件[asyncore]|文件|\support\testfile_copy<br>\support\testfile_copy-pipe|
|asynipcs|插件[asyncore]|进程间通讯|\support\testipcclient<br>\support\testipcserver|
|asynneta|插件[asyncore]|服务端代理<br>1.支持http/https代理：实现Basic/Digest认证<br>2.支持ftp/ftps代理<br>3.支持socks4.0/4.a/5.0代理|[aneta](https://github.com/netsecsp/aneta)|
|asynsock|插件[asyncore]|网络<br>1.支持ipv6兼容ipv4<br>2.支持默认DNS 解析|\support\testnetclient<br>\support\testnetserver<br>[ping](https://github.com/netsecsp/pingx)|
|dns|插件[asynsock]|域名解析<br>1.udp dns<br>2.tcp dns<br>3.httpDNS: 实现阿里云/腾迅云|\support\testdns|
|ftp |插件[asynsock]|ftp 协议|[aftpx](https://github.com/netsecsp/aftpx)|
|http|插件[asynsock]|http协议|[ahttp](https://github.com/netsecsp/ahttp)|
|ssl|插件[asynsock]|ssl/tls加/解密<br>1.支持p12证书|\support\testnetclient_ssl<br>\support\testnetserver_ssl|
|proxy|插件[asynsock]|客户端代理<br>1.支持http/https代理：实现Basic/Digest认证<br>2.支持ftp/ftps代理<br>3.支持socks4.0/4.a/5.0代理|\support\testnetclient_proxy<br>\support\testnetserver_socks|
|websocket|插件[asynsock]|websocket协议<br>1.支持数据帧分片<br>2.优先发送控制帧|\support\testnetclient_websocket<br>\support\testnetserver_websocket|
|sqlite|插件|基于sqlite-3.3.20实现IDataTransmit接口|\support\testframe|
|zip|插件|基于zlib-1.2.11.0实现IDataTransmit接口<br>1.支持压缩zip文件<br>2.deflate/inflate数据|\support\testframe|
|lua|插件|基于lua-5.4.4实现ICommand接口<br>1.支持多线程|\support\testframe<br>\support\testlua\testapi|

# 变更记录
> 2022/05/26 发布websocket插件  
> 2022/05/05 发布windows平台的asynframe framework v1.0   

# 编译环境
> sdk_v1.1-Msvc2019_20220526.zip是通过Microsoft Visual Studio 2019编译的SDK  
> sdk_v1.1-Msvc2013_20220526.zip是通过Microsoft Visual Studio 2013编译的SDK  

1. 需在工程里设置asynframe相应的include/lib路径  
2. 根据工程的运行库选择链接asynframe相应的asynsdk_mini-[MD/MDd/MT/MTd].lib  
3. 链接asyncore.lib(提供3个api函数[^1])  
[^1]: STDAPI_(extern HRESULT) Initialize( IAsynMessageEvents *param1, IKeyvalSetter *param2 );<br>STDAPI_(extern InstancesManager*) GetInstancesManager();<br>STDAPI_(extern HRESULT) Destory();  
4. 附上例子 [Pingx -4 www.baidu.com -d=udp://*:53/](https://github.com/netsecsp/pingx)
```c++
class CAsynPingHandler : public asynsdk::asyn_message_events_impl
{
public:
    CAsynPingHandler(IAsynFrameThread *lpAsynFrameThread, IAsynNetwork *lpAsynNetwork)
    {
        m_spAsynFrameThread = lpAsynFrameThread;
        CreateAsynFrame(lpAsynFrameThread, 0, &m_spAsynFrame);
        m_spAsynNetwork = lpAsynNetwork;
        m_spAsynNetwork->CreateAsynRawSocket(1, &m_spAsynRawSocket);
        m_spAsynRawSocket->Open(lpAsynFrameThread, 0, 0, 0);
        m_hNotify = CreateEvent(NULL, TRUE, FALSE, NULL);
    }

public: // interface of asyn_message_events_impl
    DECLARE_ASYN_MESSAGE_MAP(CAsynPingHandler)
    HRESULT OnIomsgNotify( uint64_t lParam1, uint64_t lParam2, IAsynIoOperation *lpAsynIoOperation )
    {
        uint32_t lErrorCode = NO_ERROR;
        lpAsynIoOperation->GetCompletedResult(&lErrorCode, 0, 0 );

        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        lpAsynIoOperation->QueryInterface(IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);

        if( lparam2 == Io_hostdns )
        {
            STRING host;
            spAsynIoOperation->GetHost(&host );
            if( lErrorCode != NO_ERROR )
            {
                printf("can't to resolver %*s, error=%d\n", host.len, host.ptr, lErrorCode);
                SetEvent(m_hNotify);
                return S_OK;
            }

            CComPtr<IStringsStack> lstIps;
            lpAsynIoOperation->GetCompletedObject(1, IID_IStringsStack, (void **)&lstIps);
            asynsdk::CStringSetter ipvx;
            lstIps->Pop(&ipvx);
            spAsynIoOperation->SetPeerAddress(0,&STRING_from_string(ipvx.m_val), 0, 0, 0);
            lstIps->Get(&host);
            printf("start to ping %*s[%s]...\n", host.len, host.ptr, ipvx.m_val.c_str());
            m_spAsynFrame->CreateTimer(1, 0, 0, 0);
            return S_OK;
        }

        asynsdk::CStringSetter host(1);
        spAsynIoOperation->GetPeerAddress(&host, 0, 0, 0);

        if( lErrorCode == NO_ERROR )
            printf("from %s: seq=%lld ttl=%lld rtt=%lldms\n", host.m_val.c_str(), lparam1, lparam2 >> 56, (lparam2 << 8) >> 8);
        else
            printf("from %s: seq=%lld, error=%d\n", host.m_val.c_str(), lparam1, lErrorCode);
        return E_NOTIMPL;
    }
    HRESULT OnTimer( uint64_t lParam1, uint64_t lParam2 )
    {
        CComPtr<IAsynNetIoOperation> spAsynIoOperation;
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, 0, 0, IID_IAsynNetIoOperation, (void **)&spAsynIoOperation);
        m_spAsynFrameThread->BindAsynIoOperation(m_spAsynIoOperation, spAsynIoOperation, BM_Oneway | BM_OsAddr, 0);

        m_spAsynFrame->CreateTimer(1, ++ lparam2, 1000, 0); //1second timer

        spAsynIoOperation->SetOpParam1(lparam2);
        m_spAsynRawSocket->Write(spAsynIoOperation, 0/*ttl*/);
        return S_OK;
    }

public:
    bool Start(const std::string &host, uint32_t af, const char *DNS_uri)
    {
        m_spAsynNetwork->CreateAsynIoOperation(m_spAsynFrame, af, 0, IID_IAsynNetIoOperation, (void **)&m_spAsynIoOperation);
        if( m_spAsynIoOperation->SetHost(STRING_from_string(host), TRUE) == S_OK )
        {// ipvx
            printf("start to ping %s...\n", host.c_str());
            m_spAsynFrame->CreateTimer(1, 0, 0, 0);
        }
        else
        {// need to dns
            m_spAsynNetwork->CreateAsynDnsResolver(STRING_from_string("dns"), 0, STRING_from_string(DNS_uri), 0, &m_spAsynDnsResolver);
            m_spAsynDnsResolver->Commit(m_spAsynIoOperation, 0);
        }
        return true;
    }
    void Shutdown()
    {
        Stop(m_spAsynFrame);
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynRawSocket     > m_spAsynRawSocket;
    CComPtr<IAsynNetwork       > m_spAsynNetwork;
    CComPtr<IAsynFrame         > m_spAsynFrame;
    CComPtr<IAsynDnsResolver   > m_spAsynDnsResolver;
    CComPtr<IAsynNetIoOperation> m_spAsynIoOperation;
    CComPtr<IAsynFrameThread   > m_spAsynFrameThread;
    HANDLE m_hNotify;
};
```

```c++
int main(int argc, const char *argv[])
{
    char *host = "www.baidu.com", ipvx = '4', *durl = "udp://*:53/"; //tcp://*:53  http://119.29.29.29/d?dn=[host].&ip=[ip]&ttl=1
    for(int i = 1; i < argc; ++ i)
    {
        if( argv[i][0] == '-' )
        {
            if( memcmp(argv[i], "-d=", 3) == 0 )
            {
                durl = argv[i]+ 3;
            }
            else
            {
                ipvx = argv[i][1];
            }
        }
        else
        {
            host = argv[i];
        }
    }

    if( Initialize(NULL, NULL) != NO_ERROR )
    {
        printf("fail to Initialize asynframe\n");
        return 1;
    }

    do
    {
        InstancesManager *lpInstancesManager = GetInstancesManager(); //获取实例管理器

        CComPtr<IAsynFrameThread> spAsynFrameThread; //创建线程
        lpInstancesManager->NewInstance(0, 0, IID_IAsynFrameThread, (void **)&spAsynFrameThread);

        lpInstancesManager->Verify(STRING_from_string(IN_AsynNetwork)); //加载网络模块

        CComPtr<IAsynNetwork    > spAsynNetwork;
        lpInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

        std::unique_ptr<CAsynPingHandler> pEvent(new CAsynPingHandler(spAsynFrameThread, spAsynNetwork));
        if( pEvent->Start(host, ipvx=='4'? AF_INET : 23, durl) )
        {
            while( WAIT_OBJECT_0 != WaitForSingleObject(pEvent->m_hNotify, 0) &&
                   kbhit() == 0 )
            {
                Sleep(100); //0.1sec
            }
        }
        pEvent->Shutdown();
    }while(0);

    Destory();

    return 0;
}
```

# 开发  
- [asynframe导出函数](/doc/pluginapi.md)  

- 接口  
  [IAsynFrame](/doc/IAsynFrame.txt)  
  [IAsynFileSystem](/doc/IAsynFileSystem.txt)  
  [IAsynIpcChannel](/doc/IAsynIpcChannel.txt)  
  [IAsynNetwork](/doc/IAsynNetwork.txt)  
  [IAsynNetAgent](/doc/IAsynNetAgent.txt)  
  [IConsole](/doc/IConsole.txt)  
  [ICrashExplorer](/doc/ICrashExplorer.txt)  
  [INet](/doc/INet.txt)  
  [IProxy](/doc/IProxy.txt)  
  [ISsl](/doc/ISsl.txt)  
  [IVmHost](/doc/IVmHost.txt)  

- [插件](/doc/externapi.md)   

# 鸣谢  
> [Log4cplus](https://github.com/log4cplus/log4cplus)  
> [Lua](http://www.lua.org)  
> [Zlib](http://www.zlib.net)  
> [Sqlite](https://www.sqlite.org/)  

# 版权信息  
> Copyright (c) 2012 - 2032, All rights reserved.  
> Author: Shengqian Yang, China, netsecsp@hotmail.com  
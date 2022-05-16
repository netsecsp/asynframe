## Asynframe framework 1.0 

# 项目背景 [english](/index_EN.md)   
软件产品开发过程中经常碰到如下场景的问题:   
1. 各个模块所需的配置参数集中管理?--涉及配置参数加载以及持久化等问题；  
2. 界面组能否利用现有的网络模块自己开发功能, 比如需要把日志文件通过http协议提交到后台?--涉及网络、httpdns以及使用网络代理等知识难点；  
3. 界面跟其他各个SDK模块（包括集成第三方开源项目）之间信息交互而产生问题?--涉及线程同步，事件序列以及操作耗时过长等问题；  
4. 各个模块（包括界面）通过创建工作线程去解决耗时/同步操作等问题,--涉及资源优化；  
5. 使用同步锁,--存在死锁问题。  

# 项目介绍  
> 这是一款windows平台下基于消息驱动的SDK开发框架，提供线程、管道、文件和网络等基础接口。  

asynframe framework解决上面所提的软件产品开发过程中的五大问题:  
1. 通过有名参数管理对象来管理各个模块的参数  
2. 通过插件化以及统一操作接口来降低学习成本  
3. 提供在调用方的线程里通知结果以及设定串行操作链来解决线程同步，事件序列以及操作耗时过长等问题  
4. 通过有名线程池优化各个模块的工作线程执行  
5. 提供无锁化机制  

**功能特性:**  
1. 可轻松集成到MFC，[DUI](https://github.com/duilib/duilib)，[Qt6.x](https://download.qt.io/archive/qt) 等其他第三方开源项目  
2. 通过设备链提供统一设备操作接口（包括File、Pipe、Socket等）  
3. 通过操作链解决集成第三方开源项目时的线程之间的同步/通讯、执行超时以及资源/性能等问题  
4. 提供基本网络协议模块：dns/udp/tcp/ssl/ftp/http/proxy  
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
|asynneta|插件[asyncore]|服务端代理<br>1.支持http[s]代理：实现Basic/Digest认证<br>2.支持ftp [s]代理<br>3.支持socks4.0/4.a/5.0代理|[aneta](https://github.com/netsecsp/aneta)|
|asynsock|插件[asyncore]|网络: <br>1.支持ipv6兼容ipv4<br>2.支持默认DNS 解析|\support\testnetclient<br>\support\testnetserver<br>[ping](https://github.com/netsecsp/pingx)|
|dns|插件[asynsock]|域名解析<br>1.udp dns<br>2.tcp dns<br>3.httpDNS: 阿里云/腾迅云|\support\testdns|
|ftp |插件[asynsock]|ftp 协议|[aftpx](https://github.com/netsecsp/aftpx)|
|http|插件[asynsock]|http协议|[ahttp](https://github.com/netsecsp/ahttp)|
|ssl|插件[asynsock]|ssl/tls加/解密<br>1.支持p12证书|\support\testsslclient<br>\support\testsslserver|
|proxy|插件[asynsock]|客户端代理<br>1.支持http[s]代理：实现Basic/Digest认证<br>2.支持ftp [s]代理<br>3.支持socks4.0/4.a/5.0代理|\support\testnetclient_proxy<br>\support\testnetserver_socks|
|sqlite|插件|基于sqlite-3.3.20实现IDataTransmit接口|\support\testframe|
|zip|插件|基于zlib-1.2.11.0实现IDataTransmit接口<br>1.支持压缩zip文件<br>2.deflate/inflate数据|\support\testframe|
|lua|插件|基于lua-5.4.4实现ICommand接口<br>1.支持多线程|\support\testframe<br>\support\testlua\testapi|

# 变更记录
> 2022/05/05发布基于windows平台的asynframe版本1.0   

# 编译环境
> sdk_1.0.0.0-Msvc2019_20220505.zip是通过Microsoft Visual Studio 2019编译的SDK  
> sdk_1.0.0.0-Msvc2013_20220505.zip是通过Microsoft Visual Studio 2013编译的SDK  

1. 需在工程里设置asynframe相应的include/lib路径  
2. 根据工程的运行库选择链接asynframe相应的asynsdk_mini-[MD/MDd/MT/MTd].lib  
3. 链接asyncore.lib(提供3个api函数)  
```c++
int main(int argc, const char *argv[])
{
    HRESULT ret = Initialize(NULL, NULL); //Initialize asynframe
    if( ret != NO_ERROR )
    {
        return 1;
    }

    InstancesManager *lpInstancesManager = GetInstancesManager(); //获取实例管理器，可以获取所有接口

    CComPtr<IAsynFrameThread> spAsynFrameThread; //创建线程
    lpInstancesManager->NewInstance(0,0,IID_IAsynFrameThread, (void**)&spAsynFrameThread);

    lpInstancesManager->Verify(STRING_from_string(IN_AsynNetwork)); //加载网络模块

    CComPtr<IAsynNetwork    > spAsynNetwork;
    lpInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

    CComPtr<IAsynUdpSocket  > spAsynUdpSocket; //创建Udp对象
    spAsynNetwork->CreateAsynTcpSocket(&spAsynTcpSocket );

    spAsynUdpSocket->Bind(asynsdk::STRING_EX::null, 0, 0, NULL); //绑定任意端口

    ......

    Destory(); //Destory asynframe
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

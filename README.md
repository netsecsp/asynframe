## Asynframe framework v2.0.1 [english](/README_EN.md) | 中文
> https://github.com/netsecsp/asynframe  

# 项目背景  
软件产品开发过程中经常碰到如下场景的问题:  
1. 各个模块所需要的配置参数集中管理--涉及配置参数加载以及持久化等问题  
2. 能否利用现有网络模块自己开发功能, 比如需要把日志文件通过http协议提交到后台--涉及网络、httpdns以及使用网络代理等知识难点  
3. 界面跟其他各个SDK模块（包括集成第三方开源项目）之间信息交互而产生问题--涉及线程同步，事件序列以及操作耗时过长等问题  
4. 各个模块（包括界面）通过创建工作线程去解决耗时/同步操作等问题--涉及资源优化  
5. 使用同步锁--存在死锁问题  
6. 模块业务逻辑复杂导致频繁发布补丁包  

# 项目介绍  
> [windows]基于消息驱动的SDK开发框架，提供日志、线程、管道、文件和网络等基础接口。  

asynframe framework解决上面所提的软件产品开发过程中的六大问题:  
1. 通过有名参数管理对象来管理各个模块的参数  
2. 通过插件化以及统一操作接口来降低学习成本  
3. 提供在调用方的线程里通知结果以及设定串行操作链来解决线程同步，事件序列以及操作耗时过长等问题  
4. 通过有名线程池优化各个模块的工作线程执行  
5. 提供无锁化机制  
6. 支持动态加载最新版本插件  
![image](https://netsecsp.github.io/img/02_asynframe.jpg)  

**功能特性:**  
1. 通过微线程核对象可轻松集成到MFC，[DUI](https://github.com/duilib/duilib)，[SoUI](https://github.com/SOUI2/soui)，[Qt6.7.3](https://download.qt.io/archive/qt) 等其他第三方开源项目  
2. 通过设备链提供统一设备操作接口（包括File、Pipe、Socket等）  
3. 通过操作链解决集成第三方开源项目时的线程之间的同步/通讯、执行超时以及资源/性能等问题  
4. 提供基本网络协议模块：dns/udp/tcp/ssl/ftp/http/rtsp/proxy/websocket  
5. 引用计数管理对象内存  
6. 支持微秒级定时器  
7. 支持动态加载[Log4cplus](https://github.com/log4cplus/log4cplus)，统一模块输出日志  
8. 支持内嵌lua, jvm和python虚拟机的开发框架  
![image](https://netsecsp.github.io/img/01_asynframe.jpg)  

**开发优势:**  
1. 支持可升级的插件化，协助windows产品模块化  
2. 支持跨进程获取崩溃时生成堆栈信息和dmp文件  
3. 通过微线程核对象嵌入其他线程隔离其他代码，便于代码重构  
4. 通过异步执行框架来获得极流畅用户体验  
5. 统一的开发模板，无锁化机制、高性能IO框架以及demo降低开发者学习成本。能够迅速开发出稳定地，高性能的应用模块。可大幅度降低开发代码量  
6. 支持网络udp/tcp端口复用框架  
7. 支持内嵌lua, jvm和python虚拟机的开发框架  
**lua:**   
a. 内置IUnknown类, 提供castOf/release接口  
b. appconf.get/set/save接口提供存取app相应配置项  
c. log.v/d/i/w/e/write 接口提供打印日志  
d. sys.create/invoke提供创建c对象/指定线程调用c函数  
e. IScriptHost.invoke提供调用lua函数, IOsCommand.Execute提供执行lua  
**python:**  
a. 内置sys.IUnknown类  
b. appconf.get/set/save接口提供存取app相应配置项  
c. log.v/d/i/w/e/write 接口提供打印日志  
d. sys.create/invoke提供创建c对象/指定线程调用c函数  
e. IScriptHost.invoke提供调用python函数，IOsCommand.Execute提供执行python  
**jvm集成frame.jar**  
a. 内置CUnknown类  
b. CSetting提供存取app相应配置项  
c. CLogger 提供打印日志  
d. CInstanceManager提供创建对象/指定线程调用c函数  
e. IScriptHost.invoke提供调用java函数，IOsCommand.Execute提供执行java  

|模块|类型|功能|例子/程序|
|:--|:--|:--|:--|
|asyncore|框架|asynframe framework|\support\testframe|
|||集成到MFC|\support\3rd\mfc\testnetserver<br>\support\3rd\mfc\testnetclient_dlg<br>\support\3rd\mfc\testnetclient_doc|
|||集成到[DUI](https://github.com/duilib/duilib)|[source](https://github.com/netsecsp/asynframe_warehouse/tree/master/3rd/Dui)|
|||集成到[SoUI](https://github.com/SOUI2/soui)|[source](https://github.com/netsecsp/asynframe_warehouse/tree/master/3rd/Sui)|
|||集成到[Qt6.7.3](https://github.com/SOUI2/soui)|[source](https://github.com/netsecsp/asynframe_warehouse/tree/master/3rd/Qt6.7.3)|
|crashexplorer|插件[asyncore]|捕获当前进程的崩溃信息，同时生成dmp文件|\support\testcrashexplorer|
|console|插件[asyncore]|命令控制台<br>1.支持加载/卸载IOsCommand插件：cmd/lua/sqlite<br>2.支持键盘/鼠标输入|\support\testconsole|
|asynfile|插件[asyncore]|文件|\support\testfile_copy<br>\support\testfile_copy-pipe|
|asynipcs|插件[asyncore]|进程间通讯|\support\testipcclient<br>\support\testipcserver|
|asynneta|插件[asyncore]|服务端代理<br>1.支持http/https代理：实现Basic/Digest认证<br>2.支持ftp/ftps代理<br>3.支持socks4.0/4.a/5.0代理<br>4.提供tcp/udp端口转发|[aneta](https://github.com/netsecsp/aneta)|
|asynsock|插件[asyncore]|网络<br>1.支持ipv6兼容ipv4<br>2.支持默认DNS 解析|\support\testnetclient<br>\support\testnetserver<br>[pingx](https://github.com/netsecsp/pingx)|
|dns|插件[asynsock]|域名解析<br>1.udp dns<br>2.tcp dns<br>3.httpDNS: 实现阿里云/腾迅云|\support\testdns|
|ftp |插件[asynsock]|ftp 协议|[aftpx](https://github.com/netsecsp/aftpx)<br>[acurl](https://github.com/netsecsp/acurl)|
|http|插件[asynsock]|http协议|[ahttp](https://github.com/netsecsp/ahttp)<br>[acurl](https://github.com/netsecsp/acurl)|
|rtsp|插件[asynsock]|rtsp协议<br>1.支持rtsp over http|\support\testnetclient_rtsp<br>\support\testnetserver_rtsp|
|ssl|插件[asynsock]|ssl/tls加/解密<br>1.支持p12证书|\support\testnetclient_ssl<br>\support\testnetserver_ssl|
|proxy|插件[asynsock]|客户端代理<br>1.支持http/https代理：实现Basic/Digest认证<br>2.支持ftp/ftps代理<br>3.支持socks4.0/4.a/5.0代理|\support\testnetclient_proxy<br>\support\testnetserver_socks|
|websocket|插件[asynsock]|websocket协议<br>1.支持数据帧分片<br>2.优先发送控制帧|\support\testnetclient_websocket<br>\support\testnetserver_websocket|
|zip|插件|基于zlib1.3.1实现IDataTransmit接口<br>1.支持压缩zip文件<br>2.deflate/inflate数据|\support\testframe|
|sqlite|插件|实现IOsComman接口[sqlite3.47.2]|\support\testframe|
|dtp|插件[asynsock]|实现tcp / udp端口复用的开发框架|\support\testnetserver_dtp-tcp.port<br>\support\testnetserver_dtp-udp.port|
|lua|插件|实现IOsCommand接口的开发框架|\support\testlua\testlua<br>\support\testlua\testapi|
|jvmproxy|插件|实现IOsCommand接口的开发框架|\support\testjava\testjvm<br>\support\testjava\testapi<br>[javax](https://github.com/netsecsp/javax)|
|python38/python312|插件|实现IOsCommand接口的开发框架|\support\testpython\testpython<br>\support\testpython\testapi|
|edgeproxy|插件[asyncore]|封装ICoreWebView2|\support\testedgeproxy|

# 变更记录
2025/02/13 发布windows平台的asynframe framework v2.0.1  
> 发布插件: edgeproxy  
> 支持动态加载log4cplus

2024/12/23 发布windows平台的asynframe framework v1.9.0  
2024/11/11 发布windows平台的asynframe framework v1.8.1  
2024/08/16 发布windows平台的asynframe framework v1.7.1  
2024/07/12 发布windows平台的asynframe framework v1.6.1  
2023/11/15 发布windows平台的asynframe framework v1.5.2  
2023/03/31 发布windows平台的asynframe framework v1.4.6  
2023/02/02 发布windows平台的asynframe framework v1.3.2  
2022/06/08 发布windows平台的asynframe framework v1.2.0  
2022/05/26 发布windows平台的asynframe framework v1.1.0  
2022/05/05 发布windows平台的asynframe framework v1.0.0  

# 编译环境
> sdk_v2.0.1-Msvc2019_20250213.zip是通过Microsoft Visual Studio 2019编译的SDK  
> sdk_v2.0.1-Msvc2013_20250213.zip是通过Microsoft Visual Studio 2013编译的SDK  

1. 需在工程里设置asynframe相应的include/lib路径  
2. 根据工程的运行库选择链接asynframe相应的asynsdk_mini-[MD/MDd/MT/MTd].lib  
3. 链接asyncore_dll.lib  
```c++
int main(int argc, const char *argv[])
{
    HRESULT ret = Initialize(NULL, NULL); //Initialize asynframe
    if( ret != NO_ERROR )
    {
        return 1;
    }

    InstancesManager *lpInstancesManager = GetInstancesManager(); //Get the instance manager, which can get all interfaces

    CComPtr<IAsynFrameThread> spAsynFrameThread; //Create thread
    lpInstancesManager->NewInstance(0,0,IID_IAsynFrameThread, (void**)&spAsynFrameThread);

    lpInstancesManager->Require(STRING_from_string(IN_AsynNetwork)); //Load network module

    CComPtr<IAsynNetwork    > spAsynNetwork;
    lpInstancesManager->GetInstance(STRING_from_string(IN_AsynNetwork), IID_IAsynNetwork, (void **)&spAsynNetwork);

    CComPtr<IAsynUdpSocket  > spAsynUdpSocket; //Create UDP object
    spAsynNetwork->CreateAsynTcpSocket(&spAsynTcpSocket );

    spAsynUdpSocket->Bind(asynsdk::STRING_EX::null, 0, 0, NULL);  

    ......

    Destory(); //Destory asynframe
    return 0;
}
```

# 开发  

<u>接口定义</u>  
[IAsynFrame](https://netsecsp.github.io/doc/IAsynFrame.txt)  
[IAsynFileSystem](https://netsecsp.github.io/doc/IAsynFileSystem.txt)  
[IAsynIpcChannel](https://netsecsp.github.io/doc/IAsynIpcChannel.txt)  
[IAsynNetwork](https://netsecsp.github.io/doc/IAsynNetwork.txt)  
[IAsynNetAgent](https://netsecsp.github.io/doc/IAsynNetAgent.txt)  
[IConsole](https://netsecsp.github.io/doc/IConsole.txt)  
[IExceptionTrapper](https://netsecsp.github.io/doc/IExceptionTrapper.txt)  
[INet](https://netsecsp.github.io/doc/INet.txt)  
[IProxy](https://netsecsp.github.io/doc/IProxy.txt)  
[ISsl](https://netsecsp.github.io/doc/ISsl.txt)  
[IScriptHost](https://netsecsp.github.io/doc/IScriptHost.txt)  
[IDtp](https://netsecsp.github.io/doc/IDtp.txt)  

<u>[插件使用](https://netsecsp.github.io/doc/externapi.md)</u>   

<u>基础模块</u>  
[asyncore](https://netsecsp.github.io/mds/asynframe.md)  
[asynfile](https://netsecsp.github.io/mds/asynfile.md)  
[asynipcs](https://netsecsp.github.io/mds/asynipcs.md)  
[asynsock](https://netsecsp.github.io/mds/asynsock.md)  
[crashexplorer](https://netsecsp.github.io/mds/crashexplorer.md)  

<u>网络模块</u>  
[asynneta](https://netsecsp.github.io/mds/asynneta.md)    
[dtp](https://netsecsp.github.io/mds/dtp.md)  
[dns](https://netsecsp.github.io/mds/dns.md)  
[ftp](https://netsecsp.github.io/mds/ftp.md)  
[http](https://netsecsp.github.io/mds/http.md)  
[rtsp](https://netsecsp.github.io/mds/rtsp.md)  
[proxy](https://netsecsp.github.io/mds/proxy.md)  
[ssl](https://netsecsp.github.io/mds/ssl.md)  
[websocket](https://netsecsp.github.io/mds/websocket.md)  

<u>扩展模块</u>  
[console](https://netsecsp.github.io/mds/console.md)  
[lua](https://netsecsp.github.io/mds/lua.md)  
[jvm](https://netsecsp.github.io/mds/jvmproxy.md)  
[python](https://netsecsp.github.io/mds/python.md)  
[zip](https://netsecsp.github.io/mds/zip.md)  
[sqlite](https://netsecsp.github.io/mds/sqlite.md)  

# 鸣谢  
[Log4cplus](https://github.com/log4cplus/log4cplus)  
[Lua](http://www.lua.org)  
[Luatinker](https://github.com/zupet/luatinker)  
[Zlib](http://www.zlib.net)  
[Sqlite](https://www.sqlite.org/)  
[FFmpeg](https://ffmpeg.org)  
[Python](https://github.com/python/cpython)  

# 版权信息  
Copyright (c) 2012 - 2032, All rights reserved.  
Author: Shengqian Yang, China, netsecsp@hotmail.com  

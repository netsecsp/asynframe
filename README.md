# 项目介绍  
> 这是一款windows平台下基于消息驱动的SDK开发框架，提供线程、管道、文件和网络等基础接口。  

解决软件产品开发过程中的4大问题:  
1. 多线程和跨模块之间的通讯/同步问题  
2. 资源占用过多／性能问题  
3. 死锁问题  
4. 极难控制执行超时的问题  

**功能特性:**  
1. 可轻松集成到MFC，[DUI](https://github.com/duilib/duilib)，[Qt6.x](https://download.qt.io/archive/qt)等系统  
2. 支持设备链，提供统一设备操作接口（包括File、Pipe、Socket等）  
3. 通过操作链解决集成第三方开源项目时的线程之间的同步/通讯以及性能等问题  
4. 实现基本网络协议模块：dns/udp/tcp/ssl/ftp/http/proxy  
5. 支持微秒级定时器  
6. 集成[log4cplus](https://github.com/log4cplus/log4cplus)，统一模块输出日志  

**开发优势:**  
1. 协助产品模块化，实现通过组装模块方式堆积产品功能。  
2. 网络模块支持IPv4/IPv6。  
3. 统一的开发模板，无锁化机制以及高性能IO框架降低开发者学习成本。能够迅速开发出稳定地，高性能的应用模块。可大幅度降低开发代码量。  

|模块|类型|功能|例子/程序|
|:--|:--|:--|:--|
|asyncore|框架|frame框架|\support\testframe|
|||集成到MFC|\support\3rd\mfc\testnetserver<br>\support\3rd\mfc\testnetclient_dlg<br>\support\3rd\mfc\testnetclient_doc|
|||集成到DUI|\support\3rd\\[dui](https://github.com/duilib/duilib)|
|crashexplorer|插件[asyncore]|捕获当前进程的崩溃信息，同时生成dmp文件|\support\testcrashexplorer|
|console|插件[asyncore]|命令控制台<br>1.支持加载/卸载ICommand插件：cmd/lua<br>2.支持键盘/鼠标输入|\support\testconsole|
|asynfile|插件[asyncore]|文件|\support\testfile_copy<br>\support\testfile_copy-pipe|
|asynipcs|插件[asyncore]|IPCS: 进程间通讯|\support\testipcclient<br>\support\testipcserver|
|asynneta|插件[asyncore]|服务端代理<br>1.支持http[s]代理：实现Basic/Digest认证<br>2.支持ftp [s]代理<br>3.支持socks4.0/4.a/5.0代理|[aneta](http://aneta.sf.net)|
|asynsock|插件[asyncore]|网络: <br>1.支持ipv6兼容ipv4<br>2.支持默认DNS 解析|\support\testnetclient<br>\support\testnetserver<br>[ping](http://pingx.sf.net)|
|dns|插件[asynsock]|域名解析<br>1.udp dns<br>2.tcp dns<br>3.httpDNS: 阿里云/腾迅云|\support\testdns|
|ftp|插件[asynsock]|ftp 协议|[aftpx](http://aftpx.sf.net)|
|http|插件[asynsock]|http协议|[ahttp](http://ahttp.sf.net)|
|ssl|插件[asynsock]|ssl/tls加/解密<br>1.支持p12证书|\support\testsslclient<br>\support\testsslserver|
|proxy|插件[asynsock]|客户端代理<br>1.支持http[s]代理：实现Basic/Digest认证<br>2.支持ftp [s]代理<br>3.支持socks4.0/4.a/5.0代理|\support\testnetclient_proxy<br>\support\testnetserver_socks|
|sqlite|插件|基于sqlite-3.3.20实现IDataTransmit接口|\support\testframe|
|zip|插件|基于zlib-1.2.11.0实现IDataTransmit接口<br>1.支持压缩zip文件<br>2.deflate/inflate数据|\support\testframe|
|lua|插件|基于lua-5.4.4实现ICommand接口<br>1.支持多线程|\support\testframe|

# 变更记录
> 2022/05/05发布基于windows平台的asynframe_v1.0  

# 编译环境
> *sdk_1.0.0.0-Msvc2019_20220505.zip 基于Microsoft Visual Studio 2019编译SDK*  
> *sdk_1.0.0.0-Msvc2013_20220505.zip 基于Microsoft Visual Studio 2013编译SDK*  
> 需在工程里设置frame相应的include/lib路径  
> 根据工程的运行库选择链接frame相应的asynsdk_mini-[MD/MDd/MT/MTd].lib  

# 接口介绍  

# 鸣谢  
> [log4cplus](https://github.com/log4cplus/log4cplus)  

# 版权信息  
> Copyright (c) 2012 - 2032, All rights reserved.  
> Author: Shengqian Yang, China, netsecsp@hotmail.com  
#This is an SDK development framework based on message driven (including asynchronous IO events) under Windows platform, which provides basic interfaces such as thread / thread pool, pipeline, file and network.  
#Functional features:  
1.It can be easily integrated into MFC, DUI and QT6 2.4 other systems  
2.Support equipment chain and provide unified equipment operation interface (including file, pipe, socket, etc.)  
3.Solve the synchronization / communication and performance problems between threads when integrating third-party open source projects through the operation chain  
4.Implement the basic network protocol module: DNS / SSL / ftp / HTTP / proxy  
5.Support high-precision timer  
6.Implement the application module:  
     DTP supports TCP / UDP port multiplexing  
     DNS supports TCP / UDP / HTTP domain name resolution and httpdns of Tencent cloud / Alibaba cloud  
     Lua facilitates application product integration and business logic control  
     Zip supports deflate / inflate data and zip multiple files  
     Console realizes console, which is convenient for debugging  
     Asynneta Implementing FTP / HTTP / Socks network proxy   
     Crashexplorer automatically writes DMP files when it detects that a process crashes  

#Development advantages:  
1.Assist in product modularization and realize the function of stacking products by assembling modules.  
2.The network module supports IPv4 / IPv6.  
3.Unified development template, lockless mechanism and high-performance IO framework reduce the learning cost of developers. It can quickly develop stable and high-performance application modules. It can reduce the amount of development code by 60%.  

#Features:  
1.implementation base framework  
2.implementation file interface  
3.implementation interprocess communication interface  
4.implementation network interface: provided DNS、IPv4、IPv6 and IPX/SPX  
5.implementation network agent service: provided ftp/http/socks network agent service  
6.implementation SSL protocol  
7.implementation FTP protocol  
8.implementation HTTP/1.0, HTTP/1.1 protocol  
9.implementation FTP, HTTP, socks4.0/4.a/5.0 proxy  

${asynfame}  
     ｜  
     ｜---bin                                     #dll  
     ｜                                           
     ｜---include                                 #Module interface files  
     ｜---lib                                     #Module library files  
     ｜                                           
     ｜---support                                 #Application source code directory  
     ｜    ｜                                     
     ｜    ｜----3rd                              
     ｜           ｜----Dui                       #intergrate dui  
     ｜           ｜----mfc                       
     ｜                 ｜----testnetclient_dlg   #intergrate mfc dlg  
     ｜                 ｜----testnetclient_doc   #intergrate mfc doc  
     ｜                 ｜----testnetserver       #intergrate mfc dlg  
     ｜    ｜----testconsole                      #console  
     ｜    ｜----testcrashexplorer                #crash explorer  
     ｜    ｜----testdns                          #udp/tcp/http DNS  
     ｜    ｜----testfiles_copy                   #copy file  
     ｜    ｜----testfiles_copy-pipe              #copy file  
     ｜    ｜----testframe                        #Asynchronous message development example  
     ｜    ｜----testipcclient                    #ipc client  
     ｜    ｜----testipcserver                    #ipc server  
     ｜    ｜----testnetclient                    #client(support IPv4/IPv6/IPX/SPX)  
     ｜    ｜----testnetclient_proxy              #client proxy  
     ｜    ｜----testnetclient_ssl                #client ssl  
     ｜    ｜----testnetserver                    #server(supportIPv4/IPv6/IPX/SPX)  
     ｜    ｜----testnetserver_socks              #server socks  
     ｜    ｜----testnetserver_ssl                #server ssl  

#这是一款windows平台下基于消息驱动（包括异步IO事件）的SDK开发框架，提供线程/线程池、管道、文件和网络等基础接口。  
#功能特点:  
1.可以轻松集成到MFC，DUI，Qt6.2.4等系统  
2.支持设备链，提供统一设备操作接口（包括File、Pipe、Socket等）  
3.通过操作链解决集成第三方开源项目时的线程之间的同步/通讯以及性能等问题  
4.实现基本网络协议模块：dns/ssl/ftp/http/proxy  
5.支持高精度定时器  
6.实现应用模块：  
        dtp支持Tcp/Udp端口复用  
        dns支持Tcp/Udp/Http域名解析，支持腾讯云/阿里云的httpDNS  
        lua方便应用产品集成lua实现业务逻辑控制  
        zip支持deflate /inflate数据，zip多文件  
        console实现控制台，便于调试  
        asynneta实现ftp/http/socks网络代理  
        crashexplorer监控到进程崩溃时自动写dmp文件  

#开发优势:  
1.协助产品模块化，实现通过组装模块方式堆积产品功能。  
2.网络模块支持IPv4/IPv6。  
3.统一的开发模板，无锁化机制以及高性能IO框架降低开发者学习成本。能够迅速开发出稳定地，高性能的应用模块。可降低60%的开发代码量。  

#模块介绍:  
1.基础模块: asynsdk.lib辅助开发模块库文件 
     asyncore.dll 基础框架（包括线程、管道、设备读写控制器等）  
     asynfile.dll 文件接口  
     asynipcs.dll 进程间通讯接口  
     asynsock.dll 网络接口：支持DNS、IPv4、IPv6 和 IPX/SPX  
     asynneta.dll 代理服务: 支持ftp/http/socks网络代理服务  
      console.dll 控 制 台  
crashexplorer.dll 监控到进程崩溃时自动写dmp文件  

2.协议模块:   
    dns.dll 实现udp/tcp/http.DNS域名解析  
    ssl.dll 实现tls/ssl加/解密  
    ftp.dll 实现ftp协议（包括隐式/显式ftps）  
   http.dll 实现http/1.0、http/1.1协议（包括https）  
  proxy.dll 实现ftp、http、socks4/4a/5代理  

3.扩展模块: 
     lua.dll 集成 lua  
     zip.dll 集成zlib  
  sqlite.dll 集成sqlite3  

4.应用模块  
     dtp.dll 提供tcp/udp端口复用  

5.应用源码  
   a. aftpx客户端程序 http://aftpx.sf.net  
      基于windows平台支持IPv4/IPv6的ftp客户端程序(控制台模式)  
      (1)支持ftp，http1.1，socks4/4a/5代理  
      (2)支持ftp/ftps  
      (3)支持下载目录  
      (4)支持断点续传  
      (5)支持限速下载  
      
   b. aftpx服务端程序 http://aftpx.sf.net  
      基于windows平台支持IPv4/IPv6的ftp服务端程序(控制台模式)  
      (1)支持帐号配置，包括：目录、限速和密码等  
      (2)支持断点续传  

   c. ahttp客户端程序 http://ahttp.sf.net  
      基于windows平台支持IPv4/IPv6的http客户端程序(控制台模式)  
      (1)支持http1.0/1.1，socks4/4a/5代理  
      (2)支持http/https  
      (3)支持断点续传  
      
   d. ahttp服务端程序 http://ahttp.sf.net  
      基于windows平台支持IPv4/IPv6的http服务端程序(控制台模式)  
      (1)支持通过浏览器查看文件目录，自动监控目录变化  
      (2)支持断点续传  
      
   e. aneta服务端程序 http://aneta.sf.net  
      基于windows平台支持ftp/http/socks代理端程序(控制台模式)  
      (1)支持ftp，http1.0/1.1，socks4/4a/5网络代理  
      (2)支持帐号配置，包括：限速和密码等  
   
   f. pingx客户端程序 http://pingx.sf.net  
      基于windows平台支持ping地址  
      (1)支持udp/tcp/http解析域名  
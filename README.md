Copyright (c) 2012 - 2032, All rights reserved.  
Author: Shengqian Yang, China, last updated 05/05/2022  
有合作意向者请通过netsecsp@hotmail.com联系 

#提供windows平台下基于消息驱动（包括异步IO事件）的c++开发框架，是基于产品设计的开发接口（简单易用）和敏捷开发框架的解决方案；支持线程、管道、文件和网络等基础接口：   
1、支持仿Windows窗口类的消息驱动接口，可以轻松嵌入到MFC框架里去，即：共享窗口线程  
2、提供统一设备操作接口（包括File、Pipe、Socket等）   
3、支持串行异步操作机制，支持Socket链  
4、实现基本网络协议模块：dns/ssl/ftp/http/proxy
5、实现应用模块：dtp，支持Tcp/Udp端口复用\
				 asynneta，实现ftp/http/socks网络代理服务  

#开发优势：  
1、协助产品模块化，实现通过组装模块方式研发产品功能。
2、所有开发的网络模块自动支持IPv4/IPv6。
3、统一的设备接口、统一的开发模板、高性能IO框架降低学习成本，解决c++初学者使用线程、锁、Socket编程以及内存泄露等所遇到的问题，能够迅速研发出稳定地，高性能的应用模块。 

#模块介绍:  
1.基础模块: asynsdk.lib辅助开发模块库文件
     asyncore.dll 基础框架（包括线程、管道、设备读写控制器等）  
     asynfile.dll 文件接口  
     asynipcs.dll 进程间通讯接口  
     asynsock.dll 网络接口：支持DNS、IPv4、IPv6 和 IPX/SPX  
     asynneta.dll 代理服务: 支持ftp/http/socks网络代理服务
      console.dll 控 制 台
crashexplorer.dll 监控进程崩溃

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
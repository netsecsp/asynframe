## Asynframe framework v1.4.4 english | [中文](/README.md)
> https://github.com/netsecsp/asynframe  

# Background  
In the process of software product development, we often encounter problems in the following scenarios:  
1. Centralized management of configuration parameters required by each module-- Involving configuration parameter loading and persistence;  
2. Can the interface group use the existing network module to develop its own functions, such as submitting the log file to the background through HTTP protocol-- Knowledge difficulties involving network, HTTP DNS and using network agent;  
3. Problems caused by information interaction between the interface and other SDK modules (including integration of third-party open source projects)-- Thread synchronization, event sequence and long operation time are involved;  
4. Each module (including the interface) solves time-consuming / synchronous operation and other problems by creating working threads, -- involving resource optimization;  
5. Using synchronous lock, -- there is a deadlock problem.  
6. The complex business logic of the module leads to frequent release of patches  

# Introduction  
> This is a message driven SDK development framework based on Windows platform, which provides basic interfaces such as threads, pipes, files and networks.  

Asynframe framework solves the six problems mentioned above in the process of software product development:  
1. Manage the parameters of each module through the famous parameter management object  
2. Reduce the learning cost through plug-in and unified operation interface  
3. Provide notification results in the caller's thread and set the serial operation chain to solve the problems of thread synchronization, event sequence and long operation time  
4. Optimize the execution of working threads of each module through the named thread pool  
5. Provide lockless mechanism  
6. Integrate Lua plug-in to realize hot update  

**Feature:**  
1. Easy integration into MFC，[DUI](https://github.com/duilib/duilib)，[Qt6.x](https://download.qt.io/archive/qt) And other third-party open source projects  
2. Provide a unified device operation interface (including file, pipe, socket, etc.)  
3. The operation chain is used to solve the problems of synchronization / communication between threads, execution timeout and resource / performance when integrating third-party open source projects  
4. Provide basic network protocol module：dns/udp/tcp/ssl/ftp/http/rtsp/proxy/websocket  
6. Reference count management object memory  
7. Provide microsecond timer  
8. Integrate [Log4cplus](https://github.com/log4cplus/log4cplus)，Unified modules output log  
![image](https://netsecsp.github.io/img/01_asynframe.jpg)  

**Development advantage:**  
1. Support the upgradable plug-in and assist the modularization of windows products.  
2. Support the generation of stack information and dmp files when cross process acquisition crashes.  
3. Embed the micro thread core object into other threads to isolate other codes, so as to facilitate code reconstruction.  
4. Get a very smooth user experience through the asynchronous execution framework.  
5. The unified development template, non locking mechanism, high-performance IO framework and demo reduce the learning cost of developers. It can rapidly develop stable and high-performance application modules. It can greatly reduce the amount of developed code.  

|module|type|function|demo|
|:--|:--|:--|:--|
|asyncore|framework|asynframe|\support\testframe|
|||integrate mfc|\support\3rd\mfc\testnetserver<br>\support\3rd\mfc\testnetclient_dlg<br>\support\3rd\mfc\testnetclient_doc|
|||integrate DUI|\support\3rd\\[dui](https://github.com/duilib/duilib)|
|crashexplorer|plugin[asyncore]|Capture the crash information of the current process and generate DMP file at the same time|\support\testcrashexplorer|
|console|plugin[asyncore]|console<br>1.implement loading / unloading ICommand plug-ins：cmd/lua<br>2.implement keyboard / mouse input|\support\testconsole|
|asynfile|plugin[asyncore]|file|\support\testfile_copy<br>\support\testfile_copy-pipe|
|asynipcs|plugin[asyncore]|Interprocess communication|\support\testipcclient<br>\support\testipcserver|
|asynneta|plugin[asyncore]|network agent service<br>1.implement http[s] agent：Basic/Digest authorize<br>2.implement ftp[s] agent<br>3. implement socks4.0/4.a/5.0 agent|[aneta](https://github.com/netsecsp/aneta)|
|asynsock|plugin[asyncore]|network: <br>1.implement IPv6 and compatible with IPv4<br>2.implement DNS|\support\testnetclient<br>\support\testnetserver<br>[ping](https://github.com/netsecsp/pingx)|
|dns|plugin[asynsock]|DNS<br>1.implement udp dns<br>2.implement tcp dns<br>3.implement httpDNS: Alibaba cloud/Tengxun cloud|\support\testdns|
|ftp|plugin[asynsock]|ftp protocol|[aftpx](https://github.com/netsecsp/aftpx)|
|http|plugin[asynsock]|http protocol|[ahttp](https://github.com/netsecsp/ahttp)|
|rtsp|plugin[asynsock]|rtsp protocol<br>1.implement rtsp over http|\support\testnetclient_rtsp<br>\support\testnetserver_rtsp|
|ssl|plugin[asynsock]|ssl/tls encryption/decryption<br>1.implement p12 certificate|\support\testnetclient_ssl<br>\support\testnetserver_ssl|
|proxy|plugin[asynsock]|client proxy<br>1.implement http/https proxy：Basic/Digest authorize<br>2.implement ftp/ftps proxy<br>3.implement socks4.0/4.a/5.0 proxy|\support\testnetclient_proxy<br>\support\testnetserver_socks|
|websocket|plugin[asynsock]|websocket protocol<br>1.implement data frame slice<br>2.priority transmission control frame|\support\testnetclient_websocket<br>\support\testnetserver_websocket|
|Dtp|plugin[asyncock]|port reuse framework to implement tcp/udp|support testnetserver_ dtp-tcp.port<br>\support\testnetserver_ dtp-udp.port|
|zip|plugin|Implementation of IDataTransmit interface based on zlib-1.2.11.0<br>1.implement zip files<br>2.deflate/inflate data|\support\testframe|
|lua|plugin|Implementation of IOsCommand interface based on lua-5.4.4<br>1.implement threads and logs|\support\testframe<br>\support\testlua\testapi|ß
|sqlite|plugin|Implementation of IOsCommand interface based on sqlite-3.3.20|\support\testframe|

# Change log
> 2023/03/18 Release asynframe framework v1.4.4  
1. Publish plugin: dtp/ras  
2. Adjust interface definition  
3. Fix known problems  
4. Fix memory leak  
> 2023/02/02 Release asynframe framework v1.3.2  
> 2022/06/08 Release asynframe framework v1.2.0  
> 2022/05/26 Release asynframe framework v1.1.0  
> 2022/05/05 Release asynframe framework v1.0.0  

# Build
> sdk_v1.4.4-Msvc2019_20230318.zip is compiled through Microsoft Visual Studio 2019  
> sdk_v1.4.4-Msvc2013_20230318.zip is compiled through Microsoft Visual Studio 2013  

1. The include / lib path corresponding to asynframe needs to be set in the project  
2. Select and link the corresponding asynsdk of asynframe according to the runtime of the asynsdk_mini-[MD/MDd/MT/MTd].lib  
3. Link asyncore.lib(3 API functions are provided[^1])  
[^1]: STDAPI_(extern HRESULT) Initialize( IAsynMessageEvents *param1, IUnknown *param2 );<br>STDAPI_(extern InstancesManager*) GetInstancesManager();<br>STDAPI_(extern HRESULT) Destory();  
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

# Development  

- Interface  
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
  [IVmHost](https://netsecsp.github.io/doc/IVmHost.txt)  
  [IDtp](https://netsecsp.github.io/doc/IDtp.txt)  

- [Plugins](https://netsecsp.github.io/doc/externapi.md)   
  <u>base modules</u>  
  - [asyncore](https://netsecsp.github.io/mds/asynframe.md)  
  - [asynfile](https://netsecsp.github.io/mds/asynfile.md)  
  - [asynipcs](https://netsecsp.github.io/mds/asynipcs.md)  
  - [asynsock](https://netsecsp.github.io/mds/asynsock.md)  
  - [crashexplorer](https://netsecsp.github.io/mds/crashexplorer.md)  

  <u>network modules</u>  
  - [asynneta](https://netsecsp.github.io/mds/asynneta.md)    
  - [dtp](https://netsecsp.github.io/mds/dtp.md)  
  - [dns](https://netsecsp.github.io/mds/dns.md)  
  - [ftp](https://netsecsp.github.io/mds/ftp.md)  
  - [http](https://netsecsp.github.io/mds/http.md)  
  - [rtsp](https://netsecsp.github.io/mds/rtsp.md)  
  - [proxy](https://netsecsp.github.io/mds/proxy.md)  
  - [ssl](https://netsecsp.github.io/mds/ssl.md)  
  - [websocket](https://netsecsp.github.io/mds/websocket.md)  

  <u>extend modules</u>  
  - [console](https://netsecsp.github.io/mds/console.md)  
  - [lua](https://netsecsp.github.io/mds/lua.md)  
  - [zip](https://netsecsp.github.io/mds/zip.md)  
  - [sqlite](https://netsecsp.github.io/mds/sqlite.md)  

# Thanks  
> [Log4cplus](https://github.com/log4cplus/log4cplus)  
> [Lua](http://www.lua.org)  
> [Zlib](http://www.zlib.net)  
> [Sqlite](https://www.sqlite.org/)  

# Copyright  
> Copyright (c) 2012 - 2032, All rights reserved.  
> Author: Shengqian Yang, China, netsecsp@hotmail.com  

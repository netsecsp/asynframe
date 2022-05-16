## Asynframe framework 1.0 

# Background [中文](/index.md) 
In the process of software product development, we often encounter problems in the following scenarios:
1. Centralized management of configuration parameters required by each module-- Involving configuration parameter loading and persistence;  
2. Can the interface group use the existing network module to develop its own functions, such as submitting the log file to the background through HTTP protocol-- Knowledge difficulties involving network, HTTP DNS and using network agent;  
3. Problems caused by information interaction between the interface and other SDK modules (including integration of third-party open source projects)-- Thread synchronization, event sequence and long operation time are involved;  
4. Each module (including the interface) solves time-consuming / synchronous operation and other problems by creating working threads, -- involving resource optimization;  
5. Using synchronous lock, -- there is a deadlock problem.  

# Introduction  
> This is a message driven SDK development framework based on Windows platform, which provides basic interfaces such as threads, pipes, files and networks.  

Asynframe framework solves the five problems mentioned above in the process of software product development:  
1. Manage the parameters of each module through the famous parameter management object  
2. Reduce the learning cost through plug-in and unified operation interface  
3. Provide notification results in the caller's thread and set the serial operation chain to solve the problems of thread synchronization, event sequence and long operation time  
4. Optimize the execution of working threads of each module through the named thread pool  
5. Provide lockless mechanism  

**Feature:**  
1. Easy integration into MFC，[DUI](https://github.com/duilib/duilib)，[Qt6.x](https://download.qt.io/archive/qt) And other third-party open source projects  
2. Provide a unified device operation interface (including file, pipe, socket, etc.)  
3. The operation chain is used to solve the problems of synchronization / communication between threads, execution timeout and resource / performance when integrating third-party open source projects  
4. Provide basic network protocol module：dns/udp/tcp/ssl/ftp/http/proxy  
6. Reference count management object memory  
7. Support microsecond timer  
8. Integrate [Log4cplus](https://github.com/log4cplus/log4cplus)，Unified modules output log  

**Development advantage:**  
1. Assist in product modularization  
2. Unified development template, lockless mechanism and high-performance IO framework reduce the learning cost of developers. It can quickly develop stable and high-performance application modules. It can greatly reduce the amount of development code  

|module|type|function|demo|
|:--|:--|:--|:--|
|asyncore|framework|asynframe|\support\testframe|
|||integrate mfc|\support\3rd\mfc\testnetserver<br>\support\3rd\mfc\testnetclient_dlg<br>\support\3rd\mfc\testnetclient_doc|
|||integrate DUI|\support\3rd\\[dui](https://github.com/duilib/duilib)|
|crashexplorer|plugin[asyncore]|Capture the crash information of the current process and generate DMP file at the same time|\support\testcrashexplorer|
|console|plugin[asyncore]|console<br>1.implement loading / unloading ICommand plug-ins：cmd/lua<br>2.implement keyboard / mouse input|\support\testconsole|
|asynfile|plugin[asyncore]|file|\support\testfile_copy<br>\support\testfile_copy-pipe|
|asynipcs|plugin[asyncore]|Interprocess communication|\support\testipcclient<br>\support\testipcserver|
|asynneta|plugin[asyncore]|network agent service<br>1.implement http[s] agent：Basic/Digest认证<br>2.implement ftp[s] agent<br>3. implement socks4.0/4.a/5.0 agent|[aneta](https://github.com/netsecsp/aneta)|
|asynsock|plugin[asyncore]|network: <br>1.implement IPv6 and compatible with IPv4<br>2.implement DNS|\support\testnetclient<br>\support\testnetserver<br>[ping](https://github.com/netsecsp/pingx)|
|dns|plugin[asynsock]|DNS<br>1.implement udp dns<br>2.implement tcp dns<br>3.implement httpDNS: Alibaba cloud/Tengxun cloud|\support\testdns|
|ftp|plugin[asynsock]|ftp protocol|[aftpx](https://github.com/netsecsp/aftpx)|
|http|plugin[asynsock]|http protocol|[ahttp](https://github.com/netsecsp/ahttp)|
|ssl|plugin[asynsock]|ssl/tls Encryption / decryption<br>1.implement p12 certificate|\support\testsslclient<br>\support\testsslserver|
|proxy|plugin[asynsock]|client proxy<br>1.implement http[s] proxy：Basic/Digest认证<br>2.implement ftp[s] proxy<br>3.implement socks4.0/4.a/5.0 proxy|\support\testnetclient_proxy<br>\support\testnetserver_socks|
|sqlite|plugin|Implementation of IDataTransmit interface based on sqlite-3.3.20|\support\testframe|
|zip|plugin|Implementation of IDataTransmit interface based on zlib-1.2.11.0<br>1.implement zip files<br>2.deflate/inflate data|\support\testframe|
|lua|plugin|Implementation of ICommand interface based on lua-5.4.4<br>1.implement threads and logs|\support\testframe<br>\support\testlua\testapi|ß

# Change log
> 2022/05/05Release asynframe 1.0 based on Windows platform

# Build
> sdk_1.0.0.0-Msvc2019_20220505.zip is compiled through Microsoft Visual Studio 2019  
> sdk_1.0.0.0-Msvc2013_20220505.zip is compiled through Microsoft Visual Studio 2013  

1. The include / lib path corresponding to asynframe needs to be set in the project  
2. Select and link the corresponding asynsdk of asynframe according to the runtime of the asynsdk_mini-[MD/MDd/MT/MTd].lib  
3. Link asyncore.lib(Three API functions are provided)  
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

    lpInstancesManager->Verify(STRING_from_string(IN_AsynNetwork)); //Load network module

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
- [asynframe export function](/doc/pluginapi.md)  

- Interface  
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

- [Plugins](/doc/externapi.md)   

# Thanks  
> [Log4cplus](https://github.com/log4cplus/log4cplus)  
> [Lua](http://www.lua.org)  
> [Zlib](http://www.zlib.net)  
> [Sqlite](https://www.sqlite.org/)  

# Copyright  
> Copyright (c) 2012 - 2032, All rights reserved.  
> Author: Shengqian Yang, China, netsecsp@hotmail.com  

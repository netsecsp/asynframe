## README english | [中文](https://github.com/netsecsp/asynframe/blob/master/README.md)

# Introduction  
> This is a message driven SDK development framework based on Windows platform, which provides basic interfaces such as threads, pipes, files and networks.  

Solve five major problems in the process of software product development:  
1. Communication / synchronization between multithreading and cross module  
2. Excessive resource occupation / performance problems  
3. Deadlock problem  
4. Control the problem of execution timeout
5. Memory leak  

**Feature:**  
1. Easy integration into MFC，[DUI](https://github.com/duilib/duilib)，[Qt6.x](https://download.qt.io/archive/qt) And other third-party open source projects  
2. Provide a unified device operation interface (including file, pipe, socket, etc.)  
3. The operation chain is used to solve the problems of synchronization / communication between threads, execution timeout and resource / performance when integrating third-party open source projects  
4. Provide basic network protocol module：dns/udp/tcp/ssl/ftp/http/proxy  
6. Reference count management object memory  
7. Support microsecond timer  
8. integrate[Log4cplus](https://github.com/log4cplus/log4cplus)，Unified modules output log  

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

# Changeling
> 2022/05/05Release asynframe 1.0 based on Windows platform

# Build
> sdk_1.0.0.0-Msvc2019_20220505.zip is an SDK compiled through Microsoft Visual Studio 2019  
> sdk_1.0.0.0-Msvc2013_20220505.zip is an SDK compiled through Microsoft Visual Studio 2013  

1. The include / lib path corresponding to asynframe needs to be set in the project  
2. Select and link the corresponding asynsdk of asynframe according to the runtime of the asynsdk_mini-[MD/MDd/MT/MTd].lib  
3. Link asyncore.lib(Three API functions are provided[^1])  
[^1]: STDAPI_(extern HRESULT) Initialize( IAsynMessageEvents *param1, IKeyvalSetter *param2 );<br>STDAPI_(extern InstancesManager*) GetInstancesManager();<br>STDAPI_(extern HRESULT) Destory();  
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

    spAsynUdpSocket->Bind(asynsdk::STRING_EX::null, 0, 0, NULL);ß

    ......

    Destory(); //Destory asynframe
    return 0;
}
```

# Development  
- [asynframe expport function](https://github.com/netsecsp/asynframe/blob/master/doc/pluginapi.md)  

- Interface  
  [IAsynFrame](https://github.com/netsecsp/asynframe/blob/master/doc/IAsynFrame.txt)  
  [IAsynFileSystem](https://github.com/netsecsp/asynframe/blob/master/doc/IAsynFileSystem.txt)  
  [IAsynIpcChannel](https://github.com/netsecsp/asynframe/blob/master/doc/IAsynIpcChannel.txt)  
  [IAsynNetwork](https://github.com/netsecsp/asynframe/blob/master/doc/IAsynNetwork.txt)  
  [IAsynNetAgent](https://github.com/netsecsp/asynframe/blob/master/doc/IAsynNetAgent.txt)  
  [IConsole](https://github.com/netsecsp/asynframe/blob/master/doc/IConsole.txt)  
  [ICrashExplorer](https://github.com/netsecsp/asynframe/blob/master/doc/ICrashExplorer.txt)  
  [INet](https://github.com/netsecsp/asynframe/blob/master/doc/INet.txt)  
  [IProxy](https://github.com/netsecsp/asynframe/blob/master/doc/IProxy.txt)  
  [ISsl](https://github.com/netsecsp/asynframe/blob/master/doc/ISsl.txt)  
  [IVmHost](https://github.com/netsecsp/asynframe/blob/master/doc/IVmHost.txt)  

- [Plugins](https://github.com/netsecsp/asynframe/blob/master/doc/externapi.md)   

# Thanks  
> [Log4cplus](https://github.com/log4cplus/log4cplus)  
> [Lua](http://www.lua.org)  
> [Zlib](http://www.zlib.net)  
> [Sqlite](https://www.sqlite.org/)  

# Copyright  
> Copyright (c) 2012 - 2032, All rights reserved.  
> Author: Shengqian Yang, China, netsecsp@hotmail.com  
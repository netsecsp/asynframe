# Initialize函数  

Initialize asynframe  

# 语法  
```c++   
HRESULT __stdcall  Initialize(/*[in ]*/IAsynMessageEvents *events, /*[in ]*/IKeyvalSetter *param2 )  
```  

# 参数  
*[in ]events*  
用于插件模块通知app事件，允许events=NULL  
*[in ]param2*  
配置参数信息，允许param2=NULL，默认自动加载应用数据目录的config.ini文件  

# 返回值  
S_OK表Initialize asynframe成功，其他值表示失败。  

# 备注  
要求param2的配置信息的key格式：module_name, val编码：utf8  

若param2配置以下键值(utf8格式)时： 
1. key=";sysroot" 表示配置系统工作目录，默认asyncore.dll所在目录  
2. key=";appdata" 表示配置应用数据目录，默认c:\Users\<account>\AppData\Roaming\netsecsp\<AppName>  
3. key="asyncore_uniqueopspool" 表示是否创建有名工作线程池  
4. key="asyncore_uniqueevtpool" 表示是否创建有名事件线程池  
5. key="asyncore_uniquenetpool" 表示是否创建有名网络线程池  
6. key="asynsock_net_iaf" 配置值2=ipv4/23=ipv6  
7. key="asynsock_dns_url" 表示配置默认dnsurl  
udp://\*:53 表示udp, tcp://\*:53 表示tcp, http://119.29.29.29/d?dn=[host].&ip=[ip]&ttl=1 表示使用腾讯云  

通过InstancesManager::GetInstance(STRING_from_string(IN_SysArgv), IID_IKeyvalSetter, &configure)获得配置对象，configure->Travel(0)表示把配置信息刷新到应用数据目录的config.ini文件里  

# GetInstancesManager函数  
获取实例管理器  

# 语法  
```c++  
InstancesManager* __stdcall GetInstancesManager()  
```  

# 返回值  
返回实例管理器的引用指针，app不能再调用Release释放  

# Destory函数  
destory asynframe  

# 语法  
```c++  
HRESULT __stdcall Destory()  
```  

# 返回值  
S_OK表示destory成功，其他值表示失败  
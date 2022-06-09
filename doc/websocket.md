# websocket 插件  

实现websocket的协议处理模块，支持INet/IAsynTcpSocket/IAsynRawSocket/IAsynTcpSocketListener等接口  
自动把http/1.1协议升级到websocket协议  

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynPtlSocket(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown** param1,  
      /*[in ]*/const char* param2,  
      /*[in ]*/IAsynRawSocket** object )  
```  

## 开发
创建ws/wss对象[client]：
```c++  
CComPtr<IAsynTcpSocket> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocket(&spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("websocket"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl? "tls/13" : "tcp/13"), &spAsynPtlSocket);
```  

创建ws/wss对象[server]：
```c++  
CComPtr<IAsynTcpSocketListener> spAsynInnSocket;
m_spAsynNetwork->CreateAsynTcpSocketListener(asynsdk::STRING_EX::null, &spAsynInnSocket);
m_spAsynNetwork->CreateAsynPtlSocket(STRING_from_string("websocket"), (IUnknown**)&spAsynInnSocket.p, STRING_from_string(ssl? "tls/13" : "tcp/13"), &spAsynPtlSocket);
```  

发送http.req  
```c++  
CComPtr<IAsynIoOperation> spAsynIoOperation; m_spAsynFrame->CreateAsynIoOperation(0, 0, &spAsynIoOperation);
spNet->SendPacket(STRING_from_string("GET"), STRING_from_string("/chat"), 0, spAsynIoOperation);
```  

opcode定义：  
0x0：表示一个延续帧。当opcode=0时，表示本次数据传输采用了数据分片，当前收到的数据帧为其中一个数据分片。第一帧: FIN=0/code>0 中间帧: FIN=0/code=0 最后帧: FIN=1/code=0  
0x1：表示这是一个字符串帧（frame）  
0x2：表示这是一个二进制帧（frame）  
0x3-7：保留的操作代码，用于后续定义的数据帧。  
0x8：表示连接断开。  
0x9：表示这是一个ping操作。  
0xA：表示这是一个pong操作。  
0xB-F：保留的操作代码，用于后续定义的控制帧  

发送websocket控制帧[opcode=0x08~0x0F]  
```c++  
spNet->Write(lpAsynIoOperation, 0x08); //发送断开命令  
```  

发送websocket数据帧[opcode=0x00~0x07/0x80~0x87]  
```c++  
spNet->Write(lpAsynIoOperation, 0x82); //发送数据  
```  

接收  
```c++  
HRESULT CService::OnIomsgNotify( uint64_t lParam1, uint64_t lAction, IAsynIoOperation *lpAsynIoOperation )
{
    uint32_t lErrorCode = NO_ERROR, lTransferedBytes;
    lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

    switch(lAction)
    {
        case Io_recv:
             if( lErrorCode == NO_ERROR )
             {// http.req/ack packet
                 if( m_upgrade )
                 {
                     if( lParam1 >= 0x08 && 0x0F >= lParam1 )
                     {// 控制帧
                         ....
                     }
                     else
                     {// 数据帧
                         ....
                     }
                 }

                 CComPtr<INetmsg> spHttpmsg;
                 lpAsynIoOperation->GetCompletedObject(1, IID_INetmsg, (void **)&spHttpmsg);

                 STRING Method;
                 STRING Params;
                 STRING V;
                 BOOL ack;
                 spHttpmsg->Getline(&Method, &Params, &V, &ack );
                 std::string method = string_from_STRING(Method);
                 std::string params = string_from_STRING(Params);
                 std::string v = string_from_STRING(V);
                 printf("rcv http %s packet: %*s %*s\n", ack? "ack" : "req", Method.len, Method.ptr, Params.len, Params.ptr);
                 
                 if( ack )
                 {// client
                     if( atoi(params.c_str())/100 == 1 )
                     {
                         m_upgrade = 1; //mark: 升级websocket协议成功

                         发送websocket帧协议
                         ....
                     }
                 }
                 else
                 {// server
                     spNet->SendPacket(STRING_from_string("101"), STRING_from_string("Switching Protocols"), 0, lpAsynIoOperation);
                     m_upgrade = 1; //mark: 接受http升级到websokcet协议
                 }
                 .....
             }
             break;
    }
    return E_NOTIMPL;
}
```  

## 例子  
\support\testnetclient_websocket  
\support\testnetserver_websocket  
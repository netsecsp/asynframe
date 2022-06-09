# console 插件  

创建控制台，支持键盘/鼠标输入，加载/卸载实现ICommand接口的插件，便于产品在线调试  

## 导出函数  
```c++  
HRESULT __stdcall CreateAsynFramePlugin( /*[out]*/IAsynFramePlugin** object )    
```  

## 开发  
加载console插件
```c++  
if( lpInstancesManager->Verify(STRING_from_string(IN_Console)) == S_OK )
{// 加载成功
    CComPtr<IConsole> console;
    lpInstancesManager->GetInstance(STRING_from_string(IN_Console), IID_IConsole, (void**)&console);

    console->AllocWindow(spAsynFrameThread, asynsdk::STRING_EX::null, 3, 0); //创建控制台
}
else
{// 加载失败
}
```  

## 例子  
\support\testconsole  

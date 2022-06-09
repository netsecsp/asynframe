# zip 插件  

基于zlib-1.2.11.0实现IDataTransmit接口，具备zip多个文件以及deflate/inflate数据功能  

## 导出函数  
```c++  
HRESULT __stdcall CreateDataTransmit(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown* param1,  
      /*[in ]*/uint64_t param2,  
      /*[out]*/IDataTransmit** object)  
```  

## 开发  
zip多个文件  
```c++  
asynsdk::CStringSetter name(1, "dst.zip");
spDataTransmit.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "zip", &name, 0));
if( spDataTransmit )
{
    BYTE tmp[1024]; 
    FILE *f1 = fopen(".\\1.txt", "rb");
    if( f1 )
    {
        asynsdk::CStringSetter v(1, ".\\scripts\\1.txt");
        spDataTransmit->Write(&v, "1.txt:comments=1:password=123456", 0);

        while( 1 ) {
        int l = fread(tmp, 1, 1024, f1);
        if( l <= 0 ) break;
        spDataTransmit->Write(0, tmp, l);
        }
        fclose(f1);
    }
    FILE *f2 = fopen(".\\2.txt", "rb");
    if( f2 )
    {
        asynsdk::CStringSetter v(1, ".\\scripts\\2.txt");
        spDataTransmit->Write(&v, "2\\2.txt", 0);

        while( 1 ) {
        int l = fread(tmp, 1, 1024, f2);
        if( l <= 0 ) break;
        spDataTransmit->Write(0, tmp, l);
        }
        fclose(f2);
    }
}
```  


## 例子  
\support\testframe  
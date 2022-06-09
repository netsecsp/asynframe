# sqlite 插件  

基于sqlite-3.3.20实现IDataTransmit接口，支持select/execute功能  

## 导出函数  
```c++  
HRESULT __stdcall CreateDataTransmit(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown* param1,  
      /*[in ]*/uint64_t param2,  
      /*[out]*/IDataTransmit** object)  
```  

## 开发  
插入数据  
```c++  
asynsdk::CStringSetter name(1, argc > 2 ? argv[2] : "test.db");
spDataTransmit.Attach(asynsdk::CreateDataTransmit(lpInstancesManager, "sqlite", &name, 0));

asynsdk::CStringSetter sql1(1, "CREATE TABLE IF NOT EXISTS coreinfo(iseq INTEGER PRIMARY KEY AUTOINCREMENT, info TEXT);");
spDataTransmit->Write(&sql1, 0, 0);

asynsdk::CStringSetter sql2(1, "insert into coreinfo(info) values('show1');");
spDataTransmit->Write(&sql2, 0, 0);

asynsdk::CStringSetter sql3(1, "insert into coreinfo(info) values('show2');");
spDataTransmit->Write(&sql3, 0, 0);
```  
查询数据  
```c++  
asynsdk::CStringSetter sql4(1, "select * from coreinfo;");
spDataTransmit->Write(&sql4, GetAsynMessageEvents(), 0);
```  
```c++  
void CSqlite::OnEventNotify(uint64_t lParam1, uint64_t lParam2, IUnknown *object)
{
    STRING *vals = (STRING *)lParam2;
    if( lParam1 == 0 )
    {// 通知列名
        printf("record");
        for(int i = 0; vals[i].ptr; ++ i)
        {
            printf("\t%*s", vals[i].len, vals[i].ptr);
        }
        printf("\n");
    }
    else
    {
        if(!vals )
        {// 通知没有数据
            printf("%6I64d records\n", lParam1);
        }
        else
        {// 通知一行数据
            printf("%6I64d", lParam1);
            for(int i = 0; vals[i].ptr; ++ i)
            {
                ....
            }
            printf("\n");
        }
    }
}
```  

## 例子  
\support\testframe  
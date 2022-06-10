# sqlite 插件  

基于sqlite-3.3.20实现IOsCommand接口，支持select/execute功能  

## 导出函数  
```c++  
HRESULT __stdcall CreateCommand(/*[in ]*/InstancesManager* lpInstancesManager,  
      /*[in ]*/IUnknown* param1,  
      /*[in ]*/uint64_t param2,  
      /*[out]*/IOsCommand** object)  
```  

## 开发  
插入数据  
```c++  
asynsdk::CStringSetter name(1, argc > 2 ? argv[2] : "test.db");
spCommand.Attach(asynsdk::CreateCommand(lpInstancesManager, "sqlite", &name, 0));

spCommand->Execute(0, STRING_from_string("CREATE TABLE IF NOT EXISTS coreinfo(iseq INTEGER PRIMARY KEY AUTOINCREMENT, info TEXT, vals int);"), 0, 0, 0, 0);

spCommand->Execute(0, STRING_from_string("INSERT INTO coreinfo(info, vals) VALUES('show1', 1);"), 0, 0, 0, 0);

spCommand->Execute(0, STRING_from_string("INSERT INTO coreinfo(info, vals) VALUES('show2', 2);"), 0, 0, 0, 0);
```  
查询数据  
```c++  
spCommand->Execute(0, STRING_from_string("SELECT * FROM coreinfo;"), 0, 0, 0, GetAsynMessageEvents());
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
        {// 通知没有后续数据
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
print(package.path)
print(package.cpath)

print(sys.luahost)
print("appdata="..sys.appdata)
print("sysroot="..sys.sysroot)

print("get global.net="..sysargv.get("net", 1))
print("set global.net=2")
sysargv.set("net", 2)
print("save to C:\\Users\\<account>\\AppData\\Roaming\\Netsecsp\\testlua\\config.ini")
sysargv.save()


print("This is my world! from test.lua")

log.i("This is my world! from lua.dll")

local api = require("testapi")
api.write("This is my world! from testapi")

function main(data)
    print(data.." from test.lua")
    return 0
end

myinfo = {
    name = "alex",
    onMessage = function(message, lparam1, lparam2, object)
       print("message="..message..", lparam1="..lparam1..", lparam2="..lparam2.." in myinfo.onMessage")
       return 0
    end
}

function onMessage(message, lparam1, lparam2, object)
    print("message="..message..", lparam1="..lparam1..", lparam2="..lparam2.." in global.onMessage")
    return 0
end

sys.invoke(nil, api.createObject(0), 10000, 1, 10)
sys.invoke(nil, myinfo.onMessage, 20000, 2, 20)
sys.invoke(nil, onMessage, 30000, 3, 30)

print("create CTestX")
local obx = api.createObject(1)
obx:workX(0)
obx:workA(1)
obx:workB(2)

local ob1 = obx:castOf("ITestA")
ob1:workA(1)
ob1:release()
ob1 = nil

local ob2 = obx:castOf("ITestB")
ob2:workB(2)
ob2:release()
ob2 = nil

print("release")
obx:release()
obx = nil

print("over")
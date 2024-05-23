print(package.path)
print(package.cpath)

print(sys.instancesmanager)
print(sys.luahost)
print(sys.appdata)

print(sysargv.net)
sysargv.net=2
print(sysargv.net)

print("save to config.ini")
sysargv.save()

print("This is my world! from test.lua")

log.i("This is my world! from lua.dll")

local api = require("testapi")
api.write("This is my world! from testapi")

function main(data)
    print(data.." from test.lua")
    return 0
end

protocol = {
    name = "alex",
    onMessage = function(message, lparam1, lparam2, object)
       print("message="..message..", lparam1="..lparam1..", lparam2="..lparam2)
       return 0
    end
}

sys.invoke(nil, api.createObject(0), 10000, 2, 3, nil)

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
import sys

print(sys.path)
print(sys.appdata)
print(sys.sysroot)
print(sys.xvmhost)
print("This is my world! from test.py")

import log
log.i("This is my world!")
log.d("This is my world!")

import appconf
appconf.set("app.name", "netsecsp")
appconf.set("app.data", 7675)
print(appconf.get("app.name", "unknown"))
print(appconf.get("app.data", 1))

def onMessage(message, lparam1, lparam2, object=None):
    print("onMessage: message=", message, ", lparam1=", lparam1, ", lparam2=", lparam2, ", object=", object)
    return 0

sys.invoke(None, onMessage, 10, 1, 2)

class TestX(sys.IUnknown):
    def __init__(self, nativeObject, addref=0):
        super().__init__(nativeObject, addref)
        print("+TestX")
    def onMessage(self, message, lparam1, lparam2, object=None):
        print("onMessage: message=", message, ", lparam1=", lparam1, ", lparam2=", lparam2, ", object=", object)
        return 0

a=TestX(0)
sys.invoke(None, a, 11, 3, 4)
a.release()

import testapi
sys.invoke(None, testapi.getEvent(), 12, 4, 5)
testapi.sum(1,2)
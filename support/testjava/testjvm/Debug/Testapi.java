package com.demo;

import com.frame.api.*;

public class Testapi {
    static {
        System.out.println(CInstanceManager.getLibraryPath());
        System.loadLibrary("Testapi");
    }
 
    public static void main( String[] args ){
        CInstanceManager.invoke(null, create(), 1, 2, 3, null);
        CLogger.i("CLogger.i: Hello World!!!");
        write("Testapi.write: Hello World!!!");
        System.out.println("app.name=" + CSetting.getString("app.name", "Testapi"));
    }

    public static void print(String text) {
        System.out.println("Testapi.print: " + text);
    }

    public native static CUnknown create();
    public native static void write(String text);
}
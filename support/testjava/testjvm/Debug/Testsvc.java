package com.demo;

import java.io.*;
import java.net.*;
import com.frame.api.*;

public class Testsvc {
    public static void main(String[] args) throws IOException {

        final int port = 7675;
        ServerSocket serverSocket = new ServerSocket(port);
        CLogger.i("service started: port=" + port);
 
        CInstanceManager.add("ActionEvent", new CInstanceManager.IAsynMessageEvents() {
            @Override
            public int onMessage(int message, long lparam1, long lparam2, CUnknown object) {
                CLogger.d("message=" + message + ", lparam1=" + lparam1 + ", lparam2=" + lparam2 + ", object=" + object + " in java");
                if (message == 6) {//通知事件
                    if (lparam1 == 0) { //系统类型
                        switch((int)lparam2) {
                            case 0: //shutdown
                                 try {
                                    serverSocket.close();
                                 } catch (IOException e) {
                                    CLogger.w("Exception: " + e.toString());
                                 }
                                 break;
                            case 1: //电源休眠
                                 break;
                            case 2: //电源恢复
                                 break;
                        }
                    }
                }
                return 0;
            }
        });

        CInstanceManager.setMainType(1);

        new Thread() {
            @Override
            public void run() {
                while(true) {
                    try {
                        Socket clientSocket = serverSocket.accept();
                        CLogger.d("new client from " + clientSocket.getInetAddress());
                        new Thread() {
                            @Override
                            public void run() {
                                try {
                                    BufferedReader sin = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                                    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

                                    String inputLine;
                                    while ((inputLine = sin.readLine()) != null) {
                                        System.out.println(inputLine);
                                        out.println(inputLine);
                                    }

                                    CLogger.d("client exit.");
                                    out.close();
                                    sin.close();
                                    clientSocket.close();
                                } catch (IOException e) {
                                    CLogger.w("client Exception: " + e.toString());
                                }
                            }
                        }.start();
                    } catch (IOException e) {//for serverSocket.close()
                        break;
                    }
                } //end while
                CLogger.d("server exit.");
                System.exit(0);
            }
        }.start();
    }
}

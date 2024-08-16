package com.demo;

import javax.swing.*;
import com.frame.api.*;

public class Testgui {
    public static void main(String[] args) {
        
        CInstanceManager.add("ActionEvent", new CInstanceManager.IAsynMessageEvents() {
            @Override
            public int onMessage(int message, long lparam1, long lparam2, CUnknown object) {
                System.out.println("message=" + message + ", lparam1=" + lparam1 + ", lparam2=" + lparam2 + ", object=" + object + " in java");
                if (message == 6) {//通知事件
                    if (lparam1 == 0) { //系统类型
                        switch((int)lparam2) {
                            case 0: //shutdown
                                 new Thread() {
                                     @Override
                                     public void run() {
                                         System.exit(0);
                                     }
                                 }.start();
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

        JFrame frame = new JFrame("Hello World Example");
        JLabel label = new JLabel("Hello World");

        frame.add(label);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
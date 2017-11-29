package com.xiaoyunchengzhu.jni.jnicalljava;

import android.util.Log;

/**
 * Created by zhangshiyu on 2017/11/24.
 */

public class CallTest {
    private static final String TAG="CallTest";
    /**
     * no-static field
     */
    private String name="calltest_name";
    /**
     * static field
     */
    public static String sName="static calltest_name";


    /**
     *  no-static method
     * @param value1
     * @param value2
     * @return
     */
    public int add(int value1,int value2){
        return value1+value2;
    }

    /**
     *  static method
     * @param value1
     * @param value2
     * @return
     */
    public static int sAdd(int value1,int value2){
        return value1+value2;
    }

    /**
     * void method
     * @param msg1
     * @param count
     */
    public void show(String msg1,int count){
        Log.i(TAG,msg1+count);
    }

    /**
     * reference type
     * @param user
     * @return
     */
    public String getUser(User user){
        return "User-- name:"+user.getName()+",age:"+user.getAge();
    }


}

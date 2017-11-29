package com.xiaoyunchengzhu.jni.jnicalljava;

/**
 * Created by zhangshiyu on 2017/11/24.
 */

public class CalledUtil{

    static {
        System.loadLibrary("calljava");
    }
    public static native String callJniString();
    public static native User newUser();
    //获取用户用户名
    public static native String getUserName(User user);
    public static native int getUserAge(User user);
    /**
     * 获取Jni 转换的 User 对象；
     * @param user
     * @return
     */
    public static native String callGetName(User user);

    //在JNI 中C 调用CallTest 类中的方法 和成员变量。
    public static native int callCallTestAddMethod(int value1,int value2);
    public static native int callCallTestSaddMethod(int value1,int value2);
    public static native String getCallTestSnameField();
    public static native String getJniUser(User user);

}

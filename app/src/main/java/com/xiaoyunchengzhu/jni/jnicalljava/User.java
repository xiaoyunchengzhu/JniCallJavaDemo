package com.xiaoyunchengzhu.jni.jnicalljava;

/**
 * Created by zhangshiyu on 2017/11/24.
 */

public class User {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return " {name:"+name+",age:"+age+"}";
    }
}

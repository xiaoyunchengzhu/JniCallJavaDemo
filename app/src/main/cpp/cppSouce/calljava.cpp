#include <calljava.h>

JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callJniString(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jobject JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_newUser(JNIEnv *env, jobject /* this */){
    //获取 Calltest class
    jclass userclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/User");
    if (userclass==NULL){
        printLog("userclass is null");
        return NULL;
    }
    //获取构造方法id
    jmethodID constructor = (env)->GetMethodID(userclass, "<init>", "()V");
    if (NULL == constructor) {
        printLog("can't constructor CallTest");
        return NULL;
    }
    //新建对象 user
    jobject user=env->NewObject(userclass,constructor);
    return user;
}
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getJniUser(JNIEnv *env,jobject,jobject user){
    //获取 Calltest class
    jclass calltestclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/CallTest");
    if (calltestclass==NULL){
        printLog("calltestclass is null");
        return NULL;
    }
    //获取构造方法id
    jmethodID constructor = (env)->GetMethodID(calltestclass, "<init>", "()V");
    if (NULL == constructor) {
        printLog("can't constructor CallTest");
        return NULL;
    }
    //新建对象 Calltest
    jobject calltest=env->NewObject(calltestclass,constructor);
    if (calltest==NULL){
        printLog("calltest is null");
        return NULL;
    }
    //获取 getUser 方法id
    jmethodID getUserId=env->GetMethodID(calltestclass,"getUser","(Lcom/xiaoyunchengzhu/jni/jnicalljava/User;)Ljava/lang/String;");
    if (getUserId==NULL){
        printLog("getUserId is null");
        return NULL;
    }
    //调用calltet 的 getuser 方法
    jstring result= (jstring) env->CallObjectMethod(calltest, getUserId, user);

    return result;
}
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getUserName(JNIEnv * env,jobject,jobject user){
    //获取 user class
    jclass userclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/User");
    if (userclass==NULL){
        printLog("userclass is null");
    }
    jfieldID  filedNameId=env->GetFieldID(userclass,"name","Ljava/lang/String;");
    if (filedNameId==NULL){
        printLog("filedNameId is null");
    }
    jstring name= (jstring) env->GetObjectField(user, filedNameId);
    return name;
}
JNIEXPORT jint JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getUserAge(JNIEnv * env,jobject,jobject user){
    //获取 user class
    jclass userclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/User");
    if (userclass==NULL){
        printLog("userclass is null");
    }
    jfieldID  filedAgeId=env->GetFieldID(userclass,"age","I");
    if (filedAgeId==NULL){
        printLog("filedAgeId is null");
    }
    jint age=  env->GetIntField(user, filedAgeId);
    return age;
}
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callGetName(JNIEnv *env,jobject,jobject user){
    //获取 user class
    jclass userclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/User");
    if (userclass==NULL){
        printLog("userclass is null");
    }
    //分别获取 getName 方法id 和 getAge 方法 id;
    jmethodID getNameId=env->GetMethodID(userclass,"getName","()Ljava/lang/String;");
    if (getNameId==NULL){
        printLog("getNameid is null");//("getNameid is null");
    }
    //分别调用 getName 方法，和getAge 方法获取name 和age
    jstring jname= (jstring) env->CallObjectMethod(user, getNameId);
    if (jname==NULL){
        printLog("jname is null");//print("jname is null");
    }

    return jname;
}
JNIEXPORT jint JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callCallTestAddMethod(JNIEnv *env,jobject,jint value1,jint value2){
    //获取 Calltest class
    jclass calltestclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/CallTest");
    if (calltestclass==NULL){
        printLog("calltestclass is null");
        return NULL;
    }
    //获取构造方法id
    jmethodID constructor = (env)->GetMethodID(calltestclass, "<init>", "()V");
    if (NULL == constructor) {
        printLog("can't constructor CallTest");
        return NULL;
    }
    //新建对象 Calltest
    jobject calltest=env->NewObject(calltestclass,constructor);
    if (calltest==NULL){
        printLog("calltest is null");
        return NULL;
    }
    //获取 add 方法id
    jmethodID addId=env->GetMethodID(calltestclass,"add","(II)I");
    if (addId==NULL){
        printLog("addid is null");
        return NULL;
    }
    //调用calltet 的 add 方法
    jint  result=  env->CallIntMethod(calltest, addId, value1, value2);
    return result;
}
JNIEXPORT jint JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callCallTestSaddMethod(JNIEnv *env,jobject,jint value1,jint value2){
    //获取 Calltest class
    jclass calltestclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/CallTest");
    if (calltestclass==NULL){
        printLog("calltestclass is null");
        return NULL;
    }
    //获取 sadd 方法id
    jmethodID saddID=env->GetStaticMethodID(calltestclass,"sAdd","(II)I");
    if (saddID==NULL){
       printLog("saddid is null");
        return  NULL;
    }
    int result=env->CallStaticIntMethod(calltestclass,saddID,value1,value2);
    return result;
}
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getCallTestSnameField(JNIEnv *env,jobject){
    //获取 Calltest class
    jclass calltestclass=env->FindClass("com/xiaoyunchengzhu/jni/jnicalljava/CallTest");
    if (calltestclass==NULL){
        printLog("calltestclass is null");
        return NULL;
    }
    //获取 sadd 方法id
    jfieldID snameId=env->GetStaticFieldID(calltestclass,"sName","Ljava/lang/String;");
    if (snameId==NULL){
        printLog("snameId is null");
        return  NULL;
    }
    jstring sname= (jstring) env->GetStaticObjectField(calltestclass, snameId);
    return sname;
}
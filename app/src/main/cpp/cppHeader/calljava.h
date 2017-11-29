//
// Created by administered on 2017/11/24.
//

#ifndef JNICALLJAVADEMO_CALLJAVA_H
#define JNICALLJAVADEMO_CALLJAVA_H

#endif //JNICALLJAVADEMO_CALLJAVA_H
#include <jni.h>
#include <string>
#include <stdlib.h>
#include <android/log.h>
#include <convertUtil.h>
extern "C"{
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callJniString(JNIEnv *, jobject /* this */);
JNIEXPORT jobject JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_newUser(JNIEnv *, jobject /* this */);
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getJniUser(JNIEnv *,jobject,jobject);
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getUserName(JNIEnv *,jobject,jobject);
JNIEXPORT jint JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getUserAge(JNIEnv *,jobject,jobject);
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callGetName(JNIEnv *,jobject,jobject);
JNIEXPORT jint JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callCallTestAddMethod(JNIEnv *,jobject,jint,jint);
JNIEXPORT jint JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_callCallTestSaddMethod(JNIEnv *,jobject,jint,jint);
JNIEXPORT jstring JNICALL
Java_com_xiaoyunchengzhu_jni_jnicalljava_CalledUtil_getCallTestSnameField(JNIEnv *,jobject);

}
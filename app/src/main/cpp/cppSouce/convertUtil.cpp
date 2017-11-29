//
// Created by administered on 2017/11/29.
//

#include <convertUtil.h>


void printLog(const char* msg){
    __android_log_print(ANDROID_LOG_INFO,"JniCall","%s",msg);
}
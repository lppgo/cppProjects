#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>


// 获取日期date
const std::string GetNowDate(){
    auto now=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//    struct tm* now_tm= localtime(&now);
//    struct tm* now_tm= localtime_r(&now);
    struct tm* now_tm= localtime(&now);
    char date[32];
    sprintf(date,"%d-%02d-%02d",
            (int)now_tm->tm_year+1900,
            (int)now_tm->tm_mon+1,
            (int)now_tm->tm_mday);
    return std::string(date);
}


// 获取当前时间,精度是秒s
const std::string GetNowTime(){
    auto now=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//    struct tm* now_tm= localtime(&now);
//    struct tm* now_tm= localtime_r(&now);
    struct tm* now_tm= localtime(&now);
    char now_time[32];
    sprintf(now_time,"%d-%02d-%02d %02d:%02d:%02d",
            (int)now_tm->tm_year+1900,
            (int)now_tm->tm_mon+1,
            (int)now_tm->tm_mday,
            (int)now_tm->tm_hour,
            (int)now_tm->tm_min,
            (int)now_tm->tm_sec);
    return std::string(now_time);
}

// 获取当前时间，精度是毫秒ms
const std::string GetNowTimeMillisSeconds(){
    auto now=std::chrono::system_clock::now();
    uint64_t dif_milliseconds=
            std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count()-
            std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count()*1000;
    time_t tt=std::chrono::system_clock::to_time_t(now);
    auto now_tm=localtime(&tt);
    char now_time[64];
    sprintf(now_time,"%d-%02d-%02d %02d:%02d:%02d.%03d",
            (int)now_tm->tm_year+1900,
            (int)now_tm->tm_mon+1,
            (int)now_tm->tm_mday,
            (int)now_tm->tm_hour,
            (int)now_tm->tm_min,
            (int)now_tm->tm_sec,
            (int)dif_milliseconds);
    return std::string(now_time);
}
#include <iostream>
#include "mytime.h"

int main(){
    std::cout<<" 获取当前日期和时间..."<<std::endl;

    for (int i=0;i<1000;i++){
        auto date=GetNowDate();
        auto now_time=GetNowTime();
        auto now_time_milli=GetNowTimeMillisSeconds();
        std::cout<<"           date:"<<date<<std::endl;
        std::cout<<"       now_time:"<<now_time<<std::endl;
        std::cout<<" now_time_milli:"<<now_time_milli<<std::endl;
    }

}
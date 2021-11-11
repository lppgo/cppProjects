#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
/*
取当前时间，精确到微秒；
gcc 4.8.5 支持
*/
int main(int argc, char* argv[]) {
    auto now = std::chrono::system_clock::now();
    //  通过不同精度获取相差的毫秒数
    uint64_t dis_millseconds =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() - std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() * 1000;

    time_t tt = std::chrono::system_clock::to_time_t(now);
    auto time_tm = localtime(&tt);
    char strTime[25] = {0};
    // sprintf(strTime, "%d-%02d-%02d %02d:%02d:%02d %03d", time_tm->tm_year + 1900,
    //         time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
    //         time_tm->tm_min, time_tm->tm_sec, (int)dis_millseconds);

    sprintf(strTime, "%d%02d%02d%02d%02d%02d%03d", time_tm->tm_year + 1900,
            time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
            time_tm->tm_min, time_tm->tm_sec, (int)dis_millseconds);

    long tl = atol(strTime);  // string to long
    std::cout << strTime << std::endl;
    std::cout << tl << std::endl;
    std::cout << tl - 1000000 << std::endl;
    return 1;
}

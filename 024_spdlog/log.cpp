#include <cstdio>
#include <iostream>
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"

using namespace std;
using namespace spdlog;

auto rotating_logger = rotating_logger_mt("ama", "logs/rotating.log", 1 * 1024 * 1024, 30);

// 1: 先安装spdlog库
// $ git clone https://github.com/gabime/spdlog.git
// $ cd spdlog && mkdir build && cd build
// $ cmake .. && make -j

// 2: include 使用

// 3: g++ -std=c++11 -g -o main  log.cpp -lpthread
int main(int argc, char* argv[]) {
    for (int i = 0; i < 100000; i++) {
        auto now = std::chrono::system_clock::now();
        //  通过不同精度获取相差的毫秒数
        uint64_t dis_millseconds =
            std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() -
            std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() * 1000;
        time_t tt = std::chrono::system_clock::to_time_t(now);
        auto time_tm = localtime(&tt);
        char strTime[25] = {0};
        // sprintf(strTime, "%d-%02d-%02d %02d:%02d:%02d %03d", time_tm->tm_year + 1900,
        //         time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
        //         time_tm->tm_min, time_tm->tm_sec, (int)dis_millseconds);

        sprintf(strTime, "%d%02d%02d%02d%02d%02d%03d", time_tm->tm_year + 1900,
                time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
                time_tm->tm_min, time_tm->tm_sec, (int)dis_millseconds);

        long tl = atol(strTime);

        rotating_logger->info("strTime :{}", strTime);
        rotating_logger->flush();
        rotating_logger->info("tl      :{}", tl);
        rotating_logger->flush();
        rotating_logger->info("tl-t0   :{}", tl - 1000000);
        rotating_logger->flush();
    }
    return 0;
}

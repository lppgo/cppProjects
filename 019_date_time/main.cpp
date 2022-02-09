#include <time.h>
#include <unistd.h>
#include <iostream>

//
void ft1();
void ft2();
void ft3();
void ft4();
void ft5();
void ft6();
//
int main() {
    // ft1();
    // ft2();
    // ft3();
    // ft4();
    // ft5();
    ft6();
    return 0;
}

//  time()
void ft1() {
    time_t now;
    now = time(NULL);
    std::cout << "自1970-01-01到现在的seconds数:" << now << std::endl;
    std::cout << "自1970-01-01到现在的hour数:" << now / 3600 << std::endl;
    std::cout << "自1970-01-01到现在的day数:" << now / (3600 * 24) << std::endl;
    std::cout << "自1970-01-01到现在的year数:" << now / (3600 * 24 * 365) << std::endl;
}

// ctime()
void ft2() {
    time_t now;
    time(&now);
    std::cout << now << std::endl;
    auto t = ctime(&now);
    std::cout << now << std::endl;
    std::cout << t << std::endl;
}

// localtime()
void ft3() {
    time_t now;
    struct tm* tinfo;
    char* buf;

    time(&now);
    tinfo = localtime(&now);
    buf = asctime(tinfo);
    std::cout << "datetime:" << buf << std::endl;

    // strftime 格式化时间
    strftime(buf, 80, "%Y-%m-%d %H:%M:%S", tinfo);
    printf("格式化的日期 & 时间 : %s\n", buf);
}

// clock()
void ft4() {
    clock_t start_t, end_t;
    double total_t;
    int i;

    start_t = clock();
    printf("程序启动，start_t = %ld\n", start_t);

    printf("开始一个大循环，start_t = %ld\n", start_t);
    for (i = 0; i < 1000000000; i++) {
    }
    end_t = clock();
    printf("大循环结束，end_t = %ld\n", end_t);

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;  //为了获取 CPU 所使用的秒数，您需要除以 CLOCKS_PER_SEC
    printf("CPU 占用的总时间：%f\n", total_t);
    printf("程序退出...\n");
}

//
void ft5() {
    time_t start_t, end_t;
    double diff_t;

    time(&start_t);
    sleep(5);
    time(&end_t);

    diff_t = difftime(end_t, start_t);
    std::cout << "diff_t:" << diff_t << std::endl;
}

//
void ft6() {
    // 获取当前时间（纪元时间到当前时间经过的秒数s）
    time_t now = time(0);
    std::cout << "纪元时间到当前时间经过的秒数 :" << now << std::endl;

    // 把now转为字符串形式
    char* dt = ctime(&now);
    std::cout << "字符串表示的当地时间 :" << dt << std::endl;

    // 把 now 转换为 tm 结构(UTC)
    tm* gmtm = gmtime(&now);
    dt = asctime(gmtm);
    std::cout << "UTC表示的日期和时间 : " << dt << std::endl;

    // 把 now 转换为 tm 结构(本地时区)
    tm* ltm = localtime(&now);
    dt = asctime(ltm);
    std::cout << "本地时区表示的日期和时间 : " << dt << std::endl;

    // 输出 tm 结构的各个组成部分
    std::cout << "年: " << 1900 + ltm->tm_year << std::endl;
    std::cout << "月: " << 1 + ltm->tm_mon << std::endl;
    std::cout << "日: " << ltm->tm_mday << std::endl;
    std::cout << "时间: " << ltm->tm_hour << ":";
    std::cout << ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;
}
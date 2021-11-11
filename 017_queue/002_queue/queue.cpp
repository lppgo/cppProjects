#include <thread>
#include <queue>
#include <iostream>
#include <sys/timeb.h>
using namespace std;

std::queue<std::string> strQueue;

void TestThread1();
void TestThread2();
void TestThread3();



// void timeElpased(){
//     struct timeb tb;
//     ftime(&tb);
//     std::string mill_tb = std::to_string(tb.millitm);
//     std::time_t t = time(0);
//     char tb2Time[64] = {};
//     strftime(tb2Time, sizeof(tb2Time), "%Y%m%d%H%M%S", localtime(&tb));
//     std::string tb2Time_mill = tb2Time + mill_tb;
// }

int main(){

    thread t1(TestThread1);
    t1.join();
    thread t2(TestThread2);
    t2.join();
    // thread t3(TestThread3);
    // t3.join();
    printf("主线程：你好帅！！！！\n");

    while(true){
        if(!strQueue.empty()){
            auto s = strQueue.front();
            strQueue.pop();

            struct timeb tb;
            ftime(&tb);
            std::string mill_tb = std::to_string(tb.millitm);
            std::time_t t = time(0);
            char tb2Time[64] = {};
            strftime(tb2Time, sizeof(tb2Time), "%Y%m%d%H%M%S", localtime(&t));
            std::string tb2Time_mill = tb2Time + mill_tb;

            int t2_int = atoi(tb2Time_mill.c_str());
            int t0_int = atoi(s.c_str());

            std::cout
                << "t2 - t0 = " << t2_int - t0_int << std::endl;
        }
    }
    // system("pause");
    return 0;
}
void TestThread1(){
    for (int i = 0; i < 1000000; i++){
            struct timeb tb;
        ftime(&tb);
        std::string mill_tb = std::to_string(tb.millitm);
        std::time_t t = time(0);
        char tb2Time[64] = {};
        strftime(tb2Time, sizeof(tb2Time), "%Y%m%d%H%M%S", localtime(&t));
        std::string tb2Time_mill = tb2Time + mill_tb;

        strQueue.push(tb2Time_mill);
    }
}
void TestThread2(){
    for (int i = 0; i < 1000000; i++){
            struct timeb tb;
        ftime(&tb);
        std::string mill_tb = std::to_string(tb.millitm);
        std::time_t t = time(0);
        char tb2Time[64] = {};
        strftime(tb2Time, sizeof(tb2Time), "%Y%m%d%H%M%S", localtime(&t));
        std::string tb2Time_mill = tb2Time + mill_tb;

        strQueue.push(tb2Time_mill);
    }
}

// void TestThread3(){
//     for (int i = 0; i < 1000000; i++){
//             struct timeb tb;
//         ftime(&tb);
//         std::string mill_tb = std::to_string(tb.millitm);
//         std::time_t t = time(0);
//         char tb2Time[64] = {};
//         strftime(tb2Time, sizeof(tb2Time), "%Y%m%d%H%M%S", localtime(&t));
//         std::string tb2Time_mill = tb2Time + mill_tb;

//         strQueue.push(tb2Time_mill);
//     }
// }


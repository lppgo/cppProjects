#include <pthread.h>
#include <iostream>

using namespace std;

#define DESC "该示例是pthread 创建不带参数的的threads ..."
#define NUM_THREADS 5

// 线程的运行函数,不带参数
void* say_hello(void* args) {
    cout << "Hello C++ multithread for lucas" << endl;
    return 0;
}

//
int main() {
    cout << DESC << endl;

    // 定义线程线程标识符，线程id变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        // 创建线程，参数依次是:线程id,线程参数,调用的函数,传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0) {
            cout << "pthread_create error : error_code = " << ret << endl;
        }
    }

    pthread_exit(NULL);  // 等各个线程退出后，main才结束;
    return 0;
}

/*

g++ test1.cpp -std=c++17 -g -Wall -lpthread

*/
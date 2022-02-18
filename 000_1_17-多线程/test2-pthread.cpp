#include <pthread.h>
#include <iostream>

using namespace std;

#define DESC "该示例是pthread 创建带参数的的threads ..."
#define NUM_THREADS 5

// 线程的运行函数，接收传入的参数
void* say_hello_args(void* threadid) {
    // 对传入的参数进行强制类型转换，由无类型指针变为int指针,然后再读取
    int tid = *((int*)threadid);
    cout << "Hello C++ multithread for lucas, tid = " << tid << endl;
    pthread_exit(NULL);
}

int main() {
    cout << DESC << endl;

    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];  // 用数组来保存i的值
    int rc, i;

    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() : 创建线程 -> " << i << endl;
        indexes[i] = i;

        // 传入的时候必须强制转为void*类型，即无类型指针;
        rc = pthread_create(&tids[i], NULL, say_hello_args, (void*)&(indexes[i]));
        if (rc) {
            cout << "Error:创建thread 失败," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

/*
g++ test2.cpp -std=c++17 -g -Wall -lpthread
 */
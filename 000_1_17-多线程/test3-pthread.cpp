#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DESC "该示例是演示如何使用pthread_join()函数来等待threads的完成 ... "
#define NUM_THREADS 5

void* wait(void* t) {
    long tid;

    tid = (long)t;

    sleep(1);
    cout << "sleep in thread" << endl;
    cout << "Thread with id : " << tid << " ... exiting" << endl;
    pthread_exit(NULL);
}

int main() {
    int ret, i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void* status;

    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() createing thread," << i << endl;
        ret = pthread_create(&threads[i], NULL, wait, (void*)&i);
        if (ret) {
            cout << "Error: unable to create thread," << ret << endl;
            exit(-1);
        }
    }

    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_join(threads[i], &status);
        if (ret) {
            cout << "Error: unable to join thread," << ret << endl;
            exit(-1);
        }
        cout << "Main: completed thread id : " << i;
        cout << " exiting with status : " << status << endl;
    }
    cout << "Main: program exiting ..." << endl;
    pthread_exit(NULL);

    return 0;
}
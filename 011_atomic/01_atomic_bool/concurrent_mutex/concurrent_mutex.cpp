#include <time.h>
#include <atomic>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <mutex>

using namespace std;
// 全局的结果数据
long total = 0;

//
std::mutex mtx;

// 点击函数
void click() {
    for (int i = 0; i < 1000000; ++i) {
        // 互斥对象来对全局共享资源的访问进行保护
        mtx.lock(); // 访问之前，锁定互斥对象
        total += 1;
        mtx.unlock();// 访问完成后，释放互斥对象
    }
}


// g++ concurrent_mutex.cpp -lboost_system -lboost_thread -lpthread -o concurrent_mutex 

int main(int argc, char* argv[]) {

    // 测试1 无锁，也无原子操作，并发不安全
        // 计时开始
    clock_t start = clock();
    // 创建100个线程模拟点击统计
    boost::thread_group threads;
    for (int i = 0; i < 100; ++i) {
        threads.create_thread(click);
    }

    threads.join_all();
    // 计时结束
    clock_t finish = clock();
    // 输出结果
    cout << "result:" << total << endl;
    cout << "duration:" << (double)(finish - start)/CLOCKS_PER_SEC << " " << endl;
    return 0;
}







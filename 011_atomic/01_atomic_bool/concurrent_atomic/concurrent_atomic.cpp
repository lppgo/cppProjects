#include <time.h>
#include <atomic>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <atomic> // 引入原子数据类型的头文件

using namespace std;

/* 
在C++11中，实现了原子操作的数据类型（atomic_bool,atomic_int,atomic_long等等），
对于这些原子数据类型的共享资源的访问，无需借助mutex等锁机制，也能够实现对共享资源的正确访问
*/

// 用原子数据类型作为共享资源的数据类型
atomic_long total(0);
//long total = 0;

// 点击函数
void click() {
    for (int i = 0; i < 1000000; ++i) {
          // 仅仅是数据类型的不同而以，对其的访问形式与普通数据类型的资源并无区别
        total += 1;
    }
}




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





// g++ concurrent_atomic.cpp -lboost_system -lboost_thread -lpthread -o concurrent_atomic 
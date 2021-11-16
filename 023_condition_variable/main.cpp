#include <condition_variable>  // std::condition_variable
#include <iostream>            // std::cout
#include <mutex>               // std::mutex, std::unique_lock
#include <thread>              // std::thread

std::mutex mtx;              // 全局互斥锁.
std::condition_variable cv;  // 全局条件变量.
bool ready = false;          // 全局标志位.

// 待唤醒thread
void do_print_id(int id) {
    // std::cout << "id:" << id << std::endl;
    for (int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> lck(mtx);
        while (!ready)     // 如果标志位不为 true, 则等待...
            cv.wait(lck);  // 当前线程被阻塞, 当全局标志位变为 true 之后,
        // 线程被唤醒, 继续往下执行打印线程编号id.
        std::cout << "thread " << id << '\n';
    }
}

// 用来唤醒休眠的thread
void go() {
    std::lock_guard<std::mutex> lck(mtx);
    ready = true;     // 设置全局标志位为 true.
    cv.notify_all();  // 唤醒所有线程.
}

int main() {
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(do_print_id, i);

    std::cout << "10 threads ready to race...\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));

    go();  // go!

    for (auto& th : threads) {
        std::cout << "wait for thread[" << th.get_id() << "] execution completed" << std::endl;
        th.join();  // 等待当前thread 执行完成
    }

    std::cout << "all threads is execution completed !" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}
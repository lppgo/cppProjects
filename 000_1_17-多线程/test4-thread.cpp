#include <iostream>
#include <thread>

using namespace std;

#define DESC "使用std::thread 创建多线程并操作 ..."

//
void foo(int m) {
    for (int i = 0; i < m; i++) {
        cout << "线程使用 '函数指针' 作为可调用对象/参数," << i << endl;
    }
}

//
class thread_obj {
   public:
    void operator()(int x) {
        for (int i = 0; i < x; i++) {
            cout << "线程使用 '函数对象' 作为可调用对象/参数," << i << endl;
        }
    }
};

int main() {
    cout << DESC << endl;

    // 函数指针
    thread td_1(foo, 3);

    // 函数对象
    thread td_2(thread_obj(), 3);

    // 定义lambda expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++) {
            cout << "线程使用 'lambda表达式' 作为可调用对象/参数," << i << endl;
        };
    };

    thread td_3(f, 3);

    // 等待线程完成
    td_1.join();
    td_2.join();
    td_3.join();

    return 0;
}

/*

g++ test4-thread.cpp -std=c++17 -g -Wall -lpthread


 */
[toc]

# C++ 多线程

## 1：进程，线程，协程

### 1.1 进程 Process

### 1.2 线程 Thread

### 1.3 协程 coroutine

## 2：创建线程

- 需要`#include <pthread.h>`, pthread 库；
- **undefined reference to 'pthread_create'问题解决**:
  - **问题原因**:pthread 库不是 Linux 系统默认的库，连接时需要使用静态库 libpthread.a，所以在使用 pthread_create()创建线程，以及调用 pthread_atfork()函数建立 fork 处理程序时，需要链接该库;
  - **问题解决**:在编译中要加 -lpthread 参数 ` gcc thread.c -o thread -lpthread`。
- `pthread_create` 创建一个新的线程，并让它可执行。下面是关于参数的说明：

```cpp
#include <pthread.h>

pthread_create (thread,attr,start_routine,arg)

//      thread 指向线程标识符指针;
//      attr 一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL;
//      start_routine 线程运行函数起始地址，一旦线程被创建就会执行;
//      arg 运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL
```

## 3：终止线程

- `pthread_exit`用于显式得退出一个线程。
- 通常情况下，pthread_exit() 函数是在线程完成工作后无需继续存在时被调用;
- 如果 main()是在它所创建的线程结束之前，并通过 pthread_exit()退出，那么其他线程将继续执行。否则它们将在 mian()结束时自动被终止;

- 示例: `test1.cpp`

## 4：向线程传递参数

- 示例: `test2.cpp`

## 5：连接和分离线程

- 我们可以使用以下两个函数来连接或分离线程：

```cpp
pthread_join(threadid,status) // 子线程阻碍调用程序，直到指定的 threadid 线程终止为止;
pthread_detach(threadid)
```

- 当创建一个线程时，它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）。只有创建时定义为可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
- `test3-pthread.cpp` 这个实例演示了如何使用 pthread_join() 函数来等待线程的完成

## 6：std::thread

- C++ 11 之后添加了新的标准线程库 **`std::thread`**，std::thread 在 `<thread>` 头文件中声明，因此使用 std::thread 时需要包含 在 <thread> 头文件;
- 编译器使用 C++11 的编译参数是 `-std=c++11`;
- std::thread 默认构造函数，创建一个空的 std::thread 执行对象;
  ```cpp
  #include<thread>
  std::thread thread_object(callable)
  ```
- 一个**可调用对象**可以是以下三种之一:

  - (1) 函数指针;
  - (2) 函数对象;
  - (3) lambda 表达式;

- 定义 callable 之后，将其传递给 std::thread 构造函数 thread_object;
- 示例:`test4-thread.cpp`

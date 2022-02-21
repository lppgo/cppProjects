
#include "./ctf.h"

int main() {
    test01();
    test02();
    return 0;
}

/*

1 : 直接编译为可执行文件
g++ main.cpp ctf.cpp -std=c++17 -g -Wall


2 :
    先编译为so动态库，再连接
    g++ ctf.cpp -fPIC -shared -o libstf.so

    动态库的连接，调用动态库
    g++ main.cpp -L. -lstf -o main -std=c++17 -g -Wall


3: 编译参数说明
    -shared 该选项指定生成动态连接库；
    -fPIC：表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的所以动态载入时是通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码段共享的目的；
    -L.：表示要连接的库在当前目录中；
    -ltest：编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，后面加上.so来确定库的名称；
    LD_LIBRARY_PATH：这个环境变量指示动态连接器可以装载动态库的路径；

 */
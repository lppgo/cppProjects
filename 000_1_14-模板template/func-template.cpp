#include <iostream>

using namespace std;

#define DESC "这是一个函数模板的demo ..."

/*
函数模板作用：
    建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表

总结：
    函数模板利用关键字 template
    使用函数模板有两种方式：自动类型推导、显示指定类型
    模板的目的是为了提高复用性，将类型参数化
*/

//普通函数
int myAdd01(int a, int b) {
    return a + b;
}
//函数模板
template <class T>  //声明一个模板，T是一个通用的数据类型
T myAdd02(T a, T b) {
    return a + b;
}
//使用函数模板是，如果用自动类型推导，不会发生自动类型转换，即隐式类型转换
void test01() {
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a, b) << endl;
    cout << myAdd01(a, c) << endl;       //自动类型推导
    cout << myAdd02<int>(a, c) << endl;  //显示指定类型
}

void test02() {
    int a = 10;
    int b = 20;
    char c = 'c';
    // float d = 3.14;
    // float e = 6.89;
    cout << myAdd02(a, b) << endl;
    // cout << myAdd02(a, c) << endl; // error
    cout << myAdd02<int>(a, c) << endl;
}
int main() {
    // test01();
    test02();
    return 0;
}
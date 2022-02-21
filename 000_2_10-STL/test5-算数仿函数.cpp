/*

功能描述：
    实现四则运算
    其中 negate 是一元运算，其他都是二元运算
仿函数原型：
    template< class T > T plus< T > //加法仿函数
    template< class T > T minus< T > //减法仿函数
    template< class T > T multiplies< T > //乘法仿函数
    template< class T > T divides< T > //除法仿函数
    template< class T > T modulus< T > //取模仿函数
    template< class T > T negate< T > //取反仿函数
 */

#include <iostream>
using namespace std;

#include <functional>  //内建函数对象 算术仿函数

// negate 一元仿函数 取反仿函数
void test01() {
    negate<int> n;
    cout << n(50) << endl;
}
// plus 二元仿函数  加法
void test02() {
    plus<int> p;
    cout << "和为: " << p(10, 20) << endl;
}
// minus 二元仿函数  减法
void test03() {
    minus<int> m;
    cout << "差为: " << m(30, 20) << endl;
}
// multiplies 二元仿函数  乘法
void test04() {
    multiplies<int> m;
    cout << "积为: " << m(30, 20) << endl;
}
// divides 二元仿函数  除法
void test05() {
    divides<int> d;
    cout << "商为: " << d(30, 6) << endl;
}
// modulus 二元仿函数  取模
void test06() {
    modulus<int> m;
    cout << "模为: " << m(40, 6) << endl;
}
int main() {
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    return 0;
}
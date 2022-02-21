#ifndef CLASS_TEMPLATE_AND_FRIEND
#define CLASS_TEMPLATE_AND_FRIEND

// body
#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Person;

template <class T1, class T2>
void printPerson1(Person<T1, T2> p);

template <class T1, class T2>
void printPerson2(Person<T1, T2> p);

// 1: 全局函数在类内部实现
void test01();
// 2: 全局函数在类内部实现
void test02();

//
#endif
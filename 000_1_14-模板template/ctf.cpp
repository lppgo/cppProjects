
#include "./ctf.h"

//类外实现
template <class T1, class T2>
void printPerson2(Person<T1, T2> p) {
    cout << "printPerson2"
         << "  Name:" << p.m_Name << "  Age:" << p.m_Age << endl;
};

//通过全局函数 打印Person信息
template <class T1, class T2>
class Person {
    friend void printPerson1(Person<T1, T2> p) {
        cout << "printPerson1"
             << "  Name:" << p.m_Name << "  Age:" << p.m_Age << endl;
    };
    //全局函数  类外实现
    //加空模板参数列表
    //如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);

   public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

   private:
    T1 m_Name;
    T2 m_Age;
};

// 1、全局函数在类内实现
void test01() {
    Person<string, int> p("Tom", 20);
    printPerson1(p);
};
// 2、全局函数在类外实现
void test02() {
    Person<string, int> p("Jim", 20);
    printPerson2(p);
};
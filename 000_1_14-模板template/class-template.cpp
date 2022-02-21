#include <iostream>

using namespace std;
#define DESC "这是一个类模板的demo ..."

template <class NameType, class AgeType = int>
class Person {
   public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson() {
        cout << "name: " << this->m_Name << "  年龄： " << this->m_Age << endl;
    }
    //姓名
    NameType m_Name;
    //年龄
    AgeType m_Age;
};
void test01() {
    Person<string, int> p("孙悟空", 1000);
    p.showPerson();
}
void test02() {
    Person<string> p("猪八戒", 1000);
    p.showPerson();
}

int main() {
    // test01();
    test02();
    return 0;
}
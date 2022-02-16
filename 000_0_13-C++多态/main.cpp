
#include <iostream>
using namespace std;

/*
多态: polymophric
    当类之间存在层次结构，并且类之间是通过继承关联的时候，就会用到多态；
    c++多态意味着调用成员函数时,会根据调用函数的对象的类型来执行不同的函数;

虚函数: virtual
    是在基类中使用virtual关键字声明的函数；
    在 derived class 中重新定义基类中的虚函数时，会告诉编译器不要不要静态连接到该函数；

动态连接(后期绑定):
    在程序中任一点可以根据所调用的对象类型来选择调用函数，这种操作被称为动态绑定。go语言中的interface也属于或者类似动态绑定

纯虚函数(pure virtual function):
    纯虚函数是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。在基类中实现纯虚函数的方法是在函数原型后加 =0;
    virtual int area() = 0;

 */

class Shape {
   protected:
    int width, height;

   public:
    Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    };
    // int area() {

    // virtual int area() {
    //     cout << "Parent class area : " << endl;
    //     return 0;
    // };

    virtual int area() = 0;
};

class Rectangle : public Shape {
   public:
    //(1) 初始化基类需要透传基类的所有构造函数,会很麻烦
    Rectangle(int a = 0, int b = 0)
        : Shape(a, b){};
    //(2) C++11 开始，使用继承构造函数 (Inheriting Constructor)，解决上述问题
    // using Base::Base;

    int area() {
        cout << "Rectangle class area : " << width * height << endl;
        return width * height;
    };
};

class Triangle : public Shape {
   public:
    // Triangle(int a = 0, int b = 0)
    //     : Shape(a, b){};
    using Shape::Shape;

    int area() {
        cout << "Triangle class area : " << (width * height) / 2 << endl;
        return (width * height) / 2;
    };
};

// main
int main() {
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    shape->area();

    shape = &tri;
    shape->area();

    return 0;
};

/*

Parent class area :
Parent class area :

导致错误输出的原因是，调用函数 area() 被编译器设置为基类中的版本，这就是所谓的静态多态，或静态链接 - 函数调用在程序执行前就准备好了。有时候这也被称为早绑定，因为 area() 函数在程序编译期间就已经设置好了。

但现在，让我们对程序稍作修改，在 Shape 类中，area() 的声明前放置关键字 virtual，如下所示：
virtual int area() {}
 */
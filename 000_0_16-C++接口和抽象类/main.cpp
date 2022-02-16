#include <iostream>

using namespace std;

class Shape {
   public:
    // 抽象类定义了一个接口
    virtual int getArea() = 0;  //

    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }

   protected:
    int width;
    int height;
};

// 派生类
class Rectangle : public Shape {
   public:
    // 实现接口
    int getArea() {
        return (width * height);
    }
};
class Triangle : public Shape {
   public:
    // 实现接口
    int getArea() {
        return (width * height) / 2;
    }
};

int main(void) {
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);
    // 输出对象的面积
    cout << "Total Triangle area: " << Tri.getArea() << endl;

    return 0;
}

/*

设计策略
面向对象的系统可能会使用一个抽象基类为所有的外部应用程序提供一个适当的、通用的、标准化的接口。然后，派生类通过继承抽象基类，就把所有类似的操作都继承下来。

外部应用程序提供的功能（即公有函数）在抽象基类中是以纯虚函数的形式存在的。这些纯虚函数在相应的派生类中被实现。

这个架构也使得新的应用程序可以很容易地被添加到系统中，即使是在系统被定义之后依然可以如此。
 */
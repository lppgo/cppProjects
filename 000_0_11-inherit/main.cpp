#include <iostream>
using namespace std;

// Base Class
class Shape {
   public:
    void setWidth(int w) {
        width = w;
    };
    void setHeight(int h) {
        height = h;
    };

   protected:
    int width;
    int height;
};

// Base Class
class PaintCost {
   public:
    int getCost(int area) {
        return area * 70;
    };
};

// inherit class
class Rectangle : public Shape, public PaintCost {
   public:
    int getArea() {
        return width * height;
    };
};

//
int main() {
    Rectangle rect;
    int area;

    rect.setWidth(10);
    rect.setHeight(5);

    area = rect.getArea();
    // 输出对象的面积
    cout << "Total area: " << rect.getArea() << endl;

    // 输出总花费
    cout << "Total paint cost: $" << rect.getCost(area) << endl;
};

/*

继承类型
当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种类型。继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。

我们几乎不使用 protected 或 private 继承，通常使用 public 继承。当使用不同类型的继承时，遵循以下几个规则：

    公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
    保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
    私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。



多继承
多继承即一个子类可以有多个父类，它继承了多个父类的特性。

 */
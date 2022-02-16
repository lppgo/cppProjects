[toc]

# 1: C++重载概述(override)

- C++允许在同一个作用域内的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载;
- 重载声明是指一个与之前已经在该作用域内声明过的函数或者方法具有相同名称的声明，但是他们的函数列表和实现不同;
- **重载决策** 当您调用一个重载函数或者重载运算符时，编译器通过您所用的参数类型与定义中的参数类型比较，决定选用最合适的定义，选择最合适的重载函数或者重载运算符的过程，称为重载决策;

# 2: C++ 函数重载

```cpp
#include <iostream>
using namespace std;

class printData {
   public:
    void print(int i) {
        cout << "int : " << i << endl;
    };
    void print(double f) {
        cout << "double : " << f << endl;
    };
    void print(char c[]) {
        cout << "字符串 : " << c << endl;
    };
};

int main(void) {
    printData pd;

    // 输出整数
    pd.print(5);
    // 输出浮点数
    pd.print(500.263);
    // 输出字符串
    char c[] = "Hello C++";
    pd.print(c);

    return 0;
}
```

# 3: C++ 运算符重载`operator`

- 您可以定义或者重载大部分 C++内置的运算符，这样您就能使用自定义的运算符；
- 重载的运算符是带有特殊名称的函数，函数名是由关键字 `operator` 和其后要重载的运算符符号构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表;
- `Box operator+(const Box&);`

```cpp
#include <iostream>
using namespace std;

class Box {
   public:
    double getVolume(void) {
        return length * breadth * height;
    }
    void setLength(double len) {
        length = len;
    }

    void setBreadth(double bre) {
        breadth = bre;
    }

    void setHeight(double hei) {
        height = hei;
    }

    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b) {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

   private:
    double length;   // 长度
    double breadth;  // 宽度
    double height;   // 高度
};
// 程序的主函数
int main() {
    Box Box1;             // 声明 Box1，类型为 Box
    Box Box2;             // 声明 Box2，类型为 Box
    Box Box3;             // 声明 Box3，类型为 Box
    double volume = 0.0;  // 把体积存储在该变量中

    // Box1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // Box2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // Box1 的体积
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;  // Volume of Box1 : 210

    // Box2 的体积
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;  // Volume of Box2 : 1560

    // 把两个对象相加，得到 Box3
    Box3 = Box1 + Box2;

    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume << endl;  // Volume of Box3 : 5400

    return 0;
}
```

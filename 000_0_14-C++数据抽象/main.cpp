#include <iostream>
using namespace std;

class Adder {
   public:
    Adder(int i = 0) {
        total = i;
    };
    void addNum(int num) {
        total += num;
    };
    int getTotal(void) {
        return total;
    }

   private:
    int total;  // 对外隐藏的数据
};

int main() {
    Adder a;

    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total : " << a.getTotal() << endl;

    return 0;
}

/*

设计策略
抽象把代码分离为接口和实现。所以在设计组件时，必须保持接口独立于实现，这样，如果改变底层实现，接口也将保持不变。

在这种情况下，不管任何程序使用接口，接口都不会受到影响，只需要将最新的实现重新编译即可。
 */
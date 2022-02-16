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
通常情况下，我们都会设置类成员状态为私有（private），除非我们真的需要将其暴露，这样才能保证良好的封装性。

这通常应用于数据成员，但它同样适用于所有成员，包括虚函数
 */
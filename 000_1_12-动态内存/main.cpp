#include <iostream>
using namespace std;

class Box {
   public:
    Box() {
        cout << "invoking box construct " << endl;
    };
    ~Box() {
        cout << "invoking box destructor" << endl;
    };
};

int main() {
    Box* myBoxArray = new Box[5];  //

    delete[] myBoxArray;  // 删除数组

    return 0;
}
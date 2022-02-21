#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print01(int val) {
    cout << "print01 val = " << val << endl;
};

// 仿函数/函数对象
class print02 {
   public:
    void operator()(int val) {
        cout << "print02 val = " << val << endl;
    }
};

void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), print02());
}

int main() {
    test01();
    return 0;
}

/*

g++ -std=c++17 -g -Wall test1-for_eatch.cpp
 */
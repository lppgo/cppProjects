#include <cstring>
#include <iostream>
using namespace std;

// 函数模板
template <typename T>
inline T const& Max(T const& a, T const& b) {
    return a < b ? b : a;
}

int main() {
    int i = 39;
    int j = 20;
    cout << "Max(i,j) = " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.8;
    cout << "Max(f1,f2) = " << Max(f1, f2) << endl;

    string str1 = "function-template";
    string str2 = "class-template";
    cout << "Max(str1,str2) = " << Max(str1, str2) << endl;

    return 0;
};
#include <iostream>
using namespace std;

int main() {
    cout << "Value of __LINE__ : " << __LINE__ << endl;  // Value of __LINE__ : 5
    cout << "Value of __FILE__ : " << __FILE__ << endl;  // Value of __FILE__ : main.cpp
    cout << "Value of __DATE__ : " << __DATE__ << endl;  // Value of __DATE__ : Feb 17 2022
    cout << "Value of __TIME__ : " << __TIME__ << endl;  // Value of __TIME__ : 17:34:36
    return 0;
}

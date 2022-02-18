#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {
   private:
    vector<T> elems;  //元素

   public:
    void push(T const&);  // 入栈
    void pop();           // 出栈
    T top();              // 返回栈顶元素
    bool empty() const {  // 如果栈为空，则返回真
        return elems.empty();
    };
};

template <class T>
void Stack<T>::push(T const& elem) {
    // 追加传入元素的副本
    elems.push_back(elem);
};

template <class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
};

template <class T>
T Stack<T>::top() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
};

int main() {
    try {
        Stack<int> intStack;        // int类型的栈
        Stack<string> stringStack;  // string类型的栈

        // 操作int 类型的栈
        intStack.push(7);
        cout << "intStack.top() : " << intStack.top() << endl;

        // 操作string类型的栈
        stringStack.push("class-template");
        cout << "stringStack.top() : " << stringStack.top() << endl;

        intStack.pop();
        stringStack.pop();

        // cout << "intStack.top() : " << intStack.top() << endl;

    } catch (exception const& e) {
        cerr << "Exception:" << e.what() << endl;
        return -1;
    }
}
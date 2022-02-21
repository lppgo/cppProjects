#include <algorithm>  //标准算法的头文件
#include <iostream>
#include <vector>

using namespace std;
//常用遍历算法  transform
class Transform {
   public:
    int operator()(int v) {
        return v + 100;
    }
};
//仿函数  打印
class print {
   public:
    void operator()(int val) {
        cout << val << " ";
    }
};
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //目标容器
    vector<int> v2;
    v2.resize(v.size());  //目标容器需要提前开辟空间
    transform(v.begin(), v.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), print());
    cout << endl;
}

int main() {
    test01();
    return 0;
}
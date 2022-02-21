#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
//仿函数 返回值类型是bool数据类型，称为谓词
//一元谓词
class GreaterFive {
   public:
    bool operator()(int val) {
        return val > 5;
    }
};
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //查找容器中 有没有大于5的数字
    // greaterfive（）匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了大于5的数字为：" << *it << endl;
    }
}
int main() {
    test01();
    return 0;
}

/*

谓词:
    概念：
        返回 bool 类型的仿函数称为谓词;
        如果 operator()接受一个参数，那么叫做一元谓词;
        如果 operator()接受两个参数，那么叫做二元谓词;
 */
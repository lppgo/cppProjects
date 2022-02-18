#include <iostream>
#include <vector>

#define DESC "本案例是使用 STL vector操作..."
using namespace std;

int main() {
    cout << DESC << endl;

    vector<int> vec;
    int i;

    cout << "vector size = " << vec.size() << endl;  // vector size = 0

    // 向vector 添加值
    for (i = 0; i < 5; i++) {
        vec.push_back(i + 1);
    };

    cout << "vector size = " << vec.size() << endl;  // vector size = 5

    // 访问向量中的5个值
    for (i = 0; i < 5; i++) {
        cout << "vec [" << i << "] = " << vec[i] << endl;
    }

    // 使用 iterator 访问值
    vector<int>::iterator itor = vec.begin();
    while (itor != vec.end()) {
        cout << "vec [ ] = " << *itor << endl;
        itor++;
    }

    return 0;
}

/*

关于上面实例中所使用的各种函数，有几点要注意：

push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
size( ) 函数显示向量的大小。
begin( ) 函数返回一个指向向量开头的迭代器。
end( ) 函数返回一个指向向量末尾的迭代器。
 */
#include <iostream>
#include <vector>

#include <algorithm>  //标准算法头文件

#define DESC "本案例是使用 STL vector操作..."
using namespace std;

// vector容器存放内置数据类型
//打印函数
void myPrint(int val) {
    cout << "(3)  : " << val << endl;
}

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

    //同过迭代器访问容器中的数据
    vector<int>::iterator itBegin = vec.begin();  //起始迭代器  指向容器中第一个元素
    vector<int>::iterator itEnd = vec.end();      //结束迭代器，指向容器中最后一个元素的下一个位置
    //第一种遍历方式
    while (itBegin != itEnd) {
        cout << "(1): " << *itBegin << endl;
        itBegin++;
    }

    //第二种遍历方式
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << "(2) : " << *it << endl;
    }

    //第三种遍历方式  利用STL提供遍历算法
    for_each(vec.begin(), vec.end(), myPrint);

    return 0;
}

/*

关于上面实例中所使用的各种函数，有几点要注意：

push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
size( ) 函数显示向量的大小。
begin( ) 函数返回一个指向向量开头的迭代器。
end( ) 函数返回一个指向向量末尾的迭代器。

vector 与普通数组区别：不同之处在与数组是静态空间，而 vector 可以动态扩展；

动态扩展：
    并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间；
    vector 容器的迭代器是支持随机访问的迭代器
 */
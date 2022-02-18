[toc]

# C++动态内存

## 1：C++动态内存

- 了解动态内存在 C++中如何工作的是成为一名合格的 C++程序员必不可少的，C++程序中的动态内存分为 2 个部分:
  - **堆 heap：** 在程序运行时用于动态分配内存；
  - **栈 stack：** 在函数内部声明的变量都将用栈内存；
- 很多时候，你无法提前与之需要多少内存来存储某个定义变量中的特定信息，所需内存大小需要在运行时才能确定；
- 在 C++中，你可以使用特殊的运算符 **`new`** 为给定类型的变量在 runtime 时分配堆内存，这会返回分配的内存地址，即`new`运算符；
- 如果你不再需要动态分配的内存空间，可以使用 **`delete`** 运算符，删除之前由`new`运算符分配的内存;

## 2: new 和 delete

### 2.1 new

```cpp
double* pvalue = NULL; // 初始化为null指针
pvalue = new double;   // 为变量申请内存空间

// 如果自由存储区已被用完，可能无法成功分配内存；所以建议检查 new 是否返回null指针，并采取以下适当操作：
double* pvalue =NULL;
if (!(pvalue = new double)){
    cout<<"Error: out of memory!"<<endl;
    exit(1);
}
```

- **malloc()** 函数在 c 语言就出现了，在 C++中也存在，但建议不要使用`malloc()`函数;
- **`new`** 与 **`malloc()`** 相比，优点是：**new 在分配内存的时候还创建了对象**;

### 2.2 delete

- 当你觉得某个已经分配了内存的变量不再需要使用的时候，你可以使用`delete`操作符释放它所占用的内存

```cpp
delete pvalue; // 释放pvalue所指向的内存
```

## 3: 动态内存分配示例

- https://www.runoob.com/cplusplus/cpp-dynamic-memory.html

### 3.1 double\*

```cpp
int main() {
    double* pvalue = NULL;  // 初始化为 null 的指针
    pvalue = new double;    // 为变量请求内存

    *pvalue = 100.568;  // 在分配的地址存储值
    cout << "value of pvalue : " << *pvalue << endl;
    delete pvalue;

    return 0;
}

```

### 3.2 数组的动态内存分配

```cpp
int main() {
    int** p;   // 二维数组的指针
    int i, j;  // p[4][8]
    //开始分配4行8列的二维数据
    p = new int*[4];
    for (i = 0; i < 4; i++) {
        p[i] = new int[8];
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            p[i][j] = j * i;
        }
    }
    //打印数据
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (j == 0)
                cout << endl;
            cout << p[i][j] << "\t";
        }
    }
    //开始释放申请的堆
    for (i = 0; i < 4; i++) {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}
```

### 3.3 对象的动态内存分配

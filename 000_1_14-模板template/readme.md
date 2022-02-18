[toc]

# C++ 模板 template

- 模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码;
- 模板是创建泛型类或者函数的蓝图；
- 库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念；
- 每一个容器都有一个单一的定义，比如**vector<>**，我们可以定义许多不同类型的向量，比如**vector<int>**，**vector<string>**
- 你可以使用模板来定义函数和类；

## 1：函数模板

### 1.1 definition

```cpp
template <typename type> ret-type func-name(){
    // 函数body
}

// type 是函数所使用的数据类型的占位符名称。这个名称可以在函数定义中使用。
```

### 1.2 instance

## 2：类模板

### 2.1 definition

```cpp
template <class type> class class-name{
    //
}
```

// 在这里，type 是占位符类型名称，可以在类被实例化的时候进行指定。您可以使用一个逗号分隔的列表来定义多个泛型数据类型;

### 2.2 instance

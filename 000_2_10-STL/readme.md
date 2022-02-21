[toc]

<div align="center"><front size="35">C++ STL</front></div>

# 1: C++ STL 教程

## 1.1 什么是 STL

- 1: c++ template；
- 2: **C++ STL(标准模板库)** 是一套功能强大的 C++的模板类，提供了通用的模板类和模板函数。这些模板类和函数可以实现多种流行和常用的算法和数据结构，比如向量，链表，队列，栈等.
- 3: C++ STL 的核心组件:
  |**Compontent**|**Description**|**other**|
  |:--|:--|:--|
  |**容器(Containers)**|容器是用来管理某一类对象的集合。C++提供了各种不同的容器，比如`dequeue`,`list`,`vector`,`map`,`set`等||
  |**算法(algorithms)**|算法作用于容器。它们提供了对容器的各种操作，包括对容器内容执行初始化，排序，搜索，转换等操作||
  |**迭代器(iterators)**|迭代器用于遍历对象集合的元素。这些集合可能是容器，也可能是容器的 subset||
  |**仿函数()**|行为类似函数，可以作为算法的某种策略||
  |**适配器(adaptor)**|一种用来修饰容器，仿函数，迭代器接口的东西||
  |**空间配置器()**|负责空间的配置与管理||

# 2: C++ 标准库

- C++ 标准库可以分为两部分：(1)标准函数库,(2)面向对象类库;

## 2.1 标准函数库

- 这个库是由通用的、独立的、不属于任何类的函数组成的。函数库继承自 C 语言。
- 标准函数库分为以下几类：
  - I/O 输入输出:
  - 字符串和字符处理:
  - 数学 math:
  - 时间，日期和本地化:
  - 动态分配:
  - 宽字符函数:
  - ...

## 2.2 面向对象类库

- 这个库是类及其相关函数的集合。
- C++ 标准库包含了所有的 C 标准库，为了支持类型安全，做了一定的添加和修改。
- 面向对象类库包含以下内容：
  - 标准的 C++ IO 类;
  - String 类;
  - 数值类;
  - STL 容器类;
  - STL 算法;
  - STL 函数对象;
  - STL 迭代器;
  - STL 分配器;
  - 本地化库;
  - 异常处理 Exception;
  - 其他支持;

# 3：资源

## 3.1 C++ 有用的网站

- ![C++ 参考手册 cppreference.com](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5);
- http://www.cplusplus.com;
- C++ FAQ − ![C++ 常见问题](http://www.sunistudio.com/cppfaq/);
- ![Free Country](https://www.thefreecountry.com/sourcecode/cpp.shtml) − Free Country 提供了免费的 C++ 源代码和 C++ 库，这些源代码和库涵盖了压缩、存档、游戏编程、标准模板库和 GUI 编程等 C++ 编程领域。

## 3.1 C++书籍

- 《Essential C++ 中文版》
- 《C++ Primer Plus 第 6 版中文版》
- 《C++ Primer 中文版（第 5 版）》

# 4：实例

[toc]

<div align="center"><front size="35">C++ STL 常用算法</front></div>

# 1: 模板

## 1.1 模板的概念

## 1.2 类模板

## 1.3 函数模板

# 2: STL 初识

## 2.1 STL 基本概念

## 2.2 STL 六大组件

## 2.4 STL 容器，算法，迭代器

# 3: STL 常量容器

## 3.1 string 容器

## 3.2 vector 容器

## 3.3 deque 容器

## 3.4 stack 容器

## 3.5 queue 容器

## 3.6 list 容器

## 3.7 set/multiset 容器

## 3.8 map/multimap 容器

# 4: STL 函数对象

## 4.1 函数对象

## 4.2 谓词

## 4.3 内建函数对象

# 5: STL 常用算法

## 5.1 常用遍历算法

### 5.1.1 for_each

- 函数原型：

```cpp
    for_each(iterator bug,iterator end,_func);
    //遍历算法，遍历容器元素
    //beg 开始迭代器
    //end 结束迭代器
    //_func 函数或者函数对象
```

### 5.1.2 transform

- 搬运函数容器到另一个容器中,类似于 py 中的 `map()`映射函数;
- 函数原型：

```cpp
    transform<iterator beg1,iterator end1,iterator beg2,_func>
    //beg1 源容器开始迭代器
    //end1 源容器结束迭代器
    //beg2 目标容器开始迭代器
    //_func 函数或者函数对象
```

## 5.2 常用查找算法

### 5.2.1 find

### 5.2.2 find_if

### 5.2.3 adjacent_find

### 5.2.4 binary_search

### 5.2.5 count

### 5.2.6 count_if

## 5.3 常用排序算法

### 5.3.1 sort

### 5.3.2 random_shuffle

### 5.3.3 merge

### 5.3.4 reverse

## 5.4 常用拷贝和替换算法

### 5.4.1 copy

### 5.4.2 replace

### 5.4.3 replace_if

### 5.4.4 swap

## 5.5 常用的算数生成器

### 5.5.1 accumulate

### 5.5.2 fill

## 5.6 常见集合算法

### 5.6.1 set_intersection

### 5.6.2 set_union

### 5.6.3 set_difference

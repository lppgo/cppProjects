[toc]

# C++ 预处理器

## 1：说明

- 预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理操作;
- 所有的预处理器命令都是以`#`开头的;
- 预处理器命令并不是 C++语句，不会以`;`结尾;
- C++ 还支持很多预处理指令，比如 #include、#define、#if、#else、#line 等，让我们一起看看这些重要指令 ;

## 2: #define 预处理

- `#define`预处理器命令用于创建符号常量，该符号常量通常称为**宏**；

```cpp
#define macro-name replacement-text

// 当这一行代码出现在一个文件中时，在该文件中后续出现的所有宏都将会在程序编译之前被替换为 replacement-text
```

## 3: 参数宏

- 可以使用`#define`来定义一个带有参数的宏；

```cpp
#include <iostream>
using namespace std;

#define MIN(a,b) (a<b ? a : b)

int main ()
{
   int i, j;
   i = 100;
   j = 30;
   cout <<"较小的值为：" << MIN(i, j) << endl;

    return 0;
}
```

## 4: 条件编译

- 有几个指令可以用来有选择的对部分程序源代码进行编译，这个过程称为**条件编译**;

```cpp
#include <iostream>
using namespace std;
#define DEBUG
#define MIN(a, b) (((a) < (b)) ? a : b)

int main() {
    int i, j;
    i = 100;
    j = 30;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
   /* 这是注释部分 */
   cout << MKSTR(HELLO C++) << endl;
#endif

    cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif

    return 0;
}

```

## 5: # 和 ## 运算符

- `# 和 ## 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的。`
- `# 字符串化的意思，出现在宏定义中的#是把跟在后面的参数转换成一个字符串`;

```cpp
#include <iostream>
using namespace std;

#define MKSTR( x ) #x // 会把替换文本转成 引号引起来的字符串;

int main () {
    cout << MKSTR(HELLO C++) << endl; // cout << "HELLO C++" << endl;
    return 0;
}
```

- `## 连接符号，把参数连在一起`;
- 当 `concat` 出现在程序中时，它的参数会被连接起来，并用来取代宏。例如，程序中 CONCAT(HELLO, C++) 会被替换为 "HELLO C++"，如下面实例所示;

```cpp
#include <iostream>
using namespace std;

#define concat(a, b) a ## b
int main()
{
   int xy = 100;

   cout << concat(x, y); // cout << xy;
   return 0;
}
```

## 6: C++ 中的预定义宏

- C++ 提供了下表所示的一些预定义宏：
  |**宏**|**描述**||
  |:--|:--|:--|
  |**`__LINE__`** |这会在程序编译时包含当前行号。||
  |**`__FILE__`** |这会在程序编译时包含当前文件名。||
  |**`__DATE__`** |这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。||
  |**`__TIME__`** |这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。||

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Value of __LINE__ : " << __LINE__ << endl;  // Value of __LINE__ : 5
    cout << "Value of __FILE__ : " << __FILE__ << endl;  // Value of __FILE__ : main.cpp
    cout << "Value of __DATE__ : " << __DATE__ << endl;  // Value of __DATE__ : Feb 17 2022
    cout << "Value of __TIME__ : " << __TIME__ << endl;  // Value of __TIME__ : 17:34:36
    return 0;
}
```

```cpp
#ifndef SOMETHING_H
#define SOMETHING_H
//...
#endif
```

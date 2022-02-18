[toc]

# C++ 命名空间 Namespace

假设这样一种情况，当一个班上有两个名叫 Lucas 的学生时，为了明确区分它们，我们在使用名字之外，不得不使用一些额外的信息，比如他们的家庭住址，或者他们父母的名字等等。

同样的情况也出现在 C++ 应用程序中。例如，您可能会写一个名为 xyz() 的函数，在另一个可用的库中也存在一个相同的函数 xyz()。这样，编译器就无法判断您所使用的是哪一个 xyz() 函数。

因此，引入了命名空间这个概念，专门用于解决上面的问题，它可作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。

## 1：定义命名空间

- 命名空间的定义使用关键字 namespace，后跟命名空间的名称，如下所示：

```cpp
namespace namespace_name {
   // 代码声明
}
```

- 为了调用带有命名空间的函数或变量，需要在前面加上命名空间的名称，如下所示：

```cpp
name::code;  // code 可以是变量或函数
```

## 2: using 指令

- 您可以使用 `using namespace 指令`，这样在使用命名空间时就可以不用在前面加上命名空间的名称。这个指令会告诉编译器，后续的代码将使用指定的命名空间中的名称;

## 3: 不连续的 namespace

- 命名空间可以定义在几个不同的部分中，因此 namespace 是由几个单独定义的部分组成的，一个命名空间的各个组成部分可以分散在多个文件中;
- 所以如果 namespace 的某个组成部分需要请求定义在另一个文件中的名称，则任然需要声明该名称；
- 下面的命名空间定义可以是定义一个新的命名空间，也可以是为已有的命名空间增加新的元素；

```cpp
namespace namespace_name{
    // 代码声明
}
```

### 4：嵌套的 namespace

- 命名空间可以嵌套，你可以在一个命名空间中定义另一个命名空间；

```cpp
namespace namespace_name1 {
   // code declaration
   namespace namespace_name2 {
      // code declaration
   }
}
```

- 您可以通过使用 :: 运算符来访问嵌套的命名空间中的成员：

```cpp
// 访问 namespace_name2 中的成员
using namespace namespace_name1::namespace_name2;

// 访问 namespace:name1 中的成员
using namespace namespace_name1;
```

- 示例:

```cpp
#include <iostream>
using namespace std;

// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
   // 第二个命名空间
   namespace second_space{
      void func(){
         cout << "Inside second_space" << endl;
      }
   }
}
using namespace first_space::second_space;
int main ()
{

   // 调用第二个命名空间中的函数
   func();

   return 0;
}
```

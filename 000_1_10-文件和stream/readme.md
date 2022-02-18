[toc]

# 1: file & stream

- iostream 标准库，它提供了 cin 和 cout 方法分别用于从标准输入读取流和向标准输出写入流。
- 本教程介绍如何从文件读取流和向文件写入流。这就需要用到 C++ 中另一个标准库 fstream
- 标准库`fstream`;

  | 数据类型   | describe                                                                                       |
  | :--------- | :--------------------------------------------------------------------------------------------- |
  | `ofstream` | 该类型表示输出文件流，用于创建文件并向文件写入信息                                             |
  | `ifstream` | 该类型表示输入文件流，用于从文件读取信息                                                       |
  | `fstream`  | 表示文件流，同时具有 ofstream 和 ifstream 的功能，可以创建文件，向文件写入信息，从文件读取信息 |

- 要在 C++中进行文件处理，必须在 C++源码中包含头文件`<iostream>`和`<fstream>`;

# 2: open file

- 在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream 和 fstream 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 ifstream 对象;
- 下面是 open() 函数的标准语法，open() 函数是 fstream、ifstream 和 ofstream 对象的一个成员;

```cpp
void open(const char* filename,ios::openmode mode);
// 在这里，open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式
```

| 模式标志     | 描述                                                                 | other |
| :----------- | :------------------------------------------------------------------- | :---- |
| `ios::app`   | 追加模式，所有的写入都 append 到文件末尾                             |       |
| `ios::ate`   | 文件打开后定位到文件末尾                                             |       |
| `ios::in`    | 打开文件用于读取                                                     |       |
| `ios::out`   | 打开文件用于写入                                                     |
| `ios::trunc` | 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0 |

- 您可以把以上两种或两种以上的模式结合使用。那么您可以使用下面的语法：

  ```cpp
  ofstream outfile;
  outfile.open("file.dat", ios::out | ios::trunc ); // 如果您想要以写入模式打开文件，并希望截断文件，以防文件已存在

  ifstream  afile;
  afile.open("file.dat", ios::out | ios::in ); // 打开一个文件用于读写
  ```

# 3: close file

- 当 C++ 程序终止时，它会自动关闭刷新所有流，释放所有分配的内存，并关闭所有打开的文件。但程序员应该养成一个好习惯，在程序终止前关闭所有打开的文件。

- 下面是 close() 函数的标准语法，close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员 : `void close();`

# 4: write file

- 在 c++中，我们使用`流插入运算符(<<)`向文件写入信息；
- `<<`就像输出到屏幕一样，不同的是使用的 ofstream 或者 fstream，而不是 cout 对象；

# 5: read file

- 在 c++中，我们使用`流提取运算符(>>)从文件读取信息`;
- 就像使用该运算符从键盘输入信息一样。唯一不同的是，在这里您使用的是 ifstream 或 fstream 对象，而不是 cin 对象;

# 6：文件位置指针

- `istream`和`ostream`都提供了用于重新定义文件位置指针的成员函数，这些成员函数包括关于 istream 的`seekg` (seek get)和关于
  ostream 的`seekp` (seek put);
- seekg 和 seekp 的参数通常都是一个长整型，第二个参数可以用于指定查找方向。
  - `ios::beg` : 从 stream 流的开头开始定位；
  - `ios::end` : 从流的末尾开始定位；
- 文件位置指针是一个整数，制定了从文件起始位置到指针所在位置的字节数
- 下面是关于定位 "get" 文件位置指针的实例：

  ```cpp
    // 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
    fileObject.seekg( n );

    // 把文件的读指针从 fileObject 当前位置向后移 n 个字节
    fileObject.seekg( n, ios::cur );

    // 把文件的读指针从 fileObject 末尾往回移 n 个字节
    fileObject.seekg( n, ios::end );

    // 定位到 fileObject 的末尾
    fileObject.seekg( 0, ios::end );
  ```

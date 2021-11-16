<!--
 * @Author: lucas李平平
 * @Date: 2021-09-07 17:29:46
 * @LastEditTime: 2021-09-08 10:17:17
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: /test-1/README.md
-->

[toc]

# 1: 构建 project

# 2: include 头文件定义

# 3：src C++源码

# 4：main.cpp

# 5: 创建静态库

## 5.1 base 基础知识

- 库有两种：静态库（.a、.lib）和动态库（.so、.dll）;
- 所谓静态、动态是指链接;
- **编译过程:**

  - 预编译 (.h,.cpp 等源文件)
  - ---> 编译
  - ---> 汇编
  - ---> 链接 (静态库，动态库区别来自链接阶段如何处理库，链接成可执行程序。分别称为静态链接方式，动态链接方式)
  - ---> 目标文件 (可执行程序，可执行文件)

- 静态库 libxxx.a,libxxx.lib
- Linux 静态库命名规范，必须是 `libxxx.a`。lib 为前缀，中间 xxx 是静态库 name,.a 是扩展名。

## 5.2 创建静态库

- 将 cpp 文件编译成.o 目标文件
  ```cpp
  g++ -c custoMatch.cpp
  ```
- 通过`ar`工具将.o 目标文件打包成.a 静态库文件
  ```cpp
  ar -crv custoMatch.a custoMatch.o
  ```

## 5.3 使用静态库

# 6: CMakeLists.txt

```cmake
#project name
PROJECT(test_math)
#head file path
INCLUDE_DIRECTORIES(
include
)
#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
#set environment variable
SET(TEST_MATH
${DIR_SRCS}
)
#set extern libraries
SET(LIBRARIES
libm.so
)
#add executable file
ADD_EXECUTABLE(../bin/bin ${TEST_MATH})
#add link library
TARGET_LINK_LIBRARIES(../bin/bin ${LIBRARIES})
 
```
## 6.1 make 预定义变量

- EXECUTABLE_OUTPUT_PATH：标二进制可执行文件的存放位置
- PROJECT_SOURCE_DIR：工程的根目录
- PROJECT_BINARY_DIR: 执行 cmake 命令的目录，一般是在 build 目录，在此目录执行 cmake ..
- CMAKE_CURRENT_SOURCE_DIR: 当前 CMakeLists.txt 文件所在目录
- CMAKE_CURRENT_BINARY_DIR: 编译目录，可使用 ADD_SUBDIRECTORY 来修改此变量

<div align="center"><font size=35>C++ 包管理器conan</font></div>

[toc]

# 1: conan Introduce

## 1.1 简单介绍

- Conan 是免费开源的 C 和 C ++语言的依赖项和程序包管理器。使用 python 编写，类似于 py 的 pip，java 的 maven；
- 跨平台: 可以在所有平台上使用：Windows，Linux，OSX，FreeBSD，Solaris 等；
- 可以用于开发所有目标，包括嵌入式，移动（iOS，Android）和裸机；
- 它还与所有构建系统集成，例如 CMake，Visual Studio（MSBuild），Makefile，SCons 等，包括专有系统。
- 它是专门为加速 C 和 C ++项目的开发和持续集成而设计和优化的。借助完全的二进制管理，它可以在所有平台上使用完全相同的过程为包的任意数量的不同版本创建和重用任意数量的不同二进制文件（用于不同的配置，如体系结构，编译器版本等）。由于它是分散式的，因此很容易运行您自己的服务器以私下托管您自己的软件包和二进制文件，而无需共享它们。建议使用免费的 JFrog Artifactory 社区版（CE），由 Conan 服务器在您的控制下私下托管您自己的程序包;

## 1.2 conan 特点

- conan 成熟稳定，向前兼容 compatility;
- Conan 是具有 _Client-Server 体系结构的分散式软件包管理器_。这意味着客户端可以从不同的服务器获取软件包，也可以将软件包上载到不同的服务器（`远程`），类似于`git`推拉模型到/从 git 远程服务器;
- 从较高的角度来看，服务器只是程序包存储。他们不构建也不创建包。这些包是由客户端创建的，并且如果二进制文件是从源代码构建的，则该编译也将由客户端应用程序完成;
- **Conan 客户端：** 这是一个控制台/终端命令行应用程序，其中包含用于程序包创建和使用的繁琐逻辑。Conan 客户端具有用于程序包存储的本地缓存，因此它使您可以完全创建和脱机测试程序包。您也可以脱机工作，只要不需要远程服务器上的新软件包即可;
- 推荐使用 **JFrog Artifactory Community Edition（CE）**，由 Conan 服务器在您的控制下私下托管您自己的程序包。它是 JFrog Artifactory for - Conan 软件包的免费社区版本，包括 WebUI，多个身份验证协议（LDAP），用于创建高级拓扑的虚拟和远程存储库，Rest API 和用于存储任何工件的通用存储库;
- **conan_server** 是与 Conan 客户端一起分发的小型服务器。这是一个简单的开源实现，它提供基本功能，但不提供 WebUI 或其他高级功能;
- **ConanCenter** 是一个中央公共存储库，社区在其中为流行的开源库（例如 Boost，Zlib，OpenSSL，Poco 等）提供软件包;

## 1.3 跨平台

- Conan 可在 Windows，Linux（Ubuntu，Debian，RedHat，ArchLinux，Raspbian），OSX，FreeBSD 和 SunOS 上运行，并且由于具有可移植性，因此它可在可运行 Python 的任何其他平台上运行。它可以针对任何现有平台，从裸机到桌面，移动，嵌入式，服务器，跨架构;
- _Conan 也可以与任何构建系统一起使用_。与最流行的构建系统又内置的集成，例如`CMake`,`Visual Studio(MSBuild)`,`自动工具`,`Makefile`,`Scons`等.
- Conan 可以管理编译器和任何版本。有一些最流行的默认定义:gcc,cl.exe,clang,apple-clang,intel，具有不同的版本配置，runtime,C++标准库等;

# 2: conan Install

- ![conan安装](https://www.cnblogs.com/liqinglucky/p/14320172.html)
- `pip install conan`;
- `conan --version`; Conan version 1.45.0
- `pip install conan --upgrade`; 升级版本

# 3: conan Tutorial

- 让我们从一个示例开始：我们将创建一个 MD5 哈希计算器应用程序，该应用程序使用最流行的 C ++库之一：Poco；
- 我们将使用 CMake 作为构建系统;

## 3.1 conanfile.txt 编写

- `conan remote add conancenter https://center.conan.io`;
- `conan search poco --remote=conancenter`;搜索包
- `conan search libpng -r=conancenter`; 搜索包
- `conan inspect poco/1.11.1`;
- inspect 某一个版本之后，选择用这个版本。在项目里创建一个`conanfile.txt`的文件;
  内容如下:

```txt
// ./conanfile.txt
[requires]
poco/1.11.1

[generators]
cmake
```

## 3.2 安装所需的依赖项并生成构建系统的信息

- (1) 创建一个文件夹，里面的存放信息如下

```md
$ tree -L 1
.
├── build // 文件夹
├── conanfile.txt // conan 配置文件
├── gen_md5.cpp // .cpp 代码文件
└── readme.md
```

- (2) 在正式开始下载库文件并编译的前，我们先告诉 conan 使用 c++11 的标准来编译我们需要的库文件:
  `conan profile update settings.compiler.libcxx=libstdc++11 default`;
- (3) 现在开始使用 conan 编译我们的库文件，首先进入 build 文件夹然后执行指令:`conan install ..`;
  最后安装结束;
  Conan 安装了我们的 Poco 依赖关系，还安装了传递依赖关系：OpenSSL，zlib，sqlite 等。它还为我们的构建系统生成了 conanbuildinfo.cmake 文件;
- (4) 现在库文件已经安装好了，我们来写一个 cmake 执行我们的.cpp 文件，`CMakeLists.txt`脚本如下：

```cmake
cmake_minimum_required(VERSION 2.8.12)
project(MD5Encrypter)

add_definitions("-std=c++11 -g -Wall")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(md5 gen_md5.cpp)

target_link_libraries(md5 ${CONAN_LIBS})
```

- (5) 在 build 目录执行 cmake 命令:
  `cmake .. -DCMAKE_BUILD_TYPE=Release`
  `cmake --build .`
- (5) 可执行文件编译目录`./build/bin`，编译成功。

# 4: conan Summary

- `conan` 是一个由 python 开发的跨平台的 C,C++ 包管理器；
- conan 需要编写`conanfile.txt`来说明依赖;
- `conan search -r=conan`指令可以在远程仓库搜索包;
- `conan install ` 指令根据 conanfile.txt 安装库文件;
- 最终生成文件`conanbuildinfo.txt`;
- 编写`CMakeLists.txt`后编译项目;

- 所用命令总结

```bash
# 安装
pip install conan

# 版本
conan --version

# 升级
pip install conan --upgrade

# 搜索包
conan search poco --remote=conan-center
conan search libpng -r=conan-center

# 查看
conan inspect poco/1.9.4

# 配置文件名
conanfile.txt

# 设置默认编译版本
conan profile update settings.compiler.libcxx=libstdc++11 default

# 安装库
conan install ..


# cmake使用例子
cmake_minimum_required(VERSION 2.8.12)
project(MD5Encrypter)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(md5 md5.cpp)
target_link_libraries(md5 ${CONAN_LIBS})



# linux构建命令
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
$ cmake --build .


```

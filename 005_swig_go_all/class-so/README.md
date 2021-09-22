[toc]

# 1：准备 xxx.cpp,xxx.h 源代码和头文件

- xxx.cpp
- xxx.h

# 2：swig 接口文件

```bash
    swig -c++ -go -cgo -intgosize 64 ./include/simpleClass.i
```

```swig
%module(directors="1") src


// %rename(CPPIAMDApi) amd::ama::IAMDApi;
// %rename(CPPIAMDSpi) amd::ama::IAMDSpi;


%{
    #include <vector>
    #include <stdint.h>
    #include <string>
    #include "./../include/ama_datatype.h"
    #include "./../include/ama_export.h"
    #include "./../include/ama_struct.h"
    #include "./../include/ama_tools.h"
    #include "./../include/ama.h"
%}

%include "./../include/ama_datatype.h"
%include "./../include/ama_export.h"
%include "./../include/ama_struct.h"
%include "./../include/ama_tools.h"
%include "./../include/ama.h"


%include "std_deque.i"
%include "std_pair.i"
%include "std_string.i"
%include "std_vector.i"
%include "stdint.i"
%include "typemaps.i"

// %include "std_multimap.i"
// %include "std_multiset.i"
// %include "std_set.i"
// %include "std_array.i"
// %include "std_auto_ptr.i"
// %include "std_complex.i"
// %include "std_unordered_map.i"
// %include "std_unordered_multimap.i"
// %include "std_unordered_multiset.i"
// %include "std_unordered_set.i"
// %include "std_wstring.i"
// %include "std_shared_ptr.i"

%feature("director")IAMDSpi;

// typemap
%typemap(gotype) unsigned int "uint";



// transform c++ exception into go errors
%include "exception.i"
%exception {
    try {
        $action;
    } catch (std::runtime_error &e) {
        _swig_gopanic(e.what());
    }
}

// namespace
%nspace amd::ama::IAMDSpi;
%nspace amd::ama::IAMDApi;
// %nspace amd::ama::CPPIAMDApi;
// %nspace amd::ama::CPPIAMDSpi;
%nspace amd::ama::Tools;

// // //
// // %nodefaultctor amd::ama::IAMDApi;
// // %nodefaultctor amd::ama::IAMDSpi;



```

- 注意：将`xxx.h,xxx.cpp,xxx._wrap.cxx.xxx.go`放在同一个 dir
- go main 函数 import 对应的.go 文件
- `go build -a -v .`go 编译生成

# 3：生成.so 动态库

## 3.1 CMakeLists.txt

```cmake

```

## 3.2 生成 so 库文件

## 3.3 复制动态链接库 libExample.so 到系统目录 /usr/local/lib

## 3.4 通过`C`库引用 so 动态库

# 4： go

## 4.1 lib.go 调用 C

## 4.2 go main 函数调用生成的 swig 生成的 xxx.go

## 4.3 设置环境变量 LD_LIBRARY_PATH

`export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib`

## 4.4 出现错误

### 4.4.1 **错误 message**

- `xxx error while loading shared libraries: libXXX.so.X: cannot open shared object file: No such file`

- `分析原因：链接器ld提示找不到库文件`

### 4.4.2 **解决方法**

- 将`xxx.so`动态库文件 copy 至 usr/local/lib
- 设置环境变量 LD_LIBRARY_PATH
- 更新/etc/ld.so.cache 文件 `ldconfig`

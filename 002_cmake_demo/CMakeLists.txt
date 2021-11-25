# cmake 最低版本
cmake_minimum_required(VERSION  3.10)

# project name
project(main)

# 设置编译器编译模式
set(cmake_build_type "Debug")

# 生成共享库,这儿不需要.hpp
add_library(calculate SHARED hello.cpp)

# 生成可执行文件
add_executable(main main.cpp)

# 链接共享库
target_link_libraries(main calculate)
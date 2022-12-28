cmake_minimum_required(VERSION 3.16)

project(shmWriter)

set(CMAKE_CXX_STANDARD 17)

# 设置编译器编译模式
set(cmake_build_type "Debug")

# 设置头文件path
include_directories(include)

# 设置源文件path
aux_source_directory(src DIR_SRCS)
# aux_source_directory(src/shmWrite DIR_ENTITY)
#source_group(src src/shmWrite)

# 生成共享库,这儿不需要.hpp
#add_library(calculate SHARED hello.cpp)

# 链接共享库
#target_link_libraries(main calculate)

# 添加需要的所有的执行文件
add_executable(shmWriter ${DIR_SRCS})

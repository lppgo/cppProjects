cmake_minimum_required (VERSION 3.16.0)
set(CMAKE_PROJECT_VERSION 3.16.3)

if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

#set dirs
# set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_ROOT ${PROJECT_SOURCE_DIR})
message("project root dir:${PROJECT_ROOT}")


set(CMAKE_CXX_STANDARD 11) # 设置C++标准为 C++ 11

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   #导出clangd需要的文件，用于智能提示和基于语议的补全

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT}/build)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/build)



# project name
project(Projects-Test-1 LANGUAGES CXX)

# include_directories 向project添加多个指定头文件的搜索路径
include_directories(./include)


# # add_subdirectory 这个命令可以向当前工程添加存放源文件的子目录
# add_subdirectory(./)

# set 源文件
aux_source_directory(./src srclist) # 第一个args指定源文件dir,第二个args指定存放源文件list的变量
# aux_source_directory()也存在弊端，它会把指定目录下的所有源文件都加进来，可能会加入一些我们不需要的文件，
# 此时我们可以使用set命令去新建变量来存放需要的源文件
# set(SRC_LIST main.cpp ${srclist}) 

# 从指定源文件构建可执行程序
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin) # 设置目标可执行文件位置
add_executable(main ${srclist})
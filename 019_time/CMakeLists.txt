# cmake 最低版本
cmake_minimum_required(VERSION  3.10)

# project name
project(main CXX)

# 设置编译器编译模式
set(cmake_build_type "Debug")

set(CXX_FLAGS
        -g
        # -DVALGRIND
        -DCHECK_PTHREAD_RETURN_VALUE
        -D_FILE_OFFSET_BITS=
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -march=native
        # -MMD
        -rdynamic
        )

set(SOURCE_FILES main.cpp src/mytime.cpp)
# 添加头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加需要链接的库文件目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib ${CMAKE_CURRENT_SOURCE_DIR}/cmake/build)

#
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 生成共享库,这儿不需要.hpp
add_library(mt SHARED src/mytime.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} main.cpp)

# 链接共享库
target_link_libraries(${PROJECT_NAME} libmt.so)
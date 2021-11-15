cmake_minimum_required(VERSION 3.2)

project(yaml_test)

add_definitions(-std=c++11)


include_directories(include)
include_directories("/usr/local/include")
set(SRCS yaml_test.cpp)
add_executable(yamltest ${SRCS})

target_link_libraries(yamltest ${CMAKE_HOME_DIRECTORY} /usr/local/lib/libyaml-cpp.so)

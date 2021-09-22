/*
 * @Author: lucas李平平
 * @Date: 2021-09-22 08:43:44
 * @LastEditTime: 2021-09-22 09:18:26
 * @LastEditors: Please set LastEditors
 * @Description: 
 * @FilePath: /005_swig_go_all/class-so/include/simpleClass.cpp
 */

#include "simpleClass.h"

std::string SimpleClass::hello() {
    return "hello";
}

void SimpleClass::helloString(std::vector<std::string>* results) {
    results->push_back("world");
}

void SimpleClass::helloBytes(std::vector<char>* results) {
    results->push_back('w');
    results->push_back('o');
    results->push_back('r');
    results->push_back('l');
    results->push_back('d');
}
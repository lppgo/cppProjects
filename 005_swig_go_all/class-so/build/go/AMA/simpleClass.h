/*
 * @Author: lucas李平平
 * @Date: 2021-09-22 08:43:00
 * @LastEditTime: 2021-09-22 09:01:14
 * @LastEditors: Please set LastEditors
 * @Description: 
 * @FilePath: /005_swig_go_all/class-so/include/simpleClass.h
 */
#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <iostream>
#include <vector>
// using namespace std;

class SimpleClass {
   public:
    SimpleClass(){};
    std::string hello();
    void helloString(std::vector<std::string>* results);
    void helloBytes(std::vector<char>* results);
};

#endif
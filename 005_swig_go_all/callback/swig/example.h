/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:39
 * @LastEditTime: 2021-09-10 17:45:08
 * @LastEditors: 
 * @Description: desc
 * @FilePath: /go/callback/swig/example.h
 */
/* File : example.h */

#include <cstdio>
// #include <stdio.h>
#include <iostream>

class Callback {
   public:
    virtual ~Callback() { std::cout << "Callback::~Callback()" << std::endl; }
    virtual void run() { std::cout << "Callback::run()" << std::endl; }
};

class Caller {
   private:
    Callback* _callback;

   public:
    Caller()
        : _callback(0) {}
    ~Caller() { delCallback(); }
    void delCallback() {
        delete _callback;
        _callback = 0;
    }
    void setCallback(Callback* cb) {
        delCallback();
        _callback = cb;
    }
    void call() {
        if (_callback)
            _callback->run();
    }
};

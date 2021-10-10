/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:39
 * @LastEditTime: 2021-09-29 13:56:35
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \005_swig_go_all\callback\swig\example.h
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



// 基本流程:
// 1: InitCfg  (成功)

// 2: NewIAMDSpi
//     new MDOrderBookVector
//     new MDOrderBook
//     new MDOrderBook --- new bid_order_book
//     new MDOrderBook --- new offer_order_book

//     备注: tools 里面serialize 注释了

// 3: IAMDApiInit(MDOrderBookVector,cfg) (成功)
// 4: 初始化subscribeitem
//     CreateSubscribeItem 数组
//     item 数组元素
//     SetSubScribeItem() 给数组赋值
// 5: 调用subscribedata 方法，进行数据订阅。
/*
 * @Author: lucas李平平
 * @Date: 2021-09-11 16:20:35
 * @LastEditTime: 2021-09-11 17:00:50
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \test-2\ndnKeyChain\ndnKeyTool.cpp
 */
#include "ndnKeyTool.h"
#include <iostream>

using namespace std;

NDNKeyTool::NDNKeyTool() {
    Json::Value root;
    root["name"] = "wgh";
    root["age"] = 100;
    cout << root.toStyledString() << endl;
    cout << "hello" << endl;
    cout << to_string(1000.5) << endl;
    //pthread_t mtid ;
}
NDNKeyTool::~NDNKeyTool() {
    cout << "~NDNKeyTool" << endl;
}
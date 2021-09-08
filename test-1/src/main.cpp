/*
 * @Author: lucas李平平
 * @Date: 2021-09-07 14:06:57
 * @LastEditTime: 2021-09-08 09:48:11
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: /test-1/src/main.cpp
 */

#include "../include/custoMatch.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    double a = 10;
    double b = 2;

    // 声明一个class对象
    custoMatch c;

    double sumValue = c.add(a, b);
    double subValue = c.sub(a, b);
    double mulValue = c.mul(a, b);
    double divValue = c.div(a, b);

    cout << "a + b = " << sumValue << endl;
    cout << "a - b = " << subValue << endl;
    cout << "a * b = " << mulValue << endl;
    cout << "a / b = " << divValue << endl;
    return 0;
}
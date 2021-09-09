/*
 * @Author: lucas李平平
 * @Date: 2021-09-07 17:19:34
 * @LastEditTime: 2021-09-07 21:58:02
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: /test-1/src/custoMatch.cpp
 */
#include "../include/custoMatch.h"

double custoMatch::add(double a, double b)
{
    return a + b;
}

double custoMatch::sub(double a, double b)
{
    return a - b;
}

double custoMatch::mul(double a, double b)
{
    return a * b;
}

double custoMatch::div(double a, double b)
{
    if (b == 0)
    {
        return 0;
    }
    return a / b;
}
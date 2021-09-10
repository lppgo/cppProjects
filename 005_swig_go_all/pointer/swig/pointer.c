/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:41
 * @LastEditTime: 2021-09-10 15:24:53
 * @LastEditors:
 * @Description: desc
 * @FilePath: /go/pointer/swig/pointer.c
 */
/* File : example.c */

void add(int* x, int* y, int* result) {
    *result = *x + *y;
}

void sub(int* x, int* y, int* result) {
    *result = *x - *y;
}

int divide(int n, int d, int* r) {
    int q;
    q = n / d;
    *r = n - q * d;
    return q;
}

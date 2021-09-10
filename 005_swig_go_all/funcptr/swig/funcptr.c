/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-10 16:14:56
 * @LastEditors:
 * @Description: desc
 * @FilePath: /go/funcptr/funcptr.c
 */
/* File : example.c */

int do_op(int a, int b, int (*op)(int, int)) {
    return (*op)(a, b);
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int (*funcvar)(int, int) = add;

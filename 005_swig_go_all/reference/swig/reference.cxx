/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:41
 * @LastEditTime: 2021-09-10 11:26:52
 * @LastEditors:
 * @Description: desc
 * @FilePath: /go/reference/swig/reference.cxx
 */
/* File : example.cxx */

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER)
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <stdio.h>
#include <stdlib.h>
#include "example.h"

Vector operator+(const Vector& a, const Vector& b) {
    Vector r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

char* Vector::print() {
    static char temp[512];
    sprintf(temp, "Vector %p (%g,%g,%g)", (void*)this, x, y, z);
    return temp;
}

VectorArray::VectorArray(int size) {
    items = new Vector[size];
    maxsize = size;
}

VectorArray::~VectorArray() {
    delete[] items;
}

Vector& VectorArray::operator[](int index) {
    if ((index < 0) || (index >= maxsize)) {
        printf("Panic! Array index out of bounds.\n");
        exit(1);
    }
    return items[index];
}

int VectorArray::size() {
    return maxsize;
}

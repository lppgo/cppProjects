/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-21 18:37:30
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \005_swig_go_all\class\swig\class.cxx
 */
/* File : class.cxx */

#include "class.h"
#define M_PI 3.14159265358979323846

/* Move the shape to a new location */
void Shape::move(double dx, double dy) {
    x += dx;
    y += dy;
}

int Shape::nshapes = 0;

double Circle::area() {
    return M_PI * radius * radius;
}

double Circle::perimeter() {
    return 2 * M_PI * radius;
}

double Square::area() {
    return width * width;
}

double Square::perimeter() {
    return 4 * width;
}

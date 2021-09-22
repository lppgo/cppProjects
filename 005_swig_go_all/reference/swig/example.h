/*
 * @Author: lucas李平平
 * @Date: 2021-09-18 13:15:22
 * @LastEditTime: 2021-09-18 13:41:38
 * @LastEditors: Please set LastEditors
 * @Description: 
 * @FilePath: /005_swig_go_all/reference/example.h
 */
/* File : example.h */

class Vector {
   private:
    double x, y, z;

   public:
    Vector()
        : x(0), y(0), z(0) {}
    Vector(double x, double y, double z)
        : x(x), y(y), z(z) {}
    friend Vector operator+(const Vector& a, const Vector& b);
    char* print();
};

class VectorArray {
   private:
    Vector* items;
    int maxsize;

   public:
    VectorArray(int maxsize);
    ~VectorArray();
    Vector& operator[](int);
    int size();
};

/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-21 12:51:59
 * @LastEditors: Please set LastEditors
 * @Description: class.xxx的cpp头文件
 * @FilePath: \005_swig_go_all\class\swig\class.h
 */
/* File : class.h */
// namespace ama {
class Shape {
   public:
    Shape() { nshapes++; }
    virtual ~Shape() { nshapes--; }
    double x, y;
    void move(double dx, double dy);
    virtual double area() = 0;
    virtual double perimeter() = 0;
    static int nshapes;
};

class Circle : public Shape {
   private:
    double radius;

   public:
    Circle(double r)
        : radius(r) {}
    virtual double area();
    virtual double perimeter();
};

class Square : public Shape {
   private:
    double width;

   public:
    Square(double w)
        : width(w) {}
    virtual double area();
    virtual double perimeter();
};
// }  // namespace ama
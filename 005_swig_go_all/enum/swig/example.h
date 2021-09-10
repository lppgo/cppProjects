/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-10 10:11:56
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: /go/enum/swig/example.h
 */
/* File : example.h */

enum color { RED, BLUE, GREEN };

class Foo {
   public:
    Foo(){};
    enum speed { IMPULSE = 10, WARP = 20, LUDICROUS = 30 };
    void enum_test(speed s);
};

void enum_test(color c, Foo::speed s);

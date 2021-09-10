/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-10 17:38:33
 * @LastEditors: 
 * @Description: desc
 * @FilePath: /go/director/swig/director.h
 */
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <stdio.h>
#include <string>

class FooBarAbstract {
   public:
    FooBarAbstract(){};
    virtual ~FooBarAbstract(){};

    std::string FooBar() {
        return this->Foo() + ", " + this->Bar();
    };

   protected:
    virtual std::string Foo() {
        return "Foo";
    };

    virtual std::string Bar() = 0;
};

class FooBarCpp : public FooBarAbstract {
   protected:
    virtual std::string Foo() {
        return "C++ " + FooBarAbstract::Foo();
    }

    virtual std::string Bar() {
        return "C++ Bar";
    }
};

#endif

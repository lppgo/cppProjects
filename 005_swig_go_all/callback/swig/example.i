/* File : example.i */
%module(directors="1") swig  //directors="1"表示可以对C++的类进行继承
%{
#include "example.h"
%}

/* turn on director wrapping Callback */
%feature("director") Callback;

%include "example.h"


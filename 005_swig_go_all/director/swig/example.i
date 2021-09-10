/* File : example.i */
%module(directors="1") swig

%include "std_string.i"

%header %{
#include "director.h"
%}

%feature("director") FooBarAbstract;
%include "director.h"

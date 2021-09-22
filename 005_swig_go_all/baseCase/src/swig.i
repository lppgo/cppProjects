// swig.i

%module(directors="1") baseCase

%{

 #include "BaseCase.h"

%}

%include "std_string.i"

%include "std_map.i"

%feature("director") BaseCase;

%include "BaseCase.h"


/* File : example.i */
%module swig

%{
#include "class.h"
%}

/* Let's just grab the original header file here */
%include "class.h"
// %nspace ama::Shape;
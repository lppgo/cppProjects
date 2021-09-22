%module include
%{
#include "simpleClass.h"
%}



%include "std_string.i"
%include "std_vector.i"
%include "stdint.i"
%include "typemaps.i"

// This will create 2 wrapped types in Go called
// "StringVector" and "ByteVector" for their respective
// types.
namespace std {
   %template(StringVector) vector<string>;
   %template(ByteVector) vector<char>;
}

%include "simpleClass.h"
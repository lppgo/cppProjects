/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// source: ./src/swig.i

#ifndef SWIG_baseCase_WRAP_H_
#define SWIG_baseCase_WRAP_H_

class Swig_memory;

class SwigDirector_BaseCase : public BaseCase
{
 public:
  SwigDirector_BaseCase(int swig_p);
  SwigDirector_BaseCase(int swig_p, BaseCase const &rhs);
  virtual ~SwigDirector_BaseCase();
  void _swig_upcall_Run() {
    BaseCase::Run();
  }
  virtual void Run();
 private:
  intgo go_val;
  Swig_memory *swig_mem;
};

#endif

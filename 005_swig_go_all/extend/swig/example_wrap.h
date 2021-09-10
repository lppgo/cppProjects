/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// source: ./swig/example.i

#ifndef SWIG_swig_WRAP_H_
#define SWIG_swig_WRAP_H_

class Swig_memory;

class SwigDirector_Employee : public Employee
{
 public:
  SwigDirector_Employee(int swig_p, char const *n);
  std::string _swig_upcall_getTitle() {
    return Employee::getTitle();
  }
  virtual std::string getTitle();
  std::string _swig_upcall_getName() {
    return Employee::getName();
  }
  virtual std::string getName();
  std::string _swig_upcall_getPosition() const {
    return Employee::getPosition();
  }
  virtual std::string getPosition() const;
  virtual ~SwigDirector_Employee();
 private:
  intgo go_val;
  Swig_memory *swig_mem;
};

class SwigDirector_Manager : public Manager
{
 public:
  SwigDirector_Manager(int swig_p, char const *n);
  std::string _swig_upcall_getTitle() {
    return Employee::getTitle();
  }
  virtual std::string getTitle();
  std::string _swig_upcall_getName() {
    return Employee::getName();
  }
  virtual std::string getName();
  std::string _swig_upcall_getPosition() const {
    return Manager::getPosition();
  }
  virtual std::string getPosition() const;
  virtual ~SwigDirector_Manager();
 private:
  intgo go_val;
  Swig_memory *swig_mem;
};

#endif

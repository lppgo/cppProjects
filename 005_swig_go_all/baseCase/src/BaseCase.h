/*
 * @Author: lucas李平平
 * @Date: 2021-09-14 11:01:17
 * @LastEditTime: 2021-09-15 16:39:25
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \test-baseCase\src\BaseCase.h
 */

#include <string>

#include <iostream>

using namespace std;

class BaseCase {
   public:
    BaseCase(){};
    virtual ~BaseCase(){};

    BaseCase(const BaseCase& rhs) {
        m_caseName = rhs.m_caseName;
    }

    virtual void Run() { cout << "run the case in baseCase class." << endl; }

   public:
    string m_caseName;
};

class CaseRunner {
   public:
    BaseCase* _baseCase_;

   public:
    CaseRunner()
        : _baseCase_(0) {}

    void RegisterCase(BaseCase* bc) { _baseCase_ = bc; }

    void run() {
        if (_baseCase_)
            _baseCase_->Run();
    }
};

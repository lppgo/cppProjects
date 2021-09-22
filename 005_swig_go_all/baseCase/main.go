/*
 * @Author: lucas李平平
 * @Date: 2021-05-10 10:50:43
 * @LastEditTime: 2021-09-22 14:34:26
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \test-baseCase\main.go
 */

package main

import (
	"fmt"
	swig "test/src"
)

type TestCase1Class interface {
	swig.BaseCase
	deleteBaseCase()
	IsTestCase1Class()
}

type testCase1Class struct {
	swig.BaseCase // 这个是swig导出来的interface接口
}

func (caseClass_ *testCase1Class) IsTestCase1Class() {}

func (caseClass_ *testCase1Class) deleteBaseCase() {
	swig.DeleteDirectorBaseCase(caseClass_.BaseCase)
}

type TestClass struct {
	p swig.BaseCase
}

//
func NewGoTestBaseCase() TestCase1Class {
	om := &TestClass{}
	p := swig.NewDirectorBaseCase(om)
	om.p = p
	return &testCase1Class{BaseCase: p}
}

func (caseClass_ *TestClass) Run() {
	fmt.Println("start to run caseClass ...")
	caseClass_.case1()
	caseClass_.case2()
}

// case1

func (caseClass_ *TestClass) case1() {
	fmt.Println("run caseClass 1")
}

// case2

func (caseClass_ *TestClass) case2() {
	fmt.Println("run caseClass 2")
}

func main() {
	goCase := NewGoTestBaseCase()
	caseRuner := swig.NewCaseRunner()
	caseRuner.RegisterCase(goCase)
	caseRuner.Run()
	return
}

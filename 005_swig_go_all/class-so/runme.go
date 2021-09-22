/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-22 10:29:32
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: /class-so/runme.go
 */
// This example illustrates how C++ classes can be used from Go using SWIG.

package main

import (
	"fmt"
	// 这是swig wrapper的目录.
	// "swig_go/class-so/include"
	include "swig_go/class-so/build/go/AMA"
)

func main() {
	fmt.Println("main enter...")

	simpleClass := include.NewSimpleClass()
	result := simpleClass.Hello()
	fmt.Println("hello:", result)

	fmt.Println("main end...")
}

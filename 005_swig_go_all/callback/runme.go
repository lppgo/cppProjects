/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-28 13:32:06
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \005_swig_go_all\callback\runme.go
 */
package main

import (
	"fmt"

	. "swig_go/callback/swig"
)

// type Caller interface {
// 	Swigcptr() uintptr
// 	SwigIsCaller()
// 	DelCallback()
// 	SetCallback(arg2 Callback)
// 	Call()
// }

// type Callback interface {
// 	Swigcptr() uintptr
// 	SwigIsCallback()
// 	DirectorInterface() interface{}
// 	Run()
// }

// type GoCallback interface {
// 	Callback
// 	deleteCallback()
// 	IsGoCallback()
// }

func main() {
	fmt.Println("Adding and calling a normal C++ callback")
	fmt.Println("----------------------------------------")

	caller := NewCaller()
	callback := NewCallback()

	caller.SetCallback(callback)
	caller.Call()
	caller.DelCallback()

	go_callback := NewGoCallback()

	fmt.Println()
	fmt.Println("Adding and calling a Go callback")
	fmt.Println("--------------------------------")

	caller.SetCallback(go_callback)
	caller.Call()
	caller.DelCallback()

	DeleteGoCallback(go_callback)

	fmt.Println()
	fmt.Println("Go exit")
}

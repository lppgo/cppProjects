/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-10 17:12:45
 * @LastEditors:
 * @Description: desc
 * @FilePath: /go/callback/runme.go
 */
package main

import (
	"fmt"

	. "swig_go/callback/swig"
)

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

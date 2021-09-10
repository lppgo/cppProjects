/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-10 17:36:16
 * @LastEditors:
 * @Description: desc
 * @FilePath: /go/director/runme.go
 */
package main

import (
	"fmt"
	"os"

	"swig_go/director/swig"
)

func Compare(name string, got string, exp string) error {
	fmt.Printf("%s; Got: '%s'; Expected: '%s'\n", name, got, exp)
	if got != exp {
		return fmt.Errorf("%s returned unexpected string! Got: '%s'; Expected: '%s'\n", name, got, exp)
	}
	return nil
}

func TestFooBarCpp() error {
	fb := swig.NewFooBarCpp()
	defer swig.DeleteFooBarCpp(fb)
	return Compare("FooBarCpp.FooBar()", fb.FooBar(), "C++ Foo, C++ Bar")
}

func TestFooBarGo() error {
	fb := swig.NewFooBarGo()
	defer swig.DeleteFooBarGo(fb)
	return Compare("FooBarGo.FooBar()", fb.FooBar(), "Go Foo, Go Bar")
}

func main() {
	fmt.Println("Test output:")
	fmt.Println("------------")
	err := TestFooBarCpp()
	err = TestFooBarGo()
	fmt.Println("------------")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Tests failed! Last error: %s\n", err.Error())
		os.Exit(1)
	}
}

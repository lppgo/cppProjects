/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 13:31:38
 * @LastEditTime: 2021-09-22 14:21:34
 * @LastEditors: Please set LastEditors
 * @Description:
 * @FilePath: \005_swig_go_all\reference\runme.go
 */
// This example illustrates the manipulation of C++ references in Java.

package main

import (
	"fmt"
	"swig_go/reference/swig"
)

func main() {
	fmt.Println("Creating some objects:")
	a := swig.NewVector(3, 4, 5)
	b := swig.NewVector(10, 11, 12)

	fmt.Println("    Created ", a.Print())
	fmt.Println("    Created ", b.Print())

	// ----- Call an overloaded operator -----

	// This calls the wrapper we placed around
	//
	//      operator+(const Vector &a, const Vector &)
	//
	// It returns a new allocated object.

	fmt.Println("Adding a+b")
	c := swig.Addv(a, b)
	fmt.Println("    a+b = " + c.Print())

	// Because addv returns a reference, Addv will return a
	// pointer allocated using Go's memory allocator.  That means
	// that it will be freed by Go's garbage collector, and we can
	// not use DeleteVector to release it.

	c = nil

	// ----- Create a vector array -----

	fmt.Println("Creating an array of vectors")
	va := swig.NewVectorArray(10)
	fmt.Println("    va = ", va)

	// ----- Set some values in the array -----

	// These operators copy the value of Vector a and Vector b to
	// the vector array
	va.Set(0, a)
	va.Set(1, b)

	va.Set(2, swig.Addv(a, b))

	// Get some values from the array

	fmt.Println("Getting some array values")
	for i := 0; i < 5; i++ {
		fmt.Println("    va(", i, ") = ", va.Get(i).Print())
	}

	// Watch under resource meter to check on this
	fmt.Println("Making sure we don't leak memory.")
	for i := 0; i < 1000000; i++ {
		c = va.Get(i % 10)
	}

	// ----- Clean up ----- This could be omitted. The garbage
	// collector would then clean up for us.
	fmt.Println("Cleaning up")
	swig.DeleteVectorArray(va)
	swig.DeleteVector(a)
	swig.DeleteVector(b)
}

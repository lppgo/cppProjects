/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 13:31:38
 * @LastEditTime: 2021-09-09 17:10:39
 * @LastEditors:
 * @Description: desc
 * @FilePath: \go\constants\runme.go
 */
package main

import (
	"fmt"
	"swig_go/constants/swig"
)

func main() {
	fmt.Println("ICONST  = ", swig.ICONST, " (should be 42)")
	fmt.Println("FCONST  = ", swig.FCONST, " (should be 2.1828)")
	fmt.Printf("CCONST  = %c (should be 'x')\n", swig.CCONST)
	fmt.Printf("CCONST2 = %c(this should be on a new line)\n", swig.CCONST2)
	fmt.Println("SCONST  = ", swig.SCONST, " (should be 'Hello World')")
	fmt.Println("SCONST2 = ", swig.SCONST2, " (should be '\"Hello World\"')")
	fmt.Println("EXPR    = ", swig.EXPR, " (should be 48.5484)")
	fmt.Println("iconst  = ", swig.Iconst, " (should be 37)")
	fmt.Println("fconst  = ", swig.Fconst, " (should be 3.14)")
}

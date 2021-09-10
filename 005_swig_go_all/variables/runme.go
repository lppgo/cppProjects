// This example illustrates global variable access from Go.

package main

import (
	"fmt"

	"swig_go/variables/swig"
)

func main() {
	// Try to set the values of some global variables

	swig.SetIvar(42)
	swig.SetSvar(-31000)
	swig.SetLvar(65537)
	swig.SetUivar(123456)
	swig.SetUsvar(61000)
	swig.SetUlvar(654321)
	swig.SetScvar(-13)
	swig.SetUcvar(251)
	swig.SetCvar('S')
	swig.SetFvar(3.14159)
	swig.SetDvar(2.1828)
	swig.SetStrvar("Hello World")
	swig.SetIptrvar(swig.New_int(37))
	swig.SetPtptr(swig.New_Point(37, 42))
	swig.SetName("Bill")

	// Now print out the values of the variables

	fmt.Println("Variables (values printed from Go)")

	fmt.Println("ivar      =", swig.GetIvar())
	fmt.Println("svar      =", swig.GetSvar())
	fmt.Println("lvar      =", swig.GetLvar())
	fmt.Println("uivar     =", swig.GetUivar())
	fmt.Println("usvar     =", swig.GetUsvar())
	fmt.Println("ulvar     =", swig.GetUlvar())
	fmt.Println("scvar     =", swig.GetScvar())
	fmt.Println("ucvar     =", swig.GetUcvar())
	fmt.Println("fvar      =", swig.GetFvar())
	fmt.Println("dvar      =", swig.GetDvar())
	fmt.Printf("cvar      = %c\n", swig.GetCvar())
	fmt.Println("strvar    =", swig.GetStrvar())
	fmt.Println("cstrvar   =", swig.GetCstrvar())
	fmt.Println("iptrvar   =", swig.GetIptrvar())
	fmt.Println("name      =", swig.GetName())
	fmt.Println("ptptr     =", swig.GetPtptr(), swig.Point_print(swig.GetPtptr()))
	fmt.Println("pt        =", swig.GetPt(), swig.Point_print(swig.GetPt()))

	fmt.Println("\nVariables (values printed from C)")

	swig.Print_vars()

	// This line would not compile: since status is marked with
	// %immutable, there is no SetStatus function.
	// fmt.Println("\nNow I'm going to try and modify some read only variables")
	// swig.SetStatus(0)

	fmt.Println("\nI'm going to try and update a structure variable.\n")

	swig.SetPt(swig.GetPtptr())

	fmt.Println("The new value is")
	swig.Pt_print()
	fmt.Println("You should see the value", swig.Point_print(swig.GetPtptr()))
}

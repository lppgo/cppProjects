/*
 * @Author: lucas李平平
 * @Date: 2021-09-10 10:49:43
 * @LastEditTime: 2021-09-11 17:03:27
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \test-2\main.go
 */
package main

import (
	"fmt"
	"go_cpp/ndnKeyChain"
	"time"
)

func main() {
	fmt.Println("Go 直接调用 C++ ...")
	ndnKeyChain.Sign()
	fmt.Println("exit ...")
	time.Sleep(time.Second * 3)
	fmt.Println("exit ...")
}

/*
 * @Author: lucas李平平
 * @Date: 2021-09-11 16:25:06
 * @LastEditTime: 2021-09-11 16:59:26
 * @LastEditors: Please set LastEditors
 * @Description: desc
 * @FilePath: \test-2\ndnKeyChain\ndnKeyChain.go
 */
package ndnKeyChain

/*
#include "keyTool.h"
*/
import "C"

func Sign() {
	C.sign()
}

// #cgo LDFLAGS: -ljsoncpp        // 为g++ 添加静态链接库选项
// #cgo CXXFLAGS: -std=c++14        // 为g++ 添加编译选项

<!--
 * @Author: lucas李平平
 * @Date: 2021-09-09 15:19:27
 * @LastEditTime: 2021-09-09 15:34:19
 * @LastEditors: Please set LastEditors
 * @Description: 记录go通过swig调用C代码
 * @FilePath: /003_swig_go/README.md
-->

[toc]

<div align="center"><font size="35">go通过swig调用C代码</font></div>

# 1：环境配置

## 1.1 go

## 1.2 swig 环境配置

- [swig 下载安装](http://www.swig.org/index.php)
- [swig 文档](http://www.swig.org/Doc4.0/Sections.html#Sections)
  http://www.swig.org/Doc4.0/Sections.html#Sections

# 2: 编写 C 代码和 SWIG 接口文件

## 2.1 code xxx.c

## 2.2 编写 swig 接口文件

- xxx.i
- xxx.swig
- xxx.swigcxx

# 3: 生成 wrap 文件

`swig -go -cgo -intgosize 64 example.i`

## 3.1 生成 xxx_wrap.c 和 xxx.go

# 4: Go 调用新生成的 wrap 文件

```go
import (
	"fmt"

	"swig_go/example"
)
```

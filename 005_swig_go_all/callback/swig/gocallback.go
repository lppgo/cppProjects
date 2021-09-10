/*
 * @Author: lucas李平平
 * @Date: 2021-09-09 17:21:40
 * @LastEditTime: 2021-09-10 17:05:38
 * @LastEditors:
 * @Description: desc
 * @FilePath: /go/callback/swig/gocallback.go
 */
package swig

import (
	"fmt"
)

type GoCallback interface {
	Callback
	deleteCallback()
	IsGoCallback()
}

type goCallback struct {
	Callback
}

func (p *goCallback) deleteCallback() {
	DeleteDirectorCallback(p.Callback)
}

func (p *goCallback) IsGoCallback() {}

type overwrittenMethodsOnCallback struct {
	p Callback
}

func NewGoCallback() GoCallback {
	om := &overwrittenMethodsOnCallback{}
	p := NewDirectorCallback(om)
	om.p = p

	return &goCallback{Callback: p}
}

func DeleteGoCallback(p GoCallback) {
	p.deleteCallback()
}

func (p *overwrittenMethodsOnCallback) Run() {
	fmt.Println("GoCallback.Run")
}

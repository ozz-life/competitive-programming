package main

import "fmt"

type A string

func (a *A) GoString() string {
	return "$" + string(*a)
}

func main() {
	a := A("x")

	fmt.Printf("Using %#v\n", a) // Выведет Using $x
}
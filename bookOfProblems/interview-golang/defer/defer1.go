package main

import "fmt"

type X struct {
	V int
}

func (x X) S() {
	fmt.Println(x.V)
}

func main() {
	x := X{123}
	
	// defer x.S() // Что выведет и почему?
	
	// Как исправить программу?
	defer func() {
		x.S()
	}()

	x.V = 456
}
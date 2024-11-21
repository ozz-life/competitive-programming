package main

import (
	"fmt"
)

func main() {
	c := make([]int8, 0)
	c = append(c, []int8{1, 2, 3}...)
	c = append(c, 4)
	fmt.Println(len(c), cap(c))
	
	fmt.Println()
	
	d := make([]int16, 0)
	d = append(d, []int16{1, 2, 3}...)
	d = append(d, 4)
	fmt.Println(len(c), cap(c))
	
	fmt.Println()
	
	a := make([]int32, 0)
	a = append(a, []int32{1, 2, 3}...)
	a = append(a, 4)
	fmt.Println(len(a), cap(a))
	
	fmt.Println()

	b := make([]int64, 0)
	b = append(b, []int64{1, 2, 3}...)
	b = append(b, 4)
	fmt.Println(len(b), cap(b))
}

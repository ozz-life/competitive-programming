package main

import (
	"fmt"
	"unsafe"
)

func PrintSlice[T any](name string, s []T) {
	if len(s) == 0 {
		fmt.Printf("%s: %v, length: %d, capacity: %d, underlying array: %v\n", name, s, len(s), cap(s), s[:cap(s)])
	} else if len(s) == cap(s) {
		fmt.Printf("%p, %s: %v, length: %d = capacity: %d, underlying array: %v\n", unsafe.Pointer(&s[0]), name, s, len(s), cap(s), s[:cap(s)])
	} else {
		fmt.Printf("%p, %s: %v, length: %d, capacity: %d, underlying array: %v\n", unsafe.Pointer(&s[0]), name, s, len(s), cap(s), s[:cap(s)])
	}
}

func main() {
	var sUninit []int // неинициализированный
	PrintSlice("sUninit", sUninit)
	sUninit = append(sUninit, 0)
	PrintSlice("sUninit", sUninit)
	sUninit = append(sUninit, 0)
	PrintSlice("sUninit", sUninit)
	sUninit = append(sUninit, 0)
	PrintSlice("sUninit", sUninit)

	fmt.Println()

	a := []int{}
	PrintSlice("a", a)
	a = append(a, 0)
	PrintSlice("a", a)
	a = append(a, 0)
	PrintSlice("a", a)
	a = append(a, 0)
	PrintSlice("a", a)

	fmt.Println()

	slice8 := make([]int32, 0)
	PrintSlice("slice8", slice8)
	slice8 = append(slice8, 1)
	PrintSlice("slice8", slice8)
	slice8 = append(slice8, 2)
	PrintSlice("slice8", slice8)
	slice8 = append(slice8, 3)
	PrintSlice("slice8", slice8)

	fmt.Println()

	slice16 := make([]int32, 0)
	PrintSlice("slice16", slice16)
	slice16 = append(slice16, 0)
	PrintSlice("slice16", slice16)
	slice16 = append(slice16, 0)
	PrintSlice("slice16", slice16)
	slice16 = append(slice16, 0)
	PrintSlice("slice16", slice16)

	fmt.Println()

	slice32 := make([]int32, 0)
	PrintSlice("slice32", slice32)
	slice32 = append(slice32, 0)
	PrintSlice("slice32", slice32)
	slice32 = append(slice32, 0)
	PrintSlice("slice32", slice32)
	slice32 = append(slice32, 0)
	PrintSlice("slice32", slice32)

	fmt.Println()

	slice64 := make([]int64, 0)
	PrintSlice("slice64", slice64)
	slice64 = append(slice64, 0)
	PrintSlice("slice64", slice64)
	slice64 = append(slice64, 0)
	PrintSlice("slice64", slice64)
	slice64 = append(slice64, 0)
	PrintSlice("slice64", slice64)
}

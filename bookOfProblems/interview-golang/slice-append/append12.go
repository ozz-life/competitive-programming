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
	a := []int{1, 2, 3}

	b := a[:2]
	PrintSlice("b", a)
	b = append(b, 4)

	PrintSlice("a", a)
	PrintSlice("b", a)
}

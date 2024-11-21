package main

import (
	"fmt"
	"unsafe"
)

func main() {
	a := []string{"a", "b", "c"}
	b := a[1:2]
	b[0] = "q"

	PrintSlice("a", a)
	PrintSlice("b", b)
}

func PrintSlice[T any](name string, s []T) {
	if len(s) == 0 {
		fmt.Printf("%s: %v, length: %d, capacity: %d, underlying array: %v\n", name, s, len(s), cap(s), s[:cap(s)])
	} else if len(s) == cap(s) {
		fmt.Printf("%p, %s: %v, length: %d = capacity: %d, underlying array: %v\n", unsafe.Pointer(&s[0]), name, s, len(s), cap(s), s[:cap(s)])
	} else {
		fmt.Printf("%p, %s: %v, length: %d, capacity: %d, underlying array: %v\n", unsafe.Pointer(&s[0]), name, s, len(s), cap(s), s[:cap(s)])
	}
}

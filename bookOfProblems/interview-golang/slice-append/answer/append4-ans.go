package main

import (
	"fmt"
	"unsafe"
)

// func PrintSlice[T any](name string, s []T) {
// 	if len(s) == 0 {
// 		fmt.Printf("%s: %v, length: %d, capacity: %d, underlying array: %v\n", name, s, len(s), cap(s), s[:cap(s)])
// 	} else if len(s) == cap(s) {
// 		fmt.Printf("%p, %s: %v, length: %d = capacity: %d, underlying array: %v\n", unsafe.Pointer(&s[0]), name, s, len(s), cap(s), s[:cap(s)])
// 	} else {
// 		fmt.Printf("%p, %s: %v, length: %d, capacity: %d, underlying array: %v\n", unsafe.Pointer(&s[0]), name, s, len(s), cap(s), s[:cap(s)])
// 	}
// }

func PrintSlice[T any](name string, s []T) {
	if len(s) == 0 {
		fmt.Printf("%s: %v, length: %d, capacity: %d, underlying array: %v\n", name, s, len(s), cap(s), s[:cap(s)])
	} else if len(s) == cap(s) {
		fmt.Printf("%p, %s: %s, length: %d = capacity: %d, underlying array: %s\n", unsafe.Pointer(&s[0]), name, formatSlice(s), len(s), cap(s), formatSlice(s[:cap(s)]))
	} else {
		fmt.Printf("%p, %s: %s, length: %d, capacity: %d, underlying array: %s\n", unsafe.Pointer(&s[0]), name, formatSlice(s), len(s), cap(s), formatSlice(s[:cap(s)]))
	}
}

func formatSlice[T any](s []T) string {
	switch v := any(s).(type) {
	case []byte:
		return fmt.Sprintf("%q", string(v))
	case []rune:
		return fmt.Sprintf("%q", string(v))
	default:
		return fmt.Sprintf("%v", s)
	}
}

func main() {
	a := []byte{'a', 'b', 'c'} // abc l3 = c3
	PrintSlice("a", a)
	b := append(a[1:2], 'd')   // B NEW bd
	PrintSlice("b", b)
	b[0] = 'z'                 // zd

	fmt.Println()
	PrintSlice("a", a)
	PrintSlice("b", b)
	fmt.Printf("a[0]: %p b[0]: %p\n", &a[0], &b[0])
}

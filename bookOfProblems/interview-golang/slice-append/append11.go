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

// func main() {
// 	s1 := make([]int, 1, 2)
// 	s2 := s1
// 	s2 = append(s2, 1)
	  
// 	fmt.Println(s1[1]) // что выведет? и почему?
// }


func main() {
	s1 := make([]int, 1, 2)
	PrintSlice("s1", s1)
	s2 := s1
	PrintSlice("s2", s2)
	s2 = append(s2, 1)
	PrintSlice("s2", s2)
	  
	//fmt.Println(s1[1]) // что выведет? и почему?
	PrintSlice("s1", s1)
	
}
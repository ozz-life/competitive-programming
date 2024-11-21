package main

import (
	"fmt"
)

func printSlice(name string, s []int) {
	fmt.Printf("elements %s: %v, length: %d, capacity: %d, underlying array: %v\n", name, s, len(s), cap(s), s[:cap(s)])
}

func main() {
	a := []int{1, 2, 3}
	printSlice("a", a)

	b := a
	printSlice("b", b)
	fmt.Printf("a[0]: %p b[0]: %p\n", &a[0], &b[0])

	b = append(b, 4) // когда делается append в len == cap, создаётся новый массив b, теперь он другой массив
	printSlice("b", b)
	fmt.Printf("a[0]: %p b[0]: %p\n", &a[0], &b[0])

	c := b 
	printSlice("c", c)
	fmt.Printf("a[0]: %p b[0]: %p, c[0]: %p\n", &a[0], &b[0], &c[0])
	
	b[0] = 0
	
	e := append(c, 5) // е, основан на c, у c len < cap, поэтому они шарят b, c, e
	printSlice("e", e)
	fmt.Printf("a[0]: %p b[0]: %p, c[0]: %p, e[0]: %p\n", &a[0], &b[0], &c[0], &e[0])

	b[2] = 7
	printSlice("a", a)
	printSlice("b", b)
	printSlice("c", c)
	printSlice("e", e)
}

// func main() {
// 	a := []int{1, 2, 3} // l3 c3 1,2,3
// 	b := a              // l3 c3 1,2,3
// 	b = append(b, 4)    // a l3 c3 1,2,3   | b l4 c6 1,2,3,4 NEW
// 	c := b              // b l4 c6 1,2,3,4 | c l4 c6 1,2,3,4 C SHARED B
// 	b[0] = 0            // b l4 c6 0,2,3,4 | c l4 c6 0,2,3,4
// 	e := append(c, 5)   // c l4 c6 0,2,3,4 | e l5 c6 0,2,3,4,5 E SHARED C
// 	b[2] = 7            // b l4 c6 0,2,7,4 | c l4 c6 0,2,7,4 | e l5 c6 0,2,7,4,5 | B C E SHARED
// 	fmt.Println(a, b, c, e)
// }

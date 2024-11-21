package main

import (
	"fmt"
)

func main() {
	a := []int{1, 2, 3}
	b := a
	b = append(b, 4)
	c := b
	b[0] = 0
	e := append(c, 5)
	b[2] = 7
	fmt.Println(a, b, c, e)
}


// 
// func main() {
	
// 	a := []int{1, 2, 3} // l3 c3
// 	b := a              // b,a SHARED b = 1, 2, 3 l3 c3
// 	b = append(b, 4)    // NEW b = 1, 2, 3, 4 l4 c6
// 	c := b              // c,b SHARED c = 1, 2, 3, 4 l4 c6
// 	b[0] = 0            // b = 0, 2, 3, 4 | c = 0, 2, 3, 4 | l4 c6
// 	e := append(c, 5)   // b,c,e SHARED e = 0, 2, 3, 4, 5 | l5 c6
// 	b[2] = 7            // b = 0, 2, 7, 4 | c = 0, 2, 7, 4 | e = 0, 2, 7, 4, 5
// 	fmt.Println(a, b, c, e)
// }
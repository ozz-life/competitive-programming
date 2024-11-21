package main

import (
	"fmt"
)

func PrintSlice[T any](name string, s []T) {
	fmt.Printf("elements %s: %v, length: %d, capacity: %d, underlying array: %v\n", name, s, len(s), cap(s), s[:cap(s)])
}

func main() {
	a := make([]struct{}, 17, 17)
	a = append(a, struct{}{})
	fmt.Println("len: ", len(a))
	fmt.Println("cap: ", cap(a))
	
	// Go slices capacity increase rate
	//https://stackoverflow.com/questions/75348572/go-slices-capacity-increase-rate

	sl := []int{5: 2}
	print(sl)
}

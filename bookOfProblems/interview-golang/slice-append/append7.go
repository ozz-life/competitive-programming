package main

import (
	"fmt"
)

func main() {
	testSlice := make([]string, 0, 3)
	testSlice = append(testSlice, "Привет")
	testSlice = append(testSlice, "Привет")
	//test(testSlice)

	test(&testSlice)

	fmt.Println(testSlice)      // что выведет?
	fmt.Println(testSlice[:])   // а так?
	fmt.Println(testSlice[0:3]) // а так?
}

func test(testSlice *[]string) {
	*testSlice = append(*testSlice, "Пока")
}

// func test(testSlice []string) {
// 	testSlice = append(testSlice, "Пока")
// }

package main

import "fmt"

func add(s []string) {
	s = append(s, "x")
}

func main() {
	s := []string{"a", "b", "c"}
	add(s[1:2]) // ["a", "b", "x"]
	fmt.Println(s)
}
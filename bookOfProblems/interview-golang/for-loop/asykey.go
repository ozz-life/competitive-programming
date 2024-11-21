package main

import "fmt"

// Что выведет Println? Разные версии Go
func main() {
	f := []int{10, 20, 30, 40}
	s := make([]*int, len(f))
	for k, v := range f {
		s[k] = &v
	}

	fmt.Println(*s[0], *s[1])
}

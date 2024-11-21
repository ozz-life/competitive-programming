package main

import (
	"fmt"
)

func main() {
	a := []byte{'a', 'b', 'c'}
	b := append(a[1:2], 'd')
	b[0] = 'z'

	fmt.Printf("%s\n", a) // что отобразится после вызова?
}

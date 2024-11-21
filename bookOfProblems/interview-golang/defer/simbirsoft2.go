package main

import "fmt"

// Какое значение будет выведено первым здесь?
func main() {
	var a = 5

	fn := func(a *int) {
		*a = 10
	}

	fn(&a)
	fmt.Println(a)
}

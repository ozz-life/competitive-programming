package main

import "fmt"

func add(s []string) {
	s = append(s, "x")
	s = append(s, "y")
	s = append(s, "z")
}

func main() {
	s := []string{"a", "b", "c"}
	add(s[1:2]) // ["a", "b", "x"]
	fmt.Println(s, cap(s))
}

// Помнить. append делается ДО capacity.
// Расширение происходит, когда len == cap
// Если за раз больше впихнуть, чем cap.
// То может всё замениться ДО cap
// Но не расширится дальше и остальное пропадёт
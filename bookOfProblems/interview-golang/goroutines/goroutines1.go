package main

import (
	"fmt"
	"time"
)

func main() {
	x := make(map[int]int, 1)
	
	go func() { x[1] = 2 }()
	go func() { x[2] = 7 }()
	go func() { x[3] = 10 }()

	time.Sleep(100 * time.Millisecond)
	fmt.Println("x[1] = ", x[1])
}

////////////////////////////////////////////////////////////////////////////////
// Иногда будет fatal error: concurrent map writes
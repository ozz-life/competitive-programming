package main

import (
	"fmt"
	"sync"
	"time"
)

// Убрали мьютексы

const numRequests = 10000

var (
	count int
)

func networkRequest(wg *sync.WaitGroup) {
	time.Sleep(time.Second) // Эмуляция сетевого запроса

	count++

	wg.Done()
}

func main() {
	wg := new(sync.WaitGroup)
	wg.Add(numRequests)

	for i := 0; i < numRequests; i++ {
		go networkRequest(wg)
	}

	wg.Wait()
	fmt.Println(count)
}
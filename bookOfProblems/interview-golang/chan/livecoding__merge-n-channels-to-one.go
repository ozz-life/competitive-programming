package main
Qwerty123Lexis77Lexis77Lexis77
import (
	"fmt"
	"sync"
)

// merge объединяет несколько каналов в один
func merge(cs ...<-chan int) <-chan int {
	out := make(chan int)
	var wg sync.WaitGroup

	// Объявляем функцию, которая будет слушать один канал и передавать его значения в out
	output := func(c <-chan int) {
		defer wg.Done()
		for val := range c {
			out <- val
		}
	}

	wg.Add(len(cs))
	for _, c := range cs {
		go output(c)
	}

	// Закрываем выходной канал, когда все горутины завершатся
	go func() {
		wg.Wait()
		close(out)
	}()

	return out
}

func main() {
	ch1 := make(chan int, 2)
	ch2 := make(chan int)

	out := merge(ch1, ch2)

	go func() {
		ch1 <- 1
		ch1 <- 2
		close(ch1)
	}()

	go func() {
		ch2 <- 3
		close(ch2)
	}()

	for val := range out {
		fmt.Println(val)
	}
}
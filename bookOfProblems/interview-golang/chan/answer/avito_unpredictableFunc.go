package main

import (
	"fmt"
	"math/rand"
	"time"
)

func init() {
	rand.Seed(time.Now().UnixNano())
}


// Есть функция unpredictableFunc, работающая неопределённо долго и возвращающая число.
// Её тело нельзя изменять (представим, что внутри сетевой запрос).
func unpredictableFunc() int64 {
	rnd := rand.Int63n(5000)
	time.Sleep(time.Duration(rnd) * time.Millisecond)
	
	return rnd
}

// Нужно изменить функцию обёртку, которая будет работать с заданным таймаутом (например, 1 секунду).
// Если "длинная" функция отработала за это время - отлично, возвращаем результат.
// Если нет - возвращаем ошибку. Результат работы в этом случае нам не важен.
//
// Дополнительно нужно измерить, сколько выполнялась эта функция (просто вывести в лог)
// Сигнатуру функции менять можно.
func predictableFunc() (int64, error) {
	res := make(chan int64, 1)
	
	go func() {
		res <- unpredictableFunc()
		close(res)
	}
	
	select {
	case ret := <- res:
		return res, nil
	case <- time.After(time.Second):
		log.Print("error")
		return 0, fmt.Errorf("time out")
	}
	
}

func main() {
	fmt.Println("started")
	start := time.Now()
	fmt.Println(predictableFunc())
	fmt.Println(time.Since(start))
}
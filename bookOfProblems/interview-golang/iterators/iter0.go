package main

import (
	"fmt"
	"io"
	"iter"
	"math/big"
	"math/rand/v2"
)

func iter0(yield func() bool) {
	for range 3 {
		if !yield() {
			return
		}
	}
}

func testFuncRange0() {
	for range iter0 {
		fmt.Println("iter0")
	}
}

func iter1(yield func(i int) bool) {
	for i := range 3 {
		if !yield(i) {
			return
		}
	}
}

func testFuncRange1() {
	for i := range iter1 {
		fmt.Println("iter1", i)
	}
}

func iter2(yield func(int, int) bool) {
	for i := range 3 {
		if !yield(i, i+2) {
			return
		}
	}
}

func testFuncRange2() {
	for i, e := range iter2 {
		fmt.Println("iter2", i, e)
	}
}

func brokenIter(yield func(i int) bool) {
	for i := range 3 {
		yield(i+1)
	}
}

func testBrokenIter() {
	for i := range brokenIter {
		fmt.Println("brokenIter", i)
		if i > 1 {
			break
		}
	}
}

type Slice []int

func (s Slice) All() func(yield func(i int) bool) {
	return func(yield func(i int) bool) {
		for i := range s {
			if !yield(s[i]) {
				return
			}
		}
	}
}

func iterAll(slice Slice) {
	for i := range slice.All() {
		fmt.Println("all iter:", i)
		if i > 10 {
			break
		}
	}
}

func (s Slice) Primes() func (yield func(i int) bool) {
	return func (yield func(i int) bool) {
		for i := range s {
			if big.NewInt(int64(s[i])).ProbablyPrime(0) {
				if !yield(s[i]) {
					return
				}
			}
		}
	}
}

func iterPrimes(slice Slice) {
	for i := range slice.Primes() {
		fmt.Println("prime number:", i)
		if i > 10 {
			break
		}
	}
}

func (s Slice) FilteredIter(predicate func(i int) bool) func (yield func(i int) bool) {
	return func (yield func(i int) bool) {
		for i := range s {
			if predicate(s[i]) {
				if !yield(s[i]) {
					return
				}
			}
		}
	}
}

func iterEvens(slice Slice) {
	for i := range slice.FilteredIter(func(i int) bool {
		return i%2 == 0
	}) {
		fmt.Println("even number:", i)
		if i > 10 {
			break
		}
	}
}

// Структура для хранения результата итерации
type IterResult struct {
	Result int
	Err    error
}

// Метод ErrorIter для типа Slice
func (s Slice) ErrorIter() func(yield func(result IterResult) bool) {
	return func(yield func(result IterResult) bool) {
		for _, i := range s {
			// Создаем результат итерации
			result := IterResult{Result: i, Err: nil}
			if !yield(result) {
				return
			}
		}
	}
}

// Функция для итерации с обработкой ошибок
func iterWithErr(slice Slice) error {
	slice.ErrorIter()(func(result IterResult) bool {
		if result.Err != nil {
			return false // Если есть ошибка, прекращаем итерацию
		}
		fmt.Printf("error iter got value: %d\n", result.Result)
		return result.Result <= 10 // Продолжаем итерацию, пока результат <= 10
	})
	return nil
}

type iterEof struct {
	slice Slice
	i int
}

func (iter *iterEof) Next() (int, error) {
	defer func() {
		iter.i++
	}()
	
	if iter.i >= len(iter.slice) {
		return 0, io.EOF
	} else if rand.Float32() > .9 {
		return 0, fmt.Errorf("failed to fetch next element")
	}
	
	return iter.slice[iter.i], nil
}

func(s Slice) Iter() *iterEof {
	return &iterEof{slice: s}
}

func (s Slice) RangeCompatibleIter() func (yield func(int, error) bool) {
	iter := s.Iter()
	return func (yield func(i int, e error) bool) {
		for {
			next, err := iter.Next()
			if err == io.EOF {
				return
			}

			if !yield(next, err) {
				return 
			}
		}
	}
}

func iterTraditionalWithRange(slice Slice) {
	for i, err := range slice.RangeCompatibleIter() {
		if err != nil {
			fmt.Printf("error: %s\n", err.Error())
		}

		fmt.Println("iter got value: ", i)
	}
}

func iterTraditionalWithRangeRoundTrip(slice Slice) {
	next, stop := iter.Pull2(slice.RangeCompatibleIter())
	defer stop()
	i := 0
	for {
		result, err, valid := next()
		if !valid {
			break
		}
		
		if i > 10 {
			break
		}
		i++

		if err != nil {
			fmt.Printf("error: %s\n", err.Error())
		} else {
			fmt.Println("iter got value: ", result)
		}
	}
}

func main() {
	// testFuncRange0()
	// testFuncRange1()
	// testFuncRange2()
	//testBrokenIter()
	
	s := Slice{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
	//iterAll(s)
	//iterPrimes(s)
	//iterEvens(s)
	
	// iterWithErr(s)
	// // или
	// if err := iterWithErr(s); err != nil {
	// 	fmt.Println("Error:", err)
	// }

	//iterTraditionalWithRange(s)
	iterTraditionalWithRangeRoundTrip(s)
}
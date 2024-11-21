package main

import (
	"fmt"
)

// Определяем тип для последовательности
type Seq[V any] func() (V, bool)

// Определяем тип для функции, которая принимает два значения
type Seq2[V any] func(func(V, V) bool) bool

// Функция Pull для извлечения элементов из последовательности
func Pull[V any](seq Seq[V]) (func() (V, bool), func()) {
	return func() (V, bool) {
		val, ok := seq()
		return val, ok
	}, func() {}
}

// Функция Pairs для создания пар из последовательности
func Pairs[V any](seq Seq[V]) Seq2[V] {
	return func(yield func(V, V) bool) bool {
		next, stop := Pull(seq)
		defer stop()

		v1, ok1 := next()
		v2, ok2 := next()

		for ok1 && ok2 {
			if !yield(v1, v2) {
				return false
			}
			v1, ok1 = next()
			v2, ok2 = next()
		}
		return true
	}
}

// Пример использования
func main() {
	// Создаем последовательность
	seq := func() Seq[int] {
		i := 0
		return func() (int, bool) {
			if i < 6 {
				i++
				return i, true
			}
			return 0, false
		}
	}()

	// Создаем пары из последовательности
	pairs := Pairs(seq)

	// Вызываем функцию yield для вывода пар
	pairs(func(a, b int) bool {
		fmt.Printf("Pair: (%d, %d)\n", a, b)
		return true // Продолжаем итерацию
	})
}
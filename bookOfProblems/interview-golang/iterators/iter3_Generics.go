package main

import (
	"fmt"
	"time"
)

// Определяем структуру Employee
type Employee struct {
	Name   string
	Salary int
}

// Создаем предопределенный список сотрудников
var Employees = []Employee{
	{Name: "Elliot", Salary: 4},
	{Name: "Donna", Salary: 5},
}


// Iterate is a generic iterator function
func Iterate[E any](e []E) func(func(int, E) bool) {
	return func(yield func(int, E) bool) {
		for i := 0; i < len(e); i++ {
			// Simulate some computational work
			time.Sleep(1 * time.Second) // Уменьшил время ожидания для удобства
			if !yield(i, e[i]) {
				return
			}
		}
	}
}

func main() {
	// // Создаем итератор для среза целых чисел
	// iterator := Iterate([]int{1, 2, 3, 4})

	// // Вызываем итератор и передаем функцию обратного вызова
	// iterator(func(i int, val int) bool {
	// 	fmt.Printf("%d: %+v\n", i, val)
	// 	return true // Возвращаем true, чтобы продолжить итерацию
	// })
	
	for i, employee := range Iterate(Employees) {
		fmt.Printf("%d: %+v\n", i, employee)
	}
	
}
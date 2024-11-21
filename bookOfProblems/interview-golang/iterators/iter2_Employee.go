package main

import (
	"fmt"
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

// Определяем итератор для списка сотрудников
func EmployeeIterator(e []Employee) func(func(int, Employee) bool) {
	// Возвращаем функцию обратного вызова, которая принимает индекс и сотрудника
	return func(yield func(int, Employee) bool) {
		// Проходим по всему списку сотрудников
		for i := 0; i < len(e); i++ {
			if !yield(i, e[i]) {
				// Если yield возвращает false, прекращаем итерацию
				return
			}
		}
	}
}

func main() {
	// Создаем итератор для списка сотрудников
	//iterator := EmployeeIterator(Employees)

	for i, employee := range EmployeeIterator(Employees) {
		fmt.Printf("%d: %+v\n", i, employee)
	}
	
	// Вызываем итератор и передаем функцию обратного вызова
	// iterator(func(index int, employee Employee) bool {
	// 	// Обрабатываем каждого сотрудника
	// 	fmt.Printf("Employee %d: Name: %s, Salary: %d\n", index, employee.Name, employee.Salary)
	// 	// Возвращаем true, чтобы продолжить итерацию
	// 	return true
	// })
	
	
}

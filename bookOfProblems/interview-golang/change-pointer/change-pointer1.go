package main

import (
	"fmt"
)

func main() {
	v := 5
	p := &v
	fmt.Println(*p)

	//changePointer(p)
	p = changePointer(p)
	fmt.Println(*p)
}

// func changePointer(p *int) {
// 	v := 3
// 	p = &v
// 	//*p = v // Если нельзя менять семантику функцию
// }

func changePointer(p *int) *int{
	v := 3
	return &v
}

// В Go ВСЁ передаётся по значению
// Как поменять код, чтобы всё было как надо
// Менять надо не саму переменную, а либо разыменовывая
// подступаться и менять значение на которое указывает поинтер

// Сделать мини игру где надо угадывать число от 1 до 100
// с подсказками, числом твоих попыток и списком чисел которые
// ты ввел.

package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
)

func main() {
	randMax := big.NewInt(101)
	target, err := rand.Int(rand.Reader, randMax)
	if err != nil {
		fmt.Println("Error:", err)
	}

	answers := make([]int64, 0)
	var x int64

	for {
		fmt.Print("Введите число: ")
		_, err := fmt.Scan(&x)
		if err != nil {
			fmt.Println("Error: ошибка ввода")
			continue
		}
		answers = append(answers, x)

		if x == target.Int64() {
			fmt.Println("Угадали!")
			break
		} else if x < target.Int64() {
			fmt.Println("Вы ввели меньшее число")
		} else if x > target.Int64() {
			fmt.Println("Вы ввели большее число")
		}
	}

	fmt.Println("Вы угадали число, массив попыток: ")
	fmt.Println(answers)
}

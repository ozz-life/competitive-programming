package main

import (
	"fmt"
)

const (
	PrizeNo    = iota // 0
	PrizeSmall        // 1
	PrizeBig          // 2
)

func GetResult(a, b, aP, bP int) int {
	if aP == a && bP == b {
		return PrizeBig
	}

	if (aP > bP && a > b) || (aP < bP && a < b) || (aP == bP && a == b) {
		return PrizeSmall
	}

	return PrizeNo
}

func main() {
	fmt.Println(GetResult(1, 2, 1, 2)) // Ожидается 2 (PrizeBig - точный счёт)
	fmt.Println(GetResult(1, 2, 0, 1)) // Ожидается 0 (PrizeNo - не угадал)
	fmt.Println(GetResult(1, 1, 2, 2)) // Ожидается 1 (PrizeSmall - ничья)
	fmt.Println(GetResult(3, 1, 2, 1)) // Ожидается 1 (PrizeSmall - исход)
	fmt.Println(GetResult(0, 0, 1, 1)) // Ожидается 1 (PrizeSmall - ничья)
	fmt.Println(GetResult(1, 0, 0, 1)) // Ожидается 0 (PrizeNo - не угадал)
}

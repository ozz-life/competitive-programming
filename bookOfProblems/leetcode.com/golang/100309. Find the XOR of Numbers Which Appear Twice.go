package main

import (
	"fmt"
)

func duplicateNumbersXOR(nums []int) int {
    m := make(map[int]int, len(nums))
    
    for _, num := range nums {
        m[num]++
    }

    var result int
    for key, value := range m {
        if value == 2 {
            result ^= key
        }
    }

    return result
}

func main() {
	fmt.Println(duplicateNumbersXOR([]int{1, 2, 1, 3})) // Output: 1
	fmt.Println(duplicateNumbersXOR([]int{1, 2, 3}))    // Output: 0
	fmt.Println(duplicateNumbersXOR([]int{1, 2, 2, 1})) // Output: 3
}
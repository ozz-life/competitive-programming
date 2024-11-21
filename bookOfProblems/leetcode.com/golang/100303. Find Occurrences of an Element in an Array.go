package main

import (
	"fmt"
)

func occurrencesOfElement(nums []int, queries []int, x int) []int {
	var indices []int
	var result []int

	for i, num := range nums {
		if num == x {
			indices = append(indices, i)
		}
	}

	for _, q := range queries {
		if q-1 < len(indices) {
			result = append(result, indices[q-1])
		} else {
			result = append(result, -1)
		}
	}

	return result
}

func main() {
	nums := []int{1, 3, 1, 7}
	queries := []int{1, 3, 2, 4}
	x := 1

	fmt.Println(occurrencesOfElement(nums, queries, x)) // Output: [0, -1, 2, -1]

	nums2 := []int{1, 2, 3}
	queries2 := []int{10}
	x2 := 5

	fmt.Println(occurrencesOfElement(nums2, queries2, x2)) // Output: [-1]
}
// Test 1: 
// [1,2,3,4,5]
// 1 ^ 2 = 3
// 2 ^ 3 = 1
// 3 ^ 4 = 7
// 4 ^ 5 = 1

// Test 2:
// Input: nums = [10,100]
// 10 ^ 100 = 110
// Expected Output: 0
// Explanation: There are 2 strong pairs in the array nums: (10, 10) and (100, 100).
// The maximum XOR possible from these pairs is 10 XOR 10 = 0 since the pair (100, 100) also gives 100 XOR 100 = 0.

// Example 3:
// Input: nums = [5,6,25,30]
// Output: 7
// Explanation: There are 6 strong pairs in the array nums: (5, 5), (5, 6), (6, 6), (25, 25), (25, 30) and (30, 30).
// The maximum XOR possible from these pairs is 25 XOR 30 = 7 since the only other non-zero XOR value is 5 XOR 6 = 3.


// func maximumStrongPairXor(nums []int) int {
// 	sort.Ints(nums)
// 	maximumXOR := 0

// 	for l, r := 0, 0; r < len(nums); r++ {

// 		for !isStrongPair(nums[l], nums[r]) {
// 			l++
// 		}

//         // maximumXOR = max(maximumXOR, nums[l]^nums[r]) // так работает первый тест, но не работает следующие два
// 		maximumXOR = max(maximumXOR, nums[l]^nums[r] + 1)
// 	}

// 	return maximumXOR
// }

// func isStrongPair(x, y int) bool {
// 	return abs(x-y) <= min(x, y)
// }

// func abs(a int) int {
// 	if a < 0 {
// 		return -a
// 	}
// 	return a
// }

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }

// func min(a, b int) int {
// 	if a < b {
// 		return a
// 	}
// 	return b
// }






/////////////////////////////////////////

package main

import (
	"fmt"
	"sort"
)


func maximumStrongPairXor(nums []int) int {
	sort.Ints(nums)
	maximumXOR := 0

	for l, r := 0, 0; r < len(nums); r++ {
		for l <= r && !isStrongPair(nums[l], nums[r]) {
			l++
		}

		if l <= r {
			maximumXOR = max(maximumXOR, nums[l]^nums[r])
		}
	}

	return maximumXOR
}

func isStrongPair(x, y int) bool {
	return abs(x-y) <= min(x, y)
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	nums := []int{1, 2, 3, 4, 5}
	fmt.Println(maximumStrongPairXor(nums)) // Ожидаемый вывод: 7

	nums = []int{10, 100}
	fmt.Println(maximumStrongPairXor(nums)) // Ожидаемый вывод: 0

	nums = []int{5, 6, 25, 30}
	fmt.Println(maximumStrongPairXor(nums)) // Ожидаемый вывод: 7
}
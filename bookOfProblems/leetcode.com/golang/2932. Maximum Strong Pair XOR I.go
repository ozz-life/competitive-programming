package main

import (
	"math"
	"sort"
)

func maximumStrongPairXor(nums []int) int {
	ans := math.MinInt32
	sort.Ints(nums)

	for l, r := 0, 0; r < len(nums); r++ {
		for r < len(nums) && abs(nums[l]-nums[r]) <= min(nums[l], nums[r]) {
			ans = max(ans, nums[l]^nums[r])
			r++
		}
		l++
		r = l - 1
	}
    return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

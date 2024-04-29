func getConcatenation(nums []int) []int {
	n := len(nums)
	ans := make([]int, n*2)
	for i := 0; i < n; i++ {
		ans[i], ans[i+n] = nums[i], nums[i]
	}
	return ans
}

func getConcatenation(nums []int) []int {
	n := len(nums)
	ans := make([]int, n*2)
	for i := 0; i < n*2; i++ {
		ans[i] = nums[i%n]
	}
	return ans
}

func getConcatenation(nums []int) []int {
	return append(nums, nums...)
}

func getConcatenation(nums []int) []int {
	newArray := nums
	for _, v := range newArray {
		nums = append(nums, v)
	}
	return nums
}

func getConcatenation(nums []int) []int {
	n := len(nums)
	result := make([]int, 2*n)
	copy(result, nums)
	copy(result[n:], nums)
	return result
}
func longestOnes(nums []int, k int) int {
	var windowBest int

	for l, r := 0, 0; r < len(nums); r++ {
		if nums[r] == 0 {
			k--
		}

		for k < 0 {
			if nums[l] == 0 {
				k++
			}
			l++
		}

		windowBest = max(windowBest, r-l+1)
	}

	return windowBest
}

func longestOnes(nums []int, k int) int {
	var windowBest int

	var zeroCount int
	for l, r := 0, 0; r < len(nums); r++ {
		if nums[r] == 0 {
			zeroCount++
		}

		for zeroCount > k {
			if nums[l] == 0 {
				zeroCount--
			}
			l++
		}

		windowBest = max(windowBest, r-l+1)
	}

	return windowBest
}
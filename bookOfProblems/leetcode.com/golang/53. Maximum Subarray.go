func maxSubArray(nums []int) int {
    windowBest := math.MinInt32
    currentSum := 0

    for _, num := range nums {
        if currentSum < 0 {
            currentSum = num
        } else {
            currentSum += num
        }
        if currentSum > windowBest {
            windowBest = currentSum
        }
    }

    return windowBest
}

// 
func maxSubArray(nums []int) int {
	localSum, globalSum := nums[0], nums[0]

	for i := 1; i < len(nums); i++ {
        if localSum < 0 {
			localSum = 0
		}
		localSum += nums[i]

		if globalSum < localSum {
			globalSum = localSum
		}
	}

	return globalSum
}
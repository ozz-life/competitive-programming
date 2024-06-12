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

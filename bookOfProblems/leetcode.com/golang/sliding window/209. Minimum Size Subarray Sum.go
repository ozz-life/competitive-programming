func minSubArrayLen(target int, nums []int) int {
    minLength := math.MaxInt

    var currentSum int
    for l, r := 0, 0; r < len(nums); r++ {
        currentSum += nums[r]

        for currentSum >= target {
            minLength = min(minLength, r - l + 1)
            currentSum -= nums[l]
            l++
        }
        
    }

    if minLength == math.MaxInt {
        return 0
    } else {
        return minLength
    }
}
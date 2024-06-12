func numSubarrayProductLessThanK(nums []int, k int) int {
    var answer int
    var windowCurrent int = 1

    for l, r := 0, 0; r < len(nums); r++ {
        windowCurrent *= nums[r]

        for windowCurrent >= k && l <= r {
            windowCurrent /= nums[l]
            l++
        }

        answer += r - l + 1
    }

    return answer
}
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

func numSubarrayProductLessThanK(nums []int, k int) int {
    var count int
    product := 1

    for left, right := 0, 0; right < len(nums); right++ {
        product *= nums[right]

        for product >= k && left <= right {
            product /= nums[left]
            left++
        }

        count += right - left + 1
    }

    return count
}
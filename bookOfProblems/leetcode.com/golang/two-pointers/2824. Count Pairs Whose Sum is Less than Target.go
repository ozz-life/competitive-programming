func countPairs(nums []int, target int) int {
    sort.Ints(nums)

    l := 0
    r := len(nums) - 1

    var answer int
    for l < r {
        if nums[l] + nums[r] < target {
            answer += r - l
            l++
        } else {
            r--
        }
    }

    return answer
}

///////////////////////////////////////////////////////////////////////////////
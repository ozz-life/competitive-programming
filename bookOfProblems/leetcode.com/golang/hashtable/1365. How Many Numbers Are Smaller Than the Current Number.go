func smallerNumbersThanCurrent(nums []int) []int {
    m := make(map[int]int, len(nums))
    for _, num := range nums {
        m[num]++
    }

    result := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        for num, count := range m {
            if num < nums[i] {
                result[i] += count
            }
        }
    }

    return result
}
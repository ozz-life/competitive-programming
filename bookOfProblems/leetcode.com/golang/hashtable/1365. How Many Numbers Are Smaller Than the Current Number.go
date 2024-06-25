func smallerNumbersThanCurrent(nums []int) []int {
    frequencyMap := make(map[int]int)

    for _, num := range nums {
        frequencyMap[num]++
    }

    result := make([]int, len(nums))

    for i, num := range nums {
        count := 0
        for k, v := range frequencyMap {
            if k < num {
                count += v
            }
        }
        result[i] = count
    }

    return result
}
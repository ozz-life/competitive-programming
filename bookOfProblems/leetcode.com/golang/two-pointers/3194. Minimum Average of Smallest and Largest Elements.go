func minimumAverage(nums []int) float64 {
    sort.Ints(nums)
    n := len(nums)
    averages := make([]float64, 0, n/2)

    l := 0
    r := n - 1

    for l < r {
        avg := float64(nums[l]+nums[r]) / 2.0
        averages = append(averages, avg)
        l++
        r--
    }

    mn := ArrayMin(averages)
    return mn
}

func ArrayMin(arr []float64) float64 {
    if len(arr) == 0 {
        panic("Cannot find minimum value in an empty array")
    }

    min := math.MaxFloat64
    for _, value := range arr {
        if value < min {
            min = value
        }
    }
    return min
}
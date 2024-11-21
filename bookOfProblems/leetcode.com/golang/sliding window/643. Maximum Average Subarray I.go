func findMaxAverage(nums []int, k int) float64 {
    var windowSum int
    windowBest := math.Inf(-1)

    for l, r := 0, 0; r < len(nums); r++ {
        windowSum += nums[r]

		// if r >= k-1 { // или
        if (r - l + 1) == k {
            windowBest = math.Max(windowBest, float64(windowSum)/float64(k))
            windowSum -= nums[l]
            l++
        }

    }

    return windowBest
}
// PrefixSum
////////////////////////////////////////////////////////////////////////////////

// Time: O(n) and Space: O(n)
func findMaxAveragePFS(nums []int, k int) float64 {
	n := len(nums)
	pfs := make([]int, n+1)

	for i := range nums {
		pfs[i+1] = pfs[i] + nums[i]
	}

	avg := -math.MaxFloat64

	// nums    [1]  [12] [-5] [-6] [50]  [3]
	// pfs [0] [1]  [13] [8]  [2]  [52] [55]  <- with an extra zero at the beginning for cleaner code

	for j := 0; j <= n-k; j++ {
		rangeSum := pfs[j+k] - pfs[j]
		avg = max(avg, float64(rangeSum)/float64(k))
	}

	return avg
}

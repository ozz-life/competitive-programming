func findMaxAverage(nums []int, k int) float64 {
	windowStart, windowEnd := 0, 0
	var windowSum, result float64
	result = math.Inf(-1)

	for windowEnd < len(nums) {
		windowSum += float64(nums[windowEnd])
		
		if windowEnd >= k-1 {
			result = max(result, windowSum/float64(k))
			windowSum -= float64(nums[windowStart])
			windowStart++
		}
		windowEnd++
	}

	return result
}

func findMaxAverage(nums []int, k int) float64 {
	windowStart := 0
	windowSum, result := 0.0, -math.MaxFloat64

	for windowEnd := 0; windowEnd < len(nums); windowEnd++ {
		windowSum += float64(nums[windowEnd])

		if windowEnd >= k-1 {
			result = max(result, windowSum/float64(k))
			windowSum -= float64(nums[windowStart])
			windowStart++
		}
	}

	return result
}

// Страшное окно
////////////////////////////////////////////////////////////////////////////////

func findMaxAverage(nums []int, k int) float64 {
	windowStart, windowEnd := 0, 0
	var windowSum, result float64

	for windowEnd < k {
		windowSum += float64(nums[windowEnd])
		windowEnd++
	}

	result = windowSum / float64(k)

	for windowEnd < len(nums) {
		windowSum += float64(nums[windowEnd])
		windowSum -= float64(nums[windowStart])
		windowStart++
		windowEnd++
		currentAverage := windowSum / float64(k)
		if currentAverage > result {
			result = currentAverage
		}
	}

	return result
}
// Страшное окно
////////////////////////////////////////////////////////////////////////////////

func findMaxAverage(nums []int, k int) float64 {
	windowStart, windowSum := 0, 0.0

	for i := 0; i < k; i++ {
		windowSum += float64(nums[i])
	}

	windowBest := windowSum / float64(k)

	for windowEnd := k; windowEnd < len(nums); windowEnd++ {
		windowSum += float64(nums[windowEnd]) - float64(nums[windowStart])
		windowStart++
		currentAverage := windowSum / float64(k)
		if currentAverage > windowBest {
			windowBest = currentAverage
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

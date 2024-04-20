func maxProfit(prices []int) int {
	maxProfit := 0
	currentProfit := 0
	windowStart := 0
	windowEnd := 0
	
	for windowEnd < len(prices) {
		if prices[windowStart] > prices[windowEnd] {
			windowStart = windowEnd
		} else {
			currentProfit = prices[windowEnd] - prices[windowStart]
			maxProfit = max(maxProfit, currentProfit)
		}
		windowEnd++
	}

	return maxProfit
}
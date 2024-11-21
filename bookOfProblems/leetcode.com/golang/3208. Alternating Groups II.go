func numberOfAlternatingGroups(nums []int, k int) int {
	n := len(nums)
	nums = append(nums, nums...)

	l, r, ans := 0, 0, 0
	for r < (n+k)-1 {

		if nums[r] == nums[r+1] {
			l = r
		}

		r++

		if r-l >= k {
			ans++
		}
	}

	return ans
}
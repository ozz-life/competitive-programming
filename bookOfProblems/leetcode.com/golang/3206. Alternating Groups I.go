func numberOfAlternatingGroups(colors []int) int {
	n := len(colors)
	k := 3
	colors = append(colors, colors...)

	l, r, ans := 0, 0, 0
	for r < (n+k)-1 {

		if colors[r] == colors[r+1] {
			l = r
		}

		r++

		if r-l >= k {
			ans++
		}
	}

	return ans
}
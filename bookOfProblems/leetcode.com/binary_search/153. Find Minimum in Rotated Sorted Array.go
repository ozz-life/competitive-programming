func findMin(a []int) int {
    l := 0
    r := len(a) - 1
	ans := a[0]

    for l <= r {
		if a[l] < a[r] {
			ans = min(ans, a[l])
			break
		}

		m := l + (r-l) >> 1
		ans = min(ans, a[m])
		
        if a[m] >= a[l] {
            l = m + 1
        } else {
            r = m - 1
        }
    }

    return ans
}
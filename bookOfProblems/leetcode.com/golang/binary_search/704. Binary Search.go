// template 1
func search(a []int, x int) int {
	l := 0
	r := len(a) - 1

	for l <= r {
		m := l + (r-l)>>1
		if a[m] == x {
			return m
		} else if a[m] < x {
			l = m + 1
		} else if a[m] > x {
			r = m - 1
		}
	}

	return -1
}

// template 2
func search(a []int, x int) int {
	l := 0
	r := len(a) - 1

	for l < r {
		m := l + (r-l)>>1
		if a[m] == x {
			return m
		} else if a[m] < x {
			l = m + 1
		} else if a[m] > x {
			r = m
		}
	}

	if a[l] == x {
		return l
	} else {
		return -1
	}
}

// template 3
func search(a []int, x int) int {
	l := 0
	r := len(a) - 1

	for r-l > 1 {
		m := l + (r-l)>>1
		if a[m] == x {
			return m
		} else if a[m] < x {
			l = m
		} else if a[m] > x {
			r = m
		}
	}

	if a[l] == x {
		return l
	} else if a[r] == x {
		return r
	} else {
		return -1
	}
}

int LowerBoundRecursive {
}
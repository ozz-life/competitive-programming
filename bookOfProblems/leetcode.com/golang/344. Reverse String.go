func reverseString(s []byte) {
	sort.SliceStable(s, func(a, b int) bool {
		return a > b
	})
}

func reverseString(s []byte) {
	for i := 0; i < len(s)/2; i++ {
		s[i], s[len(s)-i-1] = s[len(s)-i-1], s[i]
	}
}

func reverseString(s []byte) {
    for l, r := 0, len(s)-1; l < r; l, r = l+1, r-1 {
        s[l], s[r] = s[r], s[l]
    }
}

func reverseString(s []byte) {
	l:=0
    r:=len(s)-1
	for l < r {
		s[l], s[r] = s[r], s[l]
		l++
		r--
	}
}
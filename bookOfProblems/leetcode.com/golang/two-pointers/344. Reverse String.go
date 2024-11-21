func reverseString(s []byte) {
	l := 0
	r := len(s) - 1
	for l <= r {
		s[l], s[r] = s[r], s[l]
		l++
		r--
	}
}

////////////////////////////////////////////////////////////////

func reverseString(s []byte) {
	sLen := len(s)
	for i := 0; i < sLen/2; i++ {
		s[i], s[len(s)-1-i] = s[len(s)-1-i], s[i]
	}
}
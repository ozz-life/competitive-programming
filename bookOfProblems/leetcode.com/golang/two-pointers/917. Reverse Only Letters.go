func reverseOnlyLetters(s string) string {
	runes := []rune(s)
	l := 0
	r := len(runes) - 1

	for l <= r {
		if !CharIsLetter(runes[l]) {
			l++
			continue
		}
		if !CharIsLetter(runes[r]) {
			r--
			continue
		}
		runes[l], runes[r] = runes[r], runes[l]
		l++
		r--
	}

	return string(runes)
}

func CharIsLetter(c rune) bool {
	return unicode.IsLetter(c)
}
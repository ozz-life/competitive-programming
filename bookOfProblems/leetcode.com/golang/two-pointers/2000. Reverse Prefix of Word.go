func reversePrefix(word string, ch byte) string {
	runes := []rune(word)

	for l, r := 0, 0; r < len(runes); r++ {
		if runes[r] == rune(ch) {
			for l <= r {
				runes[l], runes[r] = runes[r], runes[l]
				l++
				r--
			}
			break
		}
	}
	return string(runes)
}

////////////////////////////////////////////////////////////////////////

func reversePrefix(word string, ch byte) string {
	prefix := ""
	for i := 0; i < len(word); i++ {
		prefix = string(word[i]) + prefix
		if word[i] == ch {
			prefix += word[i+1:]
			return prefix
		}
	}

	return word
}
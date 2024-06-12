func countGoodSubstrings(s string) int {
	k := 3
	answer := 0

	for windowStart := 0; windowStart <= len(s) - k; windowStart++ {
		window := s[windowStart : windowStart+k]
		if isUnique(window) {
			answer++
		}
	}

	return answer
}

func isUnique(s string) bool {
	charFrequencyMap := make(map[byte]bool)
	for i := 0; i < len(s); i++ {
		if charFrequencyMap[s[i]] {
			return false
		}
		charFrequencyMap[s[i]] = true
	}
	return true
}
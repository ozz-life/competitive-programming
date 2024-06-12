// func lengthOfLongestSubstring(s string) int {
// 	charFrequency := make(map[byte]int)
// 	maxLen := 0

// 	for left, right := 0, 0; right < len(s); right++ {
// 		currentChar := s[right]
// 		charFrequency[currentChar]++

// 		// Shrink the window if the current character is duplicated
// 		for charFrequency[currentChar] > 1 {
// 			leftChar := s[left]
// 			charFrequency[leftChar]--
// 			if charFrequency[leftChar] == 0 {
// 				delete(charFrequency, leftChar)
// 			}
// 			left++
// 		}

// 		currentLen := right - left + 1
// 		if currentLen > maxLen {
// 			maxLen = currentLen
// 		}
// 	}

// 	return maxLen
// }

// func lengthOfLongestSubstring(s string) int {
// 	charFrequency := make(map[byte]int, len(s))

// 	var windowBest int

// 	for r, l := 0, 0; r < len(s); r++ {
// 		charFreqeuncy[s[r]]++

// 		for charFrequency[s[r]] > 1 {
// 			charFrequency[s[l]]--
// 			l++
// 		}

// 		windowBest = max(windowBest, r - l + 1)
// 	}

// 	return windowBest
// }

func lengthOfLongestSubstring(s string) int {
	charFrequency := make(map[byte]int, len(s))
	var windowBestLen int

	for l, r := 0, 0; r < len(s); r++ {
		charFrequency[s[r]]++

		for charFrequency[s[r]] > 1 {
			charFrequency[s[l]]--
			l++
		}

		windowBestLen = max(windowBestLen, r-l+1)
	}

	return windowBestLen
}

//////////////////

func lengthOfLongestSubstring(s string) int {
	frequencyMap := make(map[rune]int)
	maxLen := 0
	windowStart := 0

	for windowEnd, char := range s {
		frequencyMap[char]++

		// Shrink
		for frequencyMap[char] > 1 {
			startChar := rune(s[windowStart])
			frequencyMap[startChar]--
			if frequencyMap[startChar] == 0 {
				delete(frequencyMap, startChar)
			}
			windowStart++
		}

		currentLen := windowEnd - windowStart + 1
		if currentLen > maxLen {
			maxLen = currentLen
		}
	}

	return maxLen
}

///////////////////

func lengthOfLongestSubstring(s string) int {
	frequencyMap := make(map[byte]int)
	maxLen := 0

	for windowStart, windowEnd := 0, 0; windowEnd < len(s); windowEnd++ {
		char := s[windowEnd]
		frequencyMap[char]++

		// Shrink
		for frequencyMap[char] > 1 {
			startChar := s[windowStart]
			frequencyMap[startChar]--
			if frequencyMap[startChar] == 0 {
				delete(frequencyMap, startChar)
			}
			windowStart++
		}

		currentLen := windowEnd - windowStart + 1
		if currentLen > maxLen {
			maxLen = currentLen
		}
	}

	return maxLen
}
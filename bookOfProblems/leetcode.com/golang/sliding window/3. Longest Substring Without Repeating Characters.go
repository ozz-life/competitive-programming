func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)

	var windowBest int
	for l, r := 0, 0; r < len(s); r++ {
	   m[s[r]]++

	   for m[s[r]] > 1 {
		   m[s[l]]--
		   if m[s[l]] == 0 {
			   delete(m, s[l])
		   }
		   l++
	   }

	   windowBest = max(windowBest, r - l + 1)
	}

	return windowBest
}
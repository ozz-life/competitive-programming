func totalFruit(fruits []int) int {
	m := make(map[int]int)
	var windowBest int

	for l, r := 0, 0; r < len(fruits); r++ {
		m[fruits[r]]++

		for len(m) > 2 {
			m[fruits[l]]--
			if m[fruits[l]] == 0 {
				delete(m, fruits[l])
			}
			l++
		}

		windowBest = max(windowBest, r-l+1)
	}

	return windowBest
}
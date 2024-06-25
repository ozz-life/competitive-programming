func findPermutationDifference(s string, t string) int {
	mS := make(map[byte]int, len(s))
	mT := make(map[byte]int, len(t))

	for i := 0; i < len(s); i++ {
		mS[s[i]] = i
	}

	// for i, v := range s {
	// 	mS[v] = i
	// }

	for i := 0; i < len(t); i++ {
		mT[t[i]] = i
	}

	sum := 0
	for char := range mS {
		sum += int(math.Abs(float64(mS[char] - mT[char])))
	}

	return sum
}

func findPermutationDifference(s string, t string) int {
	sum := 0
	for i, v := range s {
		diff := i - strings.Index(t, string(v))
		sum += abs(diff)
	}
	return sum
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
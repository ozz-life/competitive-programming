func numJewelsInStones(jewels string, stones string) int {
	jewelsMap := make(map[rune]int, len(jewels))
	for _, jewel := range jewels {
		jewelsMap[jewel]++
	}

	var result int = 0
	for _, stone := range stones {
		if _, ok := jewelsMap[stone]; ok {
			result++
		}
	}
	return result
}
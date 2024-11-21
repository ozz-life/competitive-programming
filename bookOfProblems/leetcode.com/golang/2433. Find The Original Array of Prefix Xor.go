func FindPrefixXOR(a []int) []int {
	n := len(a)
	b := make([]int, n)

	b[0] = a[0]
	for i := 1; i < n; i++ {
		b[i] = a[i] ^ a[i-1]
	}

	return b
}

func findArray(pref []int) []int {
    return FindPrefixXOR(pref)
}
// Wrong Answer 108 / 795 testcases passed
// 0 red
// 1 blue

func numberOfAlternatingGroups(colors []int) int {
	var ans int

	for i := 0; i < len(colors); i++ {
		if colors[i] == 0 {
			ans++
		}
	}

	return ans
}

// Wrong Answer 103 / 795 testcases passed
func numberOfAlternatingGroups(colors []int) int {
	n := len(colors)
	subarrays := make(map[string]int)

	k := 3
	for i := 0; i <= n-k; i++ {
		subarray := fmt.Sprintf("%d,%d,%d", colors[i], colors[i+1], colors[i+2])
		subarrays[subarray]++
	}

	return uniqueCount
}

func countAlternatingGroups(colors []int, k int) int {
    n := len(colors)
    if n < k {
        return 0
    }
    
    alternatingGroups := 0
    
    for start := 0; start < k; start++ {
        isAlternating := true

        for i := start; i < start + k; i++ {
            if colors[i % n] == colors[(i + 1) % n] {
                isAlternating = false
                break
            }
        }
		
        if isAlternating {
            alternatingGroups++
        }
    }
    
    return alternatingGroups
}

// Wrong Answer 127 / 625 testcases passed
func numberOfAlternatingGroups(colors []int, k int) int {
    n := len(colors)
    if n < k {
        return 0
    }
    
    ans := 0
    
    for s := 0; s < k; s++ {
        isA := true

        for i := s; i < s + k; i++ {
            if colors[i % n] == colors[(i + 1) % n] {
                isA = false
                break
            }
        }
		
        if isA {
            ans++
        }
    }
    
    return ans
}
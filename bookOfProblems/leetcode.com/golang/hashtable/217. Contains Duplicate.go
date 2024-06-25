func containsDuplicate(nums []int) bool {
	numSet := make(map[int]struct{})

	for _, num := range nums {
		if _, found := numSet[num]; found {
			return true
		}
		numSet[num] = struct{}{}
	}

	return false
}

////////////////////////////////////////////////////////////////////////////////

func containsDuplicate(nums []int) bool {
	q := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		q[nums[i]]++
		if (q[nums[i]]) > 1 {
			return true
		}
	}

	return false
}

////////////////////////////////////////////////////////////////////////////////

func containsDuplicate(nums []int) bool {
    
    m := make(map[int]bool, len(nums))
	for _, n := range nums {
		if _, ok := m[n]; ok {
			return true
		} else {
			m[n] = true
		}
	}
	return false
}
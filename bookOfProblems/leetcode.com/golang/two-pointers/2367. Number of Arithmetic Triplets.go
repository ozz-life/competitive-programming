func arithmeticTriplets(nums []int, diff int) int {
	var ans int

	for i := 0; i < len(nums); i++ {
		for j := 1; j < len(nums); j++ {
			for k := 2; k < len(nums); k++ {
				if nums[j]-nums[i] == diff && nums[k]-nums[j] == diff {
					ans++
				}
			}
		}
	}

	return ans
}

//////////////////////////////////////////////////////////////

func arithmeticTriplets(nums []int, diff int) int {
	triplets := 0

	i, j, k := 0, 1, 2
	for i < len(nums)-2 && j < len(nums)-1 && k < len(nums) {
		// Search for the first pair. Left pointer = i, right pointer = j
		if !foundPair(diff, &i, &j, &nums) {
			continue
		}
		// We found the first pair

		// Search for the second pair. Left pointer = j, right pointer = k
		if !foundPair(diff, &j, &k, &nums) {
			continue
		}
		// We found the second pair

		// Which means we can move the pointers to the right and increase the value of triplets
		i++
		j++
		k++
		triplets++
	}

	return triplets
}

func foundPair(diff int, l, r *int, nums *[]int) bool {
	value := (*nums)[*r] - (*nums)[*l]

	if diff > value {
		*r++
		return false
	}

	if diff < value {
		*l++
		return false
	}

	return true
}
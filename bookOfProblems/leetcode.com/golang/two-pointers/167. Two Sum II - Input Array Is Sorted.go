func twoSum(numbers []int, target int) []int {
	s := 0
	e := len(numbers) - 1

	for s < e {
		sum := numbers[s] + numbers[e]
		if sum == target {
			return []int{s + 1, e + 1} // Return 1-based indices
		} else if sum < target {
			s++
		} else {
			e--
		}
	}

	return []int{} // No such pair found
}

////////////////////////////////////////////////////////////////////////////////

func twoSum(numbers []int, target int) []int {
	leftIndex := 0
	rightIndex := len(numbers) - 1

	for leftIndex < rightIndex {
		sum := numbers[leftIndex] + numbers[rightIndex]
		
		switch {
		case sum == target:
			return []int{leftIndex + 1, rightIndex + 1}
		case sum > target:
			rightIndex--
		default:
			leftIndex++
		}
	}

	return nil
}
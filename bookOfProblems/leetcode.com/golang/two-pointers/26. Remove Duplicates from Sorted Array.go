func removeDuplicates(nums []int) int {
	// l - left - last unique element
	// r - right - iterator

	l := 0
	for r := 1; r < len(nums); r++ {
		if nums[r] != nums[l] {
			l++
			nums[l] = nums[r]
		}
	}

	return l + 1
}

////////////////////////////////////////////////////////////////////////////////

// Make use of 2 pointers, a fast and slow moving pointer. Initialise fast to 1 and slow to 0.
// While fast has not reached the end of array, check if the elements at index fast and slow are same, if yes, move fast forward by 1 place.
// If not, copy the non duplicate element into the position after slow.
// Once fast reaches the end of array, all unique elements will be stored inside the first "slow" number of elements in the array.

func removeDuplicates(nums []int) int {
	slow := 0
	fast := 1
	n := len(nums)

	for fast < n {
		if nums[fast] == nums[slow] {
			fast++
		} else {
			slow++
			nums[slow] = nums[fast]
		}
	}

	return slow + 1
}
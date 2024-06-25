package kata

func SmallestIntegerFinder(numbers []int) int {
	min := numbers[0]

	for _, num := range numbers[1:] {
		if num < min {
			min = num
		}
	}

	return min
}

////////////////////////////////////////////////////////////////////////////////

package kata

func SmallestIntegerFinder(numbers []int) int {
	min := numbers[0]

	for _, num := range numbers[1:] {
		if num < min {
			min = num
		}
	}

	return min
}

////////////////////////////////////////////////////////////////////////////////

package kata

import "sort"

func SmallestIntegerFinder(numbers []int) int {
  sort.Ints(numbers)
  return numbers[0]
}

////////////////////////////////////////////////////////////////////////////////


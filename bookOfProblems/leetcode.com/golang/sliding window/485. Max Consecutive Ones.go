package main

import "errors"

/*
 * Sliding Window
 ******************************************************************************/

 func findMaxConsecutiveOnes(nums []int) int {
    var windowBest int
    for l, r := 0, 0; r < len(nums); r++ {
        if nums[r] == 0 {
            l = r + 1
        }

        windowBest = max(windowBest, r - l + 1)
    }

    return windowBest
}

func findMaxConsecutiveOnes(nums []int) int {
	windowStart, windowEnd := 0, 0
	windowBest := 0

	for windowEnd < len(nums) {
		if nums[windowEnd] == 0 {
			windowBest = max(windowEnd-windowStart, windowBest)
			windowStart = windowEnd + 1
		}
		windowEnd++
	}

	windowBest = max(windowEnd-windowStart, windowBest)
	return windowBest
}

////

func findMaxConsecutiveOnes(nums []int) int {
	windowBest := 0
	windowStart, windowEnd := 0, 0
	for windowEnd = 0; windowEnd < len(nums); windowEnd++ {
		if nums[windowEnd] == 0 {
			currentWindow := windowEnd - windowStart
			windowBest = max(windowBest, currentWindow)
			windowStart = windowEnd + 1
		}
	}
	windowBest = max(windowBest, windowEnd-windowStart)

	return windowBest
}

/*
 * Dynamic Programming
 ******************************************************************************/

func findMaxConsecutiveOnes(nums []int) int {
	dp := make([]int, len(nums)+1)

	for i, _ := range nums {
		if nums[i] == 1 {
			dp[i+1] = (dp[i] + 1)
		} else {
			dp[i+1] = 0
		}
	}
	max := 0
	for _, c := range dp {
		if max < c {
			max = c
		}
	}

	return max
}

/*
 * Prefix Sums, со сбросом в нуле.
 ******************************************************************************/

func FindPrefixSums(a []int) []int {
	n := len(a)
	b := make([]int, n+1)
	for i := 0; i < n; i++ {
		if a[i] == 1 {
			b[i+1] = b[i] + a[i]
		} else {
			b[i+1] = 0
		}
	}
	return b
}

func findMaxConsecutiveOnes(nums []int) int {
	prefixSums := FindPrefixSums(nums)

	maxValue := prefixSums[0]
	for _, value := range prefixSums {
		if value > maxValue {
			maxValue = value
		}
	}

	return maxValue
}

/*
 * StringBuilder
 ******************************************************************************/

func findMaxConsecutiveOnes(nums []int) int {
	var sb strings.Builder
	for _, num := range nums {
		sb.WriteString(strconv.Itoa(num))
	}
	str := sb.String()

	array := strings.Split(str, "0")

	maxLength := 0
	for _, s := range array {
		if len(s) > maxLength {
			maxLength = len(s)
		}
	}
	return maxLength
}

/*
 * WAT???
 ******************************************************************************/

func findMaxConsecutiveOnes(nums []int) int {
	currentLength, maxLength := 0, 0
	for _, num := range nums {
		if num != 0 {
			currentLength++
		} else {
			currentLength = 0
		}
		if maxLength < currentLength {
			maxLength = currentLength
		}
	}
	return maxLength
}

/*
 * Bitwise
 ******************************************************************************/

func findMaxConsecutiveOnes(nums []int) int {
	maxConsecutiveOnes := 0
	currentConsecutiveOnes := 0
	isCurrentOne := 1

	for _, num := range nums {
		isCurrentOne &= num

		if isCurrentOne == 1 {
			currentConsecutiveOnes++
			if maxConsecutiveOnes < currentConsecutiveOnes {
				maxConsecutiveOnes = currentConsecutiveOnes
			}
		} else {
			isCurrentOne = 1
			currentConsecutiveOnes = 0
		}
	}

	return maxConsecutiveOnes
}

/*
 * Bitwise Template 2
 ******************************************************************************/
func findMaxConsecutiveOnes(nums []int) int {
	// currentLength - текущая длина последовательности единиц
	// maxLength - максимальная длина последовательности единиц
	var currentLength, maxLength int

	// Проходим по всем элементам массива
	for i := range nums {
		// Обновляем текущую длину последовательности единиц:
		// Если текущий элемент равен 1, то увеличиваем текущую длину на 1.
		// Если текущий элемент равен 0, то сбрасываем текущую длину в 0.
		currentLength = (currentLength + nums[i]) & -nums[i]

		// Если текущая длина превышает максимальную длину, обновляем максимальную длину
		if currentLength > maxLength {
			maxLength = currentLength
		}
	}

	// Возвращаем максимальную длину последовательности единиц
	return maxLength
}

/*
 * Stack
 ******************************************************************************/

type Stack struct {
	items []interface{}
}

func New() *Stack {
	return &Stack{}
}

func NewStack() *Stack {
	return &Stack{}
}

func (s *Stack) Back() (interface{}, error) {
	return s.Peek()
}

func (s *Stack) Clear() {
	s.items = []interface{}{}
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *Stack) Len() int {
	return len(s.items)
}

func (s *Stack) Peek() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("stack is empty")
	}
	return s.items[len(s.items)-1], nil
}

func (s *Stack) Pop() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("stack is empty")
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item, nil
}

func (s *Stack) Push(item interface{}) {
	s.items = append(s.items, item)
}

func (s *Stack) Size() int {
	return s.Len()
}

func findMaxConsecutiveOnes(nums []int) int {
	stack := NewStack()
	for _, value := range nums {
		stack.Push(value)
	}

	count, max := 0, 0
	for stack.Size() != 0 {
		top, _ := stack.Peek()
		if top == 1 {
			count++
			stack.Pop()
			max = maxInt(max, count)
		} else {
			max = maxInt(max, count)
			count = 0
			stack.Pop()
		}
	}
	return max
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/*
 * Main
 ******************************************************************************/

func main() {
	nums := []int{1, 1, 1}
	findMaxConsecutiveOnes(nums)
}

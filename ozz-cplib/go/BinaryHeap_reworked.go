package main

import (
	"cmp"
	"errors"
	"fmt"
)

// BinaryHeap represents a binary heap data structure.
type BinaryHeap[T cmp.Ordered] struct {
	items []T
}

// New creates a new BinaryHeap.
func New[T cmp.Ordered]() *BinaryHeap[T] {
	return &BinaryHeap[T]{}
}

// compare is a helper function to compare two elements.
func compare[T cmp.Ordered](a T, b T) bool {
	return a > b
}

// heapifyDown maintains the heap property by moving an element down the heap.
func (h *BinaryHeap[T]) heapifyDown(i int) {
	n := len(h.items)
	for {
		left := i*2 + 1
		right := i*2 + 2
		smallest := i
		if left < n && compare(h.items[smallest], h.items[left]) {
			smallest = left
		}
		if right < n && compare(h.items[smallest], h.items[right]) {
			smallest = right
		}
		if i == smallest {
			break
		}
		h.items[smallest], h.items[i] = h.items[i], h.items[smallest]
		i = smallest
	}
}

// heapifyUp maintains the heap property by moving an element up the heap.
func (h *BinaryHeap[T]) heapifyUp(i int) {
	for i > 0 && compare(h.items[(i-1)/2], h.items[i]) {
		h.items[(i-1)/2], h.items[i] = h.items[i], h.items[(i-1)/2]
		i = (i - 1) / 2
	}
}

// Push adds an element to the heap.
func (h *BinaryHeap[T]) Push(val T) {
	h.items = append(h.items, val)
	h.heapifyUp(len(h.items) - 1)
}

// Pop removes and returns the root element of the heap.
func (h *BinaryHeap[T]) Pop() (T, error) {
	if len(h.items) == 0 {
		var zero T
		return zero, errors.New("heap is empty")
	}
	root := h.items[0]
	h.items[0] = h.items[len(h.items)-1]
	h.items = h.items[:len(h.items)-1]
	h.heapifyDown(0)
	return root, nil
}

// MakeHeap builds a heap from an unordered array.
func (h *BinaryHeap[T]) MakeHeap(items []T) {
	h.items = items
	for i := len(items)/2 - 1; i >= 0; i-- {
		h.heapifyDown(i)
	}
}

// Sort sorts an array using heap sort.
func (h *BinaryHeap[T]) Sort(items []T) {
	h.MakeHeap(items)
	for i := len(items) - 1; i > 0; i-- {
		h.items[0], h.items[i] = h.items[i], h.items[0]
		h.items = h.items[:i]
		h.heapifyDown(0)
	}
}

// IsHeap checks if the array satisfies the heap property.
func (h *BinaryHeap[T]) IsHeap(idx int) bool {
	if idx >= len(h.items) {
		return true
	}
	left := 2*idx + 1
	right := 2*idx + 2
	if left < len(h.items) && compare(h.items[idx], h.items[left]) {
		return false
	}
	if right < len(h.items) && compare(h.items[idx], h.items[right]) {
		return false
	}
	return h.IsHeap(left) && h.IsHeap(right)
}

func main() {
	var (
		DATA        = []int{5, 3, 1, 2, 4, -2, -40, 100}
		DATA_SORTED = []int{-40, -2, 1, 2, 3, 4, 5, 100}
	)

	Assert := func(ok bool) {
		if !ok {
			panic("Assertion failed")
		}
	}

	AreEqual := func(L1, L2 []int) bool {
		if len(L1) != len(L2) {
			return false
		}
		for i := range L1 {
			if L1[i] != L2[i] {
				return false
			}
		}
		return true
	}

	Copy := func(nums []int) []int {
		ans := make([]int, len(nums))
		copy(ans, nums)
		return ans
	}

	ConstructByPushing := func(nums []int) []int {
		h := New[int]()
		for _, num := range nums {
			h.Push(num)
		}
		return h.items
	}

	RemoveOneByOne := func(heap []int) []int {
		h := New[int]()
		h.MakeHeap(heap)
		removed := []int{}
		for len(h.items) != 0 {
			val, _ := h.Pop()
			removed = append(removed, val)
		}
		return removed
	}

	ApplyHeapSort := func(nums []int) []int {
		h := New[int]()
		sorted := Copy(nums)
		h.Sort(sorted)
		return sorted
	}

	ApplyMakeHeap := func(nums []int) []int {
		h := New[int]()
		h.MakeHeap(nums)
		return h.items
	}

	// Debugging Output
	fmt.Println("DATA:", DATA)
	fmt.Println("ConstructByPushing(DATA):", ConstructByPushing(DATA))

	h := New[int]()
	h.MakeHeap(ConstructByPushing(DATA))
	fmt.Println("After MakeHeap:", h.items)
	Assert(h.IsHeap(0))
	fmt.Println("RemoveOneByOne(ConstructByPushing(DATA)):", RemoveOneByOne(ConstructByPushing(DATA)))
	Assert(AreEqual(RemoveOneByOne(ConstructByPushing(DATA)), DATA_SORTED))

	sorted := ApplyHeapSort(DATA)
	fmt.Println("ApplyHeapSort(DATA):", sorted)
	Assert(AreEqual(sorted, DATA_SORTED))

	h = New[int]()
	h.MakeHeap(ApplyHeapSort(DATA))
	fmt.Println("After MakeHeap on sorted data:", h.items)
	Assert(h.IsHeap(0))
	fmt.Println("RemoveOneByOne(ApplyMakeHeap(DATA)):", RemoveOneByOne(ApplyMakeHeap(DATA)))
	Assert(AreEqual(RemoveOneByOne(ApplyMakeHeap(DATA)), DATA_SORTED))

	fmt.Println("OK")
}
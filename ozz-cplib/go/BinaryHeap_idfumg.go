package main

import (
	"cmp"
	"fmt"
)

func compare[T cmp.Ordered](a T, b T) bool {
	return a > b
}

func heap_heapify_down[T cmp.Ordered](heap []T, i int, n int) {
	for true {
		left := i*2 + 1
		right := i*2 + 2
		smallest := i
		if left < n && compare(heap[smallest], heap[left]) {
			smallest = left
		}
		if right < n && compare(heap[smallest], heap[right]) {
			smallest = right
		}
		if i == smallest {
			break
		}
		heap[smallest], heap[i] = heap[i], heap[smallest]
		i = smallest
	}
}

func heap_heapify_up[T cmp.Ordered](heap []T, i int) {
	for i > 0 && compare(heap[(i-1)/2], heap[i]) {
		heap[(i-1)/2], heap[i] = heap[i], heap[(i-1)/2]
		i = (i - 1) / 2
	}
}

func heap_push[T cmp.Ordered](heap []T, val T) []T {
	heap = append(heap, val)
	heap_heapify_up(heap, len(heap)-1)
	return heap
}

func heap_pop[T cmp.Ordered](heap []T) []T {
	heap[0] = heap[len(heap)-1]
	heap = heap[:len(heap)-1]
	heap_heapify_down(heap, 0, len(heap))
	return heap
}

func heap_make[T cmp.Ordered](heap []T) {
	for i := len(heap) / 2; i >= 0; i-- {
		heap_heapify_down(heap, i, len(heap))
	}
}

func heap_sort[T cmp.Ordered](heap []T) {
	N := len(heap)
	heap_make(heap)
	for i := N - 1; i > 0; i-- {
		heap[0], heap[i] = heap[i], heap[0]
		heap_heapify_down(heap, 0, i)
	}
	for i := 0; i < N/2; i++ {
		heap[i], heap[N-i-1] = heap[N-i-1], heap[i]
	}
}

func heap_isheap[T cmp.Ordered](heap []T, idx int) bool {
	if idx >= len(heap) {
		return true
	}
	left := 2*idx + 1
	right := 2*idx + 2
	if left < len(heap) && compare(heap[idx], heap[left]) {
		return false
	}
	if right < len(heap) && compare(heap[idx], heap[right]) {
		return false
	}
	return heap_isheap(heap, left) && heap_isheap(heap, right)
}

func main() {
	var (
		DATA        = []int{5, 3, 1, 2, 4, -2, -40, 100}
		DATA_SORTED = []int{-40, -2, 1, 2, 3, 4, 5, 100}
	)

	Assert := func(ok bool) {
		if !ok {
			panic("Assertion is failed")
		}
	}

	AreEqual := func(L1, L2 []int) bool {
		M := len(L1)
		N := len(L2)
		if M != N {
			return false
		}
		for i := 0; i < N; i++ {
			if L1[i] != L2[i] {
				return false
			}
		}
		return true
	}

	Copy := func(nums []int) []int {
		ans := make([]int, len(nums))
		for i := 0; i < len(nums); i++ {
			ans[i] = nums[i]
		}
		return ans
	}

	ConstructByPushing := func(nums []int) []int {
		pq := []int{}
		for _, num := range nums {
			pq = heap_push(pq, num)
		}
		return pq
	}

	RemoveOneByOne := func(heap []int) []int {
		removed := []int{}
		for len(heap) != 0 {
			removed = append(removed, heap[0])
			heap = heap_pop(heap)
		}
		return removed
	}

	ApplyHeapSort := func(nums []int) []int {
		sorted := Copy(nums)
		heap_sort(sorted)
		return sorted
	}

	ApplyMakeHeap := func(nums []int) []int {
		heap := Copy(nums)
		heap_make(heap)
		return heap
	}

	Assert(heap_isheap(ConstructByPushing(DATA), 0) == true)
	Assert(AreEqual(RemoveOneByOne(ConstructByPushing(DATA)), DATA_SORTED))
	Assert(AreEqual(ApplyHeapSort(DATA), DATA_SORTED))
	Assert(heap_isheap(ApplyHeapSort(DATA), 0) == true)
	Assert(AreEqual(RemoveOneByOne(ApplyMakeHeap(DATA)), DATA_SORTED))
	fmt.Println("OK")
}
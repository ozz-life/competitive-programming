// MultiSet maps the values (int) with their occurence (int):
// map[value]occurence.
type MultiSet struct {
    items map[int]int
}

// Time: O(1)
// Space: O(n)
func NewMultiSet() *MultiSet {
    return &MultiSet{
        items: make(map[int]int),
    }
}

// Time: O(n)
// Space: O(n)
func BuildMultiSet(nums []int) *MultiSet {
    // Space: O(n)
    set := NewMultiSet()
    
    // Time: O(n)
    for _, num := range nums {
        set.Add(num)
    }
    
    return set
}

// Time: O(1)
// Space: O(1)
func (s *MultiSet) Add(val int) {
    s.items[val]++
}

// NumberOfPairs returns the total number of pairs
// for all value in the multi set.
//
// For 1 occurence, we have 0 pair.
// For 2 occurences, we have 1 pair.
// For 3 occurences, we have 3 pairs.
// Number of pairs: {0, 1, 3, 6, 10, 15, 21, 28, ... }
//
// For n occurences, we have n(n-1)/2 pairs.
//
// Time: O(n)
// Space: O(1)
func (s *MultiSet) NumberOfPairs() int {
    var nb int = 0
    // Time: O(n)
    for _, n := range s.items {
        nb += (n*(n-1)/2)
    }
    return nb
}
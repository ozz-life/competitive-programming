import (
    "sort"
)

type Pair struct {
    Value int
    Index int
}

func twoSum(nums []int, target int) []int {
    pairs := make([]Pair, len(nums))
    for i, num := range nums {
        pairs[i] = Pair{Value: num, Index: i}
    }

    sort.Slice(pairs, func(i, j int) bool {
        return pairs[i].Value < pairs[j].Value
    })

    s := 0
    e := len(pairs) - 1
    for s <= e {
        sum := pairs[s].Value + pairs[e].Value
        if sum == target {
            return []int{pairs[s].Index, pairs[e].Index}
        } else if sum < target {
            s++
        } else {
            e--
        }
    }

    return []int{}
}
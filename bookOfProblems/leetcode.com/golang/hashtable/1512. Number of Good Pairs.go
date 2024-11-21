func numIdenticalPairs(nums []int) int {
    var result int
    m := make(map[int]int, len(nums))
     for _, num := range nums {
        result += m[num]
        m[num]++
     }
     return result     
}
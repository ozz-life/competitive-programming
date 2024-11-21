func containsDuplicate(nums []int) bool {
    m := make(map[int]int, len(nums))

    for _, i := range nums {
        if _, ok := m[i]; ok {
            return true
        }
        m[i] = 1
    }
    return false
}
func searchInsert(a []int, target int) int {
    l := -1
    r := len(a)
    for r - l > 1 {
        m := l + (r - l) >> 1
        if a[m] < target {
            l = m
        } else {
            r = m
        }
    }
    return r
}
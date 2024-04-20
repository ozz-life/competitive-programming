func peakIndexInMountainArray(a []int) int {
    l := -1
    r := len(a)
    for l + 1 < r {
        m := l + (r - l) / 2
        if a[m] < a[m + 1] {
            l = m
        } else {
            r = m
        }
    }
    return r
}
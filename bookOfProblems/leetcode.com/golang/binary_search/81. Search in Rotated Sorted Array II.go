func search(a []int, x int) bool {
    l, r := 0, len(a) - 1
    for l <= r {
        m := l + (r - l) >> 1

        if a[m] == x {
            return true
        }
        if a[l] == a[m] {
            l++
            continue
        }
        if a[l] <= a[m] {
            if a[l] <= x && x <= a[m] {
                r = m - 1
            } else {
                l = m + 1
            }
        } else {
            if a[m] <= x && x <= a[r] {
                l = m + 1
            } else {
                r = m - 1
            }
        }
    }
    return false
}
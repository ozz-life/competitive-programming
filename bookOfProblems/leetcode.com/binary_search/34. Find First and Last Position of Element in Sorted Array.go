func searchRange(a []int, x int) []int {
    ans := make([]int, 0, 2)
    
    l := -1
    r := len(a)
    for r - l > 1 {
        m := l + (r - l) >> 1
        if a[m] < x {
            l = m
        } else {
            r = m
        }
    }
    
    if r != len(a) && a[r] == x {
        ans = append(ans, r)
    } else {
        return []int{-1, -1}
    }
    
    l = -1
    r = len(a)
    for r - l > 1 {
        m := l + (r - l) >> 1
        if a[m] <= x {
            l = m
        } else {
            r = m
        }
    }
    
    ans = append(ans, l)
    
    return ans
}
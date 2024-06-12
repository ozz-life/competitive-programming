func findPeakElement(a []int) int {
    l, r := 0, len(a) - 1
    for l <= r {
        m := l + (r - l) >> 1

       if a[m] < a[m + 1] {
            l = m + 1
        } else {
            r = m - 1
        }
    }
    
    return l
}

func findPeakElement(nums []int) int {
    check := func(m int) bool {
        return m == 0 || nums[m-1] < nums[m]
    }

    l, r := -1, len(nums)
    for r - l > 1 {
        m := l + (r-l) >> 1
        if check(m) {
            l = m
        } else {
            r = m
        }
    }

    return l
}
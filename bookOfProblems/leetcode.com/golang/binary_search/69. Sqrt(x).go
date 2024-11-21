func greaterThanSquare(m, x int) bool {
    return m*m > x
}

func mySqrt(x int) int {
    l := -1
    r := math.MaxInt32
    for l+1 < r {
        m := l + (r-l)/2
        if greaterThanSquare(m, x) {
            r = m
        } else {
            l = m
        }
    }
    return l
}
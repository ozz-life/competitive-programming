func scoreOfString(s string) int {
    ans := 0
    for i := 1; i < len(s); i++ {
        prev := int(s[i-1])
        curr := int(s[i])
        ans += abs(curr - prev)
    }
    return ans
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
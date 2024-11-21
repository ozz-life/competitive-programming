func validPalindrome(s string) bool {
    l := 0
    r := len(s) - 1

    for l < r {
        if s[l] != s[r] {
            return isPalindromeRange(s, l+1, r) || isPalindromeRange(s, l, r-1)
        }
        l++
        r--
    }

    return true
}

func isPalindromeRange(s string, l int, r int) bool {
    for l < r {
        if s[l] != s[r] {
            return false
        }
        l++
        r--
    }
    return true
}
func isPalindrome(s string) bool {
    s = strings.ToLower(s)
    s = StringFilterAlphanumeric(s)

    l := 0
    r := len(s) - 1

    for l <= r {
        if s[l] != s[r] {
            return false
        }
        l++
        r--
    }
    return true
}

func StringFilterAlphanumeric(s string) string {
    var sb strings.Builder
    for _, r := range s {
        if unicode.IsLetter(r) || unicode.IsDigit(r) {
            sb.WriteRune(r)
        }
    }
    return sb.String()
}
func reverseVowels(s string) string {
    runes := []rune(s)
    l := 0
    r := len(runes) - 1

    for l < r {
        if !CharIsVowel(runes[l]) {
            l++
            continue
        }
        if !CharIsVowel(runes[r]) {
            r--
            continue
        }
        runes[l], runes[r] = runes[r], runes[l]
        l++
        r--
    }

    return string(runes)

func CharIsVowel(c rune) bool {
    switch unicode.ToLower(c) {
    case 'a', 'e', 'i', 'o', 'u':
        return true
    }
    return false
}
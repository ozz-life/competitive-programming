func isAnagram(s string, t string) bool {
    if len(s)!=len(t){
        return false
    }

    m1 := make(map[rune]int)
    m2 := make(map[rune]int)

    for _, char := range s {
        m1[char]++
    }

    for _, char := range t {
        m2[char]++
    }

    isAnagram := true
    for char, count := range m1 {
        if count != m2[char] {
            isAnagram = false
            break
        }
    }

    if isAnagram {
        return true
    } else {
        return false
    }
}
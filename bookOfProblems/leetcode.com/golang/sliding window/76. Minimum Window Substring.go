func minWindow(s string, t string) string {
    mT := make(map[byte]int)
    mS := make(map[byte]int)
    
    for i := 0; i < len(t); i++ {
        mT[t[i]]++
    }

    required := len(mT)
    formed := 0
    windowBestStart, windowBestEnd := 0, -1
    for l, r := 0, 0; r < len(s); r++ {
        mS[s[r]]++

        if mT[s[r]] > 0 && mS[s[r]] == mT[s[r]] {
            formed++
        }

        for l <= r && formed == required {
            if windowBestEnd == -1 || r-l+1 < windowBestEnd-windowBestStart+1 {
                windowBestStart = l
                windowBestEnd = r
            }

            mS[s[l]]--
            if mT[s[l]] > 0 && mS[s[l]] < mT[s[l]] {
                formed--
            }
            l++
        }
    }

    if windowBestEnd == -1 {
        return ""
    }
    return s[windowBestStart : windowBestEnd+1]
}
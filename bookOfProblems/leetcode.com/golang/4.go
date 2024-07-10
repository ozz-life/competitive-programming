func countSubarrays(nums []int, k int) int {
    currentAND := 0
    count := 0
	
    m := make(map[int]int)
    m[0] = 1
    
    for l, r := 0, 0; r < len(nums); r++ {
        currentAND &= nums[r]
        
        if currentAND == k {
            count += freq[currentAND]
        }
        
        for currentAND > k && l <= r {
            m[nums[l]]--
            currentAND &=^ nums[l]
            l++
        }
        
        freq[currentAND]++
    }
    
    return count
}
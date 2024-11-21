// https://leetcode.com/problems/longest-repeating-character-replacement/solutions/872604/99-javascript-solution-with-explanation/
// https://leetcode.com/problems/longest-repeating-character-replacement/solutions/2805777/longest-repeating-character-replacement/

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let count = {}
    let result = 0
    let maxFreq = 0

    for (let r = 0, l = 0; r < s.length; r++) {
        count[s[r]] = count[s[r]] ? count [s[r]] + 1 : 1;
        maxFreq = Math.max(maxFreq, count[s[r]])
        while (r - l + 1 - maxFreq > k) {
            count[s[l]]--
            l++
        }
        result = Math.max(result, r - l + 1)
    }
    return result    
};
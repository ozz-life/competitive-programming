s = "aaaaddddbbbbcccc" //Output: "abccbaabccba"
// s = "rat"//Output: "art"
// Pick the smallest character from s and append it to the result.
// Pick the smallest character from s which is greater than the last appended character to the result and append it.
// Repeat step 2 until you cannot pick more characters.
// Pick the largest character from s and append it to the result.
// Pick the largest character from s which is smaller than the last appended character to the result and append it.
// Repeat step 5 until you cannot pick more characters.
// Repeat the steps from 1 to 6 until you pick all characters from s.
/**
 * @param {string} s
 * @return {string}
 */
// var sortString = function (s) {
//     let sSort = s.split``.sort().join``
//     let result = []

//     // for (let i = 0; i < s.length; i++) {
//     //     result.push(sSort.shift())
//     //     result.push(sSort.shift())
//     // }

//     return sSort
// };

////////////////////////////////////////////////////////////////////////////////

// const sortString = s => {
//     s = s.split``.sort().join``
//     let result = ''
//     while (s.length) {
//         result += s.match(/([a-z])(?!\1)/gi).join``
//         s = s.replace(/([a-z])(?!\1)/gi, '')
//         result += (s.match(/([a-z])(?!\1)/gi) || []).reverse().join``
//         s = s.replace(/([a-z])(?!\1)/gi, '')
//     }
//     return result
// };

////////////////////////////////////////////////////////////////////////////////

// const sortString = s => {
//     let count = Array(26).fill(0), result = ''
//     for (const char of s) count[char.charCodeAt() - 97]++
//     let chars = [...new Set(s)].sort()
//     while (result.length < s.length) {
//         for (const char of chars) {
//             let idx = char.charCodeAt() - 97
//             if (count[idx]) {
//                 result += char
//                 count[idx]--
//             }
//         }
//         for (let i = chars.length - 1; i >= 0; i--) {
//             let char = chars[i], idx = char.charCodeAt() - 97
//             if (count[idx]) {
//                 result += char
//                 count[idx]--
//             }
//         }
//     }
//     return result
// }

////////////////////////////////////////////////////////////////////////////////

// const sortString = s => {
//     const cnts = new Array(26).fill(0);
//     for (let i = 0; i < s.length; i++) cnts[s.charCodeAt(i) - 97]++;
//     const res = new Array(Math.max(...cnts)).fill('');
//     for (let i = 0; i < 26; i++)
//         for (let j = 0; j < cnts[i]; j++)
//             if (0 === j % 2) res[j] += String.fromCharCode(i + 97);
//             else res[j] = String.fromCharCode(i + 97) + res[j];
//     return res.join('');
// };

////////////////////////////////////////////////////////////////////////////////

// creating an array with unique elements using Set and sort
const sortString = s => {
    const unique = [...new Set(s.split('').sort())];
    const map = new Map();
    // calculating the charac freq using Map
    for (let i = 0; i < s.length; i++) {
        map.set(s[i], map.get(s[i]) + 1 || 1);
    }

    let res = ''
    while (unique.length > 0) {
        // from left to right traverse
        for (let i = 0; i < unique.length; i++) {
            // check if we still got the freq for that char and decrement freq after we used it
            if (map.has(unique[i]) && map.get(unique[i]) > 0) {
                res += unique[i]
                map.set(unique[i], map.get(unique[i]) - 1);
            } else {
                // if we have exhausted that particular char's freq then delete from  array.As we are splicing, we decrement 'i' because after splice 'i' would be pointing the next char.
                unique.splice(i, 1);
                i--;
            }
        }
        // now reverse so that next time we are traversing from right to left
        unique.reverse()
    }
    return res;
}


console.log(sortString(s));

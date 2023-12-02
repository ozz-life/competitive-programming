s = "abacaba"

/**
 * @param {string} s
 * @return {number}
 */
//  var partitionString = function(s) {
//     let set = new Set()
//     let ans = 1

//     for (let c of s) {
//         if (set.has(c)) {
//             ans++
//             set.clear()
//         }
//         set.add(c)
//     }

//     return ans
// };

////////////////////////////////////////////////////////////////////////////////

//  var partitionString = function(s) {
//     let result = 1
//     let map = new Map()

//     for (let char of s) {
//         if(!map.has(char)) {
//             map.set(char, 1)
//         }
//         else {
//             result++
//             map = new Map()
//             map.set(char, 1)
//         }
//     }
//     // console.log(map)
//     return 0
//  }

////////////////////////////////////////////////////////////////////////////////

var partitionString = function (s) {
    let count = 1
    let subs = ''

    for (let char of s) {
        if (subs.includes(char)) {
            subs = char
            count += 1
        } else {
            subs += char
            console.log(subs)
        }
    }

}

console.log(partitionString(s));
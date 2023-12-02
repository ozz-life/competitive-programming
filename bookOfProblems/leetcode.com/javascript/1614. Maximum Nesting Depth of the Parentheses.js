/**
 * @param {string} s
 * @return {number}
 */
let s = "(1)+((2))+(((3)))"

// var maxDepth = function (s) {

//     let stack = []
//     let maxStackLength = 0

//     for (i = 0; i < s.length; i++) {
//         if (s[i] == "(") {
//             stack.push(s[i])
//             if (stack.length > maxStackLength)
//                 maxStackLength = stack.length;
//         }
//         if (s[i] == ")") {
//             stack.pop()
//         }

//     }

//     return maxStackLength
// };

////////////////////////////////////////////////////////////////////////////////

var maxDepth = function (s) {
    let depth = 0
    let maxDepth = 0

    for (const letter of s) {
        if (letter === '(') {
            depth++
        } else if (letter === ')') {
            depth--
        }

        if (depth > maxDepth) {
            maxDepth = depth
        }
    }

    return maxDepth
};

////////////////////////////////////////////////////////////////////////////////

// const maxDepth = (s) => {
//     let l = 0, r = 0
//     return s.split('').reduce((depth, c) => {
//         if (c === '(') l++
//         if (c === ')') r++
//         return Math.max(l - r, depth)
//     }, 0)
// }

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function (s) {
    let res = 0, temp = 0;

    for (let char of s) {
        if (char === '(') temp++;
        else if (char === ')') res = Math.max(res, temp--);
    }

    return res;
};

console.log(maxDepth(s));
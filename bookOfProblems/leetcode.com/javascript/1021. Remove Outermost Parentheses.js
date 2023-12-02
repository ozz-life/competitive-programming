s = "(()())(())(()(()))"

// var removeOuterParentheses = function (s) {
//     let stack = []
//     let result = []
//     for (let i = 0; i < s.length; i++) {
//         console.log(`stack: ${stack.length} || result: ${result}`)
//         if (s[i] === "(") {
//             if (stack.length !== 0) {
//                 result.push(s[i])
//             }
//             stack.push(0)
//         } else {
//             stack.pop()
//             if (stack.length !== 0) {
//                 result.push(s[i])
//             }
//         }
//     }
//     return result.join("")
// };

////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {string} s
//  * @return {string}
//  */
//  var removeOuterParentheses = function(s) {
//     let inner = '';
//     let depth = 0, start = 0;

//     for (let i = 0; i < s.length; i++) {
//         depth += s[i] === '(' ? 1 : -1; // increment depth on openning parenthesis, decrement on closing
//         if (depth === 0) { // it is true only when we closed outer parentheses
//             inner += s.substring(start + 1, i); // instead of adding chars one by one, we add the whole substring between start and current indicies
//             start = i + 1; // next oppenning parenthesis is at least next char
//         }
//         console.log(`${inner}`)
//     }

//     return inner;
// };

////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {string} s
//  * @return {string}
//  */
// var removeOuterParentheses = function (s) {
//     let counter = 0;
//     let result = '';

//     for (let i = 0; i < s.length; i++) {
//         if ((s[i] === '(' && counter++ !== 0) || (s[i] === ')' && --counter !== 0)) {
//             result += s[i];
//         }
//     }

//     return result;
// };

////////////////////////////////////////////////////////////////////////////////

// var removeOuterParentheses = function (s) {
//     let level = 0;
//     let res = "";

//     for (let i = 0; i < s.length; ++i) {

//         if (s[i - 1] === "(" && s[i] === "(") {
//             level++;
//         } else if (s[i - 1] === ")" && s[i] === ")") {
//             level--;
//         }

//         if (level > 0) {
//             res += s[i];
//         }
//     }

//     return res;
// };

////////////////////////////////////////////////////////////////////////////////

// const removeOuterParentheses = (s, res = '', depth = 0) =>
//     0 === s.length
//         ? res
//         : removeOuterParentheses(
//             s.slice(1),
//             res + (0 === depth || (1 === depth && ')' === s[0]) ? '' : s[0]),
//             depth + ('(' === s[0] ? 1 : -1),
//         );

////////////////////////////////////////////////////////////////////////////////

// const removeOuterParentheses = s => {
//     let result = '';
//     for (let [begin, end, depth] = [0, 1, 1]; end < s.length; end++) {
//       if (s[end] === '(') depth++;
//       else if (s[end] === ')') depth--;
//       if (0 === depth) {
//         result += s.slice(begin + 1, end);
//         begin = end + 1;
//       }
//     }
//     return result;
//   };

////////////////////////////////////////////////////////////////////////////////

// const removeOuterParentheses = s =>
//   Array.prototype.reduce
//     .call(
//       s,
//       ({ open, result }, paren, idx) => {
//         if (paren === '(' && open++) result.push(paren)
//         if (paren === ')' && --open) result.push(paren)
//         return { open, result }
//       },
//       { open: 0, result: [] }
//     )
//     .result.join('')

////////////////////////////////////////////////////////////////////////////////

console.log(removeOuterParentheses(s));
nums = [1, 2, 3, 2]

/**
 * @param {number[]} nums
 * @return {number}
 */
// var sumOfUnique = function (nums) {
//     let map = new Map()
//     for (let n of nums) {
//         map.set(n, map.get(n) + 1 || 1)
//     }

//     let set = new Set()
//     for (let [key, value] of map) {
//         if (value === 1) {
//             set.add(key)
//         }
//     }

//     return Array.from(set).reduce((accumulator, currentValue) => accumulator + currentValue, 0)
// };

/////////////////////////////////////////////////////////////////////////////////


var sumOfUnique = (nums => nums.filter((el, index, arr) => arr.indexOf(el) === arr.lastIndexOf(el)).reduce((a, b) => a + b, 0))

console.log(sumOfUnique(nums));
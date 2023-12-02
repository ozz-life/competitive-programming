nums = [5, 3, 6, 1, 12], original = 3

// /**
//  * @param {number[]} nums
//  * @param {number} original
//  * @return {number}
//  */
// var findFinalValue = function (nums, original) {
//     if (nums.includes(original)) {
//         original = 2 * original
//         return findFinalValue(nums, original)
//     }
//     else {
//         return original
//     }
// };

////////////////////////////////////////////////////////////////////////////////

// var findFinalValue = function (nums, original) {
//     let set = new Set(nums)
//     while (set.has(original)) original *= 2
//     return original
// };

////////////////////////////////////////////////////////////////////////////////

// var findFinalValue = function (nums, original) {
//     while (nums.includes(original)) {
//         original *= 2
//     }
//     return original
// };

////////////////////////////////////////////////////////////////////////////////

var findFinalValue = function(nums, original) {
    return nums.indexOf(original) > -1
            ? findFinalValue(nums, original * 2)
            : original;
};

////////////////////////////////////////////////////////////////////////////////

console.log(findFinalValue(nums, original));
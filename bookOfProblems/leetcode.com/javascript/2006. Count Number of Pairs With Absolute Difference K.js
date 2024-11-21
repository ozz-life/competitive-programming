// nums = [1,2,2,1], k = 1
nums = [3, 2, 1, 5, 4, 3], k = 2

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
// var countKDifference = function (nums, k) {
//     let count = 0
//     for (let i = 0; i < nums.length; i++) {
//         for (let j = i + 1; j < nums.length; j++) {
//             // console.log(`nums[i] = ${nums[i]} | nums[j] = ${nums[j]}`);
//             if (Math.abs(nums[i] - nums[j]) === k) {
//                 count++
//             }
//         }
//     }
//     return count
// };

////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {number}
//  */
//  var countKDifference = function(nums, k) {
//     const map = new Map();
//     let count = 0;

//     for (n of nums) {
//         map.set(n, map.get(n) +1 || 1)
//     }

//     console.log(map)
//     // go through array and calc the diff between target and current num
//     // if we find the diff in the map, we have a pair 
//     // we dont need to know the index numbers so we just add the occurance to the count
//     for (let i = 0; i < nums.length; i++) {
//         const diff = nums[i] - k;
//         console.log(`i: ${nums[i]} diff: ${diff}`)
//         if (map.has(diff)) {
//             console.log(`map has diff: ${diff}`)
//             count += map.get(diff);
//         }
//     }
//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

// const countKDifference = (nums, k) => {
//     return nums.map((n1) =>
//         nums.filter(n2 => n2 - n1 === k))
//             .flat().length
// }

////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {number}
//  */
//  var countKDifference = (nums, k) => nums.reduce((count, n, i) => nums.slice(i + 1).reduce((c, x) => Math.abs(x - n) === k ? ++c : c, count), 0);

////////////////////////////////////////////////////////////////////////////////

var countKDifference = function (nums, k) {
    let count = 0
    let map = new Map()

    for (n of nums) {
        map.set(n, map.get(n) + 1 || 1)
    }

    for (let i = 0; i < nums.length; i++) {
        let diff = nums[i] - k
        if(map.has(diff)) {
            count += map.get(diff)
        }
    }

    return count
}

console.log(countKDifference(nums, k));
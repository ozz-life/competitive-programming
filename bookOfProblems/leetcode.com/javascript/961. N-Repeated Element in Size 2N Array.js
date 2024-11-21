nums = [5, 1, 5, 2, 5, 3, 5, 4]

/**
 * @param {number[]} nums
 * @return {number}
 */
var repeatedNTimes = function (nums) {
    let map = new Map()
    for (const n of nums) {
        map.set(n, map.get(n) + 1 || 1)
    }

    for (let [key, value] of map) {
        if (value > 1) return key
    }
};
console.log(
repeatedNTimes(nums));
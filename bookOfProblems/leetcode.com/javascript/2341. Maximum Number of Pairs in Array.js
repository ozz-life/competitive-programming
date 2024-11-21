nums = [1, 3, 2, 1, 3, 2, 2]

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var numberOfPairs = function (nums) {
    let map = new Map()
    let pairCount = 0;
    let leftover = 0

    for (const n of nums) {
        map.set(n, map.get(n) + 1 || 1)
    }

    for (const [key, value] of map) {
        if (value % 2 == 0) {
            pairCount += value / 2
        }
        else {
            pairCount += Math.trunc(value / 2)
            leftover++
        }
    }

    return [pairCount, leftover]
};

console.log(numberOfPairs(nums));
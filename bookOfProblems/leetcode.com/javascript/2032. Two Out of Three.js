nums1 = [1, 1, 3, 2], nums2 = [2, 3], nums3 = [3]

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[]} nums3
 * @return {number[]}
 */
var twoOutOfThree = function (nums1, nums2, nums3) {
    let array = [...new Set(nums1), ...new Set(nums2), ...new Set(nums3)]
    let map = new Map()
    for (let n of array) {
        map.set(n, map.get(n) + 1 || 1)
    }
    let answer = []

    for (let [key, value] of map) {
        if (value >= 2) answer.push(key)
    }

    return answer
}


console.log(twoOutOfThree(nums1, nums2, nums3));
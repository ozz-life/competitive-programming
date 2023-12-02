arr = ["d", "b", "c", "b", "c", "a"], k = 2

/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    let map = mapCounter(arr)
    let result = []

    for (let [key, value] of map) {
        if (value == 1) {
            result.push(key)
        }
    }

    if (result.length < k) return ""
    else return result[k - 1]
};

const mapCounter = (nums) => {
    let map = new Map()
    for (const n of nums) map.set(n, map.get(n) + 1 || 1)
    return map
};

////////////////////////////////////////////////////////////////////////////////

function kthDistinct(arr: string[], k: number): string {
    return arr.filter((item, i, array) => array.indexOf(item) === array.lastIndexOf(item))[k - 1] ?? ''
};

console.log(kthDistinct(arr, k));
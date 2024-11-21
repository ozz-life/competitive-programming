nums = [3,2,3,2,2,2, 2]

// map быстрее, чем set
/**
 * @param {number[]} nums
 * @return {boolean}
 */
 var divideArray = function(nums) {
    let map = new Map()
    for (let n of nums) {
       map.has(n) ? map.delete(n) : map.set(n, true)
    }
    
    return map.size === 0
};

////////////////////////////////////////////////////////////////////////////////

var divideArray = function(nums) {
    let set = new Set()
    for (let n of nums) {
        set.has(n) ? set.delete(n) : set.add(n)
    }

    return set.size === 0
}

console.log(divideArray(nums));
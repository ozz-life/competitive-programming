// Brute force
// time O(N^2) space O(1)
var numIdenticalPairs = function (nums) {
    let count = 0

    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] === nums[j]) {
                count++
            }
        }
    }

    return count
};

var numIdenticalPairs = function (nums) {
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        for (let j = nums.length - 1; j > i; j--) {
            if (nums[i] === nums[j]) count++;
        }
    }

    return count;
};


////////////////////////////////////////////////////////////////////////////////

// time O(N) space O(N)
var numIdenticalPairs = function (nums) {
    const map = {}
    let count = 0

    for (const number of nums) {
        if (map[number]) {
            count += map[number];
            map[number] += 1;
        } else {
            map[number] = 1;
        }
    }
    return count
};

////////////////////////////////////////////////////////////////////////////////

var numIdenticalPairs = function (nums) {
    const map = {};
    let count = 0;
    nums.forEach(num => {
        if (map[num]) {
            count += map[num];
            map[num]++;
        } else {
            map[num] = 1;
        }
    })
    return count;
};


////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function (nums) {
    let count = 0;
    let map = new Map();
    nums.forEach(num => {
        if (!map.has(num)) map.set(num, 1);
        else {
            let currentCount = map.get(num);
            count += currentCount;
            map.set(num, currentCount + 1);
        }
    })
    return count;
};

////////////////////////////////////////////////////////////////////////////////

var numIdenticalPairs = function (nums) {
    let map = new Map();
    for (const n of nums) {
        map.set(n, map.get(n) + 1 || 1);
    }

    let result = 0

    //2nd line, use the n(n-1)/2 to get how many combinations are possible.
    for (const [key, value] of map) {
        result += parseInt((map.get(key) * (map.get(key) - 1)) / 2)
        console.log(result)
    }

    return result
}
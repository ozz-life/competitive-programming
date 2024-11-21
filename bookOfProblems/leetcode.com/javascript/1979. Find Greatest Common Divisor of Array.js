nums = [2,5,6,9,10]

/**
 * @param {number[]} nums
 * @return {number}
 */
var findGCD = function(nums) {
    let min = nums.sort((a, b) => a - b)[0]
    let max = nums.sort((a, b) => b - a)[0]

    return gcd(min, max)
};

function gcd(a, b) {
    a = Math.abs(a);
    b = Math.abs(b);
    if (b > a) { var temp = a; a = b; b = temp; }
    while (true) {
        if (b == 0) return a;
        a %= b;
        if (a == 0) return b;
        b %= a;
    }
}

console.log(findGCD(nums));
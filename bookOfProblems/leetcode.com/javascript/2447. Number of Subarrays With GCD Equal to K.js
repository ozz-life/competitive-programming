nums = [5], k = 1

var subarrayGCD = function (nums, k) {

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

    let n = nums.length;
    let counter = 0;

    for (let left = 0; left < n; left++) {
        let currentGCD = nums[left];
        for (let right = left; right < n; right++) {
            currentGCD = gcd(currentGCD, nums[right]);
            counter += (currentGCD == k) ? 1 : 0;
        }
    }

    return counter;
}

console.log(subarrayGCD(nums, k));

function lcm(a, b) {
    return a / gcd(a,b) * b
}

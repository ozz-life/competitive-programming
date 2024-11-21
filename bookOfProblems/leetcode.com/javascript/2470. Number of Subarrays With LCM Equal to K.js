nums = [3, 6, 2, 7, 1], k = 6

var subarrayLCM = function (nums, k) {

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

    function lcm(a, b) {
        return a / gcd(a, b) * b
    }

    let n = nums.length;
    let counter = 0;

    for (let left = 0; left < n; left++) {
        let currentLCM = nums[left];
        for (let right = left; right < n; right++) {
            currentLCM = lcm(currentLCM, nums[right]);
            counter += (currentLCM == k) ? 1 : 0;
            if (currentLCM > k) break;
        }
    }

    return counter;
}

console.log(subarrayLCM(nums, k));
let nums = [1, 2, 2]

const containsDuplicate = nums => {
    let seen = new Map();
    for (let num = 0; num < nums.length; num++) {
        if (seen.has(nums[num])) return true;
        seen.set(nums[num]);
    }
    return false;
};

console.log(containsDuplicate(nums));

////////////////////////////////////////////////////////////////////////////////

var containsDuplicate = function(nums) {
    return new Set(nums).size !== nums.length
};

let nums = [8, 1, 2, 2, 3]
// Output: [4,0,1,1,3]
// Explanation: 
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1). 
// For nums[3]=2 there exist one smaller number than it (1). 
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function (nums) {
    const sorted = [...nums].sort((a, b) => a - b);
    return nums.map((value) => sorted.indexOf(value));
};

////////////////////////////////////////////////////////////////////////////////

var smallerNumbersThanCurrent = function (nums) {
    // return nums.map(n => nums.reduce((a, b) => a + (n > b ? 1 : 0), 0))
    // Could even shorten it to a + (n > b), since true = 1 and false = 0
    return nums.map(n => nums.reduce((a, b) => a + (n > b), 0))
};
// Could even shorten it to a + (n > b), since true = 1 and false = 0

////////////////////////////////////////////////////////////////////////////////

function smallerNumbersThanCurrent(nums) {
    const sorted = Array.from(nums).sort((n1, n2) => n2 - n1);
    const map = new Map(sorted.map((num, index) => [num, nums.length - index - 1]));
    return nums.map(num => map.get(num));
}


////////////////////////////////////////////////////////////////////////////////

var smallerNumbersThanCurrent = function (nums) {
    let hash = new Map();
    let sorted = nums.slice().sort((a, b) => a - b);
    sorted.forEach((number, idx) => hash.has(number) ? null : hash.set(number, idx));
    return nums.map(x => hash.get(x));
};

////////////////////////////////////////////////////////////////////////////////

console.log(smallerNumbersThanCurrent(nums));
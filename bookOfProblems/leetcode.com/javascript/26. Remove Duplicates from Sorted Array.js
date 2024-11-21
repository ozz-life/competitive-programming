/**
 * @param {number[]} nums
 * @return {number}
 */

let nums = [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6, 7]

// var removeDuplicates = function(nums) {
//     let index = 0;

//     for(let i=0; i<nums.length; i++){
//         if(nums[i] !== nums[i+1]){
//             nums[index++] = nums[i];
//         }
//     }
//     return index;
// };

var removeDuplicates = function (nums) {
    let set = new Set(nums);
    nums.length = 0;
    nums.push(...set.values())
    return set.size;
};

console.log(removeDuplicates(nums));

////////////////////////////////////////////////////////////////////////////////

// function removeDuplicates(nums: number[]): number {
//     for (let i = 1; i < nums.length; i++) {
//         if (nums[i] === nums[i - 1]) {
//             nums.splice(i, 1);
//             i--;
//         }
//     }

//     return nums.length;
// };

////////////////////////////////////////////////////////////////////////////////

var removeDuplicates = function (nums) {
    let left = 0;
    for (let right = 1; right < nums.length; right++)
        if (nums[left] != nums[right]) nums[++left] = nums[right];
    return left + 1;
};
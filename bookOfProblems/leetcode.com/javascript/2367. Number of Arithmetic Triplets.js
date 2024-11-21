nums = [0, 1, 4, 6, 7, 10], diff = 3

// var arithmeticTriplets = function (nums, diff) {

//     let hash = new Map();
//     let count = 0;

//     for (let i = 0; i < nums.length; i++) {
//         let temp = nums[i] - diff;

//         if (hash.has(temp) && hash.has(temp - diff)) {
//             count++;
//         }
//         hash.set(nums[i], "Hard choices easy life, Easy choices hard life.");
//     }

//     return count;
// };

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

var arithmeticTriplets = function (nums, diff) {
    let count = 0;
    console.log(nums, diff)
    for (let i = 0; i < nums.length ; i++) {
        let left = i;
        let right = nums.length - 1;
        console.log(`FOR   | left: ${left}, right: ${right}`)
        while (left < right) {
            let first = nums[left] - nums[i];
            let second = nums[right] - nums[left]
            console.log(`WHILE | first: ${first}; second: ${second}`)
            if (first === diff && second === diff) {
                count++;
                left++;
                right--;
                console.log(`WHILE | left: ${left}; right: ${right}; count: ${count}`)
            }
            else if (first < diff) left++;
            else right--;
        }
    }
    return count;
};

////////////////////////////////////////////////////////////////////////////////

// var arithmeticTriplets = function (nums, diff) {
//     let result = []
//     for (let i = 0; i < nums.length; i++) {
//         for (let j = i + 1; j < nums.length; j++) {
//             for (let k = j + 1; k < nums.length; k++) {
//                 if ((nums[i] + diff) == nums[j] && nums[j] + diff == nums[k]) {
//                     result.push([nums[i], nums[j], nums[k]])
//                 }
//             }
//         }
//     }
//     return result.length
// }

////////////////////////////////////////////////////////////////////////////////

// var arithmeticTriplets = function (nums, diff) {
//     let result = 0;
//     let set = new Set(nums)

//     for (let i = 0; i < nums.length; i++) {
//         if (set.has(nums[i] + diff) && set.has(nums[i] + diff + diff)) {
//             result++
//         }
//     }

//     return result
// }


console.log(arithmeticTriplets(nums, diff)
);

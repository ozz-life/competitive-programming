nums = [1, 5, 0, 3, 5]
// nums = [0, 0, 0, 0, 3]

/**
 * @param {number[]} nums
 * @return {number}
 */

var minimumOperations = function (nums) {
    let count = 0

    function recurse(nums) {
        const someIsNotZero = nums.some(item => item !== 0);
        const isAllZero = !someIsNotZero;
    
        if (isAllZero) {
            return count;
        } else {

            let min = minimumNumberExcludingZero(nums)
            let array = []

            for (let j = 0; j < nums.length; j++) {
                if ((nums[j] - min) < 0) array.push(0)
                else array.push(nums[j] - min)
                console.log(`min: ${min} | array: ${array}`)
            }
            count++

            return recurse(array)
        }
    }

    recurse(nums)
    return count
};


function minimumNumberExcludingZero(nums) {
    return Math.min(...nums.filter(Boolean))
}

////////////////////////////////////////////////////////////////////////////////

// const minimumOperations = (nums) => {
//     let result = 0;

//     // while (!allZero(nums)) {
//         while(!nums.every(isEqualZero)) {
//         let min = Math.min(...nums.filter(x => x > 0)); // greedy: get min value
//         console.log(`min: ` + min)
//         for (let i = 0; i < nums.length; i++) { // minus min value for all non-zero values
//             if (nums[i] > 0) nums[i] -= min;
//         }
//         result++;
//     }

//     return result;
// };

// const allZero = (a) => a.every(x => x == 0);
// ///
// function isEqualZero(element, index, array) {
//     return element == 0;
// }

////////////////////////////////////////////////////////////////////////////////

// var minimumOperations = function(nums) {
//     let count = 0;

//     let filtered = nums.filter(num => num !== 0);

//     while (filtered.length) {
//         let min = Math.min(...filtered);
//         let newArr = filtered.map(num => num - min);
//         console.log(newArr)
//         filtered = newArr.filter(num => num !== 0);
//         count++;
//     }

//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[]} nums
 * @return {number}
 */
//  var minimumOperations = function(nums) {
//     var count = 0 

//     const recurse = (nums) => {
//         // Remove all zeroes so it doesnt show as the minimum 
//         nums = nums.filter((num) => num != 0)
//         // if (nums.length === 0) {return; }
//         if (nums.length === 0) return

//         // To get the lowest
//         nums.sort((a, b) => a-b)
//         console.log(nums)

//         var lowest = nums[0] 

//         for (var i = 0  ;i < nums.length; i++) {
//             nums[i] = nums[i] - lowest
//         }
//         count++
//         recurse(nums)
//     }

//     recurse(nums)
//     return count
// };

console.log(minimumOperations(nums));
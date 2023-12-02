// https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack

// nums1 = [4,1,2], nums2 = [1,3,4,2]
// nums1 = [2,4], nums2 = [1,2,3,4]
nums1 = [1, 3, 5, 2, 4], nums2 = [6, 5, 4, 3, 2, 1, 7]

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
// var nextGreaterElement = function (nums1, nums2) {
//     let res = [];
//     for (let i = 0; i < nums1.length; i++) {
//         let found = false, gn = -1; //set variables found to check if we have the desired num and the next greatest number
//         for (let j = 0; j < nums2.length; j++) {
//             if (nums1[i] === nums2[j]) found = true; //make found as true once we have discovred its location in the nums2 array
//             if (found && nums1[i] < nums2[j]) { //after we have the number check if the next number is greater than the desired number
//                 gn = nums2[j];  //asssign it to gn and break the loop
//                 break;
//             }
//         }
//         res.push(gn) //push gn and continue to do the same for rest of the elems
//     }
//     return res
// };

////////////////////////////////////////////////////////////////////////////////

// var nextGreaterElement = function(nums1, nums2) {
//     const map = {}
//     const output = []

// 	// loop on the nums2 and map its element as keys and it index as values
//     for (let k = 0; k < nums2.length; k++) {

// 	    // if current iteration element is their in map then continue
//         if (map.hasOwnProperty(nums2[k])) {
//             continue

// 		// else assign key as element and index as value
//         } else {
//             map[nums2[k]] = k
//         }    
//     } 

// 	// nested for loop to check the first greater value with the current value
//     for (let i = 0; i < nums1.length; i++) { 

// 		// get index of current iteration element of nums1 array i.e {nums1[i]} from the map
//         let nums1EleIndexInNums2Array = map[nums1[i]]

//         let currMaxVal = -1

// 		// for loop to check all the elements in nums2 array 
//         for (let j = nums1EleIndexInNums2Array; j < nums2.length; j++) {
//             if (nums1[i] < nums2[j]) {
//                 currMaxVal = nums2[j]
//                 break 
//             }    
//         }
//         output.push(currMaxVal)
//     } 
//     return output
// };

////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {number[]} nums1
//  * @param {number[]} nums2
//  * @return {number[]}
//  */
// var nextGreaterElement = function (nums1, nums2) {
//     return nums1.map(n => {
//         let next = nums2.indexOf(n) + 1;
//         while (next < nums2.length && nums2[next] < n) {
//             next++;
//         }
//         return next >= nums2.length ? -1 : nums2[next]
//     })
// };

////////////////////////////////////////////////////////////////////////////////

// var nextGreaterElement = function(findNums, nums) {
//     return findNums.map(n => {
//         let found = nums.indexOf(n);

//         if (found !== -1) {
//             // find the next greater element's index
//             while (nums[++found] < n);
//             // -1 if not found
//             if (found >= nums.length) found = -1;
//             else found = nums[found];
//         }

//         return found;
//     });
// };

////////////////////////////////////////////////////////////////////////////////

/*
1. Iterate through nums2 and for every number find the next greater number and record it
to a Hash Table.
2. Iterate through nums1 and for each number get the next greater number from Hash table.

For step 1, we can find the next greater number for each element using Stack.

Iteration from the start of array:
- For each element, we want to check if there is smaller element in stack. 
- Hence, we keep popping from stack until we find a number greater than or equal to current element.
For all popped numbers, current element is their Next Greater Number. Hence, we record them to a Hash Table
with current element as their NGN.
- Then, we push current element into stack so that we can find the NGN for current number (or not if there isn't one).
*/
// var nextGreaterElement = function (nums1, nums2) {
//     if (nums1 === null || nums2 === null || nums1.length === 0 || nums2.length === 0) {
//         return [];
//     }
//     let m = new Map();
//     let stack = [];
//     for (let i = 0; i < nums2.length; i++) {
//         while (stack.length > 0 && nums2[i] > stack[stack.length - 1]) {
//             // nums2[i] is the Next Greater Number of popped element
//             m.set(stack.pop(), nums2[i]);
//         }
//         stack.push(nums2[i]);
//     }

//     return nums1.map(num => m.get(num) || -1);
//     // T.C: O(M + N), M = length of nums1, N = length of nums2
//     // S.C: O(M + N)
// };

////////////////////////////////////////////////////////////////////////////////

/*
1. Iterate through nums2 and for every number find the next greater number and record it
to a Hash Table.
2. Iterate through nums1 and for each number get the next greater number from Hash table.

For step 1, we can find the next greater number for each element using Stack.

Iteration from the back of array:
- For each element, we want to check if there is greater element in stack. 
- Hence, we keep popping from stack until we find the greater number or stack gets empty.
- Then, we push current element into stack so that our next element can find its NGN (Next Greater Number).
*/
var nextGreaterElement = function (nums1, nums2) {
    if (nums1 === null || nums2 === null || nums1.length === 0 || nums2.length === 0) {
        return [];
    }
    let m = new Map();
    let stack = [];
    for (let i = nums2.length - 1; i >= 0; i--) {
        while (stack.length > 0 && nums2[i] >= stack[stack.length - 1]) {
            stack.pop();
        }
        if (stack.length > 0) {
            m.set(nums2[i], stack[stack.length - 1]);
        }
        stack.push(nums2[i]);
    }
    for (let i = 0; i < nums1.length; i++) {
        nums1[i] = m.get(nums1[i]) || -1;
    }
    return nums1;
    // T.C: O(M + N), M = length of nums1, N = length of nums2
    // S.C: O(N)
};


console.log(nextGreaterElement(nums1, nums2));
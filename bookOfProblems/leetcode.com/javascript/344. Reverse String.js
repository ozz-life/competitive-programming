let s = "abcd"

// var reverseString = function(s) {
//     for (let i = 0, j = s.length - 1; i < j;) {
//         [s[i], s[j]] = [s[j], s[i]];
//         i++;
//         j--;
//     }
//     return s;
// };

////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {character[]} s
//  * @return {void} Do not return anything, modify s in-place instead.
//  */
// var reverseString = function (s) {
//     let left = 0; // it will start at index 1
//     let right = s.length - 1 // it will be the last index of array
//     while (left < right) {
//         // We will swap the values 
//         // We will keep swaping untill left is less then right
//         let temp = s[left]
//         s[left] = s[right]
//         s[right] = temp
//         left++ // increment left to move forward
//         right-- // decrement right so we can reach the center/mid
//     }

//     return s
// };
////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {character[]} s
//  * @return {void} Do not return anything, modify s in-place instead.
//  */
// var reverseString = function (s) {
//     let i = 0, j = s.length - 1;
//     while (i < j) {
//         // ES6 destructuring assignment
//         [s[i], s[j]] = [s[j], s[i]];
//         i++;
//         j--;
//     }
//     return s
// };
////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {character[]} s
//  * @return {void} Do not return anything, modify s in-place instead.
//  */
//  var reverseString = (s) => {
//     for (let [a, b] = [0, s.length - 1]; a < b; a++, b--) {
//         [s[a], s[b]] = [s[b], s[a]]
//     }
//     return s
// };
////////////////////////////////////////////////////////////////////////////////

/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
 var reverseString = s => {
    reverse(0, s.length - 1);

    /**
     * @param {character[]} s
     * @return {void} Do not return anything, modify s in-place instead.
     */
    function reverse(i, j) {
        if (i >= j) return;
        [s[i], s[j]] = [s[j], s[i]];
        reverse(i + 1, j - 1);
    }
};
////////////////////////////////////////////////////////////////////////////////
console.log(reverseString(s));
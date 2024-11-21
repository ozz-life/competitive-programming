let jewels = "aA"
let stones = "aAAAijiji"

/*  BruteForce
 *  Time complexity = O(n*m)
 *  O(n*m), where N is the length of the jewels string and M is the length of the stones string. Thus the time complexity is polynomial.
 *  Space complexity = O(1)
 *  O(1), since we do not use any array or vector. We are using only constant space. Thus the brute approach has constant space complexity.
 ******************************************************************************/
// var numJewelsInStones = function (jewels, stones) {

//     let result = 0
//     for (let i = 0; i < stones.length; i++) {
//         console.log(`first cicle i:${i} stones: ${stones[i]}`)
//         for (let j = 0; j < jewels.length; j++) {
//             console.log(`second cicle j:${j} jewels: ${jewels[j]}`)
//             if (stones[i] == jewels[j])
//                 result++
//         }
//     }
//     return result
// };

// var numJewelsInStones = function(jewels, stones) {
//     let count=0;
//     for(let i in jewels){
//         console.log(`first cicle i:${i} jewels: ${stones[i]}`)
//         for(let j in stones){
//             console.log(`second cicle j:${j} stones: ${stones[j]}`)
//             if(jewels[i]==stones[j]) count=count+1
//         }
//     }
//     return count;
// };

// console.log(numJewelsInStones(jewels, stones));


// console.log(numJewelsInStones(jewels, stones));

/*  BruteForce
 *  Time complexity = O(n+m)
 *  O(n+m), where n and m is the size of jewels and stones string. The optimization is achieved because we utilized HashSets. Now, the time complexity has been reduced to linear.
 *  Space complexity = O(n)
 *  O(n), since we store the characters from the jewels string. The space complexity is dependent on the jewels string size.
 ******************************************************************************/

// var numJewelsInStones = function (jewels, stones) {
//     let jewelsPattern = new Set(jewels)

//     let result = 0
//     for (let i = 0; i < stones.length; i++) {
//         if (jewelsPattern.has(stones[i])) {
//             result++
//         }
//     }
//     return result
// };

// console.log(numJewelsInStones(jewels, stones));

////////////////////////////////////////////////////////////////////////////////

var numJewelsInStones = function (jewels, stones) {
    return [...stones].reduce(
        (acc, cur) => (jewels.includes(cur) ? ++acc : acc),
        0
    );
};

////////////////////////////////////////////////////////////////////////////////
const numJewelsInStones = (J, S) => S.split('').filter(char => J.indexOf(char) !== -1).length;
// https://leetcode.com/problems/jewels-and-stones/discuss/113563/Two-line-JavaScript-solution
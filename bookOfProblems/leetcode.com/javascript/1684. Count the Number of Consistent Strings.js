allowed = "cad", words = ["cc", "acd", "b", "ba", "bac", "bad", "ac", "d"]

/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */

// const countConsistentStrings = (allowed, words) => {
//     let set = new Set(allowed)
//     return words.reduce((a, w) => {
//         console.log(`a (previousValue): ${a} | w (currentValue): ${w}`)
//         return w.split('').every(el => set.has(el)) ? ++a : a
//     }, 0)
// }

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {
//     const re = new RegExp(`^[${allowed}]+$`);
//     let count = 0

//     words.forEach(word => {
//         if (word.match(re)) count++
//     })

//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {
//     let count = 0;
//     for (let item of words) {
//         if (item.split('').every(word => allowed.includes(word))) {
//             count++;
//         }
//     }
//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {
//     let map = {};
//     for (let i of allowed) {
//         map[i] = (map[i] || 0) + 1;
//     }
//     console.log(map)

//     let ans = words.length;

//     for (let i of words) {
//         let flag = 0;

//         for (let j of i) {

//             if (!map[j]) {
//                 flag = 1;
//                 ans -= 1;
//             }

//             if (flag) {
//                 break;
//             }
//         }
//     }

//     return ans;
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {
//     let set = new Set(allowed)
//     // console.log(set)
//     let count = 0

//     words.forEach(word => {
//         let w = new Set(word)
//         // console.log(w)
//         let test = new Set([...set, ...w])
//         console.log(test)
//         if (set.size === test.size) {
//             count++
//         }
//     })

//     return count
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {

//     let count = 0;

//     for (let i = 0; i < words.length; i++) {

//         let word = words[i];
//         let flag = true;

//         for (let j = 0; j < word.length; j++) {
//             let letter = word[j];
//             if (allowed.indexOf(letter) == -1) flag = false;
//         }

//         if (flag) count++;
//     }

//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

// const countConsistentStrings = (allowed, words) =>
//     words.filter(
//         word => [...word].every(letter => allowed.includes(letter))
//     ).length

////////////////////////////////////////////////////////////////////////////////

// const countConsistentStrings = function (allowed, words) {
//     let count = 0

//     for (const word of words) {
//         for (const letter of word) {
//             if (!allowed.includes(letter)) {
//                 count--
//                 break
//             }
//         }
//         count++
//     }

//     return count
// };

////////////////////////////////////////////////////////////////////////////////

var countConsistentStrings = function (allowed, words) {
    allowed = new Set(allowed);

    return words.reduce((acc, curr) => {
        console.log(`acc: ${acc} | curr: ${curr}`)
        return [...curr].every(str => allowed.has(str)) ? acc += 1 : acc;
    }, 0);
};

////////////////////////////////////////////////////////////////////////////////

// const countConsistentStrings = function (allowed, words) {
//     const regex = new RegExp(`^[${allowed}]+$`);
//     return words.filter(word => regex.test(word)).length;
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {
//     const chars = new Set(allowed);
//     console.log(chars)

//     return words
//         .filter((word) => {
//             for (const char of word) {
//                 if (!chars.has(char)) {
//                     return false;
//                 }
//             }

//             return true;
//         })
//         .length;
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function (allowed, words) {

//     // Add allowed letters to a set
//     let allowedSet = new Set();
//     for (let i = 0; i < allowed.length; i++) {
//         allowedSet.add(allowed[i]);
//     }
//     // console.log(allowedSet)

//     let consistentCount = 0;

//     // Check each word
//     for (let i = 0; i < words.length; i++) {

//         let word = words[i];
//         let isValid = true;

//         // Check the letters and if any are not in the Set, break and set word as invalid
//         for (let j = 0; j < word.length; j++) {
//             if (!allowedSet.has(word[j])) {
//                 isValid = false;
//                 break;
//             }
//         }

//         // Update count if the word is valid
//         if (isValid)
//             consistentCount++;

//     }

//     return consistentCount;
// };

////////////////////////////////////////////////////////////////////////////////

// Solution 2 (fast):

// var countConsistentStrings = function (allowed, words) {
//     allowed = new Set(allowed); // make Set from allowed so we can get chars with O(1)
//     let wrongWords = 0; // this will hold the number of wrong words (words that are not consistent)
//     for (let word of words) {
//         for (let char of word) {
//             if (!allowed.has(char)) { // if char of a word is not in allowed then it's wrong word
//                 wrongWords++; // increase wrong word
//                 break; // we can break eralier once we find the first not allowed char
//             };
//         };
//     }

//     return words.length - wrongWords; // get the number of consistent words by substracting the number of non-consistent words from the all words
// };


////////////////////////////////////////////////////////////////////////////////
// FUNCTIONAL PROGRAMMING
// /**
//  * @param {string} allowed
//  * @param {string[]} words
//  * @return {number}
//  */
// var countConsistentStrings = function (allowed, words) {
//     return words.reduce((count, s) => {
//         return [...new Set([...s])].every(ch => allowed.includes(ch)) ? count + 1 : count;
//     }, 0)
// };

// ////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function(allowed, words) {
//     set = new Set(allowed);

//     count = 0

//     for (let i = 0; i < words.length; i++) {
//         word = words[i]
//         consistent = true

//         for (let j = 0; j < word.length; j++) {
//             char = word[j]

//             if (!set.has(char)) {
//                 consistent = false
//                 break;
//             }
//         }

//         if (consistent) {
//             count += 1
//         }
//     }

//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

// var countConsistentStrings = function(allowed, words) {
//     let numberofconsistentwords = 0;
//     words.forEach(word => {
//         let isConsistent = true;
//         for(let i = 0 ; i < word.length;i++){
//             const character = word[i];
//           if(isConsistent !== false && allowed.indexOf(character) === -1){
//                 isConsistent = false;
//             }  
//         }
//         if(isConsistent){
//             numberofconsistentwords++;
//         }
//     })
//     return numberofconsistentwords;
// };

// ////////////////////////////////////////////////////////////////////////////////
// // Faster, than 99%
// /**
//  * @param {string} allowed
//  * @param {string[]} words
//  * @return {number}
//  */
//  var countConsistentStrings = function(allowed, words) {
//     let ans = 0;
//     const map = new Int32Array(26);
//     allowed.split('').forEach(a=>++map[a.charCodeAt(0)-97]);
//     for(let i=0;i<words.length;++i){
//         let valid = true;
//         for(let j=0;j<words[i].length;++j){
//             if(map[words[i].charCodeAt(j)-97]===0){
//                 valid = false;
//                 break;
//             }
//         }
//         if(valid) ++ans;
//     }
//     return ans;
// };
////////////////////////////////////////////////////////////////////////////////

console.log(countConsistentStrings(allowed, words));
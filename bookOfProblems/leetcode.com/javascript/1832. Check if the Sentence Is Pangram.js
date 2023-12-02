/**
 * @param {string} sentence
 * @return {boolean}
 */
//  let sentence = "thequickbrownfoxjumpsoverthelazydog"
let sentence = "leetcode"

// var checkIfPangram = function (sentence) {
//     return (sentence) => [...new Set(sentence)].length === 26;
// };

var checkIfPangram = function (sentence) {
    let result = [...new Set(sentence)]
    return result.length === 26;
};

////////////////////////////////////////////////////////////////////////////////

// var checkIfPangram = function(sentence) {
//     let s = new Set()
//     for(let i=0; i<sentence.length; i++){
//         s.add(sentence[i])
//     }
    
//     return s.size === 26;
// };

////////////////////////////////////////////////////////////////////////////////

console.log(checkIfPangram(sentence))
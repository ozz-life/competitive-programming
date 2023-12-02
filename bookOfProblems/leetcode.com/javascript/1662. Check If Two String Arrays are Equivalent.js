/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
let word1 = ["abc", "d", "defg"]
let word2 = ["abcddefg"]

var arrayStringsAreEqual = function (word1, word2) {
    word1 = word1.join('')
    word2 = word2.join('')
    if (word1 == word2) return true
    else return false
};

////////////////////////////////////////////////////////////////////////////////

var arrayStringsAreEqual = function (word1, word2) {
    return (word1.join("") == word2.join(""))
};

////////////////////////////////////////////////////////////////////////////////

const arrayStringsAreEqual = (word1, word2) => {
    const str1 = word1.reduce((acc, cv) => acc + cv, '')
    const str2 = word2.reduce((acc, cv) => acc + cv, '')
  
    return str1 === str2;
  }

console.log(arrayStringsAreEqual(word1, word2));
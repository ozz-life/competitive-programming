let word1 = "ab"
let word2 = "pqrs"

/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function (word1, word2) {

    let l = Math.max(word1.length, word2.length)

    let newWord = ''
    for (let i = 0; i < l; i++) {
        newWord += (word1[i] ?? '') + (word2[i] ?? '')
    }


    return newWord
};
console.log(
mergeAlternately(word1, word2));
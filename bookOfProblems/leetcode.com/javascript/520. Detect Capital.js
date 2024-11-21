let word = 'Ug'

/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {

    let firstLetterCapitalize = word.charAt(0).toUpperCase()
    let wordRemainder = word.slice(1).toLowerCase()

    if (word == word.toLowerCase()) return true
    if (word == word.toUpperCase()) return true
    if (word == firstLetterCapitalize + wordRemainder) return true
    else return false
    
};

console.log(detectCapitalUse(word));
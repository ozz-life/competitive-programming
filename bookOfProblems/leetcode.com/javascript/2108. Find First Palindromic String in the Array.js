/**
 * @param {string[]} words
 * @return {string}
 */
var firstPalindrome = function (words) {
    for (word of words) {
        if (word == word.split('').reverse().join('')) return word
    }
    return ''
};

////////////////////////////////////////////////////////////////////////////////

const firstPalindrome = (words) => {
    let result = ""
    let left = 0
    let right = words.length - 1

    while (left <= right + 1) {
        if (words[left] === words[left].split('').reverse().join('')) {
            return words[left]
        }
        if (words[right] === words[right].split('').reverse().join('')) {
            result = words[right]
        }
        left++
        right--
    }

    return result
}

////////////////////////////////////////////////////////////////////////////////

var firstPalindrome = function (words) {
    return words.filter(x => x === x.split('').reverse().join(''))[0] || ""
};


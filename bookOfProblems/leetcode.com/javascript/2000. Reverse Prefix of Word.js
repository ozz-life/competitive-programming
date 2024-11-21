word = "xyxzxe", ch = "z"
/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function (word, ch) {

    let chIndex = word.indexOf(ch)
    let prefix = word.slice(0, chIndex + 1).split('').reverse().join('')
    let postfix = word.slice(chIndex + 1)

    return prefix.concat(postfix)
};

console.log(reversePrefix(word, ch));

////////////////////////////////////////////////////////////////////////////////

var reversePrefix = function (word, ch) {
    const index = word.indexOf(ch);
    return word.substr(0, index + 1).split('').reverse().join('') + word.substr(index + 1);
};
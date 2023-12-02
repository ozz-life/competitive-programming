s = "foobar", letter = "o"

/**
 * @param {string} s
 * @param {character} letter
 * @return {number}
 */
var percentageLetter = function (s, letter) {
    let map = new Map()

    for (let char of s) {
        map.set(char, map.get(char) + 1 || 1)
    }

    let allCharsQuantity = 0
    for (let [key, value] of map) {
        allCharsQuantity += value
    }

    let percentage = 0
    percentage = Math.floor(map.get(letter) / s.length * 100)
    percentage = percentage ? percentage : 0;
    return percentage
};

console.log(percentageLetter(s, letter));
s = "abccbaacz"

/**
 * @param {string} s
 * @return {character}
 */
var repeatedCharacter = function (s) {

    let set = new Set()
    for (let i = 0; i < s.length; i ++) {
        let currentChar = s[i]
        if (set.has(currentChar)) return currentChar
        set.add(currentChar)
    }
};

////////////////////////////////////////////////////////////////////////////////

var repeatedCharacter = function (s) {
    for (let i = 0; i < s.length; i++) {
        console.log(`i = ${i}`)
        for (let j = 0; j < i; j++) {
            console.log(`s[i] = ${s[i]} | s[j] = ${s[j]}`)
            if (s[i] === s[j]) return s[i]
        }
    }

}

console.log(repeatedCharacter(s));
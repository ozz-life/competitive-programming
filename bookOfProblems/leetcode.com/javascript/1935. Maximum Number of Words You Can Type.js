text = "leet code", brokenLetters = "lt"

/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */

var canBeTypedWords = function (text, brokenLetters) {
    let lettersArr = brokenLetters.split('')
    let checker = word => !lettersArr.some(letter => word.includes(letter))
    return text.split(' ').filter(checker)
}

////////////////////////////////////////////////////////////////////////////////

function canBeTypedWords(text, brokenLetters) {
    const uniqueBrokenLetters = new Set(brokenLetters.split(''));
    const words = text.split(' ');
    let total = 0;

    outer: for (let i = 0; i < words.length; i++) {
        const uniqueWordLetters = [...new Set(words[i])];

        for (let j = 0; j < uniqueWordLetters.length; j++) {
            if (uniqueBrokenLetters.has(uniqueWordLetters[j])) {
                continue outer;
            }
        }

        total++;
    }

    return total;
};

////////////////////////////////////////////////////////////////////////////////

const canBeTypedWords = (text, bro) => {
    let arr = text.split(' ');
    let s = new Set();
    for (const k of bro) s.add(k);
    let cnt = 0;
    for (const key of arr) {
        let flag = 0;
        for (const one of key) { if (s.has(one)) { flag = 1; break; } }
        if (!flag) cnt++;
    }
    return cnt;
};


console.log(canBeTypedWords(text, brokenLetters));
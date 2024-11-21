let s = 'teetbook'
/** 
* @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function (s) {
    var middle = Math.floor(s.length / 2);
    let halveA = s.slice(0, middle).toLowerCase()
    let halveB = s.slice(middle, s.length).toLowerCase()
    let vowels = new Set(['a', 'e', 'i', 'o', 'u'])
    let halveAcnt = 0
    let halveBcnt = 0

    for (let char of halveA) {
        if (vowels.has(char)) halveAcnt++
    }
    for (let char of halveB) {
        if (vowels.has(char)) halveBcnt++
    }

    console.log(halveBcnt)
    if (halveAcnt == halveBcnt) return true
    else return false
};

////////////////////////////////////////////////////////////////////////////////

function halvesAreAlike(s: string): boolean {
    const nonVowels = new RegExp('b|c|d|f|g|h|j|k|l|m|n|p|q|r|s|t|v|w|x|y|z', 'gi')
    const part1: string = s.slice(0, s.length / 2).replace(nonVowels, '');
    const part2: string = s.slice(s.length / 2).replace(nonVowels, '');

    return part1.length === part2.length;
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @return {boolean}
 */
const halvesAreAlike = (
    s,
    vowels = new Set(['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']),
) =>
    ![...s].reduce(
        (acc, curr, idx) =>
            acc + +(vowels.has(curr) ? (idx < s.length / 2 ? 1 : -1) : 0),
        0,
    );

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


console.log(halvesAreAlike(s));

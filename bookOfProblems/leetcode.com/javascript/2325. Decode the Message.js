/**
 * @param {string} key
 * @param {string} message
 * @return {string}
 */

let key = "the quick brown fox jumps over the lazy dog"
let message = "vkbs bs t suepuv"

var decodeMessage = function (key, message) {

    // let modKey = [...new Set(key.replaceAll(` `, ``).split(``))];
    // let modKey = [...new Set(key.replaceAll(` `, ``))];
    // let modKey = Array.from(new Set(key.split(' ').join('')))
    // key = Array.from(new Set(key.split(' ').join('')))

    let modKey = [...new Set(key.replaceAll(` `, ``))];

    const firstCharCode = 'a'.charCodeAt(0); // 97
    let decoded = ''
    for (let char of message) {
        decoded += char === ' ' ? ' ' : String.fromCharCode(modKey.indexOf(char) + firstCharCode)
    }

    return decoded
};

////////////////////////////////////////////////////////////////////////////////

// const decodeMessage = (key, message) => {
//     const table = [...key].reduce((a, c) => (a.includes(c) || c === " " ? a : [...a, c]), []);
//     return [...message].reduce(
//         (a, c) =>
//             c === " "
//                 ? (a += " ")
//                 : (a += String.fromCharCode(table.findIndex((x) => x === c) + 97)),
//         ""
//     );
// };

////////////////////////////////////////////////////////////////////////////////

// const decodeMessage = (key, message) => {
//     const letters = `abcdefghijklmnopqrstuvwxyz`;
//     const modKey = [...new Set(key.replaceAll(` `, ``).split(``))];
//     const map = modKey.reduce((m, l, i) => (m[l] = letters[i], m), {});
//     return message.split(``).map(w => w in map ? map[w] : w).join(``);
// };

console.log(decodeMessage(key, message));
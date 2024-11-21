s = "a5c1e1"

// var replaceDigits = function (s) {
//     let res = ''
//     for (let i = 0; i < s.length; i++) {
//         if (i % 2 !== 0) {
//             res += String.fromCharCode(s[i - 1].charCodeAt() + parseInt(s[i]))
//             console.log(`ifA: ${res}`)
//         } else {
//             res += s[i]
//             console.log(`ifB: ${res}`)
//         }

//     }
//     return res;
// };

////////////////////////////////////////////////////////////////////////////////

// function replaceDigits(s: string): string {
//     const res = new Array < Char > (s.length);
//     for (let i = 1; i < s.length; i += 2) {
//         res[i - 1] = s[i - 1];
//         res[i] = String.fromCharCode(s.charCodeAt(i - 1) + Number(s[i]));
//     }
//     return s.length % 2 === 0 ? res.join('') : `${res.join('')}${s[s.length - 1]}`;
// }

// type Char = string;

////////////////////////////////////////////////////////////////////////////////

// var replaceDigits = function (s) {
//     for (let i = 1; i < s.length; i += 2) {
//         let str = String.fromCharCode(s[i - 1].charCodeAt() + Number(s[i]));
//         s = s.replace(s[i], str);
//     }
//     return s;
// };

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @return {string}
 */
// var replaceDigits = function (s) {
//     let newStr = '' // Create empty string variable
//     // Loop trough string odd values 
//     for (let i = 1; i < s.length; i = i + 2) {
//         // push to string previous value and shift function return value'
//         newStr += s[i - 1]
//         newStr += shift(s[i - 1], s[i])
//     }
//     if (s.length % 2) newStr += s[s.length - 1];

//     return newStr
// };


// function shift(char, num) {
//     let asciiVal = char.charCodeAt() // get ascii value for character
//     asciiVal = asciiVal + Number(num)     // add number to value 
//     return String.fromCharCode(asciiVal)
// }

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @return {string}
 */
var replaceDigits = function (s) {
    let newStr = ""

    for (let i = 1; i < s.length; i += 2) {
        newStr += s[i - 1]
        newStr += shift(s[i - 1], s[i])
    }
    if (s.length % 2) newStr += s[s.length - 1];


    return newStr

    function shift(char, int) {
        let asciiVal = char.charCodeAt()
        return String.fromCharCode(asciiVal + Number(int))
    }
};

////////////////////////////////////////////////////////////////////////////////

console.log(replaceDigits(s));
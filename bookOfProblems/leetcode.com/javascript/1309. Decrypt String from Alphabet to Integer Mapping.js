// var freqAlphabets = function (s) { // for example s = "10#11#12"
//     let res = '';
//     let i = 0;
//     while (i < s.length) { // we need while loop to easier control current index
//         if (s[i + 2] === '#') { // if third char from the current index is # (10# or 11#) then we have to convert it to char j from z
//             let code = parseInt(s[i] + s[i + 1], 10) + 96; // if 10# then we take 10 and add 96 to it so we get j and so on
//             res += String.fromCharCode(code);
//             i = i + 3; // we need to jump all three chars 10# and go to the first char in the next set of chars (for example 1 in 11#)
//         } else {
//             let code = s[i].charCodeAt(0) + 48; // this is the case for 1 or 9, we need to add 48 to it to get chars from a to i
//             res += String.fromCharCode(code);
//             i++; // in this case we jump only 1 step
//         }
//     }

//     return res;
// };

// ////////////////////////////////////////////////////////////////////////////////

// var freqAlphabets = function (s) {
//     return s
//         .match(/\d{2}(?=#)|\d/g)
//         .map(num => String.fromCharCode(96 + +num))
//         .join('')
// };

// ////////////////////////////////////////////////////////////////////////////////

// const freqAlphabets = s => String.fromCharCode(...s.match(/([0-9][0-9]#|[0-9])/g).map(x => parseInt(x) + 96));

// ////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {string} s
//  * @return {string}
//  */
// var freqAlphabets = function (s) {

//     let decryptedString = '';
//     let i = 0;

//     while (i < s.length) {
//         if (parseInt(s[i] + s[i + 1]) <= 26 && s[i + 2] === '#') {
//             decryptedString += String.fromCharCode(96 + parseInt(s[i] + s[i + 1]));
//             i += 3;
//         } else {
//             decryptedString += String.fromCharCode(96 + parseInt(s[i]));
//             i++;
//         }
//     }

//     return decryptedString;
// };

// ////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {string} s
//  * @return {string}
//  */
// var freqAlphabets = function (s) {
//     const base = 'a'.charCodeAt(0) - 1;
//     return s.replace(/(\d\d#|\d)/g, c =>
//         c[2] === '#'
//             ? String.fromCharCode(base + parseInt(c.slice(0, -1)))
//             : String.fromCharCode(base + parseInt(c))
//     );
// };

// ////////////////////////////////////////////////////////////////////////////////

// function freqAlphabets(s: string): string {
//     const jZMap = {
//         '10#': 'j',
//         '11#': 'k',
//         '12#': 'l',
//         '13#': 'm',
//         '14#': 'n',
//         '15#': 'o',
//         '16#': 'p',
//         '17#': 'q',
//         '18#': 'r',
//         '19#': 's',
//         '20#': 't',
//         '21#': 'u',
//         '22#': 'v',
//         '23#': 'w',
//         '24#': 'x',
//         '25#': 'y',
//         '26#': 'z',
//     };
//     const aIMap = {
//         1: 'a',
//         2: 'b',
//         3: 'c',
//         4: 'd',
//         5: 'e',
//         6: 'f',
//         7: 'g',
//         8: 'h',
//         9: 'i',
//     };

//     return s.replace(/\d\d#/g, m => jZMap[m]).replace(/\d/g, m => aIMap[m]);
// }

////////////////////////////////////////////////////////////////////////////////

var freqAlphabets = function (s) { 
    let res = '';
    let i = 0;
    while (i < s.length) {
        if (s[i + 2] === '#') {
            let code = parseInt(s[i] + s[i + 1], 10) + 96;
            res += String.fromCharCode(code);
            i = i + 3;
        } else {
            let code = s[i].charCodeAt(0) + 48;
            res += String.fromCharCode(code);
            i++;
        }
    }

    return res;
};


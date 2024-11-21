coordinates = "h3"

////////////////////////////////////////////////////////////////////////////////
//https://leetcode.com/problems/determine-color-of-a-chessboard-square/discuss/2249368/JavaScript-Solution-(With-Illustration)
// const squareIsWhite = (s) => s.charCodeAt(0) % 2 !== s.charCodeAt(1) % 2;

////////////////////////////////////////////////////////////////////////////////

// const squareIsWhite = function (coordinates) {
//     const letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'];
//     const [l, n] = coordinates.split('');
//     if ((letters.indexOf(l) % 2 == 0 && n % 2 == 0) || (letters.indexOf(l) % 2 == 1 && n % 2 == 1))
//         return true;
//     return false;
// };

////////////////////////////////////////////////////////////////////////////////
// /**
//  * @param {string} coordinates
//  * @return {boolean}
//  */
// const squareIsWhite = (coordinates) => {
//     return coordinates[0].charCodeAt(0) % 2 !== parseInt(coordinates[1]) % 2;
// }

// Explanation:

// The "eveness" or "oddness" of a letter or number in the coordinate is represented by 0 (even) or 1 (odd).
// For a letter, this is calculated using the Unicode code point % 2 (this works out since "a" = 97, "b" = 98, ...).
// For a number, this is simply number % 2.

// If the "evenness" of both the letter and number are the same (even/even or odd/odd), false is returned.
// Otherwise, if the "evenness" of the letter and number are different (even/odd or odd/even), true is returned.

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} coordinates
 * @return {boolean}
 */
var squareIsWhite = function (coordinates) {
    let oddchar = "aceg", evenchar = "bdfh", ch = coordinates.charAt(0), n = parseInt(coordinates.charAt(1) + "");
    if ((n % 2 != 0 && oddchar.includes(ch)) || (n % 2 == 0 && evenchar.includes(ch))) {
        return false;
    }
    return true;
};


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

console.log(squareIsWhite(coordinates));
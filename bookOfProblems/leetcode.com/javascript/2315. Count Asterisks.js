// let s = "yo|uar|e**|b|e***au|tifu|l"
let s = "l|*e*et|c**o|*de|"
/**
 * @param {string} s
 * @return {number}
 */

var countAsterisks = function (s) {
    let toggle = false
    let count = 0

    for (let char of s) {
        // if (char == "|") toggle = toggle ? false : true
        if (char == "|") toggle = !toggle
        if (char == "*" && !toggle) count++

    }
    return count
}

////////////////////////////////////////////////////////////////////////////////

// var countAsterisks = function(s) {
//     let pair=0, count=0;
//     for(let c of s){
//         if(c == '|')    pair++;
//         if(pair % 2 == 0 && c == '*')    count++;
//     }
//     return count;
// };

console.log(countAsterisks(s));

let words = ["pay", "attention", "practice", "attend"]
let pref = "at"

////////////////////////////////////////////////////////////////////////////////
// const prefixCount = (words, pref) => {
//     let count = 0;
//     for (const word of words) {
//       if (word.startsWith(pref)) count++     
//     }
//     return count;
//   }

////////////////////////////////////////////////////////////////////////////////

// var prefixCount = function (words, pref) {
//     return words.filter(word => word.startsWith(pref)).length;
// };

////////////////////////////////////////////////////////////////////////////////

// const prefixCount = (words, pref) => {
//     let count = 0;

//     words.forEach(word => {
//         if (word.startsWith(pref)) count++;
//     })

//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

var prefixCount = function (words, pref) {
    return words.reduce((sum, word) => sum + (word.startsWith(pref) ? 1 : 0), 0);
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
console.log(prefixCount(words, pref));
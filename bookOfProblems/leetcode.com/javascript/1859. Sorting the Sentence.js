let s = "is2 sentence4 This1 a3"

// /**
//  * @param {string} s
//  * @return {string}
//  */
//  var sortSentence = function(s) {
//     let words = [];

//     s.split(' ').forEach(word => {
//         let index = parseInt(word[word.length - 1]);
//         let actualWord = word.slice(0, word.length - 1);
//         words[--index] = actualWord;
//     });

//     return words.join(' ');
// };

////////////////////////////////////////////////////////////////////////////////

const sortSentence = function (s) {
    return s.split(' ')
        .sort((a, b) => a.slice(-1) - b.slice(-1))
        .map((word) => word.slice(0, -1))
        .join(' ');
};

console.log(sortSentence(s));
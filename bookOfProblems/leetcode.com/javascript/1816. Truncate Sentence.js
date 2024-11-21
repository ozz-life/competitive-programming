s = "Hello how are you Contestant"
k = 4

// /**
// * @param {string} s
// * @param {number} k
// * @return {string}
// */
// var truncateSentence = function (s, k) {
//     let arr = s.split(" ")
//     arr.length = k
//     return arr.join(" ")
// };

////////////////////////////////////////////////////////////////////////////////

// const truncateSentence = (s, k) => s.split(' ', k).join(' ');

////////////////////////////////////////////////////////////////////////////////

// const truncateSentence = (s, k) => {
//     let spaceCount = 0;
//     for (let i = 0; i < s.length; ++i) {
//         if (s[i] === ' ' && ++spaceCount === k) return s.slice(0, i);
//     }
//     return s;
// };

////////////////////////////////////////////////////////////////////////////////

const truncateSentence = function(s, k) {
    let spaceCount = 0;

    for (let i = 0; i < s.length; i++) {
        if (s.charCodeAt(i) === 32) {
            spaceCount++;

            if (spaceCount === k) {
                return s.slice(0, i);
            }
        }
    }

    return s;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

console.log(truncateSentence(s, k));
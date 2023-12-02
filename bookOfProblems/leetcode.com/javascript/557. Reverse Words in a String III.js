s = "Let's take LeetCode contest"

// var reverseWords = function (s) {
//     // s = "God Ding" -------> arrOfWords = [ 'God', 'Ding' ]
//     let arrOfWords = s.split(' ')  

//      for(let i = 0; i < arrOfWords.length; ++i) {
//          // arrOfWords = [ 'God', 'Ding' ] -------> eachWord = "God"
//         let eachWord = arrOfWords[i].split(''); 

//         // left = "G", right = "d"
//         let left = 0, right = eachWord.length-1; 

//         //here below is : classic swap function

//         while(left < right) { 
//             // eachWord[right] = "d"  -------> temp = "d"
//             let temp = eachWord[right]
//             // eachWord[left] = "G"  -------> eachWord[right] = "G"
//             eachWord[right] = eachWord[left]
//             // eachWord[left]  -------> temp = "d"
//             eachWord[left] = temp 
//             console.log(`left: ${left} | eachWord[left]: ${eachWord[left]} | right: ${right} | eachWord[right]: ${eachWord[right]} | temp: ${temp}`)
//             left++;
//             right--;
//         }
//         // eachWord = "doG"  -------> eachWord.join('') = [ 'd', 'o', 'G' ]  -------> [ 'doG', 'Ding' ]
//         arrOfWords[i] = eachWord.join('')
//     }
//     //after swaping each word ------> arrOfWords[i] = [ 'doG', 'gniD' ]

//     // arrOfWords[i] = [ 'doG', 'gniD' ] ------> "doG gniD"
//     return arrOfWords.join(' ') 
// }

////////////////////////////////////////////////////////////////////////////////

// var reverseWords = function (s) {
//     return s.split(' ').map((word) => word.split('').reverse().join('')).join(' ')
// }

////////////////////////////////////////////////////////////////////////////////

// var reverseWords = function (s) {
//     return s.split(' ').reduce((a, b) => a + ' ' + b.split('').reverse().join(''), '').trim()
// };

////////////////////////////////////////////////////////////////////////////////
// STACK 
// var reverseWords = function (s) {
//     let res = '';
//     let word = '';
//     for (let c of s) {
//         if (c === ' ') {
//             res += word + c;
//             word = '';
//         } else {
//             word = c + word;
//         }
//     }
//     return res + word;
// };

////////////////////////////////////////////////////////////////////////////////

// function reverseWords() {
//     let arr = s.split(" ");
//     let result = [];
//     for (let i = 0; i < arr.length; i++) {
//         result.push(arr[i].split("").reverse().join(""));
//     }

//     return result.join(" ");
// };

////////////////////////////////////////////////////////////////////////////////

// function reverseWords(s) {
//     return s.split(" ").reduce((p, c) => {
//         return (p = `${p} ${c.split("").reverse().join("").trim()}`);
//     }, []).trim();
// }

////////////////////////////////////////////////////////////////////////////////

// var reverseWords = function (s) {
//     let arrOfWords = s.split(' ');

//     for (let w = 0; w < arrOfWords.length; w++) {
//         let arrOfLetters = arrOfWords[w].split('');
//         for (let i = 0, j = arrOfLetters.length - 1; i < j;) {
//             [arrOfLetters[i], arrOfLetters[j]] = [arrOfLetters[j], arrOfLetters[i]];
//             i++;
//             j--;
//         }
//         arrOfWords[w] = arrOfLetters.join('')
//     }
//     console.log(arrOfWords)

//     return arrOfWords.join(' ')
// }

////////////////////////////////////////////////////////////////////////////////

var reverseWords = function (s) {
    let arrOfWords = s.split(' ')
    let result = []
    for (let word of arrOfWords) {
        result.push(word.split('').reverse().join(''))
    }
    return result.join(' ')
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
console.log(reverseWords(s))
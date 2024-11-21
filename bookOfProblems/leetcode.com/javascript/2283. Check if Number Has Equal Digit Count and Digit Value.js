// Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false.

let num = "1210"
// /**
//  * @param {string} num
//  * @return {boolean}
//  */
// var digitCount = function (num) {
//     let arr = Array(num.length).fill(0)
//     for (let char of num) {
//         arr[Number(char)]++
//     }

//     return arr.join('') === num;
// };


////////////////////////////////////////////////////////////////////////////////

// const mapCounter = (nums) => {
//     let map = new Map()
//     for (const n of nums) map.set(n, map.get(n) + 1 || 1)
//     console.log(map)
//     return map
// };

// const digitCount = (num) => {
//     let map = mapCounter(num), l = num.length;
//     for (let i = 0; i < l; i++) {
//         let cnt = map.get(i + '') || 0
//         if (num[i] != cnt) return false;
//     }
//     return true;
// };

////////////////////////////////////////////////////////////////////////////////

const digitCount = function (num) {
    return num.split('').every((x, i) => num.split('').filter(a => a == i).length == x);
  };



console.log(digitCount(num));
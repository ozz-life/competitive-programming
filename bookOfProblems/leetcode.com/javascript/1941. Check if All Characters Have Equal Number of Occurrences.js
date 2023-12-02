s = "abcabc"
// /**
//  * @param {string} s
//  * @return {boolean}
//  */
// var areOccurrencesEqual = function (s) {
//     let map = new Map()
//     for (let i = 0; i < s.length; i++) {
//         map.set(s[i], map.get(s[i]) + 1 || 1);
//     }
//     console.log(map)
// };

////////////////////////////////////////////////////////////////////////////////

// var areOccurrencesEqual = (s) => {
//     let count = s.split('').reduce((obj, cur) => {
//         obj.hasOwnProperty(cur) ? obj[cur] += 1 : obj[cur] = 1
//         return obj
//     }, {})
//     return new Set(Object.values(count)).size === 1
// };

////////////////////////////////////////////////////////////////////////////////

// var areOccurrencesEqual = function (s) {
//     const map = new Map();
//     for (let char of s) {
//         map.set(char, 1 + (map.get(char) ?? 0));

//     }
//     return new Set([...map.values()]).size === 1;
// };

////////////////////////////////////////////////////////////////////////////////

// var areOccurrencesEqual = function (s) {

//     // Map the characters and their counts
//     let map = new Map();
//     for (let i = 0; i < s.length; i++) {
//         map.set(s[i], map.get(s[i]) + 1 || 1);
//     }

//     // Iterate through all map values
//     let expected;
//     for (const value of map.values()) {
//         // Get the first value so we know what the expected count for all should be
//         if (expected === undefined)
//             expected = value;
//         // If anything does not match the first expected count, fail
//         else if (value != expected)
//             return false;
//     }

//     // Return true if no prior failures
//     return true;
// };

////////////////////////////////////////////////////////////////////////////////

// var areOccurrencesEqual = function (s) {
//     let myMap = new Map();
//     for (const element of s) {
//         // myMap.set(element, (myMap.get(element) || 0) + 1);
//         myMap.set(element, myMap.get(element) + 1 || 1);
//     }
//     const myMapValues = [...myMap.values()];
//     const firstMyMapValue = myMapValues[0];
//     return myMapValues.every((e) => e === firstMyMapValue);
// };

////////////////////////////////////////////////////////////////////////////////

// const areOccurrencesEqual = (s) => {
//     if (!s.length) return false;

//     const charMap = new Map();
//     for (let letter of s) {
//         if (charMap.has(letter)) {
//             charMap.set(letter, charMap.get(letter) + 1)
//         } else {
//             charMap.set(letter, 1)
//         }
//     }

//     // Returns an iterator object
//     const charArray = charMap.values();
//     // Grab the initial value. If any of the values in the Map iterator are different, we can immediately return false
//     const current = charArray.next().value;
//     for (const [key, value] of charMap) {
//         if (value !== current) return false;
//     }

//     return true;
// };

////////////////////////////////////////////////////////////////////////////////

var areOccurrencesEqual = function (s) {
    let myMap = new Map();
    for (const element of s) {
        myMap.set(element, myMap.get(element) + 1 || 1);
    }
    const charArray = myMap.values();
    const current = charArray.next().value;
    for (const [key, value] of myMap) {
        if (value !== current) return false;
    }

    return true;
}

console.log(areOccurrencesEqual(s));
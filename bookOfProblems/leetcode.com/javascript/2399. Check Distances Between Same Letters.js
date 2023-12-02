//s = "abaccb", distance = [1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
//s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
s = "zz", distance = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1]

// /**
//  * @param {string} s
//  * @param {number[]} distance
//  * @return {boolean}
//  */
// var checkDistances = function (s, distance) {
//     let alphabet = new Map()
//     let occurrences = new Map()

//     // j = 97, from "a".codePointAt()
//     for (let i = 0, j = 97; i < 26; i++, j++) {
//         let char = String.fromCodePoint(j)
//         alphabet.set(char, i)
//     }

//     for (let i = 0; i < s.length; i++) {
//         occurrences.set(s[i], getIndicesOf(s[i], s))
//     }

//     let letterDistanceArr = []
//     let firstLetter = occurrences.keys().next().value
//     //122 = z, 97 = a
//     for (let i = 122; i > 97; i--) {
//         if (firstLetter.codePointAt() > 97) {
//             letterDistanceArr.unshift(0)
//             firstLetter = firstLetter--
//         }
//     }
//     console.log(letterDistanceArr)
//     for (let [key, value] of occurrences) {
//         let letterDistance = value[1] - value[0] - 1;
//         letterDistanceArr.push(letterDistance)
//     }
//     console.log(occurrences)

//     for (let i = 0; i < distance.length; i++) {
//         if (letterDistanceArr[i] !== distance[i]) {
//             console.log(`${letterDistanceArr[i]} !== ${distance[i]}`);
//             return false
//         }
//         else {
//             console.log(`${letterDistanceArr[i]} !== ${distance[i]}`);
//             return true
//         }
//     }
// };

// function getIndicesOf(char, string) {
//     let indices = [];
//     for (let i = 0; i < string.length; i++) {
//         if (string[i] === char) {
//             indices.push(i);
//         }
//     }
//     return indices;
// }

////////////////////////////////////////////////////////////////////////////////

// var checkDistances = function(s, distance) {
//     let arr = Array(26).fill(0)
//     for(let i=0; i<s.length; i++){
//         if(arr[s.charCodeAt(i) - 97] != 0 && i - arr[s.charCodeAt(i) - 97] != distance[s.charCodeAt(i) - 97])    
//             return false
//         arr[s.charCodeAt(i) - 97] = i+1
//     }
//     return true
// };

////////////////////////////////////////////////////////////////////////////////

// Time complexity: O(n), where n is length of input string.
// Space complexity: O(1)

// var checkDistances = function(s, distance) {
//     const arr = Array(26).fill(-1);

// 	for(let i = 0; i < s.length; i++) {
//         console.log(arr)
// 		const charCode = s[i].charCodeAt(0) - 'a'.charCodeAt(0);

// 		if(arr[charCode] !== -1)
// 			if(i - arr[charCode] - 1 !== distance[charCode])
// 				return false;

// 		arr[charCode] = i;
// 	}

// 	return true;
// };

////////////////////////////////////////////////////////////////////////////////

// const checkDistances = function (s, distance) {
//     for (let i = 0; i < s.length; i++) {
//         for (let j = i + 1; j < s.length; j++) {
//             if (s[i] === s[j]) {
//                 if (distance[s[i].charCodeAt() - 97] !== j - i - 1) return false;
//                 break;
//             }
//         }
//     }
//     return true;
// };

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @param {number[]} distance
 * @return {boolean}
 */
// var checkDistances = function (s, distance) {
//     var hash = {} // our map
//     for (let i = 0; i < s.length; i++) { // our single loop
//         if (hash[s[i]] === undefined) {
//             // if there is no entry, we will compute 
//             // what the next occurance index is. 
//             hash[s[i]] = distance[s.charCodeAt(i) - 97] + i + 1
//         } else {
//             // since we have an entry, we will check to see if it matches
//             // if the entry does not match, we break our loop. 
//             if (hash[s[i]] != i) return false
//         }
//     }
//     // finished our 1 loop, so let us get out. 
//     return true
// };

////////////////////////////////////////////////////////////////////////////////

// var checkDistances = function(s, distance) {
//     let arr = Array(26).fill(-1);
//     for (let i = 0; i < s.length; i++) {
//         let code = s[i].charCodeAt(0) - 97;
//         if (arr[code] === -1) {
//             arr[code] = i; // first instance, just track the index
//         } else {
//             // compare the diff between this index and the previous index with the distances for that char
//             // add -1 because for some reason, the diff between 0 and 2 = 1...
//             if (Math.abs(arr[code] - i) - 1 !== distance[code]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// };

////////////////////////////////////////////////////////////////////////////////

var checkDistances = function(s, distance) {
    let map = new Map()
    
    for(let i = 0; i < s.length; i++){
        map.has(s[i]) === false ? map.set(s[i], [i]) : map.get(s[i]).push(i) 
    }  
    
    for(let [char,[a,b]] of map){
        if (!(b-a-1 === distance[char.charCodeAt() - 97]))  return false 
    }
    
  return true
};

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
console.log(checkDistances(s, distance));
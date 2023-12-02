target = [1,2,3,4], arr = [2,4,1,3]

/**
 * @param {number[]} target
 * @param {number[]} arr
 * @return {boolean}
 */
// var canBeEqual = function(target, arr) {
//     let map1 = new Map()
//     let map2 = new Map()

//     for(let n of target) {
//         map1.set(n, map1.get(n) +1 || 1)        
//     }
//     for(let n of arr) {
//         map2.set(n, map2.get(n) +1 || 1)        
//     }
    
//     return compareMaps(map1, map2)
// };

// function compareMaps(map1, map2) {
//     var testVal;
//     if (!(map1 && map2)) {
//         return false;
//     }
//     if (map1.size !== map2.size) {
//         return false;
//     }
//     for (let key of Array.from(map1.keys())) {
//         let val = map1.get(key);
//         testVal = map2.get(key);
//         if (testVal !== val || (testVal === undefined && !map2.has(key))) {
//             return false;
//         }
//     }
//     return true;
// }

////////////////////////////////////////////////////////////////////////////////

var canBeEqual = function(target, arr) {
    return target.sort().join('') == arr.sort().join('')
};

console.log(canBeEqual(target, arr));
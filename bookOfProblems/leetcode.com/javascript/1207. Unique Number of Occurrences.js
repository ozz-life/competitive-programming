arr = [1, 2, 2, 1, 1, 3]

// /**
//  * @param {number[]} arr
//  * @return {boolean}
//  */
// var uniqueOccurrences = function (arr) {
//     let map = new Map()
//     for (let n of arr) {
//         map.set(n, map.has(n) + 1 || 1)
//     }

//     let set = new Set()

//     for (let value of map.values()) {
//         if (set.has(value)) return false
//         else {
//             set.add(value)
//         }
//     }

//     return true
// };

/////////////////////////////////////////////////////////////////////////////////

var uniqueOccurrences = function (arr) {
    let myMap = new Map()
    for (let num of arr) {
        if (myMap.has(num)) {
            myMap.set(num, (myMap.get(num) + 1))
        } else {
            myMap.set(num, 1)
        }
    }
    let mySet = new Set()
    for (const val of myMap.values()) {
        if (mySet.has(val)) return false
        mySet.add(val)
    }
    return true
};

console.log(uniqueOccurrences(arr));
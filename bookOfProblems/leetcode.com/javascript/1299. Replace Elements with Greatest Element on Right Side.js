arr = [17, 18, 5, 4, 6, 1]

/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function (arr) {

    // let max = 0
    // let left = arr.length - 2
    // let right = arr.length - 1
    // for (left; left >= 0; left--) {
    //     console.log(left)
    // }

    let left = 0
    let right = 1
    for (left; left < arr.length - 2; left++) {
        arr[left] = max
    }

    return arr
};

console.log(replaceElements(arr));
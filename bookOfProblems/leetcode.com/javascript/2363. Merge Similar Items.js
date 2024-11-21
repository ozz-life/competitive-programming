items1 = [[1, 3], [2, 2]]
items2 = [[7, 1], [2, 2], [1, 4]]

/**
 * @param {number[][]} items1
 * @param {number[][]} items2
 * @return {number[][]}
 */
var mergeSimilarItems = function (items1, items2) {
    let vwMap = new Map(items1) // value weight Map

    for (let [value, weight] of items2) {
        (!vwMap.has(value)) ? vwMap.set(value, weight) : vwMap.set(value, vwMap.get(value) + weight)
    }

    // for (let [value, weight] of items2) {
    //     if (!vwMap.has(value)) {
    //         vwMap.set(value, weight)
    //     } else {
    //         vwMap.set(value, vwMap.get(value) + weight)
    //     }
    // }


    // return Array.from(vwMap.entries()).sort((i, j) => i[0] - j[0])
    return [...vwMap].sort((i, j) => i[0] - j[0])
};

console.log(mergeSimilarItems(items1, items2));
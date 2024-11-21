tasks = [2,2,3,3,2,4,4,4,4,4]

/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function(tasks) {
    let map = new Map()
    let counter = 0

    for (let n of tasks) {
        map.set(n, map.get(n) + 1 || 1)
    }
    console.log(map)

    for (let [key, value] of map) {
        if (value == 2 && value == 3) counter++
        counter += Math.floor(value / 3) + (value % 3 !== 0 ? 1 : 0);
        if (value == 1) return -1
    }

    return counter
};

console.log(minimumRounds(tasks));
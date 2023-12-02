// lowLimit = 1, highLimit = 10
// lowLimit = 5, highLimit = 15
lowLimit = 6745, highLimit = 28696

/**
 * @param {number} lowLimit
 * @param {number} highLimit
 * @return {number}
 */
var countBalls = function (lowLimit, highLimit) {

    let map = new Map()
    for (let i = lowLimit; i <= highLimit; i++) {
        let arr = [i].toString().split('')

        let arrNum = []
        for (let j of arr) {
            arrNum.push(Number(j))
        }

        let sum = arrNum.reduce((partialSum, a) => partialSum + a, 0);

        map.set(sum, map.get(sum) + 1 || 1);
    }

    return Math.max(...map.values())
};

console.log(countBalls(lowLimit, highLimit));
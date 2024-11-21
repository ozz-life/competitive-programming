// costs = [1, 3, 2, 4, 1], coins = 7
// costs = [10,6,8,7,7,8], coins = 5
// costs = [1,3,2,4,1], coins = 7
costs = [7,3,3,6,6,6,10,5,9,2], coins = 56

/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function (costs, coins) {
    costs.sort((a, b) => a - b)

    let count = 0
    for (let n of costs) {
        if (n <= coins) {
            count++
            coins -= n
        }
    }

    return count
};

console.log(maxIceCream(costs, coins));
nums = [12,345,2,6,7896]

/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let result = 0
    
    for (let n of nums) {
        length = recurseIsEven(n)
        if (length % 2 == 0) ++result
    }
    return result 
};

function recurseIsEven(number) {
    let count = 0

    if (number = 0) return count
    else {
        console.log(`${number} | ${count}`)
        number /= 10
        ++count
        return recurseIsEven(number)
    }
}

console.log(findNumbers(nums));
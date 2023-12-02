num = 1994

/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let map = new Map([
        [1000, 'M'],
        [900, 'CM'],
        [500, 'D'],
        [400, 'CD'],
        [100, 'C'],
        [90, 'XC'],
        [50, 'L'],
        [40, 'XL'],
        [10, 'X'],
        [9, 'IX'],
        [5, 'V'],
        [4, 'IV'],
        [1, 'I']
    ]);  

    let result = '';
    let iterator = map[Symbol.iterator]();
    let entry = iterator.next();
    
    while(num > 0){
        if(num >= entry.value[0]) {
            num -= entry.value[0];
            result += entry.value[1];
        } else {
            entry = iterator.next();
        }
    }
    return result;
};

console.log(intToRoman(num));
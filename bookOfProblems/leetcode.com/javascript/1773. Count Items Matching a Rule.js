/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
let items = [["phone", "blue", "pixel"], ["computer", "silver", "phone"], ["phone", "gold", "iphone"]]
let ruleKey = "type"
let ruleValue = "phone"

////////////////////////////////////////////////////////////////////////////////

// const map = {
//     'type': 0,
//     'color': 1,
//     'name': 2
// }

// const countMatches = (items, key, value) => items.filter(i => i[map[key]] == value).length

////////////////////////////////////////////////////////////////////////////////

var countMatches = function(items, ruleKey, ruleValue) {
    
    const indexMap = {
        type: 0,
        color: 1,
        name: 2
    };
    
    const indexToCheck = indexMap[ruleKey];
    
    //iterate thru the items array
    return items.reduce((accumulator, currentVal) => {
        // check the correct index of the inner array for the value
        const valueToCheck = currentVal[indexToCheck];
        return valueToCheck === ruleValue ? ++accumulator : accumulator;

    }, 0);
    
};

////////////////////////////////////////////////////////////////////////////////

var countMatches = function(items, ruleKey, ruleValue) {
    return items.filter(item => item[["type","color","name"].indexOf(ruleKey)] == ruleValue ).length;
};


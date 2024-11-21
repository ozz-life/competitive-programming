/**
 * @param {string} word
 * @return {boolean}
 */
let word = "aaazzz"

// var equalFrequency = function (word) {
//     let frequencyMap = new Map()
//     for (const char of word) {
//         frequencyMap.set(char, frequencyMap.has(char) ? frequencyMap.get(char) + 1 : 1);
//     }
//     console.log(frequencyMap)

//     let avg = 0;
//     for (const entry of frequencyMap) {
//         avg += entry[1]
//     }

//     if (avg / frequencyMap.size === 1 || frequencyMap.size === 1) return true;
//     avg = Math.round(avg / frequencyMap.size);

//     let oneOff = false;
//     for (const entry of frequencyMap){
//         if (Math.abs(entry[1] - avg) > 1) return false;
//         else if(Math.abs(entry[1] - avg) === 1){
//             if(oneOff === false) oneOff = true;
//             else return false;
//         }   
//     }
//     return oneOff;
// }

////////////////////////////////////////////////////////////////////////////////

var equalFrequency = function (word) {
    var set = [...new Set(word)];
    for (var i of set) {
        var obj = {}
        console.log("i: ", i)
        for (var j of word.replace(i, "")) {
            obj.hasOwnProperty(j) ? obj[j] += 1 : obj[j] = 1
            console.log("j: ", j, "obj[j]:", obj[j])
        }
        if ([...new Set(Object.values(obj))].length == 1) {
            return true;
        }
    }
    return false;
};

////////////////////////////////////////////////////////////////////////////////


console.log(equalFrequency(word))
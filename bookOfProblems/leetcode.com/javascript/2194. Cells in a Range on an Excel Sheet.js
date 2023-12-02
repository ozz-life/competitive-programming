/**
 * @param {string} s
 * @return {string[]}
 */

// let s = "K5:L10" // Output: ["K1","K2","L1","L2"]
let s = "A1:F1" // Output: ["A1","B1","C1","D1","E1","F1"]

var cellsInRange = function (s) {

    let result = []

    const toCharCode = (char) => char.charCodeAt()
    let col1 = toCharCode(s[0])
    let col2 = toCharCode(s[3])
    let row1 = s[1]
    let row2 = s[4]

    for (let i = col1; i <= col2; i++) {
        console.log("i: ", i)
        for (let j = row1; j <= row2; j++) {
            result.push(String.fromCharCode(i) + j)
            // result.push(`${String.fromCharCode(i)}${j}`);
        }
    }

    return result
}

// cell = "<col><row>" as string
// s = "<col1><row1>:<col2><row2>", s.length == 5
// col = alphabeticalLetters 
// row = integer r
// such that r1 <= r2 and c1 <= c2
// Return the list of cells (x, y) such that r1 <= x <= r2 and c1 <= y <= c2
// sorted in non-decreasing


console.log(cellsInRange(s));
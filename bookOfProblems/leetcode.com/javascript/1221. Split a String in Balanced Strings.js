var balancedStringSplit = function (s) {
    let countL = 0
    let countR = 0
    let pairs = 0

    s.split('').forEach(value => {
        if (value === "L") countL++
        else if (value === "R") countR++

        if (countL === countR) {
            pairs++
            countL = 0
            countR = 0
        }
    })
    return pairs
};

////////////////////////////////////////////////////////////////////////////////

// const balancedStringSplit = (s: string, [left, right, count]: any = [0, 0, 0]) =>
//     [...s].filter((e) => (e === "L" ? ++left : ++right) && (left === right && ([left, right] = [0, 0, ++count]))).length;

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function (s) {
    return s.split(``).reduce((f, c) => {
        c === 'L' ? f.balance++ : f.balance--;
        f.balance === 0 && f.ans++;
        return f;
    }, { balance: 0, ans: 0 }).ans;
};

////////////////////////////////////////////////////////////////////////////////

var balancedStringSplit = function (s) {
    return countOfBalStr(s, 0)
};


// The recursive tail-call function
function countOfBalStr(string, position, count = null, total = 0) {
    if (position >= string.length) {
        return total
    }

    const letter = string[position]
    const value = letter === 'L' ? 1 : -1 // We can hard code this cause this is a contraint on the question
    count += value

    if (count === 0) {
        total++
    }

    return countOfBalStr(string, position + 1, count, total)
}
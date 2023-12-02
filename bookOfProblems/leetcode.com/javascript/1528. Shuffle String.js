// You can create an auxiliary string t of length n.
// Assign t[indexes[i]] to s[i] for each i from 0 to n-1.

let s = "codeleet"
let indices = [4, 5, 6, 7, 0, 2, 1, 3]

function restoreString(s, indices) {
    let t = []
    for (let i = 0; i <= indices.length; i++) {
        t[indices[i]] = s[i];
        console.log("t[i] = " + t[i] + " | s[i] = " + s[i])
    }

    return t.join('')
}

////////////////////////////////////////////////////////////////////////////////

// var restoreString = function (s, indices) {
//     const result = []

//     for (let i = 0; i < s.length; i++) {
//         result.push(s[indices.findIndex(num => num === i)])
//     }

//     return result.join("")
// };

////////////////////////////////////////////////////////////////////////////////

// function restoreString(s, indices) {
//     const t = new Array(s.length);
//     [...s].forEach((x, i) => {
//         (t[indices[i]] = x)
//     });
//     return t.join("")
// }

////////////////////////////////////////////////////////////////////////////////

var restoreString = function (s, indices) {
    return indices.reduce((a, b, i) => {
        console.log("a: " + a + "||||| b: " + b + "||||| i: " + i)
        a[b] = s[i]
        return a
    }, []).join``
};

console.log(restoreString(s, indices));


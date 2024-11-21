/**
 * @param {string} boxes
 * @return {number[]}
 */
let boxes = "001011"

// var minOperations = function (boxes) {

//     let move = new Array(boxes.length).fill(0)
//     for (let i = 0; i < boxes.length; i++) {
//         console.log(`First cicle. i = ${i} move: ${move}`)
//         for (let j = 0; j < boxes.length; j++) {
//             if (boxes[j] === '1') {
//                 move[i] += Math.abs(j - i)
//                 console.log(`Second cicle. IF j = ${j} move: ${move}`)
//             }
//         }
//     }

//     return move
// };

////////

var minOperations = function (boxes) {
    return boxes.split('').map((box1, index1, arr) => {
        return arr.reduce((count, box2, index2) => count + (box2 === '1' ? Math.abs(index1 - index2) : 0), 0);
    });
};

////////
// O(n)
var minOperations = function (boxes) {
    let numberOfBoxes = boxes.length
    let left = new Array(boxes.length)
    let right = new Array(boxes.length)
    let count = parseInt(boxes[0])
    let answerOperation = new Array()
    left[0] = 0
    right[numberOfBoxes - 1] = 0
    for (let i = 1; i < numberOfBoxes; i++) {
        left[i] = left[i - 1] + count
        count += parseInt(boxes[i])
    }

    count = parseInt(boxes[numberOfBoxes - 1])
    for (let i = numberOfBoxes - 2; i >= 0; i--) {
        right[i] = right[i + 1] + count
        count += parseInt(boxes[i])
    }

    for (let i = 0; i < numberOfBoxes; i++) {
        answerOperation[i] = left[i] + right[i]
    }

    return answerOperation;
};
console.log(minOperations(boxes));
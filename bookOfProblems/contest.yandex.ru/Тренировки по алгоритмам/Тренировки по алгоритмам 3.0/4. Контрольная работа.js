#!/usr/bin/env node

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let commands = '';

process.stdin.on('data', function (input) {
    commands += input;
});

process.stdin.on('end', function () {

    /*
     * Code Start
     **************************************************************************/

    let input = commands.trim().split('\n');
    let n = parseInt(input[0]);
    let k = parseInt(input[0]);
    let nPart = parseInt(input[0]);
    let lOrR = parseInt(input[0]);

    // вариант Пети
    let seatNumber = nPart * 2 - (lOrR % 2)

    // нет вариантов
    if (seatNumber - k < 1 && seatNumber + k > n) console.log("-1")
    if (seatNumber - k < 1) {
        console.log(getPart(seatNumber + k), getMesto(seatNumber + k))
    }
    if (seatNumber + k > n) {
        console.log(getPart(seatNumber - k), getMesto(seatNumber - k))
    }

    if (nPart - getPart(seatNumber - k) < getPart(seatNumber + k) - nPart) {
        console.log(getPart(seatNumber - k), getMesto(seatNumber - k))
    } else {
        console.log(getPart(seatNumber + k), getMesto(seatNumber + k))
    }

});

// function getPart(n) {
//     return (n + 1) / 2;
// }
function getPart(n) {
    return Math.floor((parseInt(n) + 1) * 0.5);
}

function getMesto(n) {
    return 2 - n % 2
}
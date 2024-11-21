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
    let [n, k] = input[0].trim().split(' ').map(Number);
    let arr1 = input[1].trim().split(' ').map(Number);
    let arr2 = input[2].trim().split(' ').map(Number);

    for (let i = 0; i <= arr2.length; i++) {
        if (binarySearch(arr1, arr2[i]) === false) console.log("NO")
        else console.log("YES")
    }
});

function binarySearch(array, target) {

    let left = 0;
    let right = array.length - 1

    while (left <= right) {
        let middle = Math.floor(left + ((right - left) / 2));
        let guess = array[middle]

        if (guess === target) {
            return middle
        } else if (guess > target) {
            right = middle - 1
        } else if (guess < target) {
            left = middle + 1
        }
    }
    return false
}
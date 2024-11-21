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
    let stickers = input[1].trim().split(' ').map(Number);
    let k = parseInt(input[2]);
    let collectors = input[3].trim().split(' ').map(Number);

    let set = new Set(stickers.sort((a, b) => a - b))
    let stickersArr = [...set]

    let min = stickersArr.at(0)
    let max = stickersArr.at(-1)

    for (let i = 0; i < k; i++) {
        if (collectors[i] > max) {
            console.log(stickersArr.length)
            continue;
        }
        if (collectors[i] <= min) {
            console.log(0)
            continue;
        }
        else if (collectors[i] > min && collectors[i] <= max) {
            console.log(findLower(stickersArr, collectors[i]) + 1);
        }
        // else {
        //     console.log(findLower(stickersArr, collectors[i]) + 1);
        // }
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
    return -1
}

function findLower(array, x) // max i: a[i] <= x
{
    let l = -1;            // a[l] <= x
    let r = array.length; // a[r] > x
    while (r > l + 1) {
        let m = (l + r) / 2; // m > l, m < r
        if (array[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

function leftBinarySearch(array, target) {
    let left = 0;
    let right = array.length;

    while (left < right) {
        let middle = Math.floor(left + ((right - left) / 2));
        let guess = array[middle];

        if (guess >= target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    if (array[left] === target) {
        return left;
    } else {
        return -1;
    }
}

function rightBinarySearch(array, target) {
    let left = 0;
    let right = array.length;

    while (left < right) {
        let middle = Math.floor((left + right) / 2);
        let guess = array[middle];

        if (guess > target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    if (left > 0 && array[left - 1] === target) {
        return left - 1;
    }

    return -1;
}
#!/usr/bin/env node
'use strict'

process.stdin.resume()
process.stdin.setEncoding('utf-8')

let currentLine = 0
let inputString = ''

process.stdin.on('data', raw_data => {
    inputString += raw_data
})

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(line => {
        return line.trim()
    })
    main()
})

function readLine() {
    return inputString[currentLine++]
}

/*
 * Code Start
 ******************************************************************************/

function findMax(n, m, matrix) {
    let max = Number.MIN_SAFE_INTEGER;
    let maxRow = 0;
    let maxCol = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                maxRow = i;
                maxCol = j;
            } else if (matrix[i][j] === max) {
                if (i < maxRow) {
                    maxRow = i;
                    maxCol = j;
                } else if (i === maxRow && j < maxCol) {
                    maxCol = j;
                }
            }
        }
    }
    return [max, maxRow+1, maxCol+1];
}


function main() {

    let [n, m] = readLine().split(' ').map(Number)
    let matrix = []
    for (let i = 0; i < n; i++) {
        matrix[i] = readLine().split(' ').map(Number)
    }

    console.log(findMax(n, m, matrix))
}
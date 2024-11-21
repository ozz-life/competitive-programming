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

function main() {

    let [n, m] = readLine().split(' ').map(Number)
    console.log(generatePascalTriangle(n, m));
}

function generatePascalTriangle(n, m) {
    let triangle = [];
    for (let i = 0; i < n; i++) {
        triangle[i] = [];
        for (let j = 0; j < m; j++) {
            if (i === 0 || j === 0) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j] + triangle[i][j - 1];
            }
        }
    }
    return triangle;
}
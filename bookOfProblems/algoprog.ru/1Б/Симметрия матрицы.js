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

    let n = readLine()
    let matrix = []
    for (let i = 0; i < n; i++) {
        matrix[i] = readLine().split(' ').map(Number)
    }
    console.log(isSymmetric(n, matrix))

}

function isSymmetric(n, matrix) {
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] !== matrix[j][i]) {
                return 'no';
            }
        }
    }
    return 'yes';
}
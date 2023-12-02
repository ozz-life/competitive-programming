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

function rotateArrayRight(arr, n) {
    for (let i = 0; i < n; i++) {
        let last = arr.pop();
        arr.unshift(last);
    }
}

function main() {

    let n = readLine()
    let arr = [] = readLine().split(' ').map(Number)
    rotateArrayRight(arr, 3)

    console.log(arr)
}
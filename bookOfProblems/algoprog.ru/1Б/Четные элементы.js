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
    let arr = [] = readLine().split(' ').map(Number)
    let arrRes = []
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] % 2 == 0) arrRes.push(arr[i])
    }

    console.log(arrRes)
}

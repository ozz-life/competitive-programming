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

    let n = Number(readLine())
    let nPrevious = n - 1
    let nNext = n + 1

    console.log(`The next number for the number ${n} is ${nNext}.`)
    console.log(`The previous number for the number ${n} is ${nPrevious}.`)
}
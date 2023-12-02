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

    let n = readLine().toString()
    n.split('')
    let result = 0

    for(let number of n) {
        result += Number(number)
    }

    console.log(result)
}
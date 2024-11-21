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

    let result = 0
    for (let i = 0; i < n; i++) {
        result += Math.pow(i, 2)
    }
    let remain = Math.pow((n - 1), 2) + Math.pow(n, 2)


    console.log(result + remain)
}
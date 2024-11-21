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

    let a = readLine()
    let b = readLine()
    let c = readLine()
    
    let arr = []
    arr.push(a, b, c)

    let max = 0
    for (let i = 0; i <= arr.length; i++) {
        max < arr[i] ? max = arr[i] : 0
    }

    console.log(max)
}
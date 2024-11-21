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
    let a = Number(readLine())
    let b = Number(readLine())
    let c = Number(readLine())

    let result = isTrianglePossible(a, b, c)
    console.log(result === true ? "YES" : "NO")
}

function isTrianglePossible(a, b, c) {
    if (a + b > c && a + c > b && b + c > a) {
        return true;
    }
    return false;
}


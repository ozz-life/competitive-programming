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

    let d = Number(readLine())
    let e = Number(readLine());

    [a, b] = sortTwoNumbers(a, b)
    [b, c] = sortTwoNumbers(b, c)
    [a, b] = sortTwoNumbers(a, b)
    [d, e] = sortTwoNumbers(d, e)

    //console.log(a, b, c, d, e)

    let result = (c <= d && b <= e) ? true : false
    console.log(result ? "YES" : "NO")
}

function sortTwoNumbers(a, b) {
    if (a > b) {
        return [a, b] = [b, a];
    }
    return [a, b];
}
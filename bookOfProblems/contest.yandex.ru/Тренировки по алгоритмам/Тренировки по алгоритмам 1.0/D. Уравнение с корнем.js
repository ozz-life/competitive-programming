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

    if (c < 0 || (a == 0 && b != c**2)) console.log('NO SOLUTION')
    else if ((a == 0 && b == c**2) || a == b == c == 0) console.log("MANY SOLUTIONS")
    else {
        if ((c**2 - b) % a == 0) console.log(((c**2 - b) / a))
        else console.log("NO SOLUTION")
    }
}
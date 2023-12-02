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
function allDivisors(number) {

    let result = []
    for (let i = 0; i * i <= number; i++) {
        if (number % i == 0) {
            result.push(i)
            if (number / i != i) result.push(number / i)
        }
    }

    return result.sort((a, b) => a - b)
}

function main() {

    let n = readLine()
    console.log(allDivisors(n));
}
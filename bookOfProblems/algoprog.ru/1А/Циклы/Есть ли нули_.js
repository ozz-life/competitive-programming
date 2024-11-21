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
    let arr = []
    for (let i = 0; i < n; i++) {
        arr[i] = Number(readLine())
    }

    let hasZero = false
    for (let i = 0; i < n; i++) {
        if (arr[i] === 0) {
            hasZero = true;
            break;
        }
    }

    if (hasZero) {
        console.log("YES");
    } else {
        console.log("NO");
    }
}
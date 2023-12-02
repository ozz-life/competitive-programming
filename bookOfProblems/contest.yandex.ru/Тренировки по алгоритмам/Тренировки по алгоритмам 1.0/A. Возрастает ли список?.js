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
    let arr = readLine().split(' ').map(Number)

    let result = true
    for (let i = 0; i < arr.length - 1; i++) {
        if (arr[i + 1] > arr[i]) continue
        else {
            result = false
            break
        }
    }

    console.log(result == true ? "YES" : "NO")
}
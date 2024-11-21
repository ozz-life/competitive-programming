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
    let n = Number(readLine()) // количество резервуаров
    let a = readLine().split(' ').map(Number)

    let flag = true
    for (let i = 0; i < a.length - 2; i++) {
        if (a[i] > a[i + 1]) {
            flag = false
        }
    }

    if (flag) {
        console.log(a[n - 1] - a[0])
    } else console.log(-1)

}

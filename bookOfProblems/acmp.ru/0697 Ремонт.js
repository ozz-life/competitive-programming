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
    const [l, w, h] = readLine().split(' ').map(Number)
    let p = 2 * (l + w) // периметр комнаты
    let pb = p * h // площадь боковой поверхности
    console.log(Math.ceil(pb / 16))
}
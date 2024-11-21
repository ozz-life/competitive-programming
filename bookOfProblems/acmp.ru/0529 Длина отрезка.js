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

// https://en.wikipedia.org/wiki/Euclidean_distance
// x1 = startX, x2 = endX, y1= startY, y2 = endY
function lineSegmentLength(x1, x2, y1, y2) {
    let dx = x2 - x1;
    let dy = y2 - y1;
    return Math.sqrt(Math.pow(dx, 2) + Math.pow(dy,2));
}

function main() {
    const [x1, x2, y1, y2] = readLine().split(' ').map(Number)
    console.log(lineSegmentLength(x1, y1, x2, y2).toFixed(5))
}
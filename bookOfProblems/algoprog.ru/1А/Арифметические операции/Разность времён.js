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
    const timeConstants = new Map([
        ['SECOND', 1000],
        ['MINUTE', 60000],
        ['HOUR', 3600000],
        ['DAY', 86400000],
        ['WEEK', 604800000],
        ['YEAR', 31556736000],
        ['NORMAL_YEAR', 31536000000],
        ['LEAP_YEAR', 31622400000],
        ['DECADE', 315567360000],
        ['HALF_YEAR', 15778368000],
        ['AVERAGE_MONTH', 2629728000],
        ['',],
    ]);

    let timestamp0H = readLine()
    let timestamp0M = readLine()
    let timestamp0S = readLine()
    let timestamp1H = readLine()
    let timestamp1M = readLine()
    let timestamp1S = readLine()

    let timestamp0HtoMS = timestamp0H * timeConstants.get('HOUR')
    let timestamp0MtoMS = timestamp0M * timeConstants.get('MINUTE')
    let timestamp0StoMS = timestamp0S * timeConstants.get('SECOND')
    let timestamp1HtoMS = timestamp1H * timeConstants.get('HOUR')
    let timestamp1MtoMS = timestamp1M * timeConstants.get('MINUTE')
    let timestamp1StoMS = timestamp1S * timeConstants.get('SECOND')

    let result =
        ((timestamp1HtoMS - timestamp0HtoMS) +
            (timestamp1MtoMS - timestamp0MtoMS) +
            (timestamp1StoMS - timestamp0StoMS)) / timeConstants.get('SECOND')

    console.log(result)
}
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
    let add = readLine().split(' ')
    let a = readLine().split(' ')
    let b = readLine().split(' ')
    let c = readLine().split(' ')

    // Тестовый набор сразу в переменные, без чтения стандартного ввода
    // let add = "8(495)430-23-97"
    // let a = "+7-4-9-5-43-023-97"
    // let b = "4-3-0-2-3-9-7"
    // let c = "8-495-430"

    let numbers = []
    numbers.push(add, a, b, c)

    let transformNumbers = numbers.map(transformToDeleteSymbolsWithoutPlus)
        .map(transformFrom7To11NumbersWithPlus)
        .map(transform8toPlus7StartWith)

    for (let i = 1; i < transformNumbers.length; i++) {
        if (transformNumbers[0] == transformNumbers[i]) console.log('YES')
        else console.log('NO')
    }
}

function transformToDeleteSymbolsWithoutPlus(itemNumber) {
    let regex = /[^+0-9]/gi;
    return itemNumber.toString().replace(regex, "");
}

function transformFrom7To11NumbersWithPlus(itemNumber) {
    if (itemNumber.length == 7) {
        return itemNumber = "+7495" + itemNumber
    } else {
        return itemNumber
    }
}

function transform8toPlus7StartWith(itemNumber) {
    if (itemNumber.startsWith("8")) {
        return itemNumber.replace("8", "+7")
    } else return itemNumber
}
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
    let [troom, tcond] = readLine().split(' ').map(Number)
    let workingMode = readLine()

    switch (workingMode) {
        case 'freeze':
            if (troom > tcond) console.log(tcond)
            else if (troom <= tcond) console.log(troom)
            break;
        case 'heat':
            if (troom < tcond) console.log(tcond)
            else if (troom >= tcond) console.log(troom)
            break;
        // «auto» — автоматический режим. В этом режиме кондиционер может как увеличивать, так и уменьшать температуру в комнате до желаемой.
        case 'auto':
            console.log(tcond)
            break;
        //«fan» — вентиляция. В этом режиме кондиционер осуществляет только вентиляцию воздуха и не изменяет температуру в комнате.
        case 'fan':
            console.log(troom)
            break;
        // default:
        //     console.log("default switch error")
        //     break;
    }
}


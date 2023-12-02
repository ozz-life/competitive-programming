#!/usr/bin/env node
     
process.stdin.resume();
process.stdin.setEncoding("utf-8")
 
let standardInputString = ''
let currentLine = 0
 
function readLine() {
    return standardInputString[currentLine++]
}
 
process.stdin.on('data', rawData => {
    standardInputString += rawData
})
 
process.stdin.on('end', _ => {
    standardInputString = standardInputString.trim().split('\n').map(line => {
        return line.trim()
    })
    main()
})
// ********** Code Start **********
 
function main() {
 
    let a = readLine()
    if (a % 2 == 0 && a > 2) {
        console.log('YES')
    } else {
        console.log('NO')
    }
}
#!/usr/bin/env node

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let commands = '';

process.stdin.on('data', function (input) {
    commands += input;
});

process.stdin.on('end', function () {

    /*
     * Code Start
     **************************************************************************/

    let input = commands.trim().split('\n');
    let k = parseInt(input[0]);
    let s = input[1].trim().split(' ').toString()

    // взять все символы в slidingWindow. Посчитать их количество.
    // вычислить из максимального все остальные
    // mostFrequency = slidingWindowMap.size - MAX <= k

    //Сохрани для каждой буквы алфавита все позиции и дальше только на них пиши поиск
    // for (let char = 0; char <= s.length; char++) {
    //     map.set(s[char], char);
    // }

    // let slidingWindowMaxValue = 0;
    // let mostFrequency = slidingWindowMap.size - slidingWindowMaxValue;
    // let slidingWindowMaxMapSize = 0
    // for (let r = 0, l = 0; r < s.length; r++) {
    //     if (slidingWindowMap.size - mostFrequency <= k) {
    //         slidingWindowMap.set(s[r], slidingWindowMap.get(s[r]) + 1 || 1);
    //         for (const [key, value] of slidingWindowMap) {
    //             slidingWindowMaxValue = Math.max(slidingWindowMaxValue, value);
    //         }
    //         if (slidingWindowMap.size > slidingWindowMaxMapSize) slidingWindowMaxMapSize = slidingWindowMap.size
    //     }
    //     else {
    //        console.log('else') 
    //     }

    let count = {}
    let result = 0
    let maxFreq = 0

    for (let r = 0, l = 0; r < s.length; r++) {
        count[s[r]] = count[s[r]] ? count [s[r]] + 1 : 1;
        maxFreq = Math.max(maxFreq, count[s[r]])
        while (r - l + 1 - maxFreq > k) {
            count[s[l]]--
            l++
        }
        result = Math.max(result, r - l + 1)
    }

    console.log(result)
});
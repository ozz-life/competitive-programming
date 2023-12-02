s = "MCMXCIV"

var romanToInt = function (s) {
    let map = new Map([
        ['I', 1],
        ['V', 5],
        ['X', 10],
        ['L', 50],
        ['C', 100],
        ['D', 500],
        ['M', 1000],
    ])

    let num = map.get(s.at(-1))

    for (let i = s.length - 2; i >= 0; i--) {
        if (map.get(s[i]) >= map.get(s[i + 1])) {
            num += map.get(s[i])
        } else {
            num -= map.get(s[i])
        }
    }

    return num
}

console.log(romanToInt(s));
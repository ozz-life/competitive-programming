str1 = "ABABAB", str2 = "ABAB"

/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function (str1, str2) {
    if (str1 + str2 == str2 + str1) {
        return str1.slice(0, gcd(str1.length, str2.length))
    } else {
        return ""
    }
};

function gcd(a, b) {
    a = Math.abs(a);
    b = Math.abs(b);
    if (b > a) { var temp = a; a = b; b = temp; }
    while (true) {
        if (b == 0) return a;
        a %= b;
        if (a == 0) return b;
        b %= a;
    }
}

console.log(gcdOfStrings(str1, str2));
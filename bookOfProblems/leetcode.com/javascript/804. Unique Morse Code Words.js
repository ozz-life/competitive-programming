/**
 * @param {string[]} words
 * @return {number}
 */
let words = ["gin", "zen", "gig", "msg"]

var uniqueMorseRepresentations = function (words) {

    const alphabet = { a: ".-", b: "-...", c: "-.-.", d: "-..", e: ".", f: "..-.", g: "--.", h: "....", i: "..", j: ".---", k: "-.-", l: ".-..", m: "--", n: "-.", o: "---", p: ".--.", q: "--.-", r: ".-.", s: "...", t: "-", u: "..-", v: "...-", w: ".--", x: "-..-", y: "-.--", z: "--.." }
    return new Set(words.map(word => word.split('').map(letter => alphabet[letter]).join(''))).size

    // return new Set(
    //     words.map(
    //         word => word.split('')
    //             .map(letter => alphabet[letter])
    //             .join('')
    //     )
    // ).size

};

console.log(uniqueMorseRepresentations(words));
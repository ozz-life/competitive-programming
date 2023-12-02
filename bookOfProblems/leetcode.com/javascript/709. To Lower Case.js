/**
 * @param {string} s
 * @return {string}
 */
var toLowerCase = function (s) {
    return s.toLowerCase()
};

////////////////////////////////////////////////////////////////////////////////

var toLowerCase = function (s) {
    let output = '';
    for (let i = 0; i < s.length; i++) {
        const character = s.charCodeAt(i);
        if (character >= 65 && character <= 90) {
            output += String.fromCharCode(character + 32);
        } else {
            output += s[i];
        }
    }

    return output;
};

////////////////////////////////////////////////////////////////////////////////

const toLowerCase = str =>
    str.replace(/[A-Z]/g, a => String.fromCharCode(a.charCodeAt(0) + 32));
// ecause the regular expression in the first parameter is global, the function is invoked multiple times for each full match to be replaced.
// See also: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replace#specifying_a_function_as_a_parameter

////////////////////////////////////////////////////////////////////////////////

var toLowerCase = function (s) {
    let alphabet = { A: "a", B: "b", C: "c", D: "d", E: "e", F: "f", G: "g", H: "h", I: 'i', J: 'j', K: 'k', L: 'l', M: 'm', N: 'n', O: 'o', P: 'p', Q: 'q', R: 'r', S: 's', T: 't', U: 'u', V: 'v', W: 'w', X: 'x', Y: 'y', Z: 'z' }
    let str = ''
    for (char of s) {
        if (char in alphabet) {
            str += alphabet[char]
        }
        else {
            str += char
        }
    }
    return str

};

////////////////////////////////////////////////////////////////////////////////

var toLowerCase = function(str) {
    // create an array from the string by splitting up the characters
	let a = str.split('');
	
	// map over each element in the array and add 32 to the character if uppercase, otherwise return the character
    let b = a.map(a => (
        a.charCodeAt() < 91 && a.charCodeAt() > 64 ? String.fromCharCode(a.charCodeAt() + 32) : a
    ));
	
	// join the characters of the new array made up of all lowercase letters and return a string
    return b.join('');    
}

////////////////////////////////////////////////////////////////////////////////
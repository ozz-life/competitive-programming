/**
 * @param {string} seq
 * @return {number[]}
 */

let seq = "()(())()"
var maxDepthAfterSplit = function (seq) {
    let arr = []
    for (let i = 0; i < seq.length; i++) {
        arr.push(seq[i] == "(" ? i & 1 : 1 - i & 1)
    }
    return arr
};

////////////////////////////////////////////////////////////////////////////////

var maxDepthAfterSplit = function(seq) {
    const result = [];
    let depth = 0;
    for(let ch of seq) {
        if (ch == '(') {
            ++depth;
            result.push(depth & 1);
        } else  {
            result.push(depth & 1);
            --depth;
        }
    }
    return result;
};

////////////////////////////////////////////////////////////////////////////////

console.log(maxDepthAfterSplit(seq));
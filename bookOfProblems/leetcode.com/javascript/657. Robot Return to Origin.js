moves = "LULLLDDLUURUUULDUDDRDLDDURUUDDURDRLRURLDRDDRLUULDLDLULRUDRULUDLDUUUURLDRURLLRRUUDLLDUDDLULUURLDRLDRL"
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
    let map = new Map()

    for (let char of moves) {
        map.set(char, map.get(char) + 1 || 1)
    }

    console.log(map)
    if (map.get('U') != map.get('D')) return false
    if (map.get('L') != map.get('R')) return false
    else return true
};

console.log(judgeCircle(moves));
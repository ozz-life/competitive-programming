rings = "B0R0G0R9R0B0G0R9R8B9G9"

/**
 * @param {string} rings
 * @return {number}
 */
// var countPoints = function (rings) {
//     let rods = '0123456789';
//     let count = 0;
//     for (let rod of rods) { // looping over the variable, rods
//         if (rings.includes(`R${rod}`) &&
//             rings.includes(`G${rod}`) &&
//             rings.includes(`B${rod}`)) count++; // checking if rings includes
//         // R, G, & B on that rod
//         // if so, add to count
//     } return count;
// };

////////////////////////////////////////////////////////////////////////////////

// var countPoints = function (rings) {
//     let n = rings.length;

//     let map = new Map(); // map of  rod nums  to their  set of colors
//     for (let i = 0; i < n; i += 2) {
//         let color = rings[i];
//         let rod = +rings[i + 1];

//         if (!map.has(rod)) map.set(rod, new Set());
//         map.get(rod).add(color);
//     }
//     console.log(map)

//     let count = 0;
//     for (let [rod, setColors] of map) {
//         console.log(`rod: ${rod} | setColors: ${setColors.size}`)
//         if (setColors.size == 3) count++;
//     }
//     return count;
// };

////////////////////////////////////////////////////////////////////////////////

var countPoints = function (rings) {
    let map = new Map();

    for (let i = 0; i < rings.length; i += 2) {
        let color = rings[i];
        let position = rings[i + 1];

        if (map.has(position)) {
            let current = map.get(position);
            current.add(color);
        } else {
            map.set(position, new Set(color));
        }
    }

    return Array.from(map.values()).reduce((acc, item) => {
        return item.size === 3 ? acc + 1 : acc;
    }, 0);
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

console.log(countPoints(rings));
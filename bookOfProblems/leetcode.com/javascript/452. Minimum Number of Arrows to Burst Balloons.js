points = [[10, 16], [2, 8], [1, 6], [7, 12]]

/**
 * @param {number[][]} points
 * @return {number}
 */
// var findMinArrowShots = function (points) {
//     points.sort((a, b) => a[0] - b[0])
//     let prev = null, count = 0

//     console.log(points)
//     for (let [start, end] of points) {
//         if (prev == null || prev < start) {
//             console.log(`${prev}, ${end}`)
//             count++
//             prev = end
//         } else {
//             prev = Math.min(prev, end)
//             console.log(`else ${prev}, ${end}`)
//         }
//     }
//     return count

// };

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    points.sort((a, b) => a[0] - b[0])
    
    let darts = 1
    let currentOverlapR = points[0][1]

    for (let i = 1; i < points.length; i++) {
        if (points[i][0] > currentOverlapR) {
            darts++
            currentOverlapR = points[i][1]
            continue
        }
        if (points[i][1] <= currentOverlapR) {
            currentOverlapR = Math.min(currentOverlapR, points[i][1])
        }
    }

    return darts
};

console.log(findMinArrowShots(points));
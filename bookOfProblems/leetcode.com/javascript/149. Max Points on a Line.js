points = [[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]

// var maxPoints = function (points) {
//     return (points.length == 1) ? 1 : points.map((cv, i, arr) => {
//         return arr.map((value, index) => {
//             return [arr[index][0] - cv[0], arr[index][1] - cv[1]]
//         })
//     }).map((v) => {
//         return v.map((cv, i, arr) => {
//             return arr.map((value, index) => {
//                 return cv[0] * arr[index][1] - arr[index][0] * cv[1]
//             })
//         })
//     }).map((p, i, arr) =>
//         p.map((cv, i, ar) => {
//             return cv.reduce((sum, val) => {
//                 return (val == 0) ? sum += 1 : sum += 0
//             }, 0)
//         })).map((el, i) => {
//             return (el.reduce((o, c, ind) =>
//                 (o < c && i != ind) ? c : o))
//         }).reduce((o, c, i) =>
//             (o < c && i != 0) ? c : o, 0);
// };

////////////////////////////////////////////////////////////////////////////////

// Get the greatest common divisor, based on Euclid's algorithm
// const getGcd = (a, b) => b === 0 ? a : getGcd(b, a % b);

// Get the components of the slope between two points
// (actually returning the slope can cause problems due to division inaccuracy)
// const getSlopeComponents = ([x1, y1], [x2, y2]) => {
//     const yDiff = y2 - y1;
//     const xDiff = x2 - x1;
//     const gcd = getGcd(yDiff, xDiff);
//     return gcd === 0 ? [yDiff, xDiff] : [yDiff / gcd, xDiff / gcd];
// };

// // Get the maximum number of points with the same slope as a given starting point
// const getMaxPointsFromPoint = (startPoint, points) => {
//     const slopeCounts = {};
//     let samePointEncounters = 0;

//     for (const endPoint of points) {
//         const slopeComponents = getSlopeComponents(startPoint, endPoint);
//         if (slopeComponents[0] === 0 && slopeComponents[1] === 0) {
//             samePointEncounters++;
//         } else if (slopeComponents in slopeCounts) {
//             slopeCounts[slopeComponents]++;
//         } else {
//             slopeCounts[slopeComponents] = 1;
//         }
//     }

//     return Math.max(0, ...Object.values(slopeCounts)) + samePointEncounters;
// };

// // Find the maximum number of points along a line starting from any given point
// const maxPoints = points => points.reduce((result, point) => Math.max(result, getMaxPointsFromPoint(point, points)), 0);

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[][]} points
 * @return {number}
 */
// var maxPoints = function(points) 
// {
//     const n = points.length;
//     if(n === 1)
//         return 1;
//     const INF = 100000;     // Anything over 20k should suffice for "infinite" slope.

//     let maxLP = 0;
//     for(let i=0; i<n-1; i++)
//     {
//         let [x0,y0] = points[i];

//         /* Find the slopes between this point and the others. */
//         let slopes = new Map();
//         for(let j=i+1; j<n; j++)
//         {
//             let [x1,y1] = points[j];
//             let slope = INF;
//             if(x1 !== x0)
//                 slope = (y1-y0)/(x1-x0);
//             let cnt = slopes.get(slope) || 0;
//             slopes.set(slope, cnt+1);
//         }

//         /* Find the most frequently occuring slope. */
//         let slopeArr = [...slopes];
//         let pointMax = slopeArr.reduce((acc,val)=>Math.max(acc,val[1]),0);

//         maxLP = Math.max(maxLP, pointMax);
//     }

//     return maxLP+1;
// };

////////////////////////////////////////////////////////////////////////////////

// var maxPoints = function (points, max = 0) {
//     //Take each point as Center, and enumerate.
//       for (let i = 0; i < points.length-1; i++) {
//     //See how many points are with the same angle with current center.
//         let counter = {}, curMax = 0;
//         for (let j = i + 1; j < points.length; j++) {
//           let key = getAngle(points[i][0], points[i][1], points[j][0], points[j][1]);
//           counter[key] = (counter[key] || 0) + 1;
//           curMax = Math.max(counter[key], curMax);
//         }
//         max = Math.max(max, curMax + 1);
//       }
//       return max;

//     //Seperated function to calculate angle between 2 points.
//       function getAngle(x1, y1, x2, y2) {
//         let dx = Math.abs(x1 - x2),dy = Math.abs(y1 - y2),gcd = Math.min(dx, dy);
//         return (x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2)
//           ? "-" + dy / gcd + "" + dx / gcd
//           : dy / gcd + "" + dx / gcd;
//       }
//     };

////////////////////////////////////////////////////////////////////////////////

// var maxPoints = function(points) {
//     const n = points.length;

//     const calculateSlope = (x1, y1, x2, y2) => {
//         return x2 - x1 === 0 ? Infinity : (y2 - y1) / (x2 - x1);
//     };

//     let max = 1;
//     for(let i = 0; i < n; i += 1) {
//         const [x1, y1] = points[i];
//         const slopes = new Map();
//         for(let j = i + 1; j < n; j += 1) {
//             const [x2, y2] = points[j];
//             const slope = calculateSlope(x1, y1, x2, y2);
//             if(!slopes.has(slope)) {
//                 slopes.set(slope, 0);
//             }
//             slopes.set(slope, slopes.get(slope) + 1);
//         }

//         for(const [,occurrences] of slopes) {
//             max = Math.max(max, occurrences + 1);
//         }
//     }

//     return max;
// };

////////////////////////////////////////////////////////////////////////////////

/*
 * @lc app=leetcode id=149 lang=javascript
 *
 * [149] Max Points on a Line
 */

// @lc code=start

// var getGCD = function(a, b) {
//     return b === 0 ? a : getGCD(b, a % b);
// }

// var getSlope = function (p1, p2) {
//     var xDiff = p1[0] - p2[0];
//     var yDiff = p1[1] - p2[1];
//     if (xDiff === 0) return 'y';
//     if (yDiff === 0) return 'x';
//     var gcd = getGCD(xDiff, yDiff);
//     xDiff /= gcd;
//     yDiff /= gcd;
//     return `${xDiff}/${yDiff}`;
// }

// /**
//  * @param {number[][]} points
//  * @return {number}
//  */
// var maxPoints = function(points) {
//     var len = points.length;
//     if (len < 3) return len;
//     var max = 0;
//     for (var i = 0; i < len; i++) {
//         var map = new Map();
//         var sameCount = 0;
//         var curMax = 0;
//         for (var j = i + 1; j < len; j++) {
//             if (points[j][0] === points[i][0] && points[j][1] === points[i][1]) {
//                 sameCount++;
//                 continue;
//             }
//             var slope = getSlope(points[i], points[j]);
//             if (!map.has(slope)) map.set(slope, 1);
//             else map.set(slope, map.get(slope) + 1);
//             curMax = Math.max(curMax, map.get(slope));
//         }
//         max = Math.max(max, curMax + sameCount + 1);
//     }
//     return max;
// };


// console.log(maxPoints([[0,0],[1,1],[0,0]]))
// console.log(maxPoints([[1,1],[1,1],[1,1]]))
// console.log(maxPoints([[4,0],[4,-1],[4,5]]))
// console.log(maxPoints([[1,1],[2,2],[3,3]]))
// console.log(maxPoints([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]))
// console.log(maxPoints([[0,0],[94911151,94911150],[94911152,94911151]]))


// @lc code=end

////////////////////////////////////////////////////////////////////////////////

// var maxPoints = function (points) {
//     let max = 0;
//     for (const x of points) {
//         const slopes = new Map();
//         for (const y of points) {
//             if (x === y) continue;
//             let slope = Infinity;
//             if (y[0] - x[0] !== 0) {
//                 slope = (y[1] - x[1]) / (y[0] - x[0]);
//             }
//             if (slopes.has(slope)) {
//                 slopes.set(slope, slopes.get(slope) + 1);
//             } else {
//                 slopes.set(slope, 1);
//             }
//             max = Math.max(max, slopes.get(slope));
//         }
//     }
//     return max + 1;
// };

////////////////////////////////////////////////////////////////////////////////


// This is unnecessary, but being able to do .addLine(slope) and extracting the maxVal is useful
class LineMap extends Map {
    constructor() {
      super();
      this.maxVal = 0;
    }
    
    addLine(slope) {
      if (this.has(slope)) this.set(slope, this.get(slope) + 1);
      else {
       // Since this slope was never seen, a slope can only exist if there's 2 Points.
       //  We calculated these... that's how we got the slope in the FIRST place
       this.set(slope, 2);
      }
      
      this.maxVal = Math.max(this.maxVal, this.get(slope));
    }
    
    clear() {
      super.clear(); // We want to call the super class, ie. the Map() and clear that
      this.maxVal = 0; // Then we want to RESET the value
    }
  }
  
  function getSlope(aPoint, bPoint) {
    const [x1, y1] = aPoint;
    const [x2, y2] = bPoint;
    // This is very important. A vertical line has a slope of undefined.
    // We should use a UNIQUE value to represent this a vertical line. Else, last test will fail.
    if (x1 === 0 && x2 === 0) return Math.PI; 
    return parseFloat((y2 - y1) / (x2 - x1));
  }
  /**
   * @param {number[][]} points
   * @return {number}
   */
  var maxPoints = function(points) {
    
    const lines = new LineMap();
    let mostPoints = 1; // Considering we are always going to recieve at least 1 point
    
    
    for (let i = 0; i < points.length; i++) {
      const aPoint = points[i];
      lines.clear();
      for (let j = i + 1; j < points.length; j++) {
        const bPoint = points[j];
        const slope = getSlope(aPoint, bPoint);
        lines.addLine(slope);
      }
      console.log('lines', lines);
      mostPoints = Math.max(mostPoints, lines.maxVal);
    }
    return mostPoints;
  };

////////////////////////////////////////////////////////////////////////////////

console.log(
    maxPoints(points));
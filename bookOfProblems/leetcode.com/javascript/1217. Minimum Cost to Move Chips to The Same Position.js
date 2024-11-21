/**
 * @param {number[]} position
 * @return {number}
 */

var minCostToMoveChips = function (chips) {
    return Math.min(
      ...chips.reduce(
        (acc, cur) => {
          cur % 2 ? acc[0]++ : acc[1]++;
          return acc;
        },
        [0, 0]
      )
    );
  };

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function (position) {
    const map = new Map();
    let cost = 0;

    // Count even and odd numbers
    for (let i = 0; i < position.length; i++) {
        position[i] % 2 == 0 ? map.set('evens', map.get('evens') + 1 || 1)
            : map.set('odds', map.get('odds') + 1 || 1)
    }
    // if number of odds are greater, we should determine the cost of moving only even numbers or else vice versa 
    const oddOrEven = (map.get('evens') || 0) > (map.get('odds') || 0) ? 1 : 0;

    for (let i = 0; i < position.length; i++) {
        if (position[i] % 2 == oddOrEven) cost++
    }

    return cost
};

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function (position) {
    let evenPosistionChips = 0;
    let oddPositionChips = 0
    for (let i of position) {
        if (i % 2 === 0) {
            evenPosistionChips++;
        } else {
            oddPositionChips++;
        }
    }
    return Math.min(evenPosistionChips, oddPositionChips)
};

////////////////////////////////////////////////////////////////////////////////

const minCostToMoveChips = position => Math.min(...position.reduce((acc, cur) => { cur % 2 ? acc[0]++ : acc[1]++; return acc; }, [0, 0]));

////////////////////////////////////////////////////////////////////////////////

const minCostToMoveChips = position => Math.min(...position.reduce((acc, cur) => (++acc[cur % 2], acc), [0, 0]));

////////////////////////////////////////////////////////////////////////////////

var minCostToMoveChips = function(position) {
    return Math.min(position.reduce((count, pos) => count + (pos & 1), 0), position.reduce((count, pos) => count + 1 - (pos & 1), 0));
};

////////////////////////////////////////////////////////////////////////////////

var minCostToMoveChips = function (position) {
    let evenCount = 0, oddCount = 0;

    for (let pos of position) {
        pos % 2 === 0 ? evenCount++ : oddCount++;
    }

    return Math.min(evenCount, oddCount)
};

////////////////////////////////////////////////////////////////////////////////

var minCostToMoveChips = function (chips) {
    return Math.min(
      ...chips.reduce(
        (cumm, cur) => {
          cur % 2 ? cumm[0]++ : cumm[1]++;
          return cumm;
        },
        [0, 0]
      )
    );
  };
names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
//  var sortPeople = function(names, heights) {

// };


////////////////////////////////////////////////////////////////////////////////

// /**
//  * @param {string[]} names
//  * @param {number[]} heights
//  * @return {string[]}
//  */
// var sortPeople = function (names, heights) {
//     let data = [];

//     for (let i = 0; i < names.length; i++) {
//         let obj = {
//             name: names[i],
//             height: heights[i]
//         };
//         data.push(obj);
//         console.log(obj)
//     }

//     // sort data in descending order using the predicate (a, b) => b.height - a.height
//     // (if we wanted to sort in ascending order then we'd do (a, b) => a.height - b.height), and use .map() so we return only the name properties.
//     return data.sort((a, b) => b.height - a.height).map(item => item.name);
// };

////////////////////////////////////////////////////////////////////////////////

// const sortPeople = (names, heights) =>
//     names.map((name, i) => [heights[i], name])
//         .sort((a, b) => b[0] - a[0])
//         .map(el => el[1])

////////////////////////////////////////////////////////////////////////////////

var sortPeople = function (names, heights) {
    let length = heights.length;
    let map = new Map();
    for (let i = 0; i < length; i++) {
        map.set(heights[i], names[i]);
    }
    console.log(map)

    heights.sort((a, b) => b - a);
    let res = [];
    for (let height of heights) {
        res.push(map.get(height));
    }
    return res;
};

////////////////////////////////////////////////////////////////////////////////

var sortPeople = function (names, heights) {
    // merge both arrays at same index
    return names.map((e, i) => e + heights[i])
        //sort the merged array in decresing order 
        .sort((a, b) => b.match(/\d+/) - a.match(/\d+/))
        // convert to string
        .join(' ')
        //use regex to remove integers from string
        .replace(/[0-9]/g, '')
        //move back into array 
        .split(" ")
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

console.log(sortPeople(names, heights));
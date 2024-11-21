'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');
process.stdin.on('data', function (input) {

  let map = new Map();
  for (let n of input) {
    if (n == " " || n == "\n" || n == "\r\n" || n == "\r") continue
    map.set(n, (map.get(n) ?? 0) + 1);
  }

  let maxHeight = 0;
  for (const [key, value] of map) {
    maxHeight = Math.max(maxHeight, value);
  }

  const sortedMap = new Map(Array.from(map).sort((a, b) => a[0].codePointAt(0) - b[0].codePointAt(0)));
  let keyString = Array.from(sortedMap.keys()).join('');

  // for (let i = maxHeight; i >= 1; i--) {
  //   let row = '';

  //   for (let j = 0; j < histogram.length; j++) {
  //     if (histogram[j] >= i) {
  //       row += '#';
  //     } else {
  //       row += ' ';
  //     }
  //   }

  //   console.log(row);
  // }  

  //////////////

  for (let i = maxHeight; i >= 1; i--) {
    let row = '';

    sortedMap.forEach((value, key) => {
      if (value >= i) {
        row += '#';
      } else {
        row += ' ';
      }
    });

    console.log(row);
  }

  console.log(keyString)

});
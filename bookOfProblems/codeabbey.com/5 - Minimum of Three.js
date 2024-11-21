
"use strict"

let array0 = [];

function getValue(){
    let testDate = document.getElementById('getValue').value;
    let array = testDate.split(/\n|\s/g).map(a=>Number(a))
    console.table(array);

    return array0 = array;
 }

let arrayA = [];
let arrayB = [];
let arrayC = [];
let arrayResult = [];

if (array0.length > 0) {
    do {
        arrayA.push(array0.pop());
        arrayB.push(array0.pop());
        arrayC.push(array0.pop());
    } while (array0.length > 0);
} else {
    null;
}

function diffAndCreateResultArray (arrayA, arrayB, arrayC) {
    for (let i = 0; i < arrayA.length; i++) {
        arrayResult.push(Math.min(arrayA[i], arrayB[i], arrayC[i]));
    }
    arrayResult.reverse().join();
}

diffAndCreateResultArray(arrayA, arrayB, arrayC);

 console.log(arrayA);
 console.log(arrayB);
 console.log(array0);
 console.log(arrayResult);

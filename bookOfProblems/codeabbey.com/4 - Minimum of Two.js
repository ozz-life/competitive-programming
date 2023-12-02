let array0 = [];

function getValue(){
    let testDate = document.getElementById('getValue').value;
    let array = testDate.split(/\n|\s/g).map(a=>Number(a))
    console.table(array);

    return array0 = array;
 }

let arrayA = [];
let arrayB = [];
let arrayResult = [];

if (array0.length > 0) {
    do {
        arrayA.push(array0.pop());
        arrayB.push(array0.pop());
    } while (array0.length > 0);
} else {
    null;
}

function diffAndCreateResultArray (arrayA, arrayB) {
    for (let i = 0; i < arrayA.length; i++) {
        if (arrayA[i] < arrayB[i]) {
            arrayResult.push(arrayA[i]);
        } else {
            arrayResult.push(arrayB[i]);
        }
    }
    arrayResult.reverse();
}

diffAndCreateResultArray(arrayA, arrayB);

 console.log(arrayA);
 console.log(arrayB);
 console.log(array0);
 console.log(arrayResult);

//  function minimumOfTwo(data){
//     data = data.split(/\n|\s/g).map(a=>Number(a))
//     let arr = []
//     for(let i = 0; i < data.length; i+=2){
//       data[i]<data[i+1] ? arr.push(data[i]) : arr.push(data[i+1])
//     }
//     return arr.join(' ')
//   }
// function add(n1: number, n2: number) {
//     return n1 + n2;
// }

// function printResult(num: number) {
//     console.log('result -> ', num);
// }

// printResult(add(5, 6));

// function addAndHandle(n1: number, n2: number, cb: (num: number) => void) {
//     const result = n1 + n2;
//     cb(result);
// }

// // let combineValues;
// // combineValues = 5; // because till here combine values is of type any
// // let combineValues: Function;
// // combineValues = printResult; //because it can still take a function

// let combineValues: (a: number, b: number) => number;
// combineValues = add;
// console.log(combineValues(8, 8));


// addAndHandle(10, 20, (result) => {
//     console.log(result);
// })
// declaration, definition,, statement -- 
function square(num) {
    return num * num;
}

// function expression -- store a function inside a variable
const square = function (num) {
    return num * num;
}

// First Class function -- A function can be treated like a variable. In this a function can be passed to another function, used, manipulated and returned from a function.
function displayMsg(cb) {
    console.log('square of number -- ', ccb(5));
}
displayMsg(square);

// IIFE -- Immediately Invoked Function Expression
(function square(num) {
    return num * num;
})(5);

// Params vs Arguments
function square(num) { // < -- params (we received params in a function)
    return num * num;
}
square(5) // < -- arguments

// Spread vs Rest operators
function multiply(...num) { // rest operator
    return num[0] * num[1];
}
const arr = [5, 6];
multiply(...arr); // spread operator

// arrow vs regular function
// 1. syntax
// 2. implicit return -- in arrow function we may not use the return keyword
// 3. arguments -- inside a regular function we get the arguments keyword
// 4. this -- inside a arrow function this points to the global object
const arr = [1, 2, 3, 4, 5];
// const thisIsThis = { hey: 1 };


// a function which returns an array by squaring each index
// const result = myMap(arr, transformArray, thisIsThis);
// console.log('result squared -- ', result);

// function transformArray(elem, index, origArray) {
//     console.log('this -- ', this);
//     return elem * elem;
// }

// function myMap(dataArray, callbackFn, thisArg) {
//     let finalArray = [];

//     for (let i = 0; i < dataArray.length; i++) {
//         const value = dataArray[i];
//         const newValue = callbackFn.call(thisArg, value, i, dataArray);
//         finalArray.push(newValue);
//     }

//     return finalArray;
// }




// polyfill - 
Array.prototype.myMap = function (callbackFn, thisArg) {
    // NOTE: here if we console this then it will print the array as we are calling the myMap function on the array

    // edge case -- 
    if (typeof callbackFn !== "function") {
        throw new TypeError("Callback function is not a function");
    }

    // edge case -- map doesn't create an empty array, but it creates an array of specific length,
    const result = new Array(this.length);
    // map doesn't use for loop, it uses while loop and it sets the new value in the particular index instead of pushing it into the array
    let ind = 0;
    while (ind < this.length) {
        // edge case -- need to check if index is initialized or not
        if (this.hasOwnProperty(ind)) {
            result[ind] = callbackFn.call(thisArg, this[ind], ind, this);
        }
        ind++;
    }
    return result;
}

function getSquaredNumber(num) {
    return num * num;
}

// always have a named function call as a callbackFn because otherwise we have to read the entire function to understand what is happening inside it.
const resultPolyfill = arr.myMap(getSquaredNumber);
console.log('result -- ', resultPolyfill);
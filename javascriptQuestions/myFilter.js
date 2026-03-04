// const arr = [1, 2, 3, 4, 5];
// const thisIsThis = { name: "magic" };

// const result = myFilter(arr, transformFunction, thisIsThis);
// console.log('result -- ', result);

// function transformFunction(ele, index, array) {
//     console.log('this -- ', this);
//     return ele % 2 === 0;
// }

// function myFilter(dataArray, callbackFn, thisArg) {
//     const result = [];

//     for (let i = 0; i < dataArray.length; i++) {
//         const value = dataArray[i];

//         const needToAdd = callbackFn.call(thisArg, value, i, arr);

//         needToAdd && result.push(value);
//     }

//     return result;
// }

// using prototype chain
const arr = [1, 2, 3, 4, 5, 6];

Array.prototype.myFilter = function (callbackFn, thisArg) {
    if (typeof callbackFn !== "function") {
        throw new TypeError("Callback function is not a function");
    }

    const result = [];
    let index = 0;
    while (index < this.length) {
        if (this.hasOwnProperty(index)) {
            const value = this[index];
            const needToAdd = callbackFn.call(thisArg, value, index, this);
            if (needToAdd) result.push(value);
        }
        index++;
    }
    return result;
}

function transformFunction(ele, index, arr) {
    return ele % 2 === 0;
}

const result = arr.myFilter(transformFunction);
console.log('result -- ', result);
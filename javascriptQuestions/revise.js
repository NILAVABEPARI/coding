const arr = [1, 2, 3, 4, 5];
const arr2 = [, , 4, 5];

Array.prototype.myReduce = function (callbackFn, initValue) {
    if (this === null) throw new TypeError("array is null");

    if (typeof callbackFn != "function") throw new TypeError("callback is not a function");

    const array = Object(this);
    const len = array.length >>> 0;

    let accumulator, startInd = 0;
    if (arguments.length > 1) {
        accumulator = initValue;
    } else {
        while (startInd < len && !(startInd in array)) startInd++;
        if (startInd >= len) throw new Error("reduce on empty array with no initial value");

        accumulator = array[startInd++];
    }

    for (let i = startInd; i < len; i++) {
        if (i in array) {
            accumulator = callbackFn(accumulator, array[i], i, array);
        }
    }

    return accumulator;
}

const result1 = arr.myReduce(sumFunction, 0);
const result2 = arr2.myReduce(sumFunction, 0);
const result3 = Array.prototype.myReduce.call("abc", (a, b) => a + b);

function sumFunction(acc, currVal, ind, origArray) {
    return acc + currVal;
}

console.log('result1 -- ', result1);
console.log('result2 -- ', result2);
console.log('result3 -- ', result3);
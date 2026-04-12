const arr = [1, 2, 3, 4, 5, 6];
const arr2 = "abc";

const result = arr.reduce(function (acc, next, index, array) {
    return acc + next;
}, 0);

console.log('result -- ', result);

Array.prototype.myReduce = function (callbackFn, initialValue) {
    console.log('arguments -- ', arguments);
    if (this == null) { // !! == and not === because null and undefined are not same
        throw new TypeError("Array.prototype.myReduce called on null or undefined");
    }

    if (typeof callbackFn !== "function") {
        throw new TypeError("CallbackFN is not a function");
    }

    // Because reduce can work on: arrays, strings, array - like objects
    const object = Object(this); // it converts this into an object
    // !! Object("abc") becomes -> { "0": "a", "1": "b", "2": "c", length: 3 }
    console.log('array after converting this to object -- ', object);

    const len = object.length >>> 0; // !! zero-fill right shift.
    // length can be weird and changed manually, hence the above line is required
    // { length: "10" }     // string --- converted to 10
    // { length: -5 }       // invalid --- 4294967295 (ignored by loop)
    // { length: 3.7 }      // decimal -- converted to 3
    // { length: undefined } --- converted to 0

    let accumulator, startIndex = 0;

    // arguments.length show the number of parameters passed to the function -- here callback and initialValue means 2
    if (arguments.length > 1) {
        accumulator = initialValue;
    } else {
        // find first valid element
        // !! 0 in [undefined] // true
        // !! 0 in [,] -- sparse array // false
        while (startIndex < len && !(startIndex in object)) {
            startIndex++;
        }

        if (startIndex >= len) {
            throw new TypeError("Reduce of empty array with no initial value");
        }

        accumulator = object[startIndex++];
    }

    for (let i = startIndex; i < len; i++) {
        if (i in object) { // handles sparse arrays
            // !! Reduce has NO thisArg parameter hence we do not use .call
            accumulator = callbackFn(accumulator, object[i], i, object);
        }
    }
    return accumulator;
}

const result2 = arr.myReduce(function (acc, next, index, array) {
    return acc + next;
}, 0);

console.log('result2 -- ', result2);

console.log('result3 -- ', Array.prototype.myReduce.call("abc", (a, b) => a + b));

console.log('result4 -- ', Array.prototype.myReduce.call({ 0: 10, 1: 20, length: "2" }, (a, b) => a + b));

console.log('result5 -- ', [, , 3, 4].myReduce((a, b) => a + b));
// convert to array
function show() {
    console.log(Array.prototype.slice.call(arguments));
}
show(1, 2, 3);


const arr = ["👋", "😎", "🍐", "🐼", "🙏"];
const arr2 = ["👋", , "🍐", "🐼", "🙏"];
const arr3 = "abc";

console.log('slice normal -- ', arr.slice());
console.log('slice normal -- ', arr2.slice());
console.log('slice normal -- ', arr3.slice());
console.log('slice with start -- ', arr.slice(2));
console.log('slice with start, end -- ', arr.slice(1, 5));
console.log('slice with negative start -- ', arr.slice(-2));
console.log('-----------------');

Array.prototype.mySlice = function (start, end) {
    // console.log('this -- ', this);
    if (this == null) {
        throw new TypeError("Array.prototype.mySlice called on null or undefined");
    }

    const arr = Object(this);
    const len = arr.length >>> 0;
    const result = [];

    let relativeStart = start === undefined ? 0 : Number(start);
    let actualStart = relativeStart < 0
        ? Math.max(len + relativeStart, 0)
        : Math.min(relativeStart, len);

    let relativeEnd = end === undefined ? len : Number(end);
    let final = relativeEnd < 0
        ? Math.max(len + relativeEnd, 0)
        : Math.min(relativeEnd, len);

    while (actualStart < final) {
        if (actualStart in arr) {
            result.push(arr[actualStart]);
        } else {
            result.length++; // preserve hole
        }
        actualStart++;
    }
    return result;
}

console.log('mySlice normal -- ', arr.mySlice());
console.log('mySlice normal -- ', arr2.mySlice());
console.log('mySlice normal -- ', Array.prototype.mySlice.call("abc", 1, 3));
console.log('mySlice with start -- ', arr.mySlice(2));
console.log('mySlice with start, end -- ', arr.mySlice(1, 5));
console.log('mySlice with negative start -- ', arr.mySlice(-2));
const sampleData = [1, 2, [3, 4, [5, 6, [7, 8, 9, [10]]]]];
const sampleData2 = [1, , , 2];

// inbuilt function -- 
console.log("using inbuilt function flat() -- ", sampleData.flat()); // 1 level
console.log("using inbuilt function flat() -- ", sampleData2.flat()); // 1 level
console.log("using inbuilt function flat(2) -- ", sampleData.flat(2)); // 2nd level nested
console.log("using inbuilt function flat(100) -- ", sampleData.flat(100)); // entire array

// !! simple trick (only if array has numbers)
console.log("using trick -- ", sampleData.toString().split(",").map(Number));

// using polyfill -- 
function flatten(origArray, level = 1) {
    const result = [];

    origArray.forEach(element => {
        if (Array.isArray(element) && level > 0) {
            result.push(...flatten(element, level - 1));
        } else {
            result.push(element);
        }
    });

    return result;
}

// in prototype chain -- 
Array.prototype.myFlat = function (depth = 1) {
    const result = [];

    const flatten = (arr, currentDepth) => {
        arr.forEach((element) => {
            if (Array.isArray(element) && currentDepth > 0) {
                flatten(element, currentDepth - 1);
            } else {
                result.push(element);
            }
        });
    };

    flatten(this, depth);

    return result;
};

console.log("using polyfill -- ", sampleData.myFlat()); // 1 level
console.log("using polyfill -- ", sampleData2.myFlat()); // 1 level
console.log("using polyfill -- ", sampleData.myFlat(2)); // 2nd level nested
console.log("using polyfill -- ", sampleData.myFlat(100)); // entire array
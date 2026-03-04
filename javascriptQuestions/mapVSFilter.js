const array = [1, 2, 3, 4, 5];
const mapResult = array.map((arr) => {
    return arr + 2;
})

const forEach = array.forEach((arr, i) => {
    // forEach doesn't return anything
    array[i] = arr + 3;
})

console.log(mapResult, forEach, array);
type Combine = number | string;
type CombineDescription = 'as-string' | 'as-number';

function combine(n1: Combine, n2: Combine, resultConversion: CombineDescription) {
    let result;
    if (typeof n1 === 'number' && typeof n2 === 'number') {
        result = n1 + n2;
    } else {
        result = n1.toString() + n2.toString();
    }
    if (resultConversion === 'as-number')
        return +result;
    else return result.toString();
}

const combineAges = combine(30, 14, 'as-number');
console.log(combineAges);

const combineStringAges = combine("30", "14", 'as-number');
console.log(combineStringAges);

const combineNames = combine('nilava', 'bepari', 'as-string');
console.log(combineNames);

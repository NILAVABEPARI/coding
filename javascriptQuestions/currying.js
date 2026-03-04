// // function (a,b) into function(a)(b);
// function f(a) {
//     return function (b) {
//         return `${a} ${b}`;
//     }
// }
// console.log(f(5)(6));


// // Question 1 -- sum(2)(6)(1)
// function sum(a) {
//     return function (b) {
//         return function (c) {
//             return `sum = ${a + b + c}`;
//         }
//     }
// }
// console.log(sum(2)(6)(1));

// // Question 2 -- 
// function evaluate(operator) {
//     return function (a) {
//         return function (b) {
//             if (operator === "sum") return a + b;
//             else if (operator === "multiply") return a * b;
//             else if (operator === "divide") return a / b;
//             else if (operator === "subtract") return a - b;
//             else return "invalid operation";
//         }
//     }
// }
// console.log(evaluate("sum")(2)(4));

// //Question 3 -- Infinite currying
// function sum(a) {
//     return function (b) {
//         if (b || b === 0) return sum(a + b);
//         return a;
//     }
// }
// console.log(sum(2)(3)(15)());

// function sumAdvance(...a) {
//     return function (...b) {
//         if (b?.length === 0) {
//             return a?.[0] || 0;
//         } else {
//             return sumAdvance(a?.reduce((acc, curr) => acc + curr, 0),
//                 b?.reduce((acc, curr) => acc + curr, 0));
//         }
//     }
// }
// console.log("sumAdvance -- ", sumAdvance(2, 3, 4)(12, 5)());

// // Question 4 -- Partial Application
// function sum2(a) {
//     return function (b, c) {
//         return a + b + c;
//     }
// }
// const x = sum2(10);
// console.log(x(5, 6));
// console.log(sum(20)(1, 4));

// Question 5 -- Convert f(a,b,c,d) to (a)(b)(c)(d)
function curry(func) {
    console.log('func inside curry -- ', func);
    return function curriedFunc(...args) {
        console.log('args inside curriedFunc -- ', args);
        console.log('args.length -- ', args.length, " -- func.length -- ", func.length);
        if (args.length >= func.length) {
            console.log('----------');
            return func(...args);
        }
        else {
            return function (...next) {
                console.log('next inside return -- ', next);
                console.log('----------');
                return curriedFunc(...args, ...next);
            }
        }
    }
}
const sum = (a, b, c, d) => a + b + c + d;
const totalSum = curry(sum);
console.log(totalSum(1)(2)(3)(4));
console.log(totalSum(1, 2)(3, 4));

// the curry function is called the number of times totalSum is called
// args contains the 1st argument in the totalSum function, and next contains the 2nd argument
// in each turn, 1 argument from the totalSum function is taken and added to the array of the  sum function's argument




// f(1,2,3,4) -->> fun(1)(2)(3)(4)
const sum2 = (a, b, c, d) => a + b + c + d;
const targetSum = curry2(sum);
targetSum(1)(2)(3)(4);

function curry2(func) {
    return function curriedFunction(...args) {
        if (args.length >= func.length)
            return func(...args);
        else {
            return function (...next) {
                return curriedFunction(...args, ...next);
            }
        }
    }
}


sum3(1, 2, 3)(4, 5)();

function sum3(...a) {
    return function (...b) {
        if (!b || b.length === 0) return a?.[0] || 0;
        else return sum3(a?.reduce((acc, curr) => acc + curr, 0), b?.reduce((acc, curr) => acc + curr, 0));
    }
}
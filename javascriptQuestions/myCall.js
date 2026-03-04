// let obj = { name: "nilava" };
// function sayHello(age, profession) {
//     return 'Hello ' + this.name + " age -- " + age + " profession -- " + profession;
// }
// console.log(sayHello.call(obj, 25, "software developer"));

// // Question 4 - Output Based Question
// const person = { name: "nilava" };
// function sayHi(age) {
//     return `${this.name} is ${age}`;
// }
// console.log(sayHi.call(person, 24));
// console.log(sayHi.bind(person, 24));
// // the 1st console will print the text but the 2nd console will return a function as bind returns a reusable function

// // Question 5 - Call with function inside object
// const age = 10;
// var person2 = {
//     name: "Nilava",
//     age: 20,
//     getAge: function () {
//         return this.age;
//     }
// }
// var person3 = { age: 24 }
// console.log(person2.getAge.call(person3));
// // as we are using call method so this will point to person3 object and output will be 24

// // Question - 6 - What is the output ?
// var status = "😎"
// setTimeout(() => {
//     const status = "😍";
//     const data = {
//         status: "🍐",
//         getStatus() {
//             return this.status;
//         }
//     }
//     console.log(data.getStatus()); // 🍐
//     console.log(data.getStatus.call(this)); // 😎
// }, 0);


// Polyfill for Call
const car = {
    color: "red",
    company: "audi"
}
function purchaseCar(currency, price) {
    console.log(`I have purchased ${this.color} - ${this.company} car for ${currency}${price}`);
}
Function.prototype.myCall = function (context = {}, ...args) {
    console.log('this inside myCall function -- ', this);
    if (typeof this !== "function") {
        throw new Error(this + " is not a function");
    }
    const fnSymbol = Symbol();
    console.log('fnSymbol -- ', fnSymbol);

    context[fnSymbol] = this;
    const result = context[fnSymbol](...args);
    delete context[fnSymbol];
    // this is done to remove the temporary function reference from the car object

    return result;
}
// purchaseCar.call(car, "$", 50000);
purchaseCar.myCall(car, "$", 50000);

console.log('car after function call -- ', car);
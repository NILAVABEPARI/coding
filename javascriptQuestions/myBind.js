let obj = { name: "nilava" };
function sayHello(age, profession) {
    return 'Hello ' + this.name + " age -- " + age + " profession -- " + profession;
}
// reusable function
const bindFunc = sayHello.bind(obj);
console.log(bindFunc(24, "nurse"));
//single line call
console.log(sayHello.bind(obj)(25, "software developer"));

// polyfill for Bind
const car = {
    color: "red",
    company: "audi"
}
function purchaseCar(currency, price) {
    console.log(`I have purchased ${this.color} - ${this.company} car for ${currency}${price}`);
}
Function.prototype.myBind = function (context = {}, ...args) {
    if (typeof this !== "function") {
        throw new Error(this + "is not a function");
    }

    context.fn = this;
    return function (...newArgs) {
        return context.fn(...args, ...newArgs);
    }
}
const myBindFunc = purchaseCar.myBind(car);
myBindFunc("$", 50000);
const myBindFunc2 = purchaseCar.myBind(car, "$");
myBindFunc2(50000);
const myBindFunc3 = purchaseCar.myBind(car)("$", 50000);
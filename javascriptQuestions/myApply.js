//!! output based questions remaining

let obj = { name: "nilava" };
function sayHello(age, profession) {
    return 'Hello ' + this.name + " age -- " + age + " profession -- " + profession;
}
console.log(sayHello.apply(obj, [25, "software developer"]));

// Polyfill for Apply
const car = {
    color: "red",
    company: "audi"
}
function purchaseCar(currency, price) {
    console.log(`I have purchased ${this.color} - ${this.company} car for ${currency}${price}`);
}
Function.prototype.myApply = function (context, args = []) {
    if (typeof this !== "function") {
        throw new TypeError(this + " is not a function");
    }
    context = context == null ? globalThis : Object(context);
    if (!Array.isArray(args)) {
        throw new TypeError("args is not an array");
    }
    const fnSymbol = Symbol();
    context[fnSymbol] = this;
    const result = context[fnSymbol](...args);
    delete context[fnSymbol];
    return result;
}
// purchaseCar.apply(car, ["$", 50000]);
purchaseCar.myApply(car, ["$", 50000]);
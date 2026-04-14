/*
    * 4 things New keyword do -- 
    *     1. create a brand new object
    *     2. Link that object to another object
    *     3. call the function with "this" set to new object
    *     4. if function does not return anything, it return the newly created object
*/

function SuperHero(name) {
    this.name = name;
    this.villain = "Galactus";
    /*
        * If we return a primitive then the return statement will be ignored
        * return 2; --- output will still be object of SuperHero
        * If we return an object or an array or a function the output will be the object or array or function
        * return {}; or return []; or return function(){}; -- output will be {}, or [], or function()
    */
}

function myNew(ConstructorFn, ...args) {
    console.log("ConstructorFn -- ", ConstructorFn); // this is the function itself -- SuperHero
    /*
        * Connects that object to the constructor’s prototype:
        * obj.__proto__ = SuperHero.prototype;
        * This gives the object access to shared methods.
    */
    console.log('ConstructorFn.prototype -- ', ConstructorFn.prototype);
    /*
        ! Object.create() -- 
        * It creates a new empty object. BUT ALSO: lets you specify its prototype.
        * Example: const obj = Object.create(personPrototype);
        * means: Create: {}
        * BUT internally: obj.__proto__ = personPrototype
        * Equivalent to: 
        * const obj = {};
        * obj.__proto__ = personPrototype;
    */
    const newObj = Object.create(ConstructorFn.prototype);
    // here we are calling the constructor of ConstructorFn manually
    const result = ConstructorFn.apply(newObj, args);

    return ((result !== null) && ((typeof result === "object" || typeof result === "function"))) ? result : newObj;
    /* Because:
        * function Test() {
        *     return function () { };
        * }
        * new Test() should return that function.
    */
}

const superHero = new SuperHero("Silver Surfer");
const newSuperHero = myNew(SuperHero, "Iron man");

console.log(superHero);
console.log(newSuperHero);
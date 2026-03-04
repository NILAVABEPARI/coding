// this in global space
console.log('this in global space -- ', this);
// this keyword in global space will represent the globalObject
// globalObject varies in different places.
// in browser globalObject (window) is different than in node (global)

// ! this keyword works differently in strict vs non strict mode

// this inside function
function x() {
    console.log('this inside function -- ', this);
    // in strict mode it will be undefined vs in non strict mode it will be window object
}
x();

// ! this substitution -- this inside non-strict mode
// if the value of this keyword is undefined or null then it will be replaced by globalObject only in non strict mode

// the value of this keyword depends on how the function is called
// for normal x() calling in strict mode this is undefined inside a function
// where as if we call it using window object then the this will point to the window object
window.x();


// this inside an object's method
const obj = {
    a: 10,
    x: function () {
        console.log('this inside object\'s method -- ', this);
    }
}
obj.x();
// here this points to the object itself which is calling the function.
// hence this.a will print 10

// inside arrow functions -- 
const obj2 = {
    a: 10,
    x: () => {
        console.log('this inside arrow method -- ', this);
    }
}
obj2.x();
// arrow functions doesn't have their own this binding.
// it retains the this value of the enclosing lexical context

const obj3 = {
    a: 20,
    x: function () {
        const y = () => {
            console.log('this inside object\'s method returning arrow function -- ', this);
        }
        y();
    }
}
obj3.x();
// here this will point to obj3

// !!this inside DOM elements -- reference to HTML elements

// this inside class 
class User {
    constructor(n) {
        this.name = n;
    }
    getName() {
        console.log('inside a class -- ', this.name);
    }
}
const user = new User("nilava");
user.getName();

// Question 2 - What is the result of accessing its ref? Why?
function makeUser() {
    return {
        name: "John",
        ref: this
    };
}
let user2 = makeUser();
console.log(user2.ref.name); // nothing will be printed as this inside ref is pointing to the window object
// !! this is also printing the ref variable

// Fix the above problem
function makeUser() {
    return {
        name: "John",
        ref() {
            return this;
        }
    };
}
let user3 = makeUser();
console.log(user3.ref().name);


// Question 3 - What is the Output ?
const user4 = {
    name: "Nilava Bepari!",
    logMessage() {
        console.log(this.name);
    }
}
setTimeout(user4.logMessage, 1000);
// this will print nothing as the setTimeout is not calling a method of user4 rather it is calling a callback function which points to the window object

/// fix the above problem
const user5 = {
    name: "Nilava Bepari!",
    logMessage() {
        console.log(this.name);
    }
}
setTimeout(function () { user5.logMessage(); }, 1000);

// Question 5 --create an  object calculator
let calculator = {
    read() {
        this.a = +prompt("a = ", 0);
        this.b = +prompt("b = ", 0);
    },
    sum() {
        return this.a + this.b;
    },
    mul() {
        return this.a * this.b;
    }
}
calculator.read();
console.log(calculator.sum());
console.log(calculator.mul());


//!! more output questions remaining -- watched till 17:25
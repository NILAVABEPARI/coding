// constructor function -- Before ES6 classes
function User(name, age) { this.name = name; this.age = age; }
const user1 = new User("John", 25);
const user2 = new User("Alex", 30);
console.log(user1.name); // John
console.log(user2.name); // Alex

// Class constructor -- with ES6
class User { constructor(name, age) { this.name = name; this.age = age; } }
const user = new User("John", 25);

// When a constructor called with new explicitly returns an object, that object becomes the result.
function User2(name) {
    this.name = name;
    return { age: 20 };
}
const user3 = new User2("John");
console.log(user3.name); // ! undefined
console.log(user3.age); // ! 20
// But if it returns a primitive, the primitive return value is ignored, and the newly created object is returned.
function User() { this.name = "John"; return 10; }
// delete key from object
const user = {
    name: "nilava",
    age: 25
}

delete user.age;

// interview question --  // output -- 5 as delete only works on keys of objects and not on local variables
const func = (function (a) {
    delete a;
    return a;
})(5);
console.log(func);

// output -- // it will be a: three and b: two as the late defined a will replace the previous value
const obj = {
    a: "one",
    b: "two",
    a: "three"
};
console.log('obj -- ', obj);

// ! Most important -- // output will be 456 because in line 28 b is an object so inside a it will be stored as a["[object Object]"]. Same will be the case for c. Hence line 27 will override the previous line
const a = {};
const b = { key: "b" }
const c = { key: "c" }
a[b] = 123;
a[c] = 456;
console.log(a);

// JSON.stringify and JSON.parse
// most common use case is storing something in localstorage -- we cant store complete object inside the local storage hence we need to store a single string, and while fetching data form local storage we need to parse it to convert it back to an object
const user2 = {
    name: "nilava",
    age: 25
}
const strObj = JSON.stringify(user2);
console.log(strObj);
console.log(JSON.parse(strObj));
localStorage.setItem("test", strObj);
console.log("localstorage -- ", localStorage.getItem("test"));

// output -- only converts the given keys (if available in object) to string
console.log("selective stringify -- ", JSON.stringify(user2, ["name", "school"]));

// output -- here we are passing the reference of 1 object to another and not creating a new object
const cd = { greetings: "hey!" };
const dd = cd;

cd.greetings = "hello!!";
console.log('dd -- ', dd.greetings); // output -- hello!!

// ! Important console log -- both will return false as they are comparing different memory locations -- js compares objects by reference and not by value
console.log({ a: 1 } == { a: 1 });
// console.log({ a: 1 } === { a: 1 });

// output -- 
// the 1st 2 calls will take the value object from global object, and since we are using spread operator so it will clone the object, and will not modify the original object and hence the output will be 20 in both cases 
// the last 2 calls will take the global object by reference and hence will modify the original object, and the output will be 20 and 40
const value = { number: 10 };
const multiply = (x = { ...value }) => {
    console.log((x.number *= 2));
}
multiply();
multiply();
multiply(value);
multiply(value);

// output -- when the function is called the reference to the original object is passed and in the 1st line of the function the objects age is changed which will be reflected in the 1st console
// then a new object is created and returned which will be stored in personObj2 and reflected in 2nd console log
function changeAgeAndReference(person) {
    person.age = 25;
    person = {
        name: " John",
        age: 50
    }
    return person;
}
const personObj1 = {
    name: "Alex",
    age: 30,
}
const personObj2 = changeAgeAndReference(personObj1);
console.log(personObj1);
console.log(personObj2);

// cloning object
let user3 = {
    name: "nilava",
    age: 25
}
const objClone = Object.assign({}, user3); // this will not clone nested objects
console.log('objClone -- ', objClone);
const objClone2 = JSON.parse(JSON.stringify(user3));
console.log('objClone2 -- ', objClone2);
const objClone3 = { ...user3 };
console.log('objClone3 -- ', objClone3);
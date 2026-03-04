console.log('Object and Array Types!!!');

// * alternate way to define object type
// const person: {
//     name: string;
//     age: number;
// } = {
//     name: "NILAVA",
//     age: 24
// }


// const person: {
//     name: string;
//     age: number;
//     hobbies: string[];
//     role: [number, string]; // tuple -- it is an array with exactly 2 values 1st being number and 2nd being string
// } = {
//     name: "NILAVA",
//     age: 24,
//     hobbies: ["sports", "cooking"],
//     role: [2, "admin"]
// }


// enum -- by default it increments values from 0 but we can change that to start from a different number or can assign string values as well
enum Role { ADMIN, READ_ONLY, AUTHOR }
// enum Role { ADMIN = 5, READ_ONLY, AUTHOR }
// enum Role { ADMIN = "ADMIN", READ_ONLY = "READ_ONLY", AUTHOR = "AUTHOR" }
const person = {
    name: "NILAVA",
    age: 24,
    hobbies: ["sports", "cooking"],
    role: Role.ADMIN
}

console.log(person.name);

let activities: string[];
activities = ["sports"];

person.hobbies.forEach((ele) => console.log(ele.toUpperCase()));

// person.role.push("author");  // !!! typescript cant catch this and allows push operation
// person.role[1] = 1; // error
// person.role = [0,"user", "guest"] // error
console.log(person.role);

const product: {
    id: string;
    price: number;
    tags: string[];
    details: {
        title: string;
        description: string
    }
} = {
    id: 'abc1',
    price: 12.99,
    tags: ['great-offer', 'hot-and-new'],
    details: {
        title: 'Red Carpet',
        description: 'A great carpet - almost brand-new!'
    }
}
console.log(product.details.description);


if (person.role === Role.ADMIN) {
    console.log("is admin");
}
"use strict";
console.log('Object and Array Types!!!');
var Role;
(function (Role) {
    Role[Role["ADMIN"] = 0] = "ADMIN";
    Role[Role["READ_ONLY"] = 1] = "READ_ONLY";
    Role[Role["AUTHOR"] = 2] = "AUTHOR";
})(Role || (Role = {}));
const person = {
    name: "NILAVA",
    age: 24,
    hobbies: ["sports", "cooking"],
    role: Role.ADMIN
};
console.log(person.name);
let activities;
activities = ["sports"];
person.hobbies.forEach((ele) => console.log(ele.toUpperCase()));
console.log(person.role);
const product = {
    id: 'abc1',
    price: 12.99,
    tags: ['great-offer', 'hot-and-new'],
    details: {
        title: 'Red Carpet',
        description: 'A great carpet - almost brand-new!'
    }
};
console.log(product.details.description);
if (person.role === Role.ADMIN) {
    console.log("is admin");
}
//# sourceMappingURL=objs-arrays-enums.js.map
const villain = {
    fightWith: "Thanos"
}
const superHero = {
    name: "Silver Surfer"
}

Object.prototype.myCreate = function (parentObject, keysObject = undefined) {
    if ((parentObject !== null) && (typeof parentObject !== "object")) {
        throw new TypeError("parentObject must be object or null");
    }
    function F() { }
    F.prototype = parentObject;
    const newObj = new F();
    if (keysObject !== undefined) {
        Object.defineProperties(newObj, keysObject);
    }
    return newObj;
}
// the second argument is passed to create new keys in the newly created object and we need to pass it in this format only
const obj = Object.myCreate(superHero, { origin: { value: "nilava" } });
console.log("newly created object -- ", obj);
console.log("obj.name -- ", obj.name);
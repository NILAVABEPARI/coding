// Syntax –
(() => {
    // Function code here
})();

// OR
(function () {
    // Function code here
})();

// Example –
(function () {
    console.log("This is an IIFE!");
})();
// Output: This is an IIFE!

// with parameters – 
(function (name) {
    console.log(`Hello, ${name}!`);
})('Alice');
// Output: Hello, Alice!

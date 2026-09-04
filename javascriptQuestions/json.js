// Parsing –
const invalidJsonString = '{"name": "John", "age": 30, "city": "New York",}'; // Note the extra comma
try {
    const parsedObject = JSON.parse(invalidJsonString);
    console.log(parsedObject);
} catch (error) {
    console.log('Invalid JSON:', error.message);  // Output: Invalid JSON: Unexpected token } in JSON at position 60
}

// using reviver function – it allows to modify the values before they are returned
const jsonString = '{"name": "John", "age": 30, "birthYear": 1991}';
const parsedObject = JSON.parse(jsonString, (key, value) => {
    // Modify the age value to be in months
    if (key === 'age') {
        return value * 12;  // Convert age to months
    }
    return value;
});

console.log(parsedObject);
// Output: { name: 'John', age: 360, birthYear: 1991 }

// closure example -- 
function outer() {
    let x = 10;
    function inner() {
        console.log(x);
    }
    return inner;
}
const fn = outer();
fn();

// 4 will be printed every time
function x() {
    for (var i = 0; i < 3; i++) {
        setTimeout(() => {
            console.log(i);
        }, i * 1000);
    }
}
x();
// it can be fixed using let instead of var

function abc() {
    for (var i = 0; i < 3; i++) {
        function close(z) {
            setTimeout(() => {
                console.log(z);
            }, z * 1000);
        }
        close(i);
    }
}
abc();


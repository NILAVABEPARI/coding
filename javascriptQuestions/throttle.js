const btn = document.querySelector(".increment_btn");
const btnPress = document.querySelector(".increment_pressed");
const count = document.querySelector(".increment_count");

let pressedCount = 0;
let triggerCount = 0;

// const throttle = _.throttle(() => {
//     count.innerHTML = ++triggerCount;
// }, 800);

const myThrottle = (callbackFn, delay) => {
    let last = 0;
    return function (...args) {
        let now = new Date().getTime();
        if (now - last < delay) return;
        last = now;
        return callbackFn(...args);
    }
}

const throttle = myThrottle(() => {
    count.innerHTML = ++triggerCount;
}, 1000);

btn.addEventListener("click", () => {
    btnPress.innerHTML = ++pressedCount;
    throttle();
});
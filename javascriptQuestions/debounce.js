const btn = document.querySelector(".increment_btn");
const btnPress = document.querySelector(".increment_pressed");
const count = document.querySelector(".increment_count");

let pressedCount = 0;
let triggerCount = 0;

// const debounce = _.debounce(() => {
//     count.innerHTML = ++triggerCount;
// }, 800);

const myDebounce = (callbackFn, delay) => {
    let timer;
    return function (...args) {
        if (timer) clearTimeout(timer);
        timer = setTimeout(() => {
            callbackFn(...args);
        }, delay);
    }
}

const debounceCount = myDebounce(() => {
    count.innerHTML = ++triggerCount;
}, 800);

btn.addEventListener("click", () => {
    btnPress.innerHTML = ++pressedCount;
    debounceCount();
});
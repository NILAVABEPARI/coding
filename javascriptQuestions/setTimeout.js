
// setTimeout Syntax -- 
function showMyName(name) {
    console.log('name -- ', name);
}

setTimeout(() => {
    showMyName("SilverSurfer");
}, 1000);

setTimeout(showMyName, 1000, "SilverSurfer");
setTimeout(showMyName, 4000, "SilverSurfer 1");
setTimeout(showMyName, 3000, "SilverSurfer 2");

// ! setTimeout doesn't guarantee that the function will run just after the specified time. It makes sure that the function doesn't run before the specified time. It will only run if the main thread is free. 


// polyfill of setTimeout
(function () {
    let timerId = 1;
    const timerMap = {};

    function scheduler() {
        const now = Date.now();
        // Loop through all timers and execute ones that are due
        for (let id in timerMap) {
            const timer = timerMap[id];
            if (now >= timer.time) {
                timer.callback(...timer.args);
                delete timerMap[id];
            }
        }
        // Continue running only if timers remain
        if (Object.keys(timerMap).length > 0) {
            requestAnimationFrame(scheduler);
        }
    }
    window.setTimeout = function (callback, delay, ...args) {
        const id = timerId++;
        timerMap[id] = {
            callback,
            time: Date.now() + delay,
            args
        };
        // Start scheduler if this is first timer
        if (Object.keys(timerMap).length === 1) {
            requestAnimationFrame(scheduler);
        }
        return id;
    };

    window.clearTimeout = function (id) {
        delete timerMap[id]; // simple cancel
    };
})();

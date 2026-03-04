setInterval(() => {
    console.log('learning frontend');
}, 1000);

function showName(name) {
    console.log('name is ', name);
}

console.log('1');
setInterval(showName, 1000, "silver surfer");
console.log('2');

(function () {
    let intervalId = 1;
    const intervals = {};

    function scheduler() {
        const now = Date.now();

        for (let id in intervals) {
            const interval = intervals[id];
            if (now >= interval.nextTime) {
                interval.callback(...interval.args);
                interval.nextTime = now + interval.delay; // reschedule
            }
        }

        if (Object.keys(intervals).length > 0) {
            requestAnimationFrame(scheduler);
        }
    }

    window.setInterval = function (callback, delay, ...args) {
        const id = intervalId++;

        intervals[id] = {
            callback,
            delay,
            args,
            nextTime: Date.now() + delay
        };

        if (Object.keys(intervals).length === 1) {
            requestAnimationFrame(scheduler);
        }

        return id;
    };

    window.clearInterval = function (id) {
        delete intervals[id];
    };
})();

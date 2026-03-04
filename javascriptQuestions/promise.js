// const p1 = new Promise((resolve, reject) => {
//     // setTimeout(() => resolve("P1 Success"), 3000);
//     setTimeout(() => reject("P1 Fail"), 3000);
// })
// const p2 = new Promise((resolve, reject) => {
//     // setTimeout(() => resolve("P2 Success"), 1000);
//     setTimeout(() => reject("P2 Fail"), 1000);
// })
// const p3 = new Promise((resolve, reject) => {
//     // setTimeout(() => resolve("P3 Success"), 2000);
//     setTimeout(() => reject("P3 Fail"), 2000);
// })

// // Promise.all
// Promise.all([p1, p2, p3])
//     .then(res => { console.log('result -- ', res); })
//     .catch(error => { console.error('error while receiving -- ', error); })
// // it will call all the promises simultaneously and the response time will be the max time taken by the promises
// // if 1 promise fails, we get an error returned and it will not wait for other promises

// // Promise.allSettled
// Promise.allSettled([p1, p2, p3])
//     .then(res => { console.log('result -- ', res); })
//     .catch(error => { console.error('error while receiving -- ', error); })
// // it will fetch all the promises even if any of the promise fails
// // it will return us the array of the promises whether it passes or fails

// // Promise.race
// Promise.race([p1, p2, p3])
//     .then(res => { console.log('result -- ', res); })
//     .catch(error => { console.error('error while receiving -- ', error); })
// // it will return the 1st settled promise whether it is a failure or success

// // Promise.any
// Promise.any([p1, p2, p3])
//     .then(res => { console.log('result -- ', res); })
//     .catch(error => {
//         console.error('error while receiving -- ', error);
//         console.log('error array -- ', error.errors);
//     })
// // it will return the 1st success promise even if it gets any fail promise before it
// // if all the promises fail then it will return AggregateError
// // it will also return an array when all the results fail



// promise polyfill
const STATE = {
    FULFILLED: "fulfilled",
    REJECTED: "rejected",
    PENDING: "pending",
}

class MyPromise {
    #value = "";
    #state = STATE.PENDING;
    #thenCbs = [];
    #catchCbs = [];

    constructor(callback) {
        try {
            callback(this.#onSuccess, this.#onFail);
        } catch (e) {
            this.#onFail(e);
        }
    }

    #runCallbacks = () => {
        queueMicrotask(() => {
            if (this.#state === STATE.FULFILLED) {
                this.#thenCbs.forEach(cb => {
                    cb(this.#value);
                })
                this.#thenCbs = [];
            }

            if (this.#state === STATE.REJECTED) {
                this.#catchCbs.forEach(cb => {
                    cb(this.#value);
                })
                this.#catchCbs = [];
            }
        })
    }

    #onSuccess = (value) => {
        if (this.#state !== STATE.PENDING) return;
        this.#value = value;
        this.#state = STATE.FULFILLED;
        this.#runCallbacks();
    }

    #onFail = (value) => {
        if (this.#state !== STATE.PENDING) return;

        if (!this.#catchCbs.length) {
            throw new Error("Uncaught Promise");
        }

        this.#value = value;
        this.#state = STATE.REJECTED;
        this.#runCallbacks();
    }

    then = (thenCb, catchCb) => {
        return new MyPromise((resolve, reject) => {
            this.#thenCbs.push(value => {
                if (thenCb == null) {
                    resolve(value);
                    return;
                }

                resolve(thenCb(value));
            });

            this.#catchCbs.push(value => {
                if (catchCb == null) {
                    reject(value);
                    return;
                }

                resolve(catchCb(value));
            });
            this.#runCallbacks();
        })
    }

    catch = (cb) => {
        this.then(undefined, cb);
    }

    static resolve = data => {
        return new MyPromise(function (resolve) {
            resolve(data);
        })
    }
    static reject = data => {
        return new MyPromise(function (_, reject) {
            reject(data);
        })
    }
}

const myPromise = new MyPromise(function (resolve, reject) {
    setTimeout(() => {
        reject("Done error");
    }, 1000);
});

console.log('1');
myPromise.then(data => {
    console.log('data -- ', data);
})
console.log('2');



// promise.all polyfill
function fakeFetcher(url, time, failIt = false) {
    return () => {
        return new Promise(function (resolve, reject) {
            setTimeout(() => {
                if (failIt) {
                    reject("API fail for " + url);
                } else {
                    resolve("Data Received for " + url);
                }
            }, time);
        })
    }
}

const p1 = fakeFetcher("P1", 1000);
const p2 = fakeFetcher("P2", 2000);
const p3 = fakeFetcher("P3", 3000, true);

const allData = Promise.allSettled([p1(), p2(), p3()]);
allData.then(data => {
    console.log(data);
}).catch(error => {
    console.log(error);
})

Promise.all = function (promises = []) {
    return new Promise(function (resolve, reject) {
        const result = [];
        const completed = 0;

        if (!promises.length) {
            resolve([]);
            return;
        }

        promises.forEach(function (promise, index) {
            promise
                .then(data => {
                    result[index] = data;
                    completed++;

                    if (completed === promises.length) {
                        resolve(result);
                    }
                })
                .catch(error => {
                    reject(error)
                })
        })

        return result;
    })
}


// promise.allSettled polyfill
Promise.allSettled = function (promises = []) {
    return new Promise(function (resolve, reject) {
        const result = [];
        const completed = 0;
        if (!promises.length) {
            resolve([]);
            return;
        }
        promises.forEach(function (promise, index) {
            promise
                .then(data => { result[index] = { status: "fulfilled", value: data }; })
                .catch(error => { result[index] = { status: "rejected", reason: error }; })
                .finally(() => {
                    completed++;
                    if (completed === promises.length) { resolve(result); }
                })
        })
        return result;
    })
}
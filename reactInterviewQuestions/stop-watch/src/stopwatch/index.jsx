import { useState, useRef, useEffect } from 'react';
import './style.css'

function Stopwatch() {
    const [time, setTime] = useState(0);

    const startTimeRef = useRef(0);
    const intervalRef = useRef(null);
    const needToResumeRef = useRef(false);

    function handleStart() {
        if (intervalRef.current) return;
        startTimeRef.current = new Date().getTime() - time;
        intervalRef.current = setInterval(() => {
            setTime(new Date().getTime() - startTimeRef.current);
        }, 10);
    }
    function handlePause() {
        clearInterval(intervalRef.current);
        intervalRef.current = null;
    }
    function handleReset() {
        clearInterval(intervalRef.current);
        intervalRef.current = null;
        setTime(0);
    }

    function handleFocus() {
        if (needToResumeRef.current) {
            needToResumeRef.current = false;
            handleStart();
        }
    }

    function handleBlur() {
        needToResumeRef.current = !!intervalRef.current;
        clearInterval(intervalRef.current);
        intervalRef.current = null;
    }

    useEffect(() => {
        window.addEventListener("blur", handleBlur)
        window.addEventListener("focus", handleFocus);

        return () => {
            window.removeEventListener("blur", handleBlur)
            window.removeEventListener("focus", handleFocus);
        }
    }, [time]);

    function formatTime(ms) {
        const milliseconds = Math.floor(ms % 1000).toString().padStart(3, "0");
        const s = Math.floor((ms / 1000) % 60).toString().padStart(2, "0");
        const m = Math.floor((ms / (1000 * 60)) % 60).toString().padStart(2, "0");
        const h = Math.floor(ms / (1000 * 60 * 60)).toString().padStart(2, "0");

        return `${h}:${m}:${s}:${milliseconds}`;
    }

    return (
        <div className='stopwatch'>
            <span className='time'>{formatTime(time)}</span>
            <div>
                <button onClick={handleStart}>Start</button>
                <button onClick={handlePause}>Pause</button>
                <button onClick={handleReset}>Reset</button>
            </div>
        </div>
    )
}

export default Stopwatch
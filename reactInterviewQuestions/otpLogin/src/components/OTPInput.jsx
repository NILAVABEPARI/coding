import { useEffect, useRef, useState } from "react";

function OTPInput({ length = 4, onOTPSubmit = () => { } }) {
    const [otp, setOtp] = useState(new Array(length).fill(""));
    const inputRefs = useRef([]);

    function handleChange(index, e) {
        const value = e.target.value;
        if (isNaN(value)) return;

        const newOtp = [...otp];
        newOtp[index] = value.slice(-1);
        setOtp(newOtp);

        // move to next field if current is already filled
        if (value && index < length - 1 && inputRefs.current[index + 1]) {
            inputRefs.current[index + 1].focus();
        }

        // trigger function submit 
        const combinedOtp = newOtp.join("");
        if (combinedOtp.length === length && !newOtp.includes("")) {
            onOTPSubmit(combinedOtp);
        }
    }

    function handleKeyDown(index, e) {
        // move to previous field on backspace press
        if (e.key === "Backspace" && !otp[index] && index > 0 && inputRefs.current[index - 1]) {
            // 2nd check for there is no value in the current field
            inputRefs.current[index - 1].focus();
        }
    }

    function handleClick(index) {
        inputRefs.current[index].setSelectionRange(1, 1);
    }

    function handlePaste(e) {
        e.preventDefault();

        const pastedData = e.clipboardData.getData("text");

        // !! regex checking for number -- no need to memorize
        if (!/^\d+$/.test(pastedData)) return;

        const digits = pastedData.slice(0, length).split("");
        const newOtp = [...otp];

        for (let i = 0; i < length; i++) {
            newOtp[i] = digits[i] || "";
        }
        setOtp(newOtp);

        if (digits.length === length) {
            onOTPSubmit(digits.join(""));
        }

        const nextIndex = digits.length < length ? digits.length : length - 1;
        inputRefs.current[nextIndex]?.focus();

    }

    useEffect(() => {
        if (inputRefs.current[0]) {
            inputRefs.current[0].focus();
        }
    }, [])

    return (
        <div>
            {
                otp.map((value, index) => {
                    return (
                        <input
                            type="tel" // !! this opens the numeric keypad in mobile view
                            ref={input => inputRefs.current[index] = input}
                            key={index}
                            inputMode="numeric"
                            value={value}
                            maxLength={1}
                            onChange={(e) => handleChange(index, e)}
                            onClick={() => handleClick(index)}
                            onKeyDown={(e) => handleKeyDown(index, e)}
                            onPaste={handlePaste}
                            aria-label={`OTP digit ${index + 1}`}
                            className="otpInput"
                        />
                    )
                })
            }
        </div>
    )
}

export default OTPInput
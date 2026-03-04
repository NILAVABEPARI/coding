import { useState } from "react";
import OTPInput from "./OTPInput";

function OTPLogin() {
    const [phoneNumber, setPhoneNumber] = useState("");
    const [showOtpInput, setShowOtpInput] = useState(false);

    function handlePhoneSubmit(event) {
        event.preventDefault();

        // phone number validations 
        const isValid = /^[6-9]\d{9}$/.test(phoneNumber); // 1st number from 6-9 and total 10 numbers

        if (!isValid) {
            alert("Enter a valid 10-digit phone number");
            return;
        }

        // API calls
        setShowOtpInput(true)
    }

    function handlePhoneNumber(event) {
        const value = event.target.value.replace(/\D/g, "");
        setPhoneNumber(value);
    }

    function onOTPSubmit(otp) {
        alert('login successful');
    }

    return (
        <div>
            {!showOtpInput ?
                <form onSubmit={handlePhoneSubmit}>
                    <input
                        type="tel" // !! this opens the numeric keypad in mobile view
                        inputMode="numeric"
                        value={phoneNumber}
                        placeholder="Enter phone number"
                        onChange={handlePhoneNumber}
                        maxLength={10}
                    />
                    <button type="submit">Submit</button>
                </form> :
                <div>
                    <p>Enter otp sent to {phoneNumber}</p>
                    <OTPInput length={4} onOTPSubmit={onOTPSubmit} />
                </div>
            }
        </div>
    )
}

export default OTPLogin;
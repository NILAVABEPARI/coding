import { useState } from 'react';

type AuthUser = {
    name: string
    email: string
}

export const User = () => {
    // const [user, setUser] = useState<AuthUser | null>(null); // !! type in useState hook
    const [user, setUser] = useState<AuthUser>({} as AuthUser); // !! type assertion in useState hook

    const handleLogin = () => {
        setUser({
            name: "Nilava",
            email: "example@email.com"
        });
    }

    // for type assertion
    // const handleLogout = () => {
    //     setUser(null)
    // }

    return (
        <div>
            <button onClick={handleLogin}>Login</button>
            {/* <button onClick={handleLogout}>Logout</button> */}
            {/* <div>User name is {user?.name}</div>
            <div>User email is {user?.email}</div> */}
            {/* // !! not due to type assertion we don't need to have check before accessing properties */}
            <div>User name is {user.name}</div>
            <div>User email is {user.email}</div>
        </div>
    )
}
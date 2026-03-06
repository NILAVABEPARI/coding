type InputProps = {
    value: string,
    handleChange: (event: React.ChangeEvent<HTMLInputElement>) => void
}

export const Input = ({ value, handleChange }: InputProps) => {   // !! destructuring of props
    return <input type="text" value={value} onChange={handleChange} />
}
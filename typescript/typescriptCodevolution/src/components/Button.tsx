type ButtonProp = {
    handleClick: (event: React.MouseEvent<HTMLButtonElement>, id: number) => void
}

export const Button = (props: ButtonProp) => {
    return <button onClick={(event) => props.handleClick(event, 1)}>Click</button>
}
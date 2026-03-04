const Cell = ({ filled, onClick, disabled, label }) => {
    return <button
        type="button"
        aria-label={label}
        onClick={onClick}
        disabled={disabled}
        className={filled ? "cell cell-activated" : "cell"}
    />
}

export default Cell;
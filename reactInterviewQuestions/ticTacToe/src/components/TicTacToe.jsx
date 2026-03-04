import { useState } from "react";
import useTicTacToe from "../hooks/use-tic-tac-toe"

function TicTacToe() {
    const [size, setSize] = useState(3);
    const { board, gridSize, handleClick, resetGame, getStatusMessage } = useTicTacToe(size);
    return (
        <div className='game'>
            <div className="controls">
                <label>Grid Size:
                    <input type="number" min="3" value={size}
                        onChange={(e) => setSize(Number(e.target.value))} />
                </label>
            </div>
            <div className="status">
                {getStatusMessage()}
                <button className='reset-button' onClick={resetGame}>Reset Game</button>
            </div>

            <div className="board"
                style={{
                    display: "grid",
                    gridTemplateColumns: `repeat(${gridSize}, 60px)`,
                    justifyContent: "center",
                    gap: "5px"
                }}>
                {board.map((b, index) => {
                    return (
                        <button className='cell'
                            key={index}
                            onClick={() => handleClick(index)}
                            disabled={b !== null}>
                            {b}
                        </button>
                    )
                })}
            </div>
        </div>
    )
}

export default TicTacToe

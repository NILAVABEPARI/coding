import type { JSX } from "react";

type NewGameButtonsProps = { isGameOver: boolean, startNewGame: () => void }

export default function NewGameButton({ isGameOver, startNewGame }: NewGameButtonsProps): JSX.Element | null {
    if (!isGameOver) {
        return null
    } else {
        return (
            <button className="new-game" onClick={startNewGame}>
                New Game
            </button>
        )
    }
}
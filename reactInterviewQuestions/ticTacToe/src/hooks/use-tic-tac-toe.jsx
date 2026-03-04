import { useMemo, useState } from 'react'

const initialBoard = (size) => Array(size * size).fill(null);

const generateWinningPattern = (size) => {
    const patterns = [];

    // rows
    for (let r = 0; r < size; r++) {
        const row = [];
        for (let c = 0; c < size; c++) {
            row.push(r * size + c);
        }
        patterns.push(row);
    }

    // columns
    for (let c = 0; c < size; c++) {
        const col = [];
        for (let r = 0; r < size; r++) {
            col.push(c * size + r);
        }
        patterns.push(col);
    }

    // diagonal -- top left to bottom right
    const diag1 = []
    for (let i = 0; i < size; i++) {
        diag1.push((i * size) + i);
    }
    patterns.push(diag1);

    // diagonal -- top right to bottom left
    const diag2 = [];
    for (let i = 0; i < size; i++) {
        diag2.push((i * size) + (size - 1 - i));
    }
    patterns.push(diag2);

    return patterns;
}

const useTicTacToe = (gridSize = 3) => {
    const [board, setBoard] = useState(initialBoard(gridSize));
    const [isxNext, setIsXNext] = useState(true);

    const WINNING_PATTERNS = useMemo(() => generateWinningPattern(gridSize), [gridSize]);

    const handleClick = (index) => {
        const winner = calculateWinner(board);
        if (winner || board[index]) return;

        const newBoard = [...board];
        newBoard[index] = isxNext ? "X" : "O";
        setBoard(newBoard);
        setIsXNext(!isxNext);
    }

    const calculateWinner = (currentBoard) => {
        for (let i = 0; i < WINNING_PATTERNS.length; i++) {
            const [a, b, c] = WINNING_PATTERNS[i];
            if (currentBoard[a] &&
                currentBoard[a] === currentBoard[b] &&
                currentBoard[a] === currentBoard[c]) {
                return currentBoard[a]
            }
        }
        return null;
    }

    const getStatusMessage = () => {
        const winner = calculateWinner(board);
        if (winner) return `Player ${winner} wins!!!!`;
        if (!board.includes(null)) return `It's a draw!`;
        return `Player ${isxNext ? "X" : "O"}'s turn`;
    }

    const resetGame = () => {
        setBoard(initialBoard(gridSize));
        setIsXNext(true);
    }

    return { board, gridSize, handleClick, calculateWinner, getStatusMessage, resetGame };
}

export default useTicTacToe;
import { useState } from 'react';
import './style.css'

const data = ["😎", "😍", "👋", "❤️", "🙏"];

function MemoryGame() {
    const [cards, setCards] = useState(prepareCards);
    const [firstClickIndex, setFirstClickIndex] = useState(null);
    const [secondClickIndex, setSecondClickIndex] = useState(null);
    const [turns, setTurns] = useState(0);
    const [matchingIndices, setMatchingIndices] = useState([]);

    function prepareCards() {
        const duplicateCards = [...data, ...data];

        for (let i = duplicateCards.length - 1; i >= 0; i--) {
            const j = Math.floor(Math.random() * i);
            [duplicateCards[i], duplicateCards[j]] = [duplicateCards[j], duplicateCards[i]];
        }
        console.log('data after randomizing -- ', duplicateCards);
        return duplicateCards;
    }

    const handleClick = (index) => {
        if (firstClickIndex === null) {
            setFirstClickIndex(index);
            setTurns(turns + 1);
        } else {
            const firstValue = cards[firstClickIndex];
            const secondValue = cards[index];

            if (firstValue === secondValue) {
                const newWinning = [...matchingIndices, firstClickIndex, index];
                if (newWinning.length === cards.length) {
                    alert("You Won!!!");
                    setCards(prepareCards());
                    setFirstClickIndex(null);
                    setSecondClickIndex(null);
                    setMatchingIndices([]);
                    setTurns(0);
                } else {
                    setMatchingIndices(newWinning);
                }

            } else {
                setSecondClickIndex(index);
                setTurns(turns + 1);
                setTimeout(() => {
                    setFirstClickIndex(null);
                    setSecondClickIndex(null);
                }, 3000);
            }

        }

    }

    return (
        <div className="memory-game">
            <button onClick={() => {
                setCards(prepareCards());
                setFirstClickIndex(null);
                setSecondClickIndex(null);
                setMatchingIndices([]);
                setTurns(0);
            }}>
                Restart Game
            </button>
            <span>Turns {turns}</span>
            {cards.map((emoji, index) => {
                return (
                    <div
                        data-active={matchingIndices.includes(index)}
                        data-toggle={index === firstClickIndex || index === secondClickIndex}
                        data-disabled={index === firstClickIndex}
                        data-disable-all={firstClickIndex !== null && secondClickIndex !== null}
                        onClick={(() => handleClick(index))} className='card' >
                        <div className='front'></div>
                        <div className='back'>{emoji}</div>
                    </div>
                )
            })}
        </div>
    );
}

export default MemoryGame;
import { useState, useRef, useId, createContext, useContext } from "react";
import "./style.css";

const AccordionContext = createContext();

export default function Accordion({ children, type = "single" }) {
    const [openItems, setOpenItems] = useState([]);

    function toggleItem(id) {
        if (type === "single") {
            setOpenItems(prev => (prev[0] === id ? [] : [id]));
        } else {
            setOpenItems(prev =>
                prev.includes(id)
                    ? prev.filter(item => item !== id)
                    : [...prev, id]
            );
        }
    }

    return (
        <AccordionContext.Provider value={{ openItems, toggleItem }}>
            <div className="accordion">{children}</div>
        </AccordionContext.Provider>
    );
}


function AccordionItem({ heading, children }) {
    const { openItems, toggleItem } = useContext(AccordionContext);
    const id = useId();  // !! if the same page re-renders then this hook will give the same id for the same element
    const isOpen = openItems.includes(id);

    const buttonRef = useRef(null);
    const contentRef = useRef(null);

    function handleKeyDown(e) {
        if (e.key === "Enter" || e.key === " ") { // !! 2nd check is for space press
            e.preventDefault(); // !! the browser scrolls the page by default when space is pressed
            toggleItem(id);
        }
    }

    return (
        <div className="accordion-item">
            <h3>
                <button
                    ref={buttonRef}
                    className="accordion-button"
                    aria-expanded={isOpen} // !! tells the screen reader that this is a state open / close
                    aria-controls={`content-${id}`} // !! this is the same id as the content id 
                    id={`heading-${id}`}
                    onClick={() => toggleItem(id)}
                    onKeyDown={handleKeyDown}
                >
                    {heading}
                    <span className={`arrow ${isOpen ? "rotate" : ""}`}>›</span>
                </button>
            </h3>

            <div
                ref={contentRef}
                id={`content-${id}`}
                role="region"
                aria-labelledby={`heading-${id}`} // !! this is the same as the button's id
                className={`accordion-content ${isOpen ? "open" : ""}`}
            >
                <div className="accordion-inner">{children}</div>
            </div>
        </div>
    );
}


Accordion.Item = AccordionItem;

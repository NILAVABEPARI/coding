import { useContext, useId } from "react";
import { AccordionContext } from "./accordion";
import './style.css';

export default function AccordionItem({ children, header }) {
    const { openItems, toggleItems } = useContext(AccordionContext);
    const id = useId();
    const isOpen = openItems.includes(id);

    function handleKeyDown(e) {
        if (e.key === "Enter" || e.key === " ") {
            e.preventDefault();
            toggleItems(id);
        }
    }

    return (
        <div className="accordion-item">
            <h3>
                <button
                    id={`header-${id}`}
                    className="accordion-button"
                    aria-expanded={isOpen}
                    aria-controls={`content-${id}`}
                    onClick={() => toggleItems(id)}
                    onKeyDown={handleKeyDown}
                >
                    {header}
                    <span className={`arrow ${isOpen ? "rotate" : ""}`}> {'>'} </span>
                </button>
            </h3>
            <div
                id={`content-${id}`}
                role="region"
                aria-labelledby={`heading-${id}`}
                className={`accordion-content ${isOpen ? "open" : ""}`}
            >
                <div className="accordion-inner">
                    {children}
                </div>
            </div>
        </div>
    )
}
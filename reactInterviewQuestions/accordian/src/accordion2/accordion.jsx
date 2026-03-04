import { useState, createContext } from "react";
import './style.css';

export const AccordionContext = createContext();

export default function Accordion({ children, type = "single" }) {
    const [openItems, setOpenItems] = useState([]);

    function toggleItems(id) {
        if (type === "single") {
            setOpenItems(prev => prev[0] === id ? [] : [id]);
        } else {
            setOpenItems(prev => prev.includes(id) ? prev.filter(item => item !== id) : [...prev, id]);
        }
    }

    return (
        <AccordionContext.Provider value={{ openItems, toggleItems }}>
            <div className="accordion">{children}</div>
        </AccordionContext.Provider>
    )
}
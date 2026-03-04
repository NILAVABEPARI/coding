import { useEffect, useState } from 'react';
import './style.css'

function TrafficLight({ data }) {

    const dataToShow = setLightsInDisplayOrder(data);
    const lightsInOrder = setLightsInOrder(data);

    const [activeLight, setActiveLight] = useState(lightsInOrder[0]);

    // !! toSorted returns a new array and doesn't modify the original array
    function setLightsInDisplayOrder(randomOrder) {
        return randomOrder.toSorted((a, b) => {
            return a.displayOrder - b.displayOrder;
        })
    }

    function setLightsInOrder(randomOrder) {
        return randomOrder.toSorted((a, b) => {
            return a.order - b.order;
        })
    }

    useEffect(() => {
        setTimeout(() => {
            const currentLightIndex = lightsInOrder.findIndex(l => l.color === activeLight.color);
            const nextLightIndex = (currentLightIndex + 1) % lightsInOrder.length;
            setActiveLight(lightsInOrder[nextLightIndex]);
        }, activeLight.time);
    }, [activeLight]);

    return <div className="trafficLights">
        {
            dataToShow.map(light => {
                return <Lights key={light.color} color={light.color} activeLight={activeLight} />
            })
        }
    </div>
}

function Lights({ color, activeLight }) {
    const opacity = color === activeLight.color ? 1 : 0.2;
    return <div style={{ backgroundColor: color, opacity }} className="lights" />
}

export default TrafficLight;
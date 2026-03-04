import './style.css';

export default function Switch({ isOn, onToggle = () => { }, label = "" }) {
    return (
        <div className='switch'>
            <label>
                <input type="checkbox" role="switch" checked={isOn} onChange={onToggle} />
                <span className="slider" />
                <span className="switch-label">{label}</span>
            </label>
        </div>
    )
}
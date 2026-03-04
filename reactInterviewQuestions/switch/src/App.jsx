import { useState } from 'react'
import Switch from './switch';
import './App.css'

function App() {
  const [isOn, setIsOn] = useState(false);

  function handleToggle() {
    setIsOn(!isOn);
  }

  return (
    <>
      <Switch label="Learning Switch" isOn={isOn} onToggle={handleToggle} />
    </>
  )
}

export default App

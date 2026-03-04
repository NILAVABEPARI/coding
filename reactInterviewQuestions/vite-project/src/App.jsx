import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [dataToDisplay, setDataToDisplay] = useState([
    "nilava",
    "bepari",
    "jane",
    "dey"
  ])

  function buttonClick(index) {
    const newArray = dataToDisplay.filter((data, ind) => index !== ind);
    setDataToDisplay(newArray);
  }

  return (
    <>
      <h1>list rendering</h1>
      <ul>
        {
          dataToDisplay.map((data, index) => {
            return <li key={data} onClick={() => buttonClick(index)}>{data}</li>
          })
        }
      </ul>
    </>
  )
}

export default App

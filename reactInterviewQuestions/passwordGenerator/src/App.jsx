import { useState } from 'react'
import './App.css'

function App() {

  return (

    <div className='container'>
      {/* password text and copy */}
      <div className='header'>
        <div className='title'>12334</div>
        <button className='copyBtn' onClick={() => { }}>Copy</button>
      </div>

      {/* character length */}
      <div className='charLength'>
        <span>
          <label>Character Length</label>
          <label>4</label>
        </span>

        <input type="range" min={4} max={20} value={""} onChange={""} />
      </div>

      {/* checkboxes */}

      {/* strength */}

      {/* generate button */}
    </div>

  )
}

export default App

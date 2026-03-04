import './App.css';
import Folder from './components/Folder';
import explorerData from './data/folderData'

function App() {

  return (
    <div>
      <h1>Folder Structure</h1>
      <Folder explorer={explorerData} />
    </div>
  )
}

export default App

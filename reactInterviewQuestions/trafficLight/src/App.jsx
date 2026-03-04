import './App.css'
import TrafficLight from './assets/traffic-light'

function App() {

  const lightsData = [
    {
      color: "red",
      time: 4000,
      order: 1,
      displayOrder: 3
    },
    {
      color: "yellow",
      time: 2000,
      order: 2,
      displayOrder: 1
    },
    {
      color: "green",
      time: 1000,
      order: 3,
      displayOrder: 2
    },
    {
      color: "aqua",
      time: 3000,
      order: 4,
      displayOrder: 5
    },
    {
      color: "purple",
      time: 1000,
      order: 5,
      displayOrder: 4
    }
  ]

  return (
    <TrafficLight data={lightsData} />
  )
}

export default App

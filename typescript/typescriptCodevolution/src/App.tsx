import './App.css'
import { Button } from './components/Button'
import { Container } from './components/Container'
import { Greet } from './components/Greet'
import { Heading } from './components/Heading'
import { Input } from './components/Input'
import { Oscar } from './components/Oscar'
import { Person } from './components/Person'
import { PersonList } from './components/PersonList'
import { Status } from './components/Status'

function App() {
  const personName = {
    first: "Nilava",
    last: "Bepari"
  }

  const namesList = [
    {
      first: 'Bruce',
      last: 'Wayne'
    },
    {
      first: 'Clark',
      last: 'Kent'
    },
    {
      first: 'Princess',
      last: 'Diana'
    }
  ]

  return (
    <div>
      <Greet name="nilava" messageCount={10} isLoggedIn={true} />
      <Person name={personName} />
      <PersonList names={namesList} />

      {/* Union type */}
      <Status status="loading" />

      {/* Children props */}
      <Heading>Placeholder Text</Heading>

      {/* Children props -- child is another react component */}
      <Oscar>
        <Heading>Oscar goes to Leonardo</Heading>
      </Oscar>

      {/* Optional Props -- button */}
      <Greet name="panda" isLoggedIn={true} />

      {/* Event Props */}
      <Button handleClick={(event, id) => console.log('button clicked ', event, id)} />

      {/* Event Props -- input */}
      <Input value='' handleChange={event => console.log(event)} />

      {/* Style Props */}
      <Container styles={{ border: "1px solid red", padding: "1rem" }} />
    </div>
  )
}

export default App

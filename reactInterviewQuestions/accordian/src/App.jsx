// import Accordion from './accordion/accordion';
// import './App.css'

// function App() {

//   return (
//     <Accordion type="single"> {/* single / multiple */}
//       <Accordion.Item heading="Learning React"> {/* Compound Component Pattern */}
//         {/* Accordion.Item == AccordionItem */}
//         <p>React is component based.</p>
//       </Accordion.Item>

//       <Accordion.Item heading="Learning JavaScript">
//         <p>JS is single threaded but async.</p>
//       </Accordion.Item>

//       <Accordion.Item heading="Learning Accessibility">
//         <p>ARIA attributes are important.</p>
//       </Accordion.Item>
//     </Accordion>
//   )

// }

// export default App


import Accordion from "./accordion2/accordion";
import AccordionItem from "./accordion2/accordionItem";

function App() {
  return (
    <Accordion type="single">
      <AccordionItem header="Learning react">
        <p>Learning react is fun</p>
      </AccordionItem>
      <AccordionItem header="Learning react">
        <p>Learning react is fun</p>
      </AccordionItem>
      <AccordionItem header="Learning react">
        <p>Learning react is fun</p>
      </AccordionItem>
    </Accordion>
  )
}

export default App;

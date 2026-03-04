import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'

// createRoot(document.getElementById('root')).render(
//   <StrictMode>
//     <App />
//   </StrictMode>,
// )

const UIData = {
  type: "div",
  children: [
    {
      type: "h1",
      children: "Learning React with Frontend Master is Fun"
    },
    {
      type: "p",
      children: "Awesome React"
    }, {
      type: "span",
      children: "I am span in React "
    },
    "nilava bepari"
  ]
}

function createUI(data) {
  if (typeof data === "string") {
    return document.createTextNode(data);
  }

  const elem = document.createElement(data.type);

  if (typeof data.children === "string") {
    elem.textContent = data.children;
  } else {
    data.children.forEach(child => {
      elem.appendChild(createUI(child));
    })
  }

  return elem;
}

const dom = createUI(UIData);

document.getElementById("root").appendChild(dom);
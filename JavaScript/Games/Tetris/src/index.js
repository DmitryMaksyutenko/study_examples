import { foo, Rectangle } from "./gameObjects/rectangle.js"

window.onload = () => {

    const r = new Rectangle()
    document.body.appendChild(r.elem)

}

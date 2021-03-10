import "../styles/gameObjects.css"

export class Rectangle {
    constructor() {
        this.elem = document.createElement("div")
        this.elem.classList.add("rectangle")
    }

    elem() {
        return this.elem
    }

}

export class Rectangle {
    constructor() {
        this.elem = document.createElement("div")
        this.elem.style.width = "50px"
        this.elem.style.height = "50px"
        this.elem.style.border = "1px solid black"
        this.elem.style.borderRadius = "15%"
    }

    elem() {
        return this.elem
    }

}

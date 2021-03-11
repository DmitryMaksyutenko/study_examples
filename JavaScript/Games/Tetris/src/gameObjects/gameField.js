import { Rectangle } from "../gameObjects/rectangle.js"

import "../styles/gameObjects.css"


export class GameField {

  constructor() {
    this.field = document.createElement("div")
    this.field.classList.add("gameField")
    this.blocks = []
    this.blocks.length = 22
    for (let i = 0; i < this.blocks.length; i++) {
      this.blocks[i] = []
      this.blocks[i].length = 12
    }
    for (let i = 0; i < this.blocks.length; i++) {
      for (let j = 0; j < this.blocks[i].length; j++) {
        this.blocks[i][j] = new Rectangle()
        this.field.appendChild(this.blocks[i][j].elem)
      }
    }
  }

  getField() {
    return this.field
  }

}
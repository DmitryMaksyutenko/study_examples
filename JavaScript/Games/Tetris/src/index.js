import { GameField } from "../src/gameObjects/gameField"

import "./styles/base.css"

window.onload = () => {

    var gameField = new GameField()
    document.body.appendChild(gameField.getField())
    
}

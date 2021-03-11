import { GameField } from "../src/gameObjects/gameField.js"
import { Rectangle } from "../src/gameObjects/rectangle.js"


test("The GameField createion.", () => {
  var field = new GameField()
  expect(field.blocks).toBeInstanceOf(Array)
  expect(field.getField().className).toBe("gameField")
})

test("GameField size.", () => {
  var field = new GameField()
  expect(field.blocks.length).toBe(22)
  expect(field.blocks[0].length).toBe(12)
  expect(field.blocks[5].length).toBe(12)
  expect(field.blocks[11].length).toBe(12)
})

test("GameField blocks instance.", () => {
  var field = new GameField()
  expect(field.blocks[2][4]).toBeInstanceOf(Rectangle)
  expect(field.blocks[10][8]).toBeInstanceOf(Rectangle)
  expect(field.blocks[11][1]).toBeInstanceOf(Rectangle)
  expect(field.blocks[21][11]).toBeInstanceOf(Rectangle)
})
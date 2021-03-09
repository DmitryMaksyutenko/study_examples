import {Rectangle} from "../src/gameObjects/rectangle.js"

test("Rectangle object creation.", () => {
    const rect = new Rectangle()
    expect(rect).toBeInstanceOf(Rectangle)
})

test("Rectangle creates <div>", () => {
    const rect = new Rectangle()
})
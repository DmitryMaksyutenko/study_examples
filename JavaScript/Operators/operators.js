//  The arithmetic operators.
document.write("<style>body{text-align: center;}</style>")

//  Reminder division
document.write('<p style="color: red;">The remainder.</p>')
document.write("3 % 5 = " + eval(3 % 5) + "<br>")
document.write("11 % 5 = " + 11 % 5 + "<br>")
document.write("12.3 % 2.0 = " + 12.3 % 2.0 + "<br>")
document.write("<hr>")

//  The comparison operators.
document.write('<p style="color: green">The comparison operators.</p>')
//  The operators "==" "!=" with automatic type conversion.
document.write("123 == '123' = " + eval(123 == '123') + "<br>")
document.write("123 != '123' = " + eval(123 != '123') + "<br>")
document.write("'123' == '123' = " + eval('123' == '123') + "<br>")
//  The operators "===", "!==" without automatic type conversion.
document.write("123 === '123' = " + eval(123 === '123') + "<br>")
document.write("123 !== '123' = " + eval(123 !== "123") + "<br>")
document.write("123 === 123 = " + eval(123 === 123) + "<br>")
document.write("<hr>")

//  The logical operators.
document.write('<p style="color: blue;">The logical operators.</p>')
document.write("1 && 0 = " + eval(1 && 0) + "<br>") // 0
document.write("0 && 0 = " + eval(0 && 0) + "<br>") // 0
document.write("1 && 1 = " + eval(1 && 1) + "<br>") //  1
document.write("0 && 1 = " + eval(0 && 1) + "<br>") //  0
document.write("true && fasle = " + eval(true && false) + "<br>")   // false
document.write("true && true = " + eval(true && true) + "<br>") // true
document.write("false && false = " + eval(false && false) + "<br>") // fasle
document.write("1 || 0 = " + eval(1 || 0) + "<br>") // 1
document.write("0 || 0 = " + eval(0 || 0) + "<br>") // 0
document.write("1 || 1 = " + eval(1 || 1) + "<br>") // 1
document.write("0 || 1 = " + eval(0 || 1) + "<br>") // 1
document.write("true || fasle = " + eval(true || false) + "<br>")   // true
document.write("true || true = " + eval(true || true) + "<br>") // true
document.write("false || false = " + eval(false || false) + "<br>") // false
document.write("!!1, !!0, !!5, !!true, !!fasle : " + eval(!!1)
                + ", " + eval(!!0) + ", " + eval(!!5) 
                + ", " + eval(!!true) + ", " + eval(!!false)
                + "<br>")
document.write("<hr>")

//  Ternary operator.
document.write('<p style="color: cyan">Ternary operator.</p>')
var res = 0
document.write("(1 + 1) == 2? res = 2: res; " + eval((1 + 1) == 2? res = 2: res) + "<br>")
document.write("res = " + res + "<br>")
document.write("<hr>")

//  The trick with increment/decrement.
var x, y
x = 10
//  Computation from right to left.
y = x++ + x++
document.write('<p style="color: gray;">The trick with increment/decrement.</p>')
document.write("y = x++ + x++ " + "<br>y = " + y + ", x = " + x + "<br>")
x = 10
y = ++x + ++x
document.write("y = ++x + ++x" + "<br>y = " + y + ", x = " + x + "<br>")
document.write("<hr>")

//  The tricks with the conversion.
document.write('<p style="color: red; font-weight: bold; font-size: 20px;">The tricks with the conversion.</p>')
document.write("100" + "100" + "<br>") // 100100
document.write("100" - "100" + "<br>") // 0
document.write(100 - "100" + "<br>") // 0
document.write(100 + "100" + "<br>") // 100100
document.write(100 + +"100" + "<br>") // 200
document.write("<hr>")
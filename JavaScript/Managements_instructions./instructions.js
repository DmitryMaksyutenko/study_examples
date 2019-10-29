document.write('<p style="text-align: center; color: green; font-size: 24px;">Conditional operator</p>')

var message = "Enter number"
//  The Window.prompt() displays a dialog with an optional message prompting the user to input some text. Return a string value or none.
var number = prompt(message)

if (number % 2 == 0)
{
    document.write('<div style="background-color: red; width: 50px; height: 50px; margin-left: 50%;"></div>')
}
else
{
    document.write('<div style="background-color: green; width: 50px; height: 50px; margin-left: 50%;"></div>')
}
document.write("<hr>")

document.write('<p style="text-align: center; color: blue; font-size: 24px;">Loop</p>')
var i = 0
while (i < 10)
{
    document.write('<div style="background-color: red; margin: 20px; display: inline-block; width:'+ i * 10 +'px; height: '+ i * 10 +'px;"></div>')
    i++
}

do
{
    document.write('<div style="background-color: red; margin: 20px; display: inline-block; width:'+ i * 10 +'px; height: '+ i * 10 +'px;"></div>')
    i--
}
while (i > 0)

document.write('<br>')
for (var i = 0; i < 100; i++)
{
    document.write('<p style="display: inline-block; margin-left: 3px; color: rgb('+ 250*Math.random() +', '+ 250*Math.random()+', '+ 250*Math.random()+');">'+ i +'</p>')
}
document.write("<hr>")
document.write('<p style="text-align: center; color: red; font-size: 24px;">Swith</p>')
text = prompt("Enter new number")
switch(text)
{
    case "1":
        document.write("case one<br>")
        break
    case "2":
        document.write("case two<br>")
        break
    case "3":
        document.write("case thee<br>")
        break
    case "4":
        document.write("case four<br>")
        break
    case "5":
        document.write("case five<br>")
        break
    case "6":
        document.write("case six<br>")
        break
    case "7":
        document.write("case seven<br>")
        break
    case "8":
        document.write("case eight<br>")
        break
    case "9":
        document.write("case nine<br>")
        break
    default:
        document.write("default block")
}
document.write("<hr>")
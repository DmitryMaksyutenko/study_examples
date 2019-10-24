//  A document is an object of work document (in which placed code of a script).
//  The method write() called from the document object and can display the plain text and the HTML markup.
document.write("<h1>Hello JavaScript</h1><hr>");
document.write("<b>Some text</b><hr>");

/*  VARIABLES:
    string
    numbers
    the logic value (true or false)
    object
    function
*/

//  Declaration of variable, the type is not specified.
//  The semicolon may not be specified if it is the only command in the row.
var text, num
text = "Some text in variable 'text'"
num = 123
document.write(text+'<br>')

//  The expression in which present variables of string and integer types return the string. 
text = "the value of number: "
document.write(text+num+'<br>')

//  The eval() function does the computation of the passed string.
document.write("3+(5*2+6)/4"+'<br>')
document.write(eval("3+(5*2+6)/4")+'<br>')

//  The typeof operator returns the string describes the type of the operand.
document.write('<hr>')
document.write(typeof 1)
document.write('<br>')
document.write(typeof 1.1)
document.write('<br>')
document.write(typeof "str")
document.write('<br>')
document.write(typeof function(){})
document.write('<br>')
document.write(typeof Object)
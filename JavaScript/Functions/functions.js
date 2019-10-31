//  The global variable in JavaScript is a variable of window level, were opened the document that uses the script.
//  Global variables are the properties of the window.
//  window.some_text for example
//  The local area in JavaScript is only function bounds.
//  There is possible to define a function inside another function. The inside function has access to local variables of the outside function.

document.write(page_topic())
var some_text = "this is global text!"

user_input = prompt("enter a number for generating.")
document.write(get_rand_number(user_input))
document.write(horizontal_line())

document.write(message("Global and Local variables"))
global_local_var()
document.write(horizontal_line())

document.write(message("Default parameters"))
document.write(param() + new_line())
document.write(param(2, 5) + new_line())
document.write(param(1, 1, 1) + new_line())
document.write(param(9) + new_line())
document.write(horizontal_line())

document.write(message("function as parameter"))
document.write(pass_function(message))
document.write(horizontal_line())

document.write(message("Anonymous function"))
(function(){document.write("Anonymous Function!")}())
document.write(horizontal_line())


//-------------------------------------------------------------------------------------------------------------------------
function pass_function(foo){
    return foo("this is function parameter")
}

//-------------------------------------------------------------------------------------------------------------------------
function param(x, y, z){
    if(typeof(x) == "undefined")
        x = 1
    if(typeof(y) == "undefined")
        y = 2
    if(typeof(z) == "undefined")
        z = 3
    return x + y + z
}
//-------------------------------------------------------------------------------------------------------------------------
function global_local_var(){
    document.write("<p>"+ window.some_text +"</p>")
    // var some_text = "this is local text!"
    document.write("<p>" + some_text + "</p>")
}

//-------------------------------------------------------------------------------------------------------------------------
function get_rand_number(num){
    //  Use of var instruction is necessary for making the variable local. To avoid name conflicts with the global variables.
    var text = "The random number is: "
    text += make_rnadom_number(num)
    return text
}

function make_rnadom_number(num){
    return Math.floor(num * Math.random())
}

//-------------------------------------------------------------------------------------------------------------------------
//  The topic if the pagee
function page_topic(){
    return '<p style="text-align: center; font-size: 26px; color: red;">Functions.</p>'
}

// Tne new line function
function new_line(){
    return '<br>'
}

//  The horizontal line
function horizontal_line(){
    return '<hr>'
}

function message(message){
    return '<p style="text-align: center; font-size: 30px; color: green;">' + message + '</p>' + new_line()
}
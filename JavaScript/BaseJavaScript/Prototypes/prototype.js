/*
    var A = {} // Empty object with prototype
    var A = Object.create(null) //   Empty object without prototype
    var B = Object.create(A) // Empty object with explicit prototype
*/
document.write('<p style="color: red; text-align: center; font-size: 30px;">Prototypes</p>')
document.write('<hr>')

//   Base operations
var X = {
    color: 'red',
    number: 123,

    show: function(arg){
        for (var i in this){
            if (i != "show")
                document.write(i + "-> " + this[i] + " | ")
        }
        document.write('<br>')
    }
}

var A = Object.create(X)
var B = Object.create(X)
showAll()
A.color = 'green'
A.number = 000
B.color = 'blue'
B.number = 111
showAll()
X.name = 'prototype'
A.state = true
showAll()
delete X.number
delete A.color
showAll()

document.write('<hr>')

//  Access to prototype
document.write('<p style="color: red; text-align: center; font-size: 30px;">Access to prototypes</p>')
var text = '"name" in Math'
document.write(text + ' -> ' + eval(text) + '<br>')
var A1 = {color: 'purple'}
var B1 = new Object()
B1.number = 100
show_All()
Object.prototype.name = 'object A'
document.write(text + ' -> ' + eval(text) + '<br>')
show_All()
B1.name = 'object B'
document.write('Math.name -> ' + Math.name + '<br>')
show_All()
delete Object.prototype.name
document.write(text + ' -> ' + eval(text) + '<br>')
show_All()
//  The method getPrototypeOf() of the Object returns the reference to the prototype.
document.write('Prototype of A1: ' + Object.getPrototypeOf(A1))
document.write('<hr>')

function showAll(){
    X.show("X")
    A.show("A")
    B.show("B")
    document.write("<hr>")
}

function show(obj){
    for (var x in obj){
        document.write(x + " -> " + obj[x] + " | ")
    }
    document.write("<br>")
}

function show_All(){
    document.write("Objecnt A: ")
    show(A1)
    document.write("Objecnt B: ")
    show(B1)
    document.write("<br>")
}
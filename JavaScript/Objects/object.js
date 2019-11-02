document.write('<h1 style="color: red; text-align: center; font-size: 26px;">OOP Objects</h1>')
document.write('<hr>')

//  Describing the literal of the object.
document.write('<h1 style="color: red; text-align: center; font-size: 26px;">Literal</h1>')
var person = {name: "Dima", age: 31}
document.write('<p style="text-align: center;">Name = '+ person.name +'</p>')
document.write('<p style="text-align: center;">Age = '+ person.age +'</p>')
person.name = "Ann"
person.age = 27
document.write('<p style="text-align: center;">Name = '+ person.name +'</p>')
document.write('<p style="text-align: center;">Age = '+ person.age +'</p>')

var rectangle = {
    obj: '<div style="background-color: yellow; width: 60px; height: 60px; margin-left: 48%;"></div>',
    show: function(){document.write(this.obj)}
}

rectangle.show()
document.write('<hr>')

//  Function constructor.
document.write('<h1 style="color: red; text-align: center; font-size: 26px;">Function constructor</h1>')
function Person(name, age){

    this.name = name
    this.age = age

    this.show = function(){
        document.write('<p style="text-align: center;">Name = '+ this.name +'</p>')
        document.write('<p style="text-align: center;">Age = '+ this.age +'</p>')
    }

}

var person_two = new Person("Dima", 31)
person_two.show()
document.write('<hr>')


// With operator.
document.write('<h1 style="color: red; text-align: center; font-size: 26px;">With operator</h1>')
with(rectangle){
    show()
}
document.write('<hr>')

//  for-in
document.write('<h1 style="color: red; text-align: center; font-size: 26px;">for-in operator</h1>')
for(var i in person){
    document.write('<p style="text-align: center;">'+ i + " = " + person[i] +'</p>')
}
document.write('<hr>')

// in operator
document.write('<h1 style="color: red; text-align: center; font-size: 26px;">in operator</h1>')
var a = "" in person
var b = "name" in person
document.write('<p style="text-align: center;">'+ a + ' in person</p>')
document.write('<p style="text-align: center;">'+ b + ' in person</p>')
document.write('<hr>')

// delete operator
document.write('<h1 style="color: red; text-align: center; font-size: 26px;">delete operator</h1>')
var a = "" in person
var b = "name" in person
document.write('<p style="text-align: center;">'+ a + ' in person</p>')
document.write('<p style="text-align: center;">'+ b + ' in person</p>')
delete person.name
b = "name" in person
document.write('<p style="text-align: center;">'+ a + ' in person</p>')
document.write('<p style="text-align: center;">'+ b + ' in person</p>')
document.write('<hr>')







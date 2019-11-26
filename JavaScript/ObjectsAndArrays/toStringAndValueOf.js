document.write('<p style="text-align: center; color: red; font-size: 26px;">toString() valueOf()</p>')

//  These methods defined in the prototype of an Object (The high-level prototype). In general, these methods must be overridden.
//  toString() method defined in the prototype of a high-level.
Object.prototype.toString = function(){
  let t = "<p style='text-align: center;'><u>Object self properties: </u>"

  for (let i in this){
    t += "<p style='text-align: center;'><b>" + i + "</b>: " + this[i] + "</p>"
  }

  return t
}

// valueOf() method defined in the prototype of a high-level.
Object.prototype.valueOf = function(){
  return Object.keys(this).length
}

var A = {one: 1, two: 2, three: 3, four: 4, five: 5}

//  Implicit call of toString()
document.write(A)
//  Implicit call of valueOf()
document.write("<p style='text-align: center;'>The number of properties in object A - "+ A +"</p>")

var B = {first: "первый", second: "второй", third: "третий"}
document.write(B)
document.write("<p style='text-align: center;'>The number of properties in object B - "+ B +"</p>")

document.write("<hr>")

//  The constructor function
function Person(name, age, gender){
  var g

  if (gender){
    g = "male"
  }
  else{
    g = "female"
  }

  this.name = name
  this.age = age

  Object.defineProperty(this, "gender", {
    get: function(){
      return g
    }
  })
}

Person.prototype.toString = function(){
  let t = "<p style='text-align: center;'>Personal data: "
  t += "<p style='text-align: center;'> Name: "+ this.name +"<br>"
  t += "<p style='text-align: center;'> Age: "+ this.age +"<br>"
  t += "<p style='text-align: center;'> Gender: "+ this.gender +"<br></p>"

  return t
}

Person.prototype.valueOf = function(){
  return this.age
}

var Di = new Person("Dima", 31, true)
var An = new Person("Anna", 27, false)

document.write(Di)
document.write(An)

document.write("<p style='text-align: center;'>The Dima age is : "+ Di +"</p>")
document.write("<p style='text-align: center;'>The Anna age is : "+ An +"</p>")

document.write('<hr>')

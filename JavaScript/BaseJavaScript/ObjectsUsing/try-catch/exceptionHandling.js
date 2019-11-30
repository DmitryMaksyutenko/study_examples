document.write('<h1 style="text-align: center; font-size: 24px; color: red;">Exception Handling.</h1>')
document.write('<hr>')

document.write('<h1 style="text-align: center; font-size: 24px; color: red;">try-catch Instruction.</h1>')

try{
  document.write('<p style="text-align: center;">start executing <code>try</code>-block<br>')

  let txt
  txt = prompt("enter the expressiom: ")

  document.write("the result is : " + eval(txt) + "<br>")
} catch(exception)
{
  document.write("the exeption occurred!" +"<br>")
}

document.write("execution ends")
document.write('<hr>')

document.write('<h1 style="text-align: center; font-size: 24px; color: red;">Brovser cpecific options.</h1>')

try{
  document.write('<p style="text-align: center;">start exectuting<code>try</code>-block<br></p>')
  let txt = prompt("enter expression: ")
  document.write("<p style='text-align: center;'>the result is : " + eval(txt) + "</p>")
  document.write("<p style='text-align: center;'>end of <code>try</code>-block</p>")
} catch(exception){
  let errorName = exception.name
  let errorDescription = exception.message
  let textForDisplay

  switch(errorName){
    case "ReferenceError":
      textForDisplay = "Invalid link"
      break

    case "SyntaxError":
      textForDisplay = "Invalid syntax"
      break

    default:
      textForDisplay = "Error" + errorName
  }

  document.write("<p style='text-align: center;'><b>Attention! the mistake accurred!</b></p>")
  document.write("<p style='text-align: center;'>" + textForDisplay + "</p><br>")
  document.write("<p style='text-align: center;'>Mistake description: " + errorDescription + "</p>")

  // For Mozilla browser.
  if ("fileName" in exception){
    document.write("<p style='text-align: center;'><b>File with error: </b>" + exception.fileName + "</p>")
  }
}

document.write("<p style='text-align: center;'>execution ends</p>")
document.write('<hr>')

document.write('<h1 style="text-align: center; font-size: 24px; color: red;">Exception generatong (throw).</h1>')

  let Arr = [1, 3, 6, 0, 4, 7, 9, 8]
  let num

 for (let i = 0; i < Arr.length; i++){
    num = Arr[i]

    try {
      if (num == 0){
        throw "Zerro value."
      }
      document.write("<p style='text-align: center;'>Another from zero value: " + num + "</p>")
    } catch (error) {
      document.write("<p style='text-align: center;'>Attention: " + error + "</p>")
      continue
    }

    try {
      if (num % 2 == 0){
        throw new Error("<p style='text-align: center;'>the value is even.</p>")
      }
    } catch (error) {
      document.write(error.message)
    }

    document.write("<p style='text-align: center;'>end of loop : " +  (i + 1) + "!!!</p>")
  }

document.write('<hr>')

document.write('<h1 style="text-align: center; font-size: 24px; color: red;">The nested try-cath.</h1>')

for (let i = -1; i <= 1; i+= 2){
  try {
    document.write("<p style='text-align: center;'>Outer try block.</p>")
    try {
      document.write("<p style='text-align: center;'>Internal try block.</p>")
      var A = new Array(i)
      var B = C
    } catch (error) {
      if (error.name == "RangeError"){
        error.message = "Invalid size of the array (Error code RangeError)"
        throw error
      }
      document.write("<p style='text-align: center;'>Invalid assigning.</p>")
    }
    finally{
      document.write("<p style='text-align: center;'>End of internal try-catch.</p>")
    }
      document.write("<p style='text-align: center;'>No error occurred.</p>")
  } catch (err) {
    document.write("<p style='text-align: center;'>" + err.message + ".</p>")
  }
    document.write("<p style='text-align: center;'>End of outer try-cath block.</p>")
}

document.write('<hr>')

document.write('<h1 style="text-align: center; font-size: 24px; color: red;">User defined errors.</h1>')

function MyError(id, message){
  this.id = id
  this.message = message || "User defined Error"
}

MyError.prototype = Object.create(Error.prototype)
MyError.prototype.name = "MyError"
MyError.prototype.toString = function(){
  var txt = this.message + ": " + this.name + ". "
  txt += " Error id: " + this.id + ". "
  return txt
}

MyError.prototype.constructor = MyError

try {
    document.write("<p style='text-align: center;'>Outer try block.</p>")
  try {
    document.write("<p style='text-align: center;'>Internal try block.</p>")
    throw new MyError(200, "My new Error")
  } catch (k) {
    document.write("<p style='text-align: center;'>" + k + "</p>")
    throw new k.constructor(100)
  }
} catch (error) {
  document.write("<p style='text-align: center;'>" + error + "</p>")
}

document.write('<hr>')
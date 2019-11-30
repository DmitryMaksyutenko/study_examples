document.write('<p style="text-align: center; font-size: 26px; color: red;">Object as associative array.</p>')

var obj = {name: "object", code: 123}

// Add property to object.
obj["text"] = "some text stored in object."

for (let i = 1; i < 5; i++){
  obj["property_" + i] = String.fromCharCode("A".charCodeAt(0) + i - 1)
}

for (let x in obj){
  document.write('<p style="text-align: center;">property: <b style="color: blue;">'+ x + '</b> value: <b style="color: green;">' + obj[x] + '</b></p>')
}

// Array with object names.
var objNames = Object.keys(obj)
document.write("<p style='text-align: center;'>[" + objNames.join(" | ") + "]</p>")

document.write('<hr>')

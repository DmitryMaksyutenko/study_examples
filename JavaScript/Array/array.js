document.write('<h1 style="text-align: center; font-size: 24; color: red;">Array</h1>')
document.write('<hr>')

// Explicit defining of the array elements.
document.write('<h1 style="text-align: center; font-size: 24; color: green;">Explicit defining of the array elements.</h1>')
//  var array = [value_1, value_2, value_3, ... , value_n ]
let arr_1 = [1, 'text', true, 5.5]
document.write(arr_1 + "<br>")
for (var i in arr_1){
    document.write(arr_1[i] + " | ")
}
document.write('<hr>')

//  Addition the elements into the array.
document.write('<h1 style="text-align: center; font-size: 24; color: green;">Addition the elements into the array.</h1>')
let arr_2 = []
arr_2[0] = 1
arr_2[1] = 'element'
arr_2[2] = false
arr_2[3] = 1.1

for (let i = 0; i < arr_2.length; i++){
    document.write(arr_2[i] + ' | ')
}
document.write('<hr>')

//  Using the object-constructor of the Array.
document.write('<h1 style="text-align: center; font-size: 24; color: green;">Using the object-constructor of the Array.</h1>')
let arr_3 = new Array(1, 2, 'text', false, 4.76)
for (let i = 0; i < arr_3.length; i++){
    document.write(arr_3[i] + ' | ')
}
document.write('<hr>')

//  The methods of the Array.
document.write('<h1 style="text-align: center; font-size: 24; color: red;">Array methods.</h1>')
//  All these methods are inherited from Array.prototype.
let arr_4 = new Array("a", "b", "c")

document.write(arr_4.concat(arr_1))
document.write("<br>" + arr_4.every(function(x){
    if (typeof x == "string"){
        return true
    }
}))

document.write("<br>" + arr_4.filter(function(x){
    if (x == 'a'){
        return x
    }
}))

document.write("<br>" + arr_4.sort())
document.write('<hr>')
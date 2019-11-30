document.write('<h1 style="text-align: center; font-size: 24; color: red;">Two dimensional array.</h1>')
document.write('<hr>')


Array.prototype.toString = function(){
  return this.join("") + "<br>"
}

var A = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
document.write('<b>Array A</b>:<br>')
document.write(A)

var i, j, m = 3, n = 4
var B = new Array(m)

for (i = 0; i < B.length; i++){
  B[i] = new Array(n)

  for (j = 0; j < B[i].length; j++){
    B[i][j] = "b<sub>" + (i + 1) + (j + 1) + "</sub>"
  }
}

document.write('<b>Array B</b>:<br>')
document.write(B)

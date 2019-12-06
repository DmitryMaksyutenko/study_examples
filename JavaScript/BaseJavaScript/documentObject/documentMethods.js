document.write("<p style='text-align:center; color: red; font-size: 26px;'>document methods.</p>")
document.write("<hr>")

document.write("<p style='text-align:center; color: red; font-size: 26px;'>All document methods and properties.</p>")

function showAllMethods(){
  let i = 1

  for(let attr in document){
    document.write(i +": "+ attr +" ")
    i++
  }

}

showAllMethods()

document.write("<hr>")

document.write("<p style='text-align:center; color: red; font-size: 26px;'>color properties.</p>")

function setColors(){
  document.bgColor = "grey"
  document.fgColor = "white"
  document.linkColor = "yellow"
  document.vlinkColor = "green"
  document.alinkColor = "red"

  document.write("<a href='http://www.google.com'>Google</a> ")
  document.write("<a href='http://www.github.com'>GitHub</a>")
  document.write("<a href='http://www.youtube.com'>YouTube</a>")
}

setColors()

document.write("<hr>")

document.write("<p style='text-align:center; color: red; font-size: 26px;'>Create new element metho.</p>")

function createElement(){
  let pElement = document.createElement("p")
  pElement.innerHTML = "Hello!"
  let pList = document.getElementsByName("p")
  document.body.insertBefore(pElement, pList[pList.length - 1])
}

createElement()

document.write("<hr>")

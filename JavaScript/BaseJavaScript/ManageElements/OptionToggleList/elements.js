document.write("<p style='text-align: center; font-size: 26px; color: red;'>Options Toggle Lists</p>")

var fitalic, fbold, family, fsize, fcolor, stext, tfamily, tstyle, tsize, tcolor

function setRefs(){
  stext = document.getElementById("sampleText")
  fitalic = document.getElementById("italicFont")
  fbold = document.getElementById("boldFont")
  family = document.getElementsByName("fontFamily")
  fsize = document.getElementById("fontSize")
  fcolor = document.getElementById("fontColor")
  tfamily = document.getElementById("font")
  tsyle = document.getElementById("style")
  tsize = document.getElementById("size")
  tcolor = document.getElementById("color")
}

function setHandlers(){
  fitalic.addEventListener("change", getStyle)
  fbold.onchange = getStyle

  for(let i = 0; i < family.length; i++){
    family[i].addEventListener("change", getFamily)
  }

  fsize.addEventListener("change", getSize)
  fcolor.onchange = function(){
    getColor()
  }
}

function getStyle(){
  let txt = ""

  if(fbold.checked){
    stext.style.fontWeight = "bold"
    txt = "bold"
  }
  else
    stext.style.fontWeight = "normal"

  if(fitalic.checked){
    stext.style.fontStyle = "italic"
    txt = "italic"
  }
  else
    stext.style.fontStyle = "normal"

  if(txt == "")
    txt == "regular"

  tsyle.innerHTML = txt
}

function getFamily(){
  for(let i = 0; i < family.length; i++){
    if(family[i].checked){
      stext.style.fontFamily = family[i].value
      tfamily.innerHTML = family[i].value
      return
    }
  }
}

function getSize(){
  stext.style.fontSize = fsize.value + "pt"
  tsize.innerHTML = fsize.value
}

function getColor(){
  stext.style.color = fcolor.value
  tcolor.innerHTML = convertColor(fcolor.value)
}

function convertColor(color){
  if(color == "red")
    return "Red"
  if(color == "blue")
    return "Blue"
  if(color == "green")
    return "Green"
}

function set(){
  setRefs()
  fitalic.checked = false
  fbold.checked = false
  fsize[0].checked = true
  fcolor[0].checked = true
  family[0].checked = true
  setHandlers()
  getStyle()
  getSize()
  getColor()
  getFamily()
}

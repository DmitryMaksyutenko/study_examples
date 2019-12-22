document.write("<p style='text-align: center; font-size: 26px; color: red;'>Get event source.</p>")

var colors = new Array(5)
var colorSelected

for (let i = 0; i < colors.length; i++)
    colors[i] = "rgb(0, "+ (215 + i * 10) +", 0)"

function setColor(){

    var input = document.getElementById("myDiv")
    input.style.background = colors[colorSelected]
    input.innerHTML = colors[colorSelected]

}

function next(){

    colorSelected = (colorSelected + 1) % colors.length
    setColor()

}

function previous(){

    if(colorSelected > 0)
        colorSelected--
    else
        colorSelected = colors.length - 1

    setColor()

}

function handler(event){

    var nxt, pre
    nxt = document.getElementById("next")
    pre = document.getElementById("prev")

    if(event.type == "load"){
        colorSelected = 0
        setColor()
        nxt.onclick = handler
        pre.onclick = handler
        return
    }

    if(event.type == "click"){
        if(event.target == nxt){
            next()
            return
        }
        if(event.target == pre)
            previous()
    }

}

window.onload = handler
document.write("<p style='font-size: 26px; text-align: center; color: red;'>Event dispatching.</p>")

window.onload = function(){

    let redDiv = document.getElementById("redDiv")
    let yellowDiv = document.getElementById("yellowDiv")
    let greenDiv = document.getElementById("greenDiv")
    let textBlock = document.getElementById("eventText")

    let divColors = ["Red", "Yellow", "Green"]

    redDiv.onclick = displayText
    yellowDiv.onclick = displayText
    greenDiv.onclick = displayText

    function getColor(object){

        if(object == redDiv) return divColors[0] + "<br>"
        if(object == yellowDiv) return divColors[1] + "<br>"
        if(object == greenDiv) return divColors[2] + "<br>"

    }

    function displayText(event){

        textBlock.innerHTML += getColor(this)

        // if(this == redDiv) event.stopPropagation()

    }

}
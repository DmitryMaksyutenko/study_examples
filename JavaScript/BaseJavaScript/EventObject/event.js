document.write("<p style='font-size: 36px; text-align: center; color: red;'>Event Object.</p>")

document.onmousemove = function(event){

    var div = document.getElementsByTagName("div")[0]
    var text = "<b>Mouse coordinates:</b><br>"
    text += "Horizontal coordinate: " + "<b>"+ event.clientX +"</b><br>"
    text += "Vertical coordinate: &nbsp&nbsp&nbsp&nbsp&nbsp" + "<b>"+ event.clientY +"</b><br>"
    div.innerHTML = text

}
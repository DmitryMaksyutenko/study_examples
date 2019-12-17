document.write("<p style='text-align: center; font-size: 26px; color: red;'>Drawing the text and pictures.</p>")

var picture, canvas, canvasContext
var pictureFiles = ['Linux.png', 'Windows.png', 'MacOSX.png', 'Android.png']
var textList = ['This is Linux OS',
                'This is Windows OS',
                'This is MacOSX OS',
                'This is Android OS']
var imageIndex = 0

window.onload = function(){
    picture = new Image()
    canvas = document.getElementById("osCanvas")
    canvas.title = "Click left mouse button for image change."
    canvasContext = canvas.getContext("2d")
    canvasContext.font = '30px Arial'

    set()

    picture.onload = function(){
        canvasContext.drawImage(picture, 55, 25)
    }

    canvas.onclick = function(){
        imageIndex = (imageIndex + 1)%(pictureFiles.length)
        set()
    }

    function set(){
        canvasContext.fillStyle = "yellow"
        canvasContext.fillRect(0, 0, canvas.width, canvas.height)
        canvasContext.fillStyle = "blue"
        picture.src = pictureFiles[imageIndex]
        canvasContext.fillText(textList[imageIndex], 40, 310)
    }
}
document.write('<p style="text-align: center; font-size: 26px; color: red;">Buttons and input elements.</p>')
document.write('<hr>')

var promptText = "Inset text into field. The <b>Apply</b> button used for addition the text into the docuent."
                    "<b>Unlock</b> button used for make <b>Apply</b> button be available."
var enterText = "Use the <b>Apply</b> button for text insertion."
var unlockText = "Use the <b>Unlock</b> button for <b>Apply</b> unlock."

var textField, applyButton, unlockButton, textBloc, textPrompt

textField = document.getElementById("textField")
applyButton = document.getElementById("applyButton")
unlockButton = document.getElementById("unlockButton")
textBlock = document.getElementById("mytext")
textPrompt = document.getElementById("prompt")

setColor(false)

textField.value = ""
textField.disabled = false
applyButton.disabled = false
unlockButton.disabled = true

textPrompt.innerHTML = promptText

textField.onmouseover = function(){
    if(!this.disabled)
        setColor(true)
}

textField.onmouseout = function(){
    if(!this.disabled)
        setColor(false)
}

applyButton.onclick = function(){
    textBlock.innerHTML = textField.value
    textField.disabled = true
    unlockButton.disabled = false
    applyButton.disabled = true
}

applyButton.onmouseover = function(){
    if(!this.disabled)
        applyPrompt(unlockText)
}

applyButton.onmouseout = function(){
    if(!this.disabled)
        applyPrompt(enterText)
}

unlockButton.onclick = function(){
    textField.value = ""
    textBlock.innerHTML = ""
    textField.disabled = false
    unlockButton.disabled = true
    applyButton.disabled = false
}

unlockButton.onmouseover = function(){
    if(!this.disabled)
        applyPrompt(unlockText)
}

unlockButton.onmouseout = function(){
    if(!this.disabled)
        applyPrompt(enterText)
}

function setColor(arg){
    if(arg){
        textField.style.backgroundColor = "yellow"
        textField.style.borderColor = "red"
    }
    else{
        textField.style.backgroundColor = "white"
        textField.style.borderColor = "blue"
    }
}

function applyPrompt(msg){
    textBlock.innerHTML = msg
}
document.write('<p style="text-align: center; font-size: 26px; color: red;">window methods</p>')
document.write('<hr>')

document.write('<p style="text-align: center; font-size: 26px; color: red;">confirm promt alert</p>')

while(window.confirm("Ready to enter command?")){
  var res = window.prompt("Enter the command:")

  if(res != null){
    document.write("<p style='text-align: center;'>"+ res +" = "+ eval(res) +"</p>")
  }
  else{
    break
  }

}

window.alert("end of scenario!")

document.write('<hr>')

document.write('<p style="text-align: center; font-size: 26px; color: red;">open close</p>')

function openWindow(){
  if(window.mywindow && !mywindow.closed){
    window.alert("the document already opend!")
  }
  else{
    window.mywindow = window.open("hello.html")
  }
}

function closeWindow(){
  if(window.mywindow && !mywindow.closed){
    mywindow.close()
    window.mywindow = null
  }
  else{
    window.alert("the window already closed")
  }
}

document.write('<p style="text-align: center; font-size: 26px; color: red;">load document.</p>')

function loadDoc(docName){
  window.location.assign(docName)
}

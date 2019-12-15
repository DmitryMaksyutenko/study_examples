document.write("<p style='text-align: center; font-size: 26px; color: red;'>Work with image.</p>")

var imgPaths = ['Android.png', 'Linux.png', 'MacOSX.png', 'Windows.png',]
var systems = ['Android', 'Linux', 'MacOSX', 'Windows',]

var androidDescription = 'Android is a mobile operating system developed by Google.<br> It is used by several smartphones and tablets.<br>'
var linuxDescription = 'Linux is a Unix-like, open source and community-developed<br> operating system for computers, servers, mainframes,<br> mobile devices and embedded devices.<br>'
var macOCXDescription = 'macOS is a series of proprietary graphical<br> operating systems developed and marketed by Apple Inc. since 2001.<br>'
var windowsDescriprion = 'Windows is a series of operating<br> systems developed by Microsoft.<br>'

var osListText = [androidDescription,
              linuxDescription,
              macOCXDescription,
              windowsDescriprion]

var lst, text, img

window.onload = function(){
  lst = document.getElementById('myList')
  img = document.getElementById('myPict')
  text = document.getElementsByTagName('p')[0]

  for (let i = 0; i < systems.length; i++){
    lst.options[i] = new Option(systems[i], systems[i].toLowerCase())
    console.log(lst[i])
  }

  lst.onchange = function(){
    img.src = imgPaths[lst.selectedIndex]
    img.title = lst.value
    text.innerHTML = osListText[lst.selectedIndex]
  }

  var index = 1

  lst.options[index].selected = true

  img.src = imgPaths[index]
  img.title = lst.value
  text.innerHTML = osListText[index]
}


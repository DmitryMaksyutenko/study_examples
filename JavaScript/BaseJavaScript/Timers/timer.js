//  setTimeout(function, time, arguments)
//  returns the 'id' of a process that can be terminated by the clearTimeout() method.
var timeValueToDisplay = document.getElementById("timeValue")
var time = 3000
var counter = window.setTimeout(printPage, time + 1000, Date())

var t = window.setInterval(function(){
  timeValueToDisplay.innerHTML = time / 1000
  time -= 1000
  if(time == 0){
    window.clearInterval(t)
    return
  }

}, 1000)

function setTimeOnClock(clock){
  let t1 = new Date()
  clock.innerHTML = t1.toLocaleTimeString()
}


function printPage(time){
  document.write('<p style="text-align: center; font-size: 26px; color: red;">The timer.</p>')
  document.write('<hr>')

  document.write('<p style="text-align: center; font-size: 26px; color: red;">setTimeout() method.</p>')
  document.write('passed: '+ time.toString());
  document.write('<hr>')

  document.write('<p style="text-align: center; font-size: 26px; color: red;">setInterval() method.</p>')
  let clock = document.createElement("div")
  clock.style.background = 'yellow'
  clock.style.color = 'green'
  clock.style.width = 150
  clock.style.height = 20
  clock.style.textAlign = 'center'
  clock.style.borderRadius = '20px'
  clock.style.borderStyle = 'solid'
  clock.style.borderColor = 'red'
  clock.style.borderWidth = 1
  document.body.appendChild(clock)
  //  setInterval(function, time, arguments)
  //  returns the 'id' of a process that can be terminated by the clearInterval() method.
  window.setInterval(setTimeOnClock, 1000, clock)
  document.write('<hr>')
}

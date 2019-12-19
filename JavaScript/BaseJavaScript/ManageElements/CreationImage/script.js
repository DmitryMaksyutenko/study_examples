document.write("<p style='text-align: center; font-size: 26px; color: red;'>Creation the image by script using.</p>")

window.onload = function(){
  let ctx = document.getElementsByTagName("canvas")[0].getContext("2d")

  ctx.canvas.width = 580
  ctx.canvas.height = 330
  ctx.canvas.style.border = "1px solid #009900"
  ctx.canvas.style.marginLeft = "34%"

  let x = 10, y = 10, L = 200

  for(let i = 0; i <= 7; i++){
    ctx.beginPath()
    ctx.lineWigth = 1 + i
    ctx.strokeStyle = "rgb("+(255 - i * 20) +","+ (20 * i) +", 255)"

    x += 10

    ctx.moveTo(x, y)
    ctx.lineTo(x + L / 5, y + L)
    ctx.stroke()

  }
    x += L / 5 + 20

    let sx = 1, sy = -1
    ctx.beginPath()
    ctx.linewidth = 3
    ctx.strokeStyle = "blue"
    ctx.moveTo(x, y)
    while(L > 0){
      x += sx * L
      ctx.lineTo(x, y)
      sy *= -1
      y += sy * L
      ctx.lineTo(x, y)
      L -= 10
      sx *= -1
    }
      ctx.stroke()

    let points = [[400, 60], [450, 20], [510,170], [420, 120]]
    ctx.beginPath()
    ctx.lineWidth = 5
    ctx.strokeStyle = "rgb(255, 0 ,0)"
    ctx.fillStyle = "yellow"
    ctx.moveTo(points[0][0], points[0][1])
    for(let i = 0; i < points.length; i++)
      ctx.lineTo(points[i][0], points[i][1])
    ctx.closePath()
    ctx.fill()
    ctx.stroke()

    x = 20
    y = 230
    L = 80

    ctx.beginPath()
    ctx.lineWidth = 15
    ctx.strokeStyle = "rgb(0, 100 ,0)"
    ctx.fillStyle = "rgb(0, 255, 0)"
    ctx.strokeRect(x, y, 2 * L, L)
    ctx.fillRect(x, y, 2 * L, L)
    ctx.stroke()

    let R = 80
    ctx.beginPath()
    ctx.lineWidth = 5
    ctx.strokeStyle = "rgb(100, 100, 100)"
    ctx.fillStyle = "rgb(255, 100, 100)"
    ctx.arc(x + 2 * L + 20 + R, y, R, 0, Math.PI, false)
    ctx.closePath()
    ctx.fill()
    ctx.stroke()

    ctx.beginPath()
    ctx.arc(x + 2 * L + 3 * R, y + R, R, 0, Math.PI, true)
    ctx.closePath()
    ctx.fill()
    ctx.stroke()
}

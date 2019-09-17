var dravLogo = function(){
  var canvas = document.getElementById("my_canvas");
  var context = canvas.getContext("2d")

  var gradient = context.createLinearGradient(0, 0, 0, 40);
  gradient.addColorStop(0, "#AA0000");
  gradient.addColorStop(1, "#FF0000");
  
  context.fillStyle = gradient;
  context.strokeStyle = gradient;
  

  context.lineWidth = 2;
  context.beginPath();
  context.moveTo(0, 40);
  context.lineTo(30, 0);
  context.lineTo(60, 40);
  context.lineTo(285, 40);

  context.stroke();
  context.closePath();

  context.font = "italic 40px 'Arial'";
  context.fillText("Company", 90, 36);

  context.save();
  context.translate(20, 20);
  context.fillRect(0, 0, 20, 20);

  context.fillStyle = "#FFFFFF";
  context.strokeStyle = "#FFFFFF";

  context.lineWidth = 2;
  context.beginPath();
  context.moveTo(0, 20);
  context.lineTo(10, 0);
  context.lineTo(20, 20);
  context.lineTo(0, 20);

  context.fill();
  context.closePath();
  context.restore();
};

var canvas = document.getElementById("my_canvas");

if (canvas.getContext){
  dravLogo();
}
$(document).ready(function(){

  //  Some jQuery methods can be used to either assign or read some value on a selection.
  //  When the method is called with a value as an argument,
  //  it's referred to as a setter because it sets (or assigns) that value.
  //  When the method is called with no argument, it gets (or reads) the value of the element.
  $("h1").text("Hello World!") // Setter
  console.log($("h1").text()) // Getter

  //  Attempting to call a jQuery method after calling a getter.
  //  This will NOT work:
  //  $( "h1" ).html().addClass( "test" );

  // $("#block")
  //  .find("h2")
  //  .eq(1)
  //  .html("element two")
  //  .end()
  //  .eq(0)
  //  .html("element one")
  //  .end()
  //  .eq(2)
  //  .html("element three")
  //  .end()
  //  .eq(3)
  //  .html("element four")


  var i = $("#block").children().length

  for(let x = 0;x < i ; x++){
    $("#block")
      .find("h2")
      .eq(x)
      .text("Element number " + x)
  }

})

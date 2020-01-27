$(document).ready(function(){

  var $span = $("span.subchild")
  var $text = $("<p>Parents:</p>")

  $("body").prepend($text)

  // The methods for finding the parents from a selection include .parent(), .parents(), .parentsUntil(), and .closest().

  console.log($span.parent())
  $text.after($("<p></p>").text($span.parent().get()))

  console.log($span.parents())
  $("p").last()
    .append($("<p></p>")
      .text($span
        .parents().get()))

  console.log($span.parentsUntil(".grandparent"))
  $("p").last()
    .append($("<p></p>")
      .text($span
        .parentsUntil(".grandparent").get()))


  console.log($span.closest("div"))
  $("p").last()
    .append($("<p></p>")
      .text($span
        .closest("div").get()))

  $("p").last()
    .append($("<p></p>")
      .text("Children:"))

  // The methods for finding child elements from a selection include .children() and .find().

  console.log($span.children("div"))
  $("p").last()
    .append($("<p></p>")
      .text($span
        .children("div")))

  console.log($span.find("div"))
  $("p").last()
    .append($("<p></p>")
      .text($span
        .find("div")))

  $("p").last()
    .append($("<p></p>")
      .text("Siblings:"))

  //  find previous elements with .prev(), next elements with .next(), and both with .siblings()

  console.log($("div.parent").prev())
  console.log($span.next())
  console.log($span.siblings())

  $("p").last()
    .append($("<p></p>")
      .text($span
        .prev()))

  $("p").last()
    .append($("<p></p>")
      .text($span
        .next()))

  $("p").last()
    .append($("<p></p>")
      .text($span
        .siblings()))

})

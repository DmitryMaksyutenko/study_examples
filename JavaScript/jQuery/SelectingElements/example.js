$(document).ready(function(){

  //  Selecting by ID.
  $("#p_id").text("Element selected by it's ID.")

  //  Selected by Class Name.
  $(".p1").text("Element selected by it's Class Name.")

  //  Selected by Attribyte.
  $("input[name='tag_name']").val("Button")

  //  Selected by Compound selector.
  $("#ul_id li").text("Element selected by Compound CSS selector.")

  //  Filtering selections.
  console.log($("ol").has("li").length)

  var olElement = $("ol li")
  olElement.first().text("element one")
  olElement.eq(1).text("element two")
  olElement.last().text("element three")

  //  Check containing.
  if($(".p1").length){
    $("ol").append("<li>")
    $("ol li").last().text("element added")
  }

})

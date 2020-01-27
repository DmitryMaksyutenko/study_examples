$(document).ready(function(){

  // The change will affect all elemnts in the selection.
  // Specify the selection before calling a setter method.
  // $("body").html("<p>hello</p>")

  //  Move elements.
  $("body").after("<p>Hello created in .after() method.</p>")
  $("body").prepend("<p>Hello created with .prepend() method.</p>")
  $("body").before("<p>Hello created with .insertBefore() method.</p>")

  // Cloning elements.
  var clone = $("body p").eq(0).clone() // Make the clone of the element.
  var text = clone.text()
  clone.text(text + " CLONE")
  $("body p").eq(0).after(clone)

  //  Remove elements.
  var removeReturn = $("body p").eq(0).remove()
  console.log(removeReturn)

  var detachReturn = $(clone).detach()
  console.log(detachReturn)

  var emptyReturn = $("body p").last().empty()
  console.log(emptyReturn)

  // Creating new elements.
  $("<a href=''>this is a new link.</a>").prependTo("body")
  var a = $("<a>", {
    html: "This is a <strong>LINK</strong>",
    href: "",
  })
  $("body").after(a)

  // Elemets attributes manipulation.
  $("body + a").attr({
    href: function(){alert("hello")},
    "class": "newClass"
  })

})

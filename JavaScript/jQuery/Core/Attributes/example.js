$(document).ready(function(){

    //  Attributes contain extra information about element.
    //  That information can be useful, it's important to be able to get
    //  and set it.
    var element = $(".p1");
    element.css("text-align", "center")
    element.text("Attributes:")

    //  It can be called on a jQuery object and chained to other jQuety methods.
    element.after($("<p>").css("text-align", "center").text(element.attr("class")));
    element.after($("<p>").css("text-align", "center").text(element.attr("style")));

});
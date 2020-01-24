$("document").ready(function(){

    var h1List = $("h1")
    h1List.text("Some text!")

    //  Setting CSS properties.
    h1List.eq(0).css("color", "red")
    //  Multiple assigning.
    //  Use camelCase in names with a hyphen.
    h1List.eq(1).css({color: "blue",
                      fontSize: "12px",
                      textAlign: "center"})

    //  Get CSS properties.
    console.log(h1List.eq(0).css("color"))
    console.log(h1List.eq(1).attr("style"))

    //  Write CSS rules for classes that describe the various visual states, and then change the class on the element.
    h1List.eq(2).addClass("redStyle")
    h1List.eq(3).addClass("greenStyle")
    h1List.eq(4).addClass("blueStyle")
    h1List.eq(5).addClass("cyanStyle")

    //  Remove class.
    //  h1List.eq(5).removeClass("cyanStyle")

    //  Dimensions.
    console.log("first element width: " + h1List.eq(0).width())
    h1List.eq(0).width(200)
    console.log("first element width: " + h1List.eq(0).width())

    console.log("second element height: " + h1List.eq(1).height())
    h1List.eq(1).height(150)
    console.log("second element height: " + h1List.eq(1).height())

    console.log(h1List.eq(2).position())

})
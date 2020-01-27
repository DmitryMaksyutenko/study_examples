$("document").ready(function(){

    var $p = $(".p1")
    var $button = $("#clickButton")

    // Any kind of data can be stored on an element.
    $p.data("Description", "This is a paragraph element.")
    $button.data("Description", "This is a button element.")
    $button.data("Counter", {counter: 0})

    // Storing a relationship between elements using .data()
    $button.data("Text element", $p)

    $button.click(function(){

        if($button.data("Counter")["counter"] % 2 != 0)
            $button.data("Text element").text($p.data("Description"))
        else
            $button.data("Text element").text($button.data("Description"))

        $button.data("Counter")["counter"] += 1

    })

})
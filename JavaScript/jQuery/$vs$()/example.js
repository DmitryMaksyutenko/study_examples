$("document").ready(function(){

    // jQuery or $
    // Return a collection of matched elements either found in the DOM based on passed argument(s) ("this") 
    // or created by passing an HTML string.
    // jQuery()
    // jQuery( selector [, context ] )
    // jQuery( selector [, context ] )
    // jQuery( element )
    // jQuery( elementArray )
    // jQuery( object )
    // jQuery( selection )
    // jQuery( html [, ownerDocument ] )
    // jQuery( html [, ownerDocument ] )
    // jQuery( html, attributes )
    // jQuery( callback )
    // jQuery( callback )
    $("#test_p1").text($("p"))
    console.log(jQuery("p"))

    //  Core object of jQery.
    console.log($())
})
// Including jQuery before other libraries gives the approach to use
// full jQuery function name to reference library.


//  Use jQuery No-Conflict Mode.
// var $jq = jQuery.noConflict()

// $jq(document).ready(function(){
//     let elem = $jq("p.p1")
//     elem.text("$jq is an alias of jQuery!")

//     elem.css("font-size", "30px")
//     elem.css({"font-family": "Arial",
//             "color": "blue",
//             "text-align": "center"})
// })


//  Adding $ as an argument of .ready() function for using $ as alias of jQuery.
// jQuery.noConflict()

// jQuery(document).ready(function($){
//     let elem = $("p.p1")
//     elem.text("Now $ is an alias of jQuery!")
//     elem.css({"font-size": "30px", 
//             "font-family": "Helvetica",
//             "color": "red",
//             "text-align": "center"})
// })


// Immidietely invoked function expression
// jQuery.noConflict()

// (function($){
//     let elem = $("p.p1")
//     elem.text("Now $ is an alias of jQuery!")
//     elem.css({"font-size": "30px", 
//             "font-family": "Courier",
//             "color": "yellow",
//             "text-align": "center"})
// })


// Use concise syntax for the DOM ready function
jQuery(function(){
    let elem = $("p.p1")
    elem.text("Now $ is an alias of jQuery!")
    elem.css({"font-size": "30px", 
            "font-family": "Times New Roman",
            "color": "green",
            "text-align": "center"})
})
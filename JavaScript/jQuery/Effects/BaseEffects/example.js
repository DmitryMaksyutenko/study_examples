$(document).ready(function(){

    $(".inline").css({
        display: "inline-block",
        position: "relative",
        margin: "30px"
    });

    $(".squared").css({
        width: "90px",
        height: "90px",
        margin: "auto"
    });

    $(".buttons").css("margin", "10px");

    let $redSquare = $("#red");
    let $blueSquare = $("#blue");
    let $greenSquare = $("#green");
    let $yellowSquare = $("#yellow");
    let $cyanSqare = $("#cyan");
    let $pincSquare = $("#pinc");

    $redSquare.css("background", "red");
    $blueSquare.css("background", "blue");
    $greenSquare.css("background", "green");
    $yellowSquare.css("background", "yellow");
    $cyanSqare.css("background", "cyan");
    $pincSquare.css("background", "#ff99ff");

    //  ---------------------------------------------
    $("#showRed").click(function(){
        if($redSquare.is(":hidden"))
            $redSquare.show(1000);
    });

    $("#hideRed").click(function(){
        if(!$redSquare.is(":hidden"))
            $redSquare.hide(1000);
    });
    //  ---------------------------------------------

    //  ---------------------------------------------
    $("#slideUp").click(function(){
        if(!$blueSquare.is(":hidden"))
            $blueSquare.slideUp(1000);
    });

    $("#slideDown").click(function(){
        if($blueSquare.is(":hidden"))
            $blueSquare.slideDown(1000);
    });
    //  ---------------------------------------------

    //  ---------------------------------------------
    $("#fadeOut").click(function(){
        if(!$greenSquare.is(":hidden"))
            $greenSquare.fadeOut(1000);
    });

    $("#fadeIn").click(function(){
        if($greenSquare.is(":hidden"))
            $greenSquare.fadeIn(1000);
    });
    //  ---------------------------------------------

    //  ---------------------------------------------
    $("#toggle").click(function(){
        $yellowSquare.toggle(1000);
    });
    //  ---------------------------------------------

    //  ---------------------------------------------
    $("#slideToggle").click(function(){
        $cyanSqare.slideToggle(1000);
    });
    //  ---------------------------------------------

    //  ---------------------------------------------
    $("#fadeToggle").click(function(){
        $pincSquare.fadeToggle(1000);
    });
    //  ---------------------------------------------
});
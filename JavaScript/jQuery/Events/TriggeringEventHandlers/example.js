$("document").ready(function(){

    $ul1 = $("#ul1");
    $ul2 = $("#ul2");
    $gotoGoogle = $("#gotoGoogle");

    //  Not work.
    // $gotoGoogle.trigger("click");

    $ul1.on("click", function(e){
        console.log("event: " + e.type + "\n" + this.id);
    });

    $ul1.trigger("click");

    $ul2.hover(function(){
        console.log($(this).text());
    });

    //  "hover" not worck.
    $ul2.triggerHandler("mouseenter");

    //  event bubbling.
    function testMessage(){
        console.log(this.id);
    }

    $("#l3").click(testMessage);
    $("#l6").click(testMessage);

    $("#l3").trigger("click");

    // No bubbling.
    $("#l6").triggerHandler("click");

});
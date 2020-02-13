$(document).ready(function(){

    let $button = $("#toggle");
    let $colorDiv = $("#colorDiv");

    $colorDiv.on("MyColorEvent", function(event){
        if($(this).attr("class") == "redColor"){
            $(this).removeClass("redColor");
            $(this).addClass("greenColor");
        }
        else{
            $(this).removeClass("greenColor");
            $(this).addClass("redColor");
        }
    });

    $button.on("click", function(){
        $colorDiv.trigger("MyColorEvent");
    });
});
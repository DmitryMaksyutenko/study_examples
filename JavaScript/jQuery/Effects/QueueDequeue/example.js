$(document).ready(function(){

    $redDiv = $("#red");
    $greenDiv = $("#green");
    $blueDiv = $("#blue");

    $redDiv.css({
        "position": "relative",
        backgroundColor: "red",
        width: "150px",
        height: "150px",
        margin: "10px"
    });

    $greenDiv.css({
        "position": "relative",
        backgroundColor: "green",
        width: "150px",
        height: "150px",
        margin: "10px"
    });

    $blueDiv.css({
        "position": "relative",
        backgroundColor: "blue",
        width: "150px",
        height: "150px",
        margin: "10px"
    });

    //  Callback function.
    $redDiv.click(function(){
        $(this).animate({
            height: "+=10px",
        },
        2000,
        function(){
            console.log("Callback function on red div.");
        }
        );
    });

    //  Queue making.
    $greenDiv.click(function(){
        $(this).animate({
            width: "+=10px"
        },
        2000).queue(function(next){
            $(this).animate({
                height: "+=10px"
            }, 2000);

            next();
        }).clearQueue().queue(function(next){
            $(this).animate({
                opacity: "-=0.1"
            },
            1000);
        }).dequeue();
    });

    //  Replace queue.
    $blueDiv.click(function(){
        $(this).animate({
            width: "+=10px",
            height: "+=10px"
        },
        2000).queue(function(next){
            $(this).animate({
                opacity: "0.5"
            },
            1000);
        }).queue([
            function(next){
                $(this).animate({
                    height: "+=100px",
                    width: "+=100px"
                }),
                1000;
            }
        ]);
    });

});
$(document).ready(function(){

    $redDiv = $("#red");
    $greenDiv = $("#green");

    $redDiv.css({
        width: "100px",
        height: "100px",
        backgroundColor: "red",
        margin: "10px"
    });

    $greenDiv.css({
        width: "100px",
        height: "100px",
        backgroundColor: "green",
        margin: "10px",
        position: "relative"
    });

    $redDiv.animate(
        {
            width: "80%",
            opacity: 0.5,
        },
        3000,
    );

    $greenDiv.animate(
        {
            left: ["+=1400px", "swing"],
        },
        3000,
    );

});
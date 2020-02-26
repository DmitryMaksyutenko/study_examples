$(document).ready(function(){

    $.get("response.html")
        .fail(function(){
            console.log("request failed!");
        });

});
$("document").ready(function(){

    let $ulElement = $("#list");
    //  let $ulElement = $("#list p"); executes on one particular child element.

    $ulElement.on("click", function(event){
        console.log($(this).text());
    });

    $ulElement.append("<li><p>Item five</p></li>");
});
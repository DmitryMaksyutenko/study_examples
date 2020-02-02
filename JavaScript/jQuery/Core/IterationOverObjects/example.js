$("document").ready(function(){

    //  Iterate over javascript object.
    let jsArray = [1, 2, 3, 4, 5];

    $.each(jsArray, function(i, j){
        console.log(i + ": " + j);
    });

    //  Iterate over jQuery object.
    for(let i = 0; i < 5; i++){
        $("body").prepend($("<p></p>"));
    }

    let $pObj = $("p");
    //  .text() method as getter iterate over each object of selection.
    $pObj.text("Default text.");
    //  As setter, it returns concatenated strings of all elements of selection.
    console.log($pObj.text())

    $pObj.each(function(i, element){
        let $i = $(element);
        $i.text(i + " : New text.");
    });

    //  .map() used for common iteration purposes.
    console.log($pObj
        .map(function(i, element){
            return element.id;
        }
        // .get() Retrieve the DOM elements matched by the jQuery object.
    ).get());

});
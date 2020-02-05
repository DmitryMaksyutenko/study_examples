$("document").ready(function(){

    let $redDiv = $("#red_div");
    let $greenDiv = $("#green_div");
    let $blueDiv = $("#blue_div");
    let $inputElem = $("#input_id")


    // .click() tests
    $redDiv.click(function(event){
        // event.preventDefault();

        let objClass = this.id;
        let eventType = event.type;
        eventText(objClass, eventType);
    });


    $greenDiv.click(function(event){
        // event.preventDefault();

        let objClass = this.id;
        let eventType = event.type;
        eventText(objClass, eventType);
    });


    $blueDiv.click(function(event){
        // event.preventDefault();

        let objClass = this.id;
        let eventType = event.type;
        eventText(objClass, eventType);

        // Event will not passed to the parent element.
        event.stopPropagation();
    });


    // .focus() test.
    $inputElem.focus(function(event){
        let x = event.pageX;
        let y = event.pageY;
        let elementName = event.target.id;
        showMousePos(x, y, elementName);
    });


    // .mouseenter() test.
    $redDiv.mouseenter(function(event){
        let x = event.pageX;
        let y = event.pageY;
        let elementName = event.target.id;
        showMousePos(x, y, elementName);
    });


    $greenDiv.mouseenter(function(event){
        let x = event.pageX;
        let y = event.pageY;
        let elementName = event.target.id;
        showMousePos(x, y, elementName);
    });


    $blueDiv.mouseenter(function(event){
        let x = event.pageX;
        let y = event.pageY;
        let elementName = event.target.id;
        showMousePos(x, y, elementName);
    });


    $(document).on("click", function(event){
        $pressed = event.which;
        alert("The '" + $pressed + "' pressed.");
    });


    // Utility functions.
    function eventText(objectName, event){
        window.alert("Event '" + event + "' on '" + objectName + "' element.");
    }


    function showMousePos(xPos, yPos, element){
        $("#x").text("x mouse posititon : " + xPos);
        $("#y").text("y mouse posititon : " + yPos);
        $("#elem").text("on element : " + element);
    }

});
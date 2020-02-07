$("document").ready(function(){

    //  .hover() bind two handlers to the matched element, to be executed when the
    //  mouse pointer enters and leaves the element.
    let $itemOne = $("#l1");
    let $itemTwo = $("#l2");
    let $itemThree = $("#l3");
    let $itemFour = $("#l4");

    $itemOne.hover(onMouseEnterEvent, onMouseLeaveEvent);
    $itemTwo.hover(onMouseEnterEvent, onMouseLeaveEvent);
    $itemThree.hover(onMouseEnterEvent, onMouseLeaveEvent);
    $itemFour.hover(onMouseEnterEvent, onMouseLeaveEvent);

    function onMouseEnterEvent(){
        console.log("Mouse enter on object -> " + this.id);
    }

    function onMouseLeaveEvent(){
        console.log("Mouse leave on object -> " + this.id);
    }

    //  .keydown() Bind an event handler to the "keydown" JavaScript event,
    //  or trigger that event on an element.
    let $keyDownInput = $("#keydown");

    $keyDownInput.keydown(function(event){alert("Key " + event.which + " pressed.");});

    //  .scroll() Bind an event handler to the "JavaScript" event,
    //   or trigger that event on an element.
    let $bodyElemnt = $(window);
    let counter = 10000000;

    $bodyElemnt.scroll(changeBgColor);

    function changeBgColor(){
        let hexStr = counter.toString(16);
        hexStr = "#" + hexStr
        $("body").css("background-color", hexStr);
        counter++;
    }

});
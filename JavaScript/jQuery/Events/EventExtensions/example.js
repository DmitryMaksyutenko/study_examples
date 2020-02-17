$(document).ready(function(){

    let $link = $("#link");

    /*
        noBooble: Boolean
        bindType: String -> used if the event attached directly.
        delegateType: String -> used for delegated events.
        handleObj -> object provides more information about the event.
            type: String
            originType: String
            delegateTupe: String
            namespace: String
            selector: String
            data: Object
            handle: function
        setup: function(data, namespaces, function) -> called the first time a particular type is attached to an element.
        teardown: function() -> called when the final event of a particular type is removed.
        add: function(handleObj) -> called hook when event is added through API.
        remove: function(handler) -> called hook when event is removed through API.
        trigger: function(event, data) -> called when .trigger() or triggerHandler() are used.
        _default: function(event, data) -> when the .trigger() method finishes runing.
        handle: function(event, data) -> called when event occurred.
    */

    $.event.special.pushy = {
        bindType: "click",
        delegateType: "click"
    };

    $.event.special.hoverclick = {
        bindType: "mouseenter",
        delegateType: "mouseenter",
        handle: function(event){
            console.log("From hook:\n" + event.handleObj.type + "\n" +
                        event.handleObj.originType + "\n" +
                        event.handleObj.delegateType + "\n" +
                        event.handleObj.namespace + "\n" +
                        event.handleObj.selector);
        }
    }

    $link.on("pushy", function(event){
        event.preventDefault();
        $("body").append("<h1>pushy</h1>");
    })

    $("#pTag").on("hoverclick", function(event){
        console.log("From event handler function!");
    });

});
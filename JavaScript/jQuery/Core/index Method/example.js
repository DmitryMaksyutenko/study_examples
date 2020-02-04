$("document").ready(function(){

    let $ul1 = $("ul");
    let $div1 = $(".test");
    let $foo_1 = $("#foo1");

    // With no arguments.
    console.log("With no arguments.");
    console.log("The index of the element: " + $ul1.index());
    console.log("The index of the element: " + $div1.index());
    console.log("The index of the element: " + $foo_1.index());

    //  With string argument.
    console.log("With string argument.");
    console.log("The index of the element: " + $ul1.index("div"));
    console.log("The index of the element: " + $ul1.index("ul"));
    console.log("The index of the element: " + $ul1.index("#foo1"));

    console.log("The index of the element: " + $foo_1.index("#foo1"));
    console.log("The index of the element: " + $foo_1.index("#bar1"));

    console.log("The index of the element: " + $("#baz1").index("li"));

    //  With object argument.
    console.log("With object argument.");
    console.log("The index of the element: " + $ul1.index($div1));
    console.log("The index of the element: " + $ul1.index($ul1));

    console.log("The index of the element: " + $("body").index($ul1));
    console.log("The index of the element: " + $("li").index($("#bar1")));

});
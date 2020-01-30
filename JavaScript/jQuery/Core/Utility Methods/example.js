$("document").ready(function(){

    //  $.trim() Removes leading and trailing whitespace.
    let testText = "        test text               ";
    console.log(testText);
    console.log($.trim(testText));

    //  $.each() Iterates over arrays and objects.
    let liElement = $("li")
    $.each(liElement, function(i, v){
        console.log(i + ": " + v);
    });

    //  $.inArray() Returns a value's index in an array, or -1 if the value is not in the array.
    let arr1 = [1, 2, 3, 4];
    let arr2 = {foo: "one", fooo: "two"};
    console.log($.inArray(4, arr1));
    console.log($.inArray("two", arr2));

    //  $.extend() Changes the properties of the first object using the properties of subsequent objects.
    let obj1 = {prop1: "property one", prop2: "property two"};
    let obj2 = {prop3: "property three", prop4: "property four"};
    let $obj3 = $.extend(obj1, obj2);
    console.log($obj3);

    //  $.proxy() Returns a function that will always run in the provided scope.
    let foo = function(){
        console.log(this);
    };

    let obj4 = {prop5: "this is property"};
    let $proxyFunction = $.proxy(foo, obj4);
    $proxyFunction(); //    {prop5: "this is property"}

    //  $.type() checks for the internal class used to create a value.
    console.log($.type($obj3));
    console.log($.type({}));
    console.log($.type([]));
    console.log($.type(4));
    console.log($.type("text"));
    console.log($.type(function(){}));
    console.log($.type(this));
    console.log($.type(4.4));
    console.log($.type(true));
    console.log($.type($("<a></a>")));

});
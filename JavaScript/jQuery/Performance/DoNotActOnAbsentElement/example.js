$(document).ready(function(){

    let $elem = $("a");

    if($elem.length){
        $elem.text("click me!");
    }

    // BEST PRACTICE.
    jQuery.fn.doOnce = function(funct){
        this.length && funct.apply(this);
        return this;
    }

    $elem.doOnce(function(){
        this.css("textDecoration", "none");
    });

});
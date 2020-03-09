$(document).ready(function () {

    $.fn.bigText = function(){
        this.css({
            fontSize: "36px",
            position: "relative"
        });
        return this;
    }

    $("p").bigText()
        .animate({
            left: "+=850px",
            top: "+=400px"
        }, 5000);

});